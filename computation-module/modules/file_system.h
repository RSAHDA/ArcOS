//
// Created by Rishit on 13-02-2022.
//

#ifndef ARCOS_LOAD_FILE_H
#define ARCOS_LOAD_FILE_H

#include "string.h"
#include "Arduino.h"
#include <EEPROM.h>

// There will be 2 primary files in the beginning:
// -- .txt
// -- .ac (arduino c)

// System usage ONLY file conventions:
// -- .app (execute\able file for any application)
// -- .loc (locates or references a file)

// META DATA FORMAT: .(file type)*(file name)+(file location)|(file data)
// not a lot in metadata since processor doesn't have good memory.


// ------------ User File -----------
namespace FileSystem {
    const unsigned int ITEM_SPACE = 100;
    char *memoryPointer[ITEM_SPACE];

    char *getFiles() {
        for (int i = 0; i < 1024; ++i) {
            // todo
        }
    }

    class textFile {
    private:
        char filename[30];
        char data[30];
        char folder[30];
    public:
        textFile(char name[30], char d[30], char loc[30]) {
            strncpy(filename, name, 30);
            strncpy(data, d, 30);
            strncpy(folder, loc, 30);
        };

        String returnFile() {
            return ".txt*" + String(this->filename) + "+" + String(this->folder) + "|" + String(this->data);
        };

        char *returnData() {
            return this->data;
        };

        char *returnLocation() {
            return this->folder;
        };

        char *returnFilename() {
            return this->filename;
        };

        char *returnFileType() {
            return ".txt";
        };
    };


}

#endif //ARCOS_LOAD_FILE_H
