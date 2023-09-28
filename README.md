# RF Communication using Arduino and MX-05V/MX-04V

## Arduino Setup:

### Arduino A (Transmitter):

- Connects to the MX-05V RF transmitter.
- Button connected to detect the press.

### Arduino B (Receiver):

- Connects to the MX-04V RF receiver.
- Relay controlled by the Arduino.

## Connections:

### MX-05V (Transmitter):

- VCC to 5V on Arduino A.
- GND to GND on Arduino A.
- Data to any digital pin on Arduino A (let's say D3).

### MX-04V (Receiver):

- VCC to 5V on Arduino B.
- GND to GND on Arduino B.
- Data to any digital pin on Arduino B (let's say D2).

### Button on Arduino A:

- One terminal to GND.
- Other terminal to D4 on Arduino A.

### Relay on Arduino B:

- Signal pin to D5 on Arduino B.
- Make sure the relay is rated to handle the load and voltage of whatever you're switching.
