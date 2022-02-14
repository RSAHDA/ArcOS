# include "modules/file_system.h"

FileSystem::textFile file("rishit", "Rishit is a great boy", "L:/");

void setup() {
  // to always initialize for the first time:
  EEPROM.write(0, 0);
  // --------- rest of booting up: -----------
  Serial.begin(9600);
  FileSystem::getFiles();
  Serial.println("DONE!!!!");
}

void loop() {

}