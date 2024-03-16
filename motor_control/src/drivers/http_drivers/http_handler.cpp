#include "http_handler.h"
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

IPAddress local_ip(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

void handle_onconnect();
void handle_foward();
void handle_backward();
void handle_fstop();
void handle_bstop();
void handle_NotFound();
String SendHTML();
void handle_stop();


void handle_setup()
{
    WiFi.softAP("Espserver","password");
    WiFi.softAPConfig(local_ip,gateway,subnet);
    delay(100);
}

void handle_URLs()
{
    server.on("/", handle_onconnect);
    server.on("/foward", handle_foward);
    server.on("/backward", handle_backward);
    server.on("/fstop", handle_stop);
    server.on("/bstop", handle_stop);
    server.onNotFound(handle_NotFound);
    server.begin();
    Serial.println("http server started.");
}

void handle_onconnect()
{
    states.is_foward = false;
    states.is_backward = false;
    states.is_stopped= false;
    Serial.println("fwdpin OFF! | bckpin OFF");
    server.send(200, "text/html", SendHTML());
}

void handle_foward()
{
    states.is_foward = true;
    Serial.println("fwdpin HIGH!");
    server.send(200, "text/html", SendHTML());
}

void handle_backward()
{
    states.is_backward = true;
    Serial.println("bwdpin HIGH!");
    server.send(200, "text/html", SendHTML());
}

void handle_stop()
{
    states.is_stopped = true;
    Serial.println("fwdpin LOW! | bckpin LOW!");
    server.send(200, "text/html", SendHTML());
}


void handle_NotFound()
{
    server.send(404, "text/plain", "Not Found");
}



String SendHTML()
{
    String ptr = "<!DOCTYPE html> <html>\n";
    ptr += "<head><title>MOTOR CONTROL</title></head>\n"; 
    ptr += "<body>\n"; 
    ptr += "<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
    ptr += "body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;} h3 {color: #444444;margin-bottom: 50px;}\n";
    ptr += "p {font-size: 14px;color: #888;margin-bottom: 10px;}\n";
    ptr += ".button {display: block;width: 80px;background-color: #1abc9c;border: none;color: white;padding: 13px 30px;text-decoration: none;font-size: 25px;margin: 0px auto 35px;cursor: pointer;border-radius: 4px;}\n";
    ptr += ".button-on {background-color: #1abc9c;}\n";
    ptr += ".button-on:active {background-color: #16a085;}\n";
    ptr += ".button-off {background-color: #34495e;}\n";
    ptr += ".button-off:active {background-color: #2c3e50;}\n";
    ptr += "</style>\n"; 
    ptr += "<h1>GAINING CONTROL</h1>\n";
    ptr += "<h3>Controlling a motor wirelessly!</h3>\n";
    if (states.is_foward)
    {
        ptr += "<p>YOU ARE GOING FORWARD</p><a class=\"button button-off\" href=\"/fstop\">STOP</a>\n";
    }
    else
    {
        ptr += "<p>YOU ARE NOT GOING FORWARD</p><a class=\"button button-on\" href=\"/foward\">GO</a>\n";
    }

    if (states.is_backward)
    {
        ptr += "<p>YOU ARE GOING BACKWARDS</p><a class=\"button button-off\" href=\"/bstop\">STOP</a>\n";
    }
    else
    {
        ptr += "<p>YOU ARE NOT GOING BACKWARDS</p><a class=\"button button-on\" href=\"/backward\">GO</a>\n";
    }

    ptr += "</body>\n";
    ptr += "</html>\n";
    return ptr;
}