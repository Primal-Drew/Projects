#ifndef HTTP_HANDLER_H
#define HTTP_HANDLER_H
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

typedef struct
{
    bool is_foward;
    bool is_backward;
    bool is_stopped;
}direction_state;

extern direction_state states;
extern ESP8266WebServer server;
extern IPAddress local_ip;
extern IPAddress gateway;
extern IPAddress subnet;


/**
 * Handles setting up the server.
*/
void handle_setup();


/**
 * Handles all URLs.
*/
void handle_URLs();

#endif

