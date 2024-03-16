#ifndef HTTP_HANDLER_H
#define HTTP_HANDLER_H
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

typedef struct
{
    bool is_foward;
    bool is_backward;
}direction_state;

extern direction_state states;
extern ESP8266WebServer server;

/**
 * HTML that sets up the web page;
 * @param states - A pointer to a direction_state. 
 */
String SendHTML();

/**
 * Handles all URLs.
*/
void handle_URLs();

#endif

