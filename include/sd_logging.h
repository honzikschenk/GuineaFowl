#ifndef SD_LOGGING_H
#define SD_LOGGING_H

#include <SD.h>
#include <SPI.h>

class SDLogging {
    public:
        SDLogging(uint8_t chipSelect = BUILTIN_SDCARD);
        ~SDLogging();

        bool isInitialized() const;
        void begin();

        void log(const char* message);

        bool openFile(const char* filename);
        void closeFile();

    private:
        uint8_t chipSelect;
        File currentFile;
        bool initialized;
        bool fileOpen;
};

#endif
