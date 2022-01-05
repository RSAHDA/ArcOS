//
// Made by Rishit & Ragav on 02-01-2022.
//

#ifndef Memory_Bus_h
#define Memory_Bus_h

#include "Arduino.h"
#include "Wire.h"

class Master {
private:
    const int slave_address = 1;
    int answer_size;
public:
    Master(int data_size) {
        answer_size = data_size;
    }

    void run() {
        Wire.begin();
    }

    void send_to_slave(int code) {
        Wire.beginTransmission(slave_address);
        Wire.write(code);
        Wire.endTransmission();
    }

    String request_slave() {
        Wire.requestFrom(slave_address, answer_size);

        String response;
        while (Wire.available()) {
            char c = Wire.read();
            response += c;
        }

        return response;
    }
};

#endif