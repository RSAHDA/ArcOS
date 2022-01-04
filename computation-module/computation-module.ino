#include "libraries/memory-bus/memory-bus.h"

Master file_loader(8);

void setup() {
  // -------------------------------------------------------------
  // load files from flash and store in SRAM
  // -------------------------------------------------------------

  // run Master instance:
  file_loader.run();

  // send initial request:
  file_loader.send_to_slave(0);

  // request slave:
  String dirrectory-array = file_loader.request_slave();
}

void loop() {
  // put your main code here, to run repeatedly:
}
