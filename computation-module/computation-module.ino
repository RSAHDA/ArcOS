# include "modules/load_file.h"

FileSystem::textFile file("rishit", "Rishit is a great boy", "L:/");

void setup() {
  Serial.begin(9600); 
}

void loop() {
  Serial.println(file.returnFile());  
}