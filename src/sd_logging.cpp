#include "sd_logging.h"
#include <SD.h>
#include <SPI.h>

SDLogging::SDLogging(uint8_t chipSelect) : chipSelect(chipSelect), initialized(false), fileOpen(false) {}

SDLogging::~SDLogging() {
    closeFile();
}

bool SDLogging::isInitialized() const {
    return initialized;
}

void SDLogging::begin() {
    if (!initialized) {
        initialized = SD.begin(chipSelect);
    }
}

void SDLogging::log(const char* message) {
    if (!initialized || !fileOpen) {
        return;
    }
    currentFile.println(message);
    currentFile.flush();
}

bool SDLogging::openFile(const char* filename) {
    if (!initialized) {
        return false;
    }

    currentFile = SD.open(filename, FILE_WRITE);

    if (currentFile) {
        fileOpen = true;
        return true;
    } else {
        fileOpen = false;
        return false;
    }
}

void SDLogging::closeFile() {
    if (fileOpen) {
        currentFile.close();
        fileOpen = false;
    }
}
