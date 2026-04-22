#include "button_manager.h"
#include <Arduino.h>

ButtonManager::ButtonManager(uint8_t *pins) : buttonPins(pins) {
    numButtons = sizeof(pins) / sizeof(pins[0]);
}

void ButtonManager::begin() {
    for (size_t i = 0; i < numButtons; i++) {
        pinMode(buttonPins[i], INPUT_PULLUP);
    }
}

bool ButtonManager::isPressed(uint8_t buttonIndex) {
    if (buttonIndex >= numButtons) {
        return false;
    }
    return digitalRead(buttonPins[buttonIndex]) == LOW;
}

int ButtonManager::pressedButtonsBitmask() {
    int bitmask = 0;
    for (size_t i = 0; i < numButtons; i++) {
        if (isPressed(i)) {
            bitmask |= (1 << i);
        }
    }
    return bitmask;
}
