#ifndef HTTP_HANDLER_H
#define HTTP_HANDLER_H

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

/**
 * @brief Struct to hold the presence detection results
 * 
 */
typedef struct
{
    bool is_someone;
    bool is_no_one;
} presence_state;

/**
 * @brief Extern variable to hold the presence detection results
 * 
 */
extern presence_state detection;

/**
 * @brief Extern variable to hold the web server object
 * 
 */
extern ESP8266WebServer server;

/**
 * @brief Function to handle the setup process of the web server
 * 
 * @param SSID The SSID of the Wi-Fi network
 * @param password The password of the Wi-Fi network
 */
void handle_setup(char* SSID, char* password);

/**
 * @brief Function to start the web server
 * 
 */
void start_server();

#endif