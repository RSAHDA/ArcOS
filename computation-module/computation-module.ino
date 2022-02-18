#include "modules/file_system.h"
#include "modules/auth_system.h"

void userInit() {
  if (Authenticator::isNewUser()) {
  Serial.println("[*] NEW USER DETECTED");

  Serial.print("[*] USERNAME> ");
  while (Serial.available() == 0) {}
  String USERNAME = Serial.readString();

  Serial.print("[*] PASSWORD> ");
  while (Serial.available() == 0) {}
  String PASSWORD = Serial.readString();

  auto AUTH = new EEPROMFileSystem::ApplicationFile(USERNAME + " " + PASSWORD, "L:/");
  }  
}

void setup() {
  // --------- booting up: -----------
  Serial.begin(9600);
  userInit();
  
  Serial.println("[*] BOOTING OS...");
  delay(1000);
  Serial.println("[*] RETRIEVING FILES FROM MEMORY...");
  delay(500);
  Serial.println("[*] CHECKING BLUETOOTH MEMORY...");
  delay(1000);
  Serial.println("[*] COULD NOT FIND MEMORY, INITIALIZING EEPROM FOR EMERGENCY USAGE...");
  EEPROMFileSystem::getFiles();
  delay(500);

}

void loop() {

}