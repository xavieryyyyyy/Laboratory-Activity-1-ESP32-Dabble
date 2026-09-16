# Laboratory Activity 1 - Controlling ESP32 with Mobile Phone Using Dabble App

## Overview

This laboratory activity demonstrates how an ESP32-WROOM-32 can communicate with a mobile phone using the Dabble application.

For this activity, I used the Terminal module of the Dabble app to send text messages from my phone to the ESP32. The ESP32 receives the message, displays it in the Arduino IDE Serial Monitor, and sends a response back to the phone.

## Objectives

- Connect the ESP32-WROOM-32 to a mobile phone using the Dabble app.
- Use Bluetooth communication between the ESP32 and the mobile phone.
- Send messages from the Dabble Terminal to the ESP32.
- Display the received messages in the Arduino IDE Serial Monitor.
- Send a response from the ESP32 back to the Dabble Terminal.

## Hardware Used

- ESP32-WROOM-32
- USB Cable
- Laptop / Computer
- Android Mobile Phone

## Software Used

- Arduino IDE
- Dabble App
- DabbleESP32 Library

## Dabble Library Installation

To install the Dabble library in Arduino IDE:

1. Open Arduino IDE.
2. Go to `Sketch > Include Library > Manage Libraries`.
3. Search for `Dabble`.
4. Install the Dabble library by STEMpedia.

## Project Configuration

Bluetooth device name:

```text
ESP32_Dabble-Yestin
