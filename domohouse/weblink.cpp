#include "weblink.h"
/*
//-----------WIFI MODULE----------//

// Constructeurs

WifiModule::WifiModule() {};
WifiModule::~WifiModule() {};

// Public functions
        
int WifiModule::initialize(void) {
  // Network credentials
  const char* ssid     = "1234";
  const char* password = "tegm1526";
        
  Serial.begin(115200);
  // Initialize the output variables as outputs
  pinMode(outputA, OUTPUT);
  pinMode(outputB, OUTPUT);
  // Set outputs to LOW
  digitalWrite(outputA, LOW);
  digitalWrite(outputB, LOW);

  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
  
  return 0;
}

void WifiModule::boucleWifi(void) {
  
  // Variable to store the HTTP request
  String header;

  // Auxiliar variables to store the current output state
  String outputAState = "off";
  String outputBState = "off";

  // Current time
  unsigned long currentTime = millis();
  // Previous time
  unsigned long previousTime = 0;
  // Define timeout time in milliseconds (example: 2000ms = 2s)
  const long timeoutTime = 2000;

  WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {                             // If a new client connects,
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    currentTime = millis();
    previousTime = currentTime;
    while (client.connected() && currentTime - previousTime <= timeoutTime) { // loop while the client's connected
      currentTime = millis();
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

            // turns the outputs on and off
            if (header.indexOf("GET /B/on") >= 0) {
              Serial.println("OUTPUT B on");
              outputBState = "on";
              digitalWrite(outputB, HIGH);
            } else if (header.indexOf("GET /B/off") >= 0) {
              Serial.println("OUTPUT B off");
              outputBState = "off";
              digitalWrite(outputB, LOW);
            } else if (header.indexOf("GET /A/on") >= 0) {
              Serial.println("OUTPUT A on");
              outputAState = "on";
              digitalWrite(outputA, HIGH);
            } else if (header.indexOf("GET /A/off") >= 0) {
              Serial.println("OUTPUT A off");
              outputAState = "off";
              digitalWrite(outputA, LOW);
            }

            // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons
            // Feel free to change the background-color and font-size attributes to fit your preferences
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #195B6A; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #77878A;}</style></head>");

            // Web Page Heading
            client.println("<body><h1>ESP8266 Web Server</h1>");

            // Display current state, and ON/OFF buttons for OUTPUT B
            client.println("<p>OUTPUT B - State " + outputBState + "</p>");
            // If the outputBState is off, it displays the ON button
            if (outputBState == "off") {
              client.println("<p><a href=\"/B/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/B/off\"><button class=\"button button2\">OFF</button></a></p>");
            }

            // Display current state, and ON/OFF buttons for OUTPUT A
            client.println("<p>OUTPUT A - State " + outputAState + "</p>");
            // If the outputAState is off, it displays the ON button
            if (outputAState == "off") {
              client.println("<p><a href=\"/A/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/A/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
            client.println("</body></html>");

            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}
*/
