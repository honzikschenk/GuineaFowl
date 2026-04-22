#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

enum DisplayMode {
    DETECT,
    PASSTHROUGH,
    CONNECTING,
    CONFIG,
};

class Display {
    public:
        Display() : oled(128, 64, &Wire) {};
        
        void begin();
        void clear();
        void display(
            const DisplayMode mode,
            const int active_button_bitmask,
            const int connected_devices_bitmask,
            const int transfer_in_speed,
            const int transfer_out_speed,
            const long int uptime_seconds,

            const char* error = nullptr
        );

    private:
        Adafruit_SSD1306 oled;
};


# endif
