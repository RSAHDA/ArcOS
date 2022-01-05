//
// Made by Rishit & Ragav on 02-01-2022.
//

#ifndef Memory_Bus_h
#define Memory_Bus_h

#include "Arduino.h"
#include "Wire.h"

class Slave {
private:
    const int address = 1;
public:
    void run(int on_request_function, int on_receive_function) {
        Wire.begin(address);
        Wire.onRequest(on_receive_function);
        Wire.onReceive(on_receive_function);
    }
};

#endif