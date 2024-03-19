#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "http_handler.h"

void handle_NotFound();
String SendHTML();

void handle_setup(char* SSID, char* password)
{
    WiFi.begin(SSID, password);
    Serial.print("Connecting ");
    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        delay(1000);
    }
    Serial.println("");
    Serial.println("Connected!");
    Serial.print("IPAddress: ");
    Serial.println(WiFi.localIP());

    // Initialize the detection object
    detection.is_someone = false;
    detection.is_no_one = false;
}

void start_server()
{
    server.on("/", HTTP_GET, []() 
    {
        server.send(200, "text/html", SendHTML());
        Serial.println("Sent to server!");
    });
    server.onNotFound(handle_NotFound);
    server.begin();
    Serial.println("HTTP server started.");
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
    ptr += "p {font-size: 40px;color: #888;margin-bottom: 10px;}\n";
    ptr += "</style>\n";
    ptr += "<h1>INTRUDER ALERT!!!</h1>\n";
    ptr += "<h3>MOTION SURVEILLANCE SYSTEM!</h3>\n";
    ptr += "<p id=\"status\"></p>\n"; 

    if (detection.is_someone)
    {
        ptr += "<p>THERE IS SOMEONE AT THE DOOR! </p>\n";
    }
    else if (detection.is_no_one)
    {
        ptr += "<p>THE COAST IS CLEAR!</p>\n";
    }
    else
    {
        ptr += "<p>REFRESH SITE!</p>\n";
    }

    ptr += "</body>\n";
    ptr += "</html>\n";
    return ptr;

}
