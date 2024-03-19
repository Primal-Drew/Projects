#include "UniversalTelegramBot.h"
#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include "telegram_message.h"

void init_client(tlg_details* telegram)
{
    X509List cert(TELEGRAM_CERTIFICATE_ROOT);
    WiFiClientSecure client;
    telegram->cert = &cert;
    telegram->client = client;
}

void create_bot(tlg_details* telegram)
{
    UniversalTelegramBot bot(telegram->BotToken,telegram->client);
    telegram->bot = bot;
}

void get_time()
{
    Serial.print("Retrieving time:");
    configTime(0,0,"pool.tp.org");
    time_t now = time(nullptr);
    while(now < 24*3600)
    {
        Serial.print(".");
        delay(100);
        now = time(nullptr);
    }
    Serial.print(now);
}

void setup_telegram(tlg_details* telegram)
{
    telegram->client.setTrustAnchors(telegram->cert);
    telegram->bot.sendMessage(telegram->CHAT_ID, "Bot started up", "");
}