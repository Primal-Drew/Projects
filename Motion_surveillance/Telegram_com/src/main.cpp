#include "drivers/http_drivers/http_handler.h"
#include "drivers/telegram_drivers/telegram_message.h"
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "UniversalTelegramBot.h"

char* SSID = "wifiname";
char* password = "password";

// Define the global variables declared in the header file
ESP8266WebServer server(80);
presence_state detection = {true,false};

void setup()
{
  Serial.begin(115200);
  handle_setup(SSID, password);
  start_server();
}

void loop()
{
  detection.is_someone = true;
  delay(1000);
}
