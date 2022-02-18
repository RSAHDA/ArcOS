//
// Created by Rishit on 13-02-2022.
//

#ifndef ARCOS_LOAD_FILE_H
#define ARCOS_LOAD_FILE_H

#include "string.h"
#include "Arduino.h"
#include "EEPROM.h"

// PLEASE NOTE THAT EEPROM MEMORY IS ONLY TO BE USED DURING EMERGENCIES

// There will be 2 primary files in the beginning:
// -- .txt
// -- .ac (arduino c)

// System usage ONLY file conventions:
// -- .app (execute\able file for any application)
// -- .loc (locates or references a file)

// FILE FORMAT: .(file type)*(file name)+(file location)|(file data)
// not a lot in metadata since processor doesn't have good memory.


// ------------ EEPROM file system -----------
namespace EEPROMFileSystem {
    const unsigned int ITEM_SPACE = 100;
    const char key[] = "0123456789 abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*(),./';[]=-_+{}|:'><`~";
    const int TERMINATOR = 255;
    char *MemoryPointer[10];

    /*
    File System Usage by Operating System

    the OS will first retrieve all files.

    forever:
        then it will add a file(s) to MemoryPointer.
        then it will sync file system.
    */

    void getFiles() {
        // read all files and put them in MemoryPointer
        for (int i = 0; i < EEPROM.length(); ++i) {
            char file[101];
            int val = int(EEPROM.read(i));

            if (val != TERMINATOR) {
                file[strlen(file)] = key[val];
            } else {
                MemoryPointer[0] = {file};
            }
        }
    }

    void syncFiles() {
        int counter = 0;
        for (int i = 0; i < sizeof(MemoryPointer); ++i) {
            for (int j = 0; j < strlen(MemoryPointer[i]); ++j) {
                EEPROM.update(counter, String(key).indexOf(MemoryPointer[i][j]));
                ++counter;
            }
            ++counter;
            EEPROM.update(counter, TERMINATOR);
        }
    }

    // USER FILES

    class textFile {
    private:
        char filename[30];
        char data[30];
        char folder[30];
    public:
        textFile(char name[30] = "", char d[30] = "", char loc[30] = "", char file[97] = "") {
            if (file[0] == '.') {
                strncpy(filename, name, 30);
                strncpy(data, d, 30);
                strncpy(folder, loc, 30);
            } else {
                char text[strlen(file)], text2[strlen(file)];
                bool pass1, pass2, pass3 = false;

                for (int i = 0; i < strlen(file); ++i) {
                    if (file[i] == '*' or pass1) {
                        memset(text, 0, sizeof(text));
                        pass1 = true;
                        if (file[i] == '+' or pass2) {
                            strncpy(filename, text, sizeof(text));
                            memset(text, 0, sizeof(text));
                            pass2 = true;
                            if (file[i] == '|' or pass3) {
                                strncpy(folder, text, sizeof(text));
                                memset(text, 0, sizeof(text));
                                pass3 = true;
                                text2[i] = file[i];
                            } else {
                                text[i] = file[i];
                            }
                        } else {
                            text[i] = file[i];
                        }
                    } else {
                        text[i] = file[i];
                    }
                }
                strncpy(data, text2, sizeof(text2));
            }

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

    class arduinoCFile {
    private:
        char filename[15];
        char data[45];
        char folder[30];
    public:
        arduinoCFile(char name[15] = "", char d[45] = "", char loc[30] = "", char file[97] = "") {
            if (file[0] != '.') {
                strncpy(filename, name, 30);
                strncpy(data, d, 30);
                strncpy(folder, loc, 30);
            } else {
                char text[strlen(file)], text2[strlen(file)];
                bool pass1, pass2, pass3 = false;

                for (int i = 0; i < strlen(file); ++i) {
                    if (file[i] == '*' or pass1) {
                        memset(text, 0, sizeof(text));
                        pass1 = true;
                        if (file[i] == '+' or pass2) {
                            strncpy(filename, text, sizeof(text));
                            memset(text, 0, sizeof(text));
                            pass2 = true;
                            if (file[i] == '|' or pass3) {
                                strncpy(folder, text, sizeof(text));
                                memset(text, 0, sizeof(text));
                                pass3 = true;
                                text2[i] = file[i];
                            } else {
                                text[i] = file[i];
                            }
                        } else {
                            text[i] = file[i];
                        }
                    } else {
                        text[i] = file[i];
                    }
                }
                strncpy(data, text2, sizeof(text2));
            }
        };


        String returnFile() {
            return ".ac*" + String(this->filename) + "+" + String(this->folder) + "|" + String(this->data);
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
            return ".ac";
        };
    };

    // SYSTEM FILES:

    class ApplicationFile {
    private:
        char data[60];
        char folder[30];
    public:
        ApplicationFile(char d[60] = "", char loc[30] = "", char file[97] = "") {
            if (file[0] == '.') {
                strncpy(data, d, 60);
                strncpy(folder, loc, 30);
            } else {
                char text[strlen(file)], text2[strlen(file)];
                bool pass1, pass2, pass3 = false;

                for (int i = 0; i < strlen(file); ++i) {
                    if (file[i] == '*' or pass1) {
                        memset(text, 0, sizeof(text));
                        pass1 = true;
                        if (file[i] == '+' or pass2) {
                            pass2 = true;
                            if (file[i] == '|' or pass3) {
                                strncpy(folder, text, sizeof(text));
                                memset(text, 0, sizeof(text));
                                pass3 = true;
                                text2[i] = file[i];
                            } else {
                                text[i] = file[i];
                            }
                        }
                    } else {
                        text[i] = file[i];
                    }
                }
                strncpy(data, text2, sizeof(text2));
            }
        };

        String returnFile() {
            return ".app*+" + String(this->folder) + "|" + String(this->data);
        };

        char *returnData() {
            return this->data;
        };

        char *returnLocation() {
            return this->folder;
        };

        char *returnFileType() {
            return ".app";
        };
    };

    class LocationFile {
    private:
        char location[40];
        char folder[30];
    public:
        LocationFile(char loc[40] = "", char fold[30] = "", char file[97] = "") {
            if (file[0] == '.') {
                strncpy(location, loc, 60);
                strncpy(folder, fold, 30);
            } else {
                char text[strlen(file)], text2[strlen(file)];
                bool pass1, pass2, pass3 = false;

                for (int i = 0; i < strlen(file); ++i) {
                    if (file[i] == '*' or pass1) {
                        strncpy(folder, text, 30);
                        memset(text, 0, sizeof(text));
                        pass1 = true;
                        if (file[i] == '+' or pass2) {
                            pass2 = true;
                            if (file[i] == '|' or pass3) {
                                strncpy(location, text, 30);
                                memset(text, 0, sizeof(text));
                                pass3 = true;
                                text2[i] = file[i];
                            } else {
                                text[i] = file[i];
                            }
                        }
                    } else {
                        text[i] = file[i];
                    }
                }
                strncpy(loc, text2, sizeof(text2));
            }
        };

        String returnFile() {
            return ".loc*+" + String(this->folder) + "|" + String(this->location);
        };

        char *returnReference() {
            return this->location;
        };

        char *returnLocation() {
            return this->folder;
        };

        char *returnFileType() {
            return ".loc";
        };
    };

}

// ------------ Bluetooth file system ------------ // todo
namespace BluetoothFileSystem {
    const int MAX_SIZE_OF_DATA = 2000;
    const char key[] = "0123456789 abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*(),./';[]=-_+{}|:'><`~";
    const int TERMINATOR = 255;

    // USER FILES:

    class textFileBluetooth {
    private:
        char filename[30];
        char data[MAX_SIZE_OF_DATA];
        char folder[MAX_SIZE_OF_DATA];
    public:
        textFileBluetooth(char name[30], char d[MAX_SIZE_OF_DATA], char loc[MAX_SIZE_OF_DATA]) {
            strncpy(filename, name, 30);
            strncpy(data, d, MAX_SIZE_OF_DATA);
            strncpy(folder, loc, MAX_SIZE_OF_DATA);
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

    class arduinoCFileBluetooth {
    private:
        char filename[30];
        char data[MAX_SIZE_OF_DATA];
        char folder[MAX_SIZE_OF_DATA];
    public:
        arduinoCFileBluetooth(char name[30], char d[MAX_SIZE_OF_DATA], char loc[MAX_SIZE_OF_DATA]) {
            strncpy(filename, name, 30);
            strncpy(data, d, MAX_SIZE_OF_DATA);
            strncpy(folder, loc, MAX_SIZE_OF_DATA);
        };

        String returnFile() {
            return ".ac*" + String(this->filename) + "+" + String(this->folder) + "|" + String(this->data);
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
            return ".ac";
        };
    };

    // SYSTEM FILES:

    class ApplicationFileBluetooth {
    private:
        char data[MAX_SIZE_OF_DATA];
        char folder[MAX_SIZE_OF_DATA];
    public:
        ApplicationFileBluetooth(char d[MAX_SIZE_OF_DATA], char loc[MAX_SIZE_OF_DATA]) {
            strncpy(data, d, MAX_SIZE_OF_DATA);
            strncpy(folder, loc, MAX_SIZE_OF_DATA);
        };

        String returnFile() {
            return ".app*+" + String(this->folder) + "|" + String(this->data);
        };

        char *returnData() {
            return this->data;
        };

        char *returnLocation() {
            return this->folder;
        };

        char *returnFileType() {
            return ".app";
        };
    };

    class LocationFileBluetooth {
    private:
        char location[MAX_SIZE_OF_DATA];
        char folder[MAX_SIZE_OF_DATA];
    public:
        LocationFileBluetooth(char loc[MAX_SIZE_OF_DATA], char fold[MAX_SIZE_OF_DATA]) {
            strncpy(location, loc, MAX_SIZE_OF_DATA);
            strncpy(folder, fold, MAX_SIZE_OF_DATA);
        };

        String returnFile() {
            return ".loc*+" + String(this->folder) + "|" + String(this->location);
        };

        char *returnReference() {
            return this->location;
        };

        char *returnLocation() {
            return this->folder;
        };

        char *returnFileType() {
            return ".loc";
        };
    };
}

#endif //ARCOS_LOAD_FILE_H