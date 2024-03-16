#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "drivers/http_handler.h"

#define but1pin 14
#define but2pin 13


IPAddress local_ip(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);
ESP8266WebServer server(80);
direction_state states = {false,false};

void setup() {
  Serial.begin(115200);
  WiFi.softAP("Control", "password");
  WiFi.softAPConfig(local_ip, gateway, subnet);
  delay(100);
  handle_URLs();
  server.begin();
  Serial.println("http server started.");
}

void loop() 
{
  server.handleClient();
    if(states.is_foward)
  {digitalWrite(but1pin, HIGH);}
  else
  {digitalWrite(but1pin, LOW);}
  
  if(states.is_backward)
  {digitalWrite(but2pin, HIGH);}
  else
  {digitalWrite(but2pin, LOW);}

}
