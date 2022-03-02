#include "modules/file_system.h"
#include "modules/user-credentials.h"

const int RESET_PIN = 11;

bool areEqual(char *string1, char *string2) {
  if (sizeof(string1) == sizeof(string2)) {
    for (int i = 0; i < sizeof(string1)/sizeof(char); ++i) {
      if (string1[i] != string2[i]) {
        return false;
      }
      return true;
    }
  } else {
    return false;
  }
}

void userInit() {
  Serial.println("[*] ENTER IN THE PIN TO ACCESS THIS DEVICE...");
  while (true) {
    Serial.println("[*] PIN> ");
    while (Serial.available() == 0) {}
    String INPUT_PIN = Serial.readString();

    char input[sizeof(credentials::PIN)];
    INPUT_PIN.toCharArray(input, sizeof(credentials::PIN));

    if (strcmp(input, credentials::PIN) == 0) {
      Serial.println("[*] AUTHENTICATING USER...");
      break;
    } else {
      Serial.println("[*] TRY AGAIN...");
    }
  }

}

void setup() {
  // --------- booting up: -----------
  Serial.begin(9600);
  digitalWrite(RESET_PIN, HIGH);
  pinMode(RESET_PIN, OUTPUT);
  Serial.println("");
  
  Serial.println("[*] BOOTING OS...");
  delay(1000); // simulate
  Serial.println("[*] CHECKING BLUETOOTH MEMORY...");
  delay(1000); // simulate
  Serial.println("[*] COULD NOT FIND MEMORY, INITIALIZING EEPROM FOR EMERGENCY USAGE...");
  delay(500); // simulate
  Serial.println("[*] RETRIEVING FILES FROM MEMORY...");
  EEPROMFileSystem::getFiles();
  delay(500); // simulate
  Serial.println("[*] INITIALIZING USER...");
  userInit(); 
  delay(500); // simulate
}

void loop() {
  Serial.println(" ");
  Serial.print("L:/home> ");

  while (Serial.available() == 0) {}
  String command = Serial.readString();

  char buff[90];
  command.toCharArray(buff, 90);

  Serial.print(buff);
  if (areEqual(buff, "restart")) {
    Serial.println("[*] RESTARTING...");
    delay(1000);
    digitalWrite(RESET_PIN, LOW);
  } else if (areEqual(buff, "exit")) {
    Serial.println("[*] SHUTTING DOWN...");
    while (true) {}
  }
}