
# MP3 Player Project

This Arduino project implements an MP3 player using the DFRobot DFPlayer Mini module. It allows you to control audio playback through an encoder and can adjust the volume dynamically.

## Features

- Plays MP3 files from a micro SD card.
- Adjustable volume control via an encoder.
- Simple interface for playback control (play, pause, next, previous).

## Requirements

- Arduino board (e.g., Arduino Uno, Nano, etc.)
- DFRobot DFPlayer Mini MP3 module
- Micro SD card with MP3 files
- Rotary encoder
- Jumper wires
- Breadboard (optional for connections)

## Installation

1. **Install the Arduino IDE**: Download and install the [Arduino IDE](https://www.arduino.cc/en/software).

2. **Install the DFRobotDFPlayerMini Library**:
   - Open the Arduino IDE.
   - Go to **Sketch** > **Include Library** > **Manage Libraries**.
   - In the Library Manager, search for "DFRobotDFPlayerMini" and install it.

3. **Connect the Hardware**:
   - Connect the DFRobot DFPlayer Mini to the Arduino:
     - VCC to 5V
     - GND to Ground
     - TX to digital pin 4
     - RX to digital pin 5
   - Connect the rotary encoder:
     - Connect pin A to digital pin 3
     - Connect pin B to digital pin 2
     - Connect the other pins to GND and VCC

4. **Prepare the SD Card**:
   - Format the micro SD card to FAT32.
   - Create a folder named `mp3` and place your MP3 files inside.
   - Ensure the files are named with a numeric prefix (e.g., `001.mp3`, `002.mp3`, etc.) for proper playback.

## Usage

1. Open the `play_musicgame.ino` file in the Arduino IDE.
2. Upload the code to your Arduino board.
3. Use the rotary encoder to navigate through the audio files:
   - Rotate to the right to play the next file.
   - Rotate to the left to play the previous file.
   - Push the encoder to play or pause the current track.
4. Adjust the volume using the encoder as well.

## Code Overview

The code initializes the DFPlayer Mini module and sets up the rotary encoder for user input. It manages audio playback, including play, pause, next, and previous functions based on encoder input.

### Example Code Snippet

```cpp
#include <DFRobotDFPlayerMini.h>
#include "Arduino.h"
#include "DFRobotDFPlayerMini.h"
#include <SoftwareSerial.h>

SoftwareSerial softSerial(/*rx =*/4, /*tx =*/5);
#define FPSerial softSerial

int val;
int old;
int oldval;
int oldoldval;
int ran;
int numerofile;
int encoderPin1 = 3; // Pin for encoder
int encoderPin2 = 2; // Pin for encoder
int volume;
int vol = A1; // Pin for volume control
int livello;
volatile int lastEncoded = 0;
volatile long encoderValue = 0;

long lastencoderValue = 0;
int lastMSB = 0;
int lastLSB = 0;

DFRobotDFPlayerMini myDFPlayer;

void setup() {
    // Initialize serial and DFPlayer
}

void loop() {
    // Handle playback control based on encoder input
}
```

## Customization

You can modify the pins for the DFPlayer Mini and the rotary encoder by changing the pin definitions in the code. You can also adjust the volume limits to suit your preference.

## License

This project is licensed under CC-BY-SA license
Project made by Luca Passarini
