#include <ESP8266WiFi.h>
#include <ArduinoJson.h>
#define TELEGRAM_DEBUG
#include "UniversalTelegramBot.h"

const char* ssid = "wifiname";
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
  Serial.println("\nConnecting...");

  while (WiFi.status()!= WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  
  Serial.print("Retrieving time!");
  configTime(0,0,"pool.ntp.org");
  time_t now = time(nullptr);
  while(now < 24*3600)
  {
    Serial.print(".");
    delay(100);
    now = time(nullptr);
  }
  Serial.println(now);

  Serial.println("\nConnected!");
  bot.sendMessage(ChatID,"Botstarted up","");
}

void loop()
{
  if(!bot.sendMessage(ChatID,"HEY")){
    Serial.println("unable to send message");
  } else{
    Serial.println("Done");
  }
  delay(1000);
}