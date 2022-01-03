//
// Made by Rishit & Ragav on 02-01-2022.
//

#ifndef Memory_Bus_h
#define Memory_Bus_h

#include "Arduino.h"

class Master {
private:
    const int slave_address = 1;
    int answer_size;
public:
    Master(int data_size);

    void run();

    void send_to_slave(int code);

    String request_slave();
};

class Slave {
private:
    const int address = 1;
public:
    void run(arg on_request_function, arg on_receive_function);
};

#endif