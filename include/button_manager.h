#ifndef BUTTON_MANAGER_H
#define BUTTON_MANAGER_H

#include <Arduino.h>

class ButtonManager {
    public:
        ButtonManager(uint8_t *pins);
        void begin();
        bool isPressed(uint8_t buttonIndex);
        int pressedButtonsBitmask();

    private:
        uint8_t *buttonPins;
        size_t numButtons;
};

#endif
