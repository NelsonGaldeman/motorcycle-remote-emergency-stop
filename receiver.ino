#include <VirtualWire.h>

const int receivePin = 2;
const int relayPin = 5;
const long relayDuration = 5000;  // 5 seconds

void setup() {
    pinMode(relayPin, OUTPUT);
    digitalWrite(relayPin, LOW);  // Turn off the relay by default
    vw_set_rx_pin(receivePin);
    vw_setup(2000);  // Set the speed to 2k bits per second
    vw_rx_start();  // Start listening for messages
}

void loop() {
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;

    if (vw_get_message(buf, &buflen)) {
        String message = String((char *)buf);
        if (message.startsWith("TURN_ON_RELAY")) {
            digitalWrite(relayPin, HIGH);
            delay(relayDuration);
            digitalWrite(relayPin, LOW);
        }
    }
}
