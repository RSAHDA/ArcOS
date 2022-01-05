#include "modules/memory-bus/memory-bus.h"
#include "modules/command-excecuter/excecute.h"

Master file_loader(8);

void setup() {
  // -------------------------------------------------------------
  // load user files from flash and store in SRAM
  // -------------------------------------------------------------

  file_loader.run();
  file_loader.send_to_slave(0);
  String user_directory_array = file_loader.request_slave();

  // -------------------------------------------------------------
  // run preprogramed startup software:
  // -------------------------------------------------------------

  // get first command:
  int line = 0;
  String line_data;

  while (line_data != "STARTUP_SCRIPT_HALT()") {
    ++line;
    file_loader.send_to_slave(line);
    line_data = file_loader.request_slave();

    exec::find_and_execute(line_data);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}
