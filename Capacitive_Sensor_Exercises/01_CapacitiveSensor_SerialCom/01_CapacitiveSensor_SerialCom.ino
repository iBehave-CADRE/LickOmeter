// Capacitive Sensor Serial Communication Example
// This example demonstrates how to use the CapacitiveSensor library to read values from a capacitive sensor and print them to the serial monitor. The sensor is connected between pins 7 and 8.

//Loads the Capacitive Sensor Library.
#include <CapacitiveSensor.h>


// Creates an instance of the CapavitiveSensor Class and defines the send pin (7) and receive pin (8).
CapacitiveSensor cs_7_8 = CapacitiveSensor(7,8);

// NOTE: A 10MOhm Resistor is required between the send pin (7) and receive pin (8) for the sensor to work properly. You can also connect an antenna to pin 8 for better sensitivity. If the antenna is connected to pin 7, it will sense touch-release events instead of continuous touch.

// This will run once when the program starts.
void setup() {
    // Initiates serial communication at a baud rate of 9600 bits per second. This allows us to print the sensor values to the serial monitor for debugging and visualization. The serial monitor can be opened in the Arduino IDE by clicking on the magnifying glass icon in the top right corner or by pressing Ctrl + Shift + M (Cmd + Shift + M on Mac).
    Serial.begin(9600); // Begin serial communication
}

// This will run repeatedly after the setup function has completed.
void loop() {
    // Sensor resolution is set to 80; will store the capacitance as an arbitrary value in cs.
    long cs = cs_7_8.capacitiveSensor(80);
    
    //delay to reduce serial prints and temporal resolution
    delay(10); 

    // This will only print the sensor value to the serial monitor it is greater than 10 to reduce communication.
    if (cs > 10) {
      Serial.println(cs);
    }   
}