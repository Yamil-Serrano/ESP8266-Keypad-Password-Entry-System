#include <Keypad.h>

// Definition of rows and columns based on connections
const byte ROWS = 4; // Four rows
const byte COLS = 4; // Four columns

// Key mapping
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

String password = "B1AC0D5";
String input = "";

// Pins connected to the rows of the keypad
byte rowPins[ROWS] = {5, 4, 14, 12}; // GPIO5, GPIO4, GPIO14, GPIO12

// Pins connected to the columns of the keypad
byte colPins[COLS] = {13, 0, 16, 2}; // GPIO13, GPIO0, GPIO16, GPIO2

// Pin for the buzzer
const int buzzerPin = 15; // Connect the buzzer to GPIO15

// Melodies
int melodyCorrect[] = {262, 294, 330}; // Notes for the correct melody (C, D, E)
int melodyIncorrect[] = {330, 294, 262}; // Notes for the incorrect melody (E, D, C)
int noteDuration = 200; // Duration of each note

// Create an instance of the keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(115200);
  delay(1000); // Wait one second for the Serial Monitor to start
  Serial.println("-------------\nInsert The password: ");
  pinMode(buzzerPin, OUTPUT); // Set the buzzer pin as output
}

void loop() {
  char key = keypad.getKey();
  if (key) {
    if (key == '*') {
      // Check the password
      Serial.println();
      if (password == input) {
        Serial.println("-------------\nCorrect password!");
        playMelody(melodyCorrect, sizeof(melodyCorrect) / sizeof(melodyCorrect[0])); // Play correct melody
      } else {
        Serial.println("-------------\nIncorrect password!");
        playMelody(melodyIncorrect, sizeof(melodyIncorrect) / sizeof(melodyIncorrect[0])); // Play incorrect melody
      }
      delay(3000);
      input = ""; // Clear the input after checking
      Serial.print("-------------\nEnter the password: "); // Message to restart
    } else {
      input += key; // Add key to the input
      Serial.print(key); // Display the current input
    }
  }
}

// Function to play the melody
void playMelody(int* melody, int length) {
  for (int i = 0; i < length; i++) {
    tone(buzzerPin, melody[i], noteDuration); // Emit tone
    delay(noteDuration); // Wait for the note to finish
  }
  noTone(buzzerPin); // Stop the tone
}
