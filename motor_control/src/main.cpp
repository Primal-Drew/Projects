#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "drivers/http_drivers/http_handler.h"
#include "drivers/motor_drivers/h_bridge.h"

h_bridge control_pins = {D5,D6,D7};
ESP8266WebServer server(80);
direction_state states = {false,false};

void setup()
{
    Serial.begin(115200);
    h_bridge_init(&control_pins);
    handle_setup();
    handle_URLs();
}

void loop()
{
    server.handleClient();

    if(states.is_foward)
    {
        h_bridge_set_direction(&control_pins,FORWARD);
        h_bridge_set_speed(&control_pins, 100);
        states.is_foward = false;
        Serial.println("Forward");
    }

    else if(states.is_backward)
    {
        h_bridge_set_direction(&control_pins,BACKWARD);
        h_bridge_set_speed(&control_pins, 100);
        states.is_backward = false;
        Serial.println("Backward");
    }

    else if(states.is_stopped)
    {
        h_bridge_set_speed(&control_pins,0);
        states.is_stopped = false;
        Serial.println("Stopped");
    }
    
}


