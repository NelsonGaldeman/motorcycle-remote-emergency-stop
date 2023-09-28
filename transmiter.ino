#include <VirtualWire.h>

const int buttonPin = 4;
const int transmitPin = 3;

void setup() {
    pinMode(buttonPin, INPUT_PULLUP);
    vw_set_tx_pin(transmitPin);
    vw_setup(2000);  // Set the speed to 2k bits per second
}

void loop() {
    int buttonState = digitalRead(buttonPin);
    
    if (buttonState == LOW) { // Button is pressed (because of INPUT_PULLUP)
        sendMessage();
        delay(200);  // Debounce delay
    }
}

void sendMessage() {
    const char *message = "TURN_ON_RELAY";
    vw_send((uint8_t *)message, strlen(message));
    vw_wait_tx();  // Wait for the message to be sent
}
