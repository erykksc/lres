#include "secrets.h"
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>

AsyncWebServer server(80); // HTTP server will run on port 80

void setup()
{
    Serial.begin(9600);
    if (!SPIFFS.begin(true))
    {
        Serial.println("An Error has occurred while mounting SPIFFS");
        return;
    }
    // // Connect to Wi-Fi
    WiFi.begin(WIFI_SSID, WIFI_PASS);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }

    Serial.println(WiFi.localIP()); // Print the device's IP address

    // Define routes
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
              { Serial.println("Request received on /"); 
                });
      // Serve all files directly from SPIFFS
    server.serveStatic("/", SPIFFS, "/").setDefaultFile("index.html");
    server.begin(); // Start the server
}

void loop()
{
    // Nothing to do here, the server handles connections asynchronously
}
