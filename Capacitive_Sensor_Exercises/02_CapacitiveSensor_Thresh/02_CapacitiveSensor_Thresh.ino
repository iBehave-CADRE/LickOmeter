// Capacitive Sensor wit Threshold Example
// This example demonstrates how to use the CapacitiveSensor library to read values from a capacitive sensor and print them to the serial monitor. The sensor is connected between pins 7 and 8.
// An LED will serve as indicator for when the threshold is reached.

//Loads the Capacitive Sensor Library.
#include <CapacitiveSensor.h>


// Creates an instance of the CapavitiveSensor Class and defines the send pin (7) and receive pin (8).
CapacitiveSensor cs_7_8 = CapacitiveSensor(7,8);

// NOTE: A 10MOhm Resistor is required between the send pin (7) and receive pin (8) for the sensor to work properly. You can also connect an antenna to pin 8 for better sensitivity. If the antenna is connected to pin 7, it will sense touch-release events instead of continuous touch.

long cs; // This variable will store the capacitive sensor value
unsigned long csSum; // This variable will store accumulated capacitive sensor values

void setup() {
    Serial.begin(9600); // Begin serial communication
    pinMode(12, OUTPUT); //LED (to signal touches) is on pin 12 
}

void loop() {
    CapacitiveSensorRead(); // This time we put everything in a function
}

void CapacitiveSensorRead() {
    cs = cs_7_8.capacitiveSensor(80); // Sensor resolution is set to 80; will store the capacitance as an arbitrary value
	if (cs > 100) { //Arbitrary number; lower threshold
		csSum += cs; // Same as csSum = csSum + cs ; cumulative value for reachiung threshold
		Serial.println(cs); 
		if (csSum >= 3800) //Testing if csSum reached threshold, a High value means it takes longer to trigger
		{
			Serial.print("Trigger: ");
			Serial.println(csSum);
			if (csSum > 0) { csSum = 0; } //Reset of csSum
			cs_7_8.reset_CS_AutoCal(); //Stops readings and recalibration of capacitive sensor
		}
	} else {
		csSum = 0; //Timeout caused by bad readings
	}
}