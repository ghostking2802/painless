#include <Arduino_JSON.h>
#include <SoftwareSerial.h>
SoftwareSerial espSerial(5, 6);
String str;

void setup() {
// Open serial communications and wait for port to open:
Serial.begin(115200);
espSerial.begin(115200);
delay(1000);

while (!Serial) {
; // wait for serial port to connect. Needed for native USB port only
}

}
void loop() { // run over and over
if (Serial.available()) {
String json=Serial.readStringUntil("}");
Serial.println("Coming from esp8266==>>"+json);
str =String("coming from arduino: Hi head node. Wassup??");
espSerial.println(str);
delay(1000);

}
}