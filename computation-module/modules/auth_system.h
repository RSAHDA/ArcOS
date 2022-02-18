//
// Created by Yaten on 14-02-2022.
//

#ifndef ARCOS_AUTH_SYSTEM_H
#define ARCOS_AUTH_SYSTEM_H

#include "Arduino.h"
#include "file_system.h"

namespace Authenticator {
    bool isNewUser() {
        if (EEPROMFileSystem::MemoryPointer[0] == "") {
            return true;
        } else {
            return false;
        }
    }

    int authUser(char username[20], char password[20]) {
        char *AUTH_FILE = EEPROMFileSystem::MemoryPointer[0];
        EEPROMFileSystem::ApplicationFile AUTH( AUTH_FILE);

        String credentials[97] = AUTH.returnData();
    }

    int makeNewUser(char username[20], char password[20], EEPROMFileSystem::ApplicationFile file) {
        if (String(password).indexOf(" ") >= 0) {
            return 1;
        } else {
            auto auth = file.returnFile();
            char array[97];
            auth.toCharArray(array, 97);
            EEPROMFileSystem::MemoryPointer[0] = array;
            EEPROMFileSystem::syncFiles();
        }
    }
}

#endif //ARCOS_AUTH_SYSTEM_H
