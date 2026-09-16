#define CUSTOM_SETTINGS
// This allows me to choose only the Dabble modules that I need in this program instead of including all the available Dabble modules

#define INCLUDE_TERMINAL_MODULE
// I include the Terminal module because I will use it to send and receive text messages between the Dabble app and the ESP32

#include <DabbleESP32.h>
// This includes the DabbleESP32 library which allows the ESP32 to communicate with the Dabble mobile app and use features such as the Terminal module
//or it loads the Dabble library so the ESP32 can communicate with the Dabble app and use commands like Dabble.begin(), Dabble.processInput(), and Terminal.readString().

// ESP32-WROOM-32 + DABBLE BLUETOOTH TERMINAL TEST

// Check Bluetooth support and error handling of the bluetooth configuration
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled!
#endif

// Stores whether Dabble communication has already been detected
bool dabbleConnected = false;

// SETUP

void setup() {

  // Start Serial Monitor
  Serial.begin(115200);

  delay(1000);

  // Start Dabble
  // Sets the Bluetooth name of the ESP32
  Dabble.begin("ESP32_Dabble-Yestin");

  // Startup information
  Serial.println();
  Serial.println("========================================");
  Serial.println(" ESP32-WROOM-32 DABBLE TEST BY YESTIN");
  Serial.println("========================================");
  Serial.println();
  Serial.println("Bluetooth Name : ESP32_Dabble-Yestin");
  Serial.println();
  Serial.println("Waiting for Bluetooth connection...");
  Serial.println("========================================");
  Serial.println();
}

// MAIN LOOP

void loop() {

  // Processing incoming Dabble data
  // Process Dabble communication and ESP32 will continuously receive Bluetooth data from Dabble
  Dabble.processInput();

  // Check whether the phone sent something
  if (Terminal.available()) {

    // Read message from Dabble Terminal
    String message = Terminal.readString();

    // trim() removes extra spaces and newline characters from the beginning/end
    message.trim();

    // Check if the received message contains actual data
    if (message.length() > 0) {

      // Check if Dabble communication is detected for the first time
      if (!dabbleConnected) {

        dabbleConnected = true;

        Serial.println();
        Serial.println("========================================");
        Serial.println("          DABBLE CONNECTED!");
        Serial.println("========================================");
      }

      // Display the phone message on your PC
      // Print received message
      Serial.println();
      Serial.println("----------------------------------------");
      Serial.println("MESSAGE RECEIVED");
      Serial.println("----------------------------------------");
      Serial.print("Phone: ");
      Serial.println(message);
      Serial.println("----------------------------------------");

      // Send response to Dabble
      Terminal.println("ESP32: Message received!");
      Terminal.print("You sent: ");
      Terminal.println(message);
    }
  }

  delay(100);
}