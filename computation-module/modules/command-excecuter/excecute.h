//
// Created by Yaten on 04-01-2022.
//

#ifndef ARCOS_EXCECUTE_H
#define ARCOS_EXCECUTE_H

#include "Arduino.h"
#include "basic-functions.h"

namespace exec {
    // uses function overload: (int/float operations:)
    void find_and_execute(String command, float val1 = 0, float val2 = 0) {
        switch (command) {
            case (command.indexOf("ADD") >= 0):
                return basic::ADD(val1, val2);
            case (command.indexOf("SUB") >= 0):
                return basic::SUB(val1, val2);
            case (command.indexOf("DIV") >= 0):
                return basic::DIV(val1, val2);
            case (command.indexOf("MUL") >= 0):
                return basic::MUL(val1, val2);
            case (command.indexOf("POW") >= 0):
                return basic::POW(val1, val2);
            case (command.indextOf("NRT") >= 0):
                return basic::NRT(val1, val2);
        }
    }

    // string/char operations:
    void find_and_execute(String command, String val1 = "", String val2 = "") {
        switch (command) {
            case (command.indexOf("SAP") >= 0):
                return basic::SAP(val1, val2);
            case (command.indexOf("SIA") >= 0):
                return basic::SIA(&val1);
        }
    }

}

#endif //ARCOS_EXCECUTE_H
