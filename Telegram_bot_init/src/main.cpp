#include <ESP8266WiFi.h>
#include <ArduinoJson.h>
#include "UniversalTelegramBot.h"

const char* ssid = "shepherd";
const char* password = "password";

#define BotToken "6602753276:AAHxXplqfSiHmghdmsOYbKpd9jEpOeC2q_0"
#define ChatID "1237656561"

X509List cert(TELEGRAM_CERTIFICATE_ROOT);
WiFiClientSecure client;

UniversalTelegramBot bot(BotToken,client);

void setup()
{
  Serial.begin(115200);
  client.setTrustAnchors(&cert);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid,password);
  Serial.println("Connecting...");
  while (WiFi.status()!= WL_CONNECTED)
  {
    delay(500);
    Serial.println(".");
  }
  Serial.println("Connected!");
  bot.sendMessage(ChatID,"Botstarted up","");
}

void loop()
{
  Serial.println("Done");
  delay(10000);
}