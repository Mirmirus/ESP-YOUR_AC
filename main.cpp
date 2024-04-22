#include <WiFi.h>
#include <WebServer.h>

// Replace these with your desired credentials.
const char *ssid = "MIRMIR";
const char *password = "Mirmir_the_best";  // Password can be empty string if you want open network

WebServer server(80);  // Create a web server on port 80

void handleRoot() {
  server.send(200, "text/plain", "Hello, this server is working, Mirmir cool");
}

void setup() {
  Serial.begin(115200);

  // Set up the ESP32 WiFi module in AP mode.
  WiFi.softAP(ssid, password);
  Serial.println("Access Point started");
  Serial.println(WiFi.softAPIP()); // Print the IP address of the server

  // Start handling web paths.
  server.on("/", handleRoot);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();  // Handling of incoming client requests
}
