# Arduino Language Reference - LickOmeter Project

### `#include <Arduino.h>`
**Purpose:** Includes the Arduino functions for controlling the device. Must be included at the beginning of the script to use related functions.

**Usage:**
```cpp
#include <Arduino.h>
```
---

### `void setup()`
**Purpose:** Runs once when the Arduino powers on or resets. Used to initialize pins, start serial communication, and configure the system.

**Usage:**
```cpp
void setup() {
    // Initialization code here
}
```
---

### `void loop()`
**Purpose:** Runs repeatedly after setup() completes, forming the main program loop. This is where your program's continuous logic lives.

**Usage:**
```cpp
void loop() {
    // Code runs repeatedly
}
```
---

### Constructor: `CapacitiveSensor(sendPin, receivePin)`
**Purpose:** Creates a CapacitiveSensor object that will measure capacitance between two pins.

**Usage:**
```cpp
CapacitiveSensor cs_7_8 = CapacitiveSensor(7, 8);
```

**Parameters:**
- `sendPin` (int): The pin that sends the signal (also called the "send" or "drive" pin)
- `receivePin` (int): The pin that receives the signal (also called the "sense" or "receive" pin)

**Return Value:** A new CapacitiveSensor object

**Hardware Requirements:** A 10MΩ resistor must be connected between sendPin and receivePin. An optional antenna can be connected to receivePin for increased sensitivity.

**Example Variables:**
- `CapacitiveSensor cs_7_8 = CapacitiveSensor(7, 8);` - Sensor on pins 7 and 8
- `CapacitiveSensor cs_4_2 = CapacitiveSensor(4, 2);` - Sensor on pins 4 and 2

---

### `capacitiveSensor(samples)`
**Purpose:** Reads and returns the capacitive sensor value. The sensor measures the time it takes for the capacitance to charge/discharge.

**Usage:**
```cpp
long sensorValue = cs_7_8.capacitiveSensor(80);
```

**Parameters:**
- `samples` (int): Number of samples to average. Higher values = more accurate but slower response
  - Typical range: 30-100
  - Lower samples (30): Faster response, more noise
  - Higher samples (100+): Slower response, more stable readings

**Return Value:** long integer representing capacitance in arbitrary units (typically 0-1000+ depending on sensor design)

**Important Notes:**
- This function should be called in the loop()
- Blocking function: pauses execution while reading
- Raw values without filtering can be noisy

**Example Variables:**
```cpp
long rawSensorValue = cs_7_8.capacitiveSensor(80);
long smoothSensorValue = cs_7_8.capacitiveSensor(30);  // Faster but noisier
```

---

## Serial Communication Functions

### `Serial.begin(baudRate)`
**Purpose:** Initializes serial communication between the Arduino and a computer at a specified data rate.

**Usage:**
```cpp
Serial.begin(9600);
```

**Parameters:**
- `baudRate` (long): The speed of serial communication in bits per second (baud)
  - Common values: 9600, 115200
  - 9600: Standard, reliable, slower
  - 115200: Faster, requires proper hardware support

**Return Value:** void (nothing)

**Location:** Call this in `setup()`, typically as the first command

**Note:** The Serial Monitor in Arduino IDE must be set to the same baud rate to display data correctly.

---

### `Serial.println(value)`
**Purpose:** Prints a value to the serial monitor and adds a newline character at the end.

**Usage:**
```cpp
Serial.println(42);           // Prints "42" with newline
Serial.println("Hello");      // Prints "Hello" with newline
Serial.println(2.5);          // Prints "2.50" with newline
```

**Parameters:**
- `value` (various types): The data to send
  - int: `Serial.println(100)`
  - float/double: `Serial.println(3.14)`
  - String: `Serial.println("Text")`
  - char: `Serial.println('A')`

**Return Value:** Number of bytes written (int)

**Related Functions:**
- `Serial.print(value)` - Same as println() but without newline
- `Serial.write(value)` - Sends raw byte value

**Example Variables:**
```cpp
long sensorValue = 250;
if (sensorValue > 10) {
    Serial.println(sensorValue);  // Outputs "250" to serial monitor
}
```
---

## Control Flow & Timing

### `delay(milliseconds)`
**Purpose:** Pauses program execution for a specified number of milliseconds.

**Usage:**
```cpp
delay(1000);  // Pause for 1 second
delay(10);    // Pause for 10 milliseconds
```

**Parameters:**
- `milliseconds` (unsigned long): How long to pause
  - 1000 milliseconds = 1 second
  - 1 millisecond = 0.001 seconds

**Return Value:** void (nothing)

**Side Effects:** All other operations pause entirely (blocking)

**Common Use Cases:**
- Reducing serial monitor output
- Creating temporal separation between sensor reads
- Debouncing switches
- Creating timing intervals

**Example Variables:**
```cpp
delay(10);      // 10 millisecond delay
delay(500);     // 500 millisecond (0.5 second) delay
delay(1000);    // 1 second delay
```

---

### `if (condition) { ... }`
**Purpose:** Executes code only if a condition is true.

**Usage:**
```cpp
if (cs > 10) {
    Serial.println(cs);
}
```

**Parameters/Conditions:**
- `>` : greater than
- `<` : less than
- `==` : equal to
- `!=` : not equal to
- `>=` : greater than or equal
- `<=` : less than or equal
- `&&` : AND operator (both conditions true)
- `||` : OR operator (either condition true)

**Example Variables:**
```cpp
if (sensorValue > 10) { ... }           // Executes if sensorValue exceeds 10
if (sensorValue < 0) { ... }            // Executes if sensorValue is negative
if (sensorValue == 0) { ... }           // Executes if sensorValue equals 0
if (sensorValue > 10 && value < 100) { ... }  // Both conditions must be true
```

---

## Data Types

### `long`
**Purpose:** Stores large integer values (used for sensor readings that can be large).

**Range:** -2,147,483,648 to 2,147,483,647

**Usage:**
```cpp
long sensorReading = 1500;
```

### `void`
**Purpose:** Indicates a function returns no value or has no parameters.

**Usage:**
```cpp
void setup() { }  // Returns nothing
```

### `int`
**Purpose:** Stores smaller integer values.

**Range:** -32,768 to 32,767

**Usage:**
```cpp
int sensorSamples = 80;
```
