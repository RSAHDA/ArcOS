//
// Made by Rishit & Ragav on 02-01-2022.
//

#include "Arduino.h"
#include "memory-bus.h"
#include "Wire.h"

// Master:

Master::Master(int data_size) {
    answer_size = data_size;
}

void Master::run() {
    Wire.begin();
}

void Master::send_to_slave(int code) {
    Wire.beginTransmission(slave_address);
    Wire.write(code);
    Wire.endTransmission();
}

String Master::request_slave() {
    Wire.requestFrom(slave_address, answer_size);

    String response;
    while (Wire.available()) {
        char c = Wire.read();
        response += c;
    }
}

// Slave:

void Slave::run(int on_request_function, int on_receive_function) {
    Wire.begin(address);
    Wire.onRequest(on_receive_function);
    Wire.onReceive(on_receive_function);
}
