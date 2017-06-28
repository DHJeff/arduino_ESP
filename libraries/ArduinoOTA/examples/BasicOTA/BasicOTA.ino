#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

const char* ssid = "DHLabs";
const char* password = "dhlabsrfid01";

void setup() {
  Serial1.begin(9600);
  Serial1.println("Booting");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial1.println("Connection Failed! Rebooting...");
    delay(5000);
    ESP.restart();
  }

  // Port defaults to 8266
  // ArduinoOTA.setPort(8266);

  // Hostname defaults to esp8266-[ChipID]
  // ArduinoOTA.setHostname("myesp8266");

  // No authentication by default
  // ArduinoOTA.setPassword((const char *)"123");

  ArduinoOTA.begin();
  //Serial.println("Ready");
  //Serial.print("IP address: ");
  //Serial.println(WiFi.localIP());
}

void loop() {
  ArduinoOTA.handle();
  Serial1.println("ciao");
}
