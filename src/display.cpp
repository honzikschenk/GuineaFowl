#include "display.h"

Display::Display() : oled(128, 64, &Wire) {}

void Display::begin() {
    oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    oled.clearDisplay();
    oled.display();
}

void Display::clear() {
    oled.clearDisplay();
    oled.display();
}

void Display::display(
    const DisplayMode mode,
    const int active_button_bitmask,
    const int connected_devices_bitmask,
    const int transfer_in_speed,
    const int transfer_out_speed,
    const long int uptime_seconds,
    const char* error = nullptr
) {
    oled.clearDisplay();
    oled.setTextSize(1);
    oled.setTextColor(SSD1306_WHITE);
    oled.setCursor(0, 0);

    if (error) {
        oled.println("ERROR:");
        oled.println(error);
        oled.display();
        return;
    }

    switch (mode) {
        case DETECT:
            oled.println("Obstacle avoidance mode");
            break;
        case PASSTHROUGH:
            oled.println("Passthrough mode");
            break;
        case CONNECTING:
            oled.println("Connecting...");
            break;
        case CONFIG:
            oled.println("Configuring...");
            break;
    }

    oled.print("Buttons: ");
    for (int i = 0; i < 8; i++) {
        if (active_button_bitmask & (1 << i)) {
            oled.print(i);
            oled.print(" ");
        }
    }
    oled.println();

    oled.print("Devices: ");
    for (int i = 0; i < 8; i++) {
        if (connected_devices_bitmask & (1 << i)) {
            oled.print(i);
            oled.print(" ");
        }
    }
    oled.println();

    oled.print("In: ");
    if (transfer_in_speed >= 1000) {
        oled.print(transfer_in_speed / 1000.0, 1);
        oled.print(" kB/s");
    } else {
        oled.print(transfer_in_speed);
        oled.print(" B/s");
    }
    oled.println();

    oled.print("Out: ");
    if (transfer_out_speed >= 1000) {
        oled.print(transfer_out_speed / 1000.0, 1);
        oled.print(" kB/s");
    } else {
        oled.print(transfer_out_speed);
        oled.print(" B/s");
    }
    oled.println();

    long hours = uptime_seconds / 3600;
    long minutes = (uptime_seconds % 3600) / 60;
    long seconds = uptime_seconds % 60;
    oled.printf("Uptime: %02ld:%02ld:%02ld\n", hours, minutes, seconds);

    oled.display();
}
