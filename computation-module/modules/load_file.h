//
// Created by Yaten on 13-02-2022.
//

#ifndef ARCOS_LOAD_FILE_H
#define ARCOS_LOAD_FILE_H

#include "string.h"
#include "Arduino.h"

// There will be 2 primary files in the beginning:
// -- .txt
// -- .ac (arduino c)

// System usage ONLY file conventions:
// -- .app (execute\able file for any application)
// -- .loc (locates or references a file)

// META DATA FORMAT: .(file type) * (file name) + (file location) | (file data)
// not a lot in metadata since processor doesn't have good memory.


// ------------ User File -----------
namespace FileSystem {
    const unsigned int ITEM_SPACE = 276;
    char16_t SystemSpace[ITEM_SPACE];
    const int MAX_MEMORY_AVAILABLE = 0; // .app max length * ITEM_SPACE

    class textFile {
    private:
        char filename[90];
        char data[90];
        char folder[90];
    public:
        textFile(char name[90], char d[90], char loc[90]) {
            strncpy(filename, name, 90);
            strncpy(data, d, 90);
            strncpy(folder, loc, 90);
        };

        String returnFile() {
            return ".txt * " + String(this->filename) + " + " + String(this->folder) + " | " + String(this->data);
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
