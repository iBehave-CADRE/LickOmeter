# Language Reference: 05_CapacitiveSensor_ThreshTTL_attachInterrupt_ServoControl

This document explains all functions used in the `05_CapacitiveSensor_ThreshTTL_attachInterrupt_ServoControl.ino` sketch.

## Arduino Core Functions

### setup()
**Description:** Runs once when the Arduino board is powered on or reset.
**Usage:** Initialize hardware, configure pins, and set up communication.
```cpp
void setup() {
    Serial.begin(9600);
    pinMode(12, OUTPUT);
    myservo.attach(9);
}
```
**Parameters:** None
**Returns:** void

---

### loop()
**Description:** Runs repeatedly after setup() completes, as long as the board has power.
**Usage:** Main program logic that executes continuously.
```cpp
void loop() {
    noInterrupts();
    CapacitiveSensorRead();
    ServoMotorInOut();
    interrupts();
}
```
**Parameters:** None
**Returns:** void

---

### Serial.begin(speed)
**Description:** Initializes serial communication with the specified baud rate.
**Usage:** Enable communication between the Arduino and computer via USB.
```cpp
Serial.begin(9600);  // 9600 baud rate
```
**Parameters:**
- `speed` (long): Communication speed in bits per second (e.g., 9600, 115200)

**Returns:** void

---

### Serial.print(value)
**Description:** Prints data to the serial monitor without a newline character.
**Usage:** Output sensor values or debug messages.
```cpp
Serial.print("Trigger: ");
```
**Parameters:**
- `value`: Data to print (string, number, etc.)

**Returns:** void

---

### Serial.println(value)
**Description:** Prints data to the serial monitor and adds a newline character at the end.
**Usage:** Output sensor readings with line breaks for clarity.
```cpp
Serial.println(cs);  // Prints capacitive sensor value with newline
```
**Parameters:**
- `value`: Data to print (string, number, etc.)

**Returns:** void

---

### pinMode(pin, mode)
**Description:** Configures a digital pin as either INPUT, OUTPUT, or INPUT_PULLUP.
**Usage:** Set the direction and behavior of GPIO pins.
```cpp
pinMode(12, OUTPUT);           // Configure pin 12 as output for LED
pinMode(3, INPUT_PULLUP);      // Configure pin 3 as input with pull-up resistor
```
**Parameters:**
- `pin` (int): GPIO pin number
- `mode` (PinMode): INPUT, INPUT_PULLUP, or OUTPUT

**Returns:** void

---

### digitalWrite(pin, value)
**Description:** Writes a digital value (HIGH or LOW) to a specified pin.
**Usage:** Control devices like LEDs, relays, or control signals.
```cpp
digitalWrite(12, HIGH);  // Turn LED on
digitalWrite(12, LOW);   // Turn LED off
```
**Parameters:**
- `pin` (int): GPIO pin number
- `value` (PinState): HIGH (5V) or LOW (0V)

**Returns:** void

---

### digitalRead(pin)
**Description:** Reads the digital value (HIGH or LOW) from a specified pin.
**Usage:** Detect the state of buttons, sensors, or other digital inputs.
```cpp
InputState = digitalRead(3);  // Read the state of pin 3
```
**Parameters:**
- `pin` (int): GPIO pin number

**Returns:** int (HIGH or LOW)

---

### delay(ms)
**Description:** Pauses program execution for a specified number of milliseconds.
**Usage:** Create timing delays between operations.
```cpp
delay(15);   // Wait 15 milliseconds
delay(50);   // Wait 50 milliseconds
```
**Parameters:**
- `ms` (unsigned long): Number of milliseconds to pause

**Returns:** void

---

### attachInterrupt(digitalPinToInterrupt(pin), function, mode)
**Description:** Attaches an interrupt handler function to a digital pin.
**Usage:** Trigger code execution when a pin state changes, without waiting in the main loop.
```cpp
attachInterrupt(digitalPinToInterrupt(3), DetectInputChange, CHANGE);
```
**Parameters:**
- `digitalPinToInterrupt(pin)` (int): Converts pin number to interrupt number
- `function` (ISR): Function to call when interrupt occurs
- `mode` (InterruptMode): CHANGE, RISING, FALLING, LOW, HIGH, or NONE

**Returns:** void

---

### digitalPinToInterrupt(pin)
**Description:** Converts a digital pin number to its corresponding interrupt number.
**Usage:** Required to use attachInterrupt() with pin numbers instead of interrupt numbers.
```cpp
attachInterrupt(digitalPinToInterrupt(3), DetectInputChange, CHANGE);
```
**Parameters:**
- `pin` (int): GPIO pin number

**Returns:** int (Interrupt number)

---

### noInterrupts()
**Description:** Disables all interrupts.
**Usage:** Protect critical code sections from being interrupted.
```cpp
noInterrupts();
// Critical code here
interrupts();
```
**Parameters:** None
**Returns:** void

---

### interrupts()
**Description:** Re-enables interrupts after being disabled by noInterrupts().
**Usage:** Resume normal interrupt processing after critical code.
```cpp
noInterrupts();
// Critical code
interrupts();  // Re-enable interrupts
```
**Parameters:** None
**Returns:** void

---

## Servo Library Functions

### Servo.attach(pin)
**Description:** Attaches the servo object to a GPIO pin and enables PWM control.
**Usage:** Initialize servo control on the specified pin.
```cpp
myservo.attach(9);  // Attach servo to pin 9
```
**Parameters:**
- `pin` (int): GPIO pin number (must support PWM)

**Returns:** int (Pin number)

---

### Servo.write(angle)
**Description:** Writes a position (angle) value to the servo motor.
**Usage:** Move the servo to a specific angle (typically 0-180 degrees).
```cpp
myservo.write(120);  // Move servo to 120 degrees
```
**Parameters:**
- `angle` (int): Servo position in degrees (usually 0-180)

**Returns:** void

---

### Servo.read()
**Description:** Reads the current position (angle) of the servo.
**Usage:** Get the servo's current position for reference or feedback.
```cpp
CurrentServoMotorPosition = myservo.read();
```
**Parameters:** None
**Returns:** int (Current servo position in degrees)

---

## CapacitiveSensor Library Functions

### CapacitiveSensor(sendPin, receivePin)
**Description:** Constructor that creates a capacitive sensor object between two pins.
**Usage:** Initialize a capacitive touch sensor using a 10M ohm resistor between pins.
```cpp
CapacitiveSensor cs_7_8 = CapacitiveSensor(7, 8);
```
**Parameters:**
- `sendPin` (int): Pin that sends the sensor signal
- `receivePin` (int): Pin that receives the return signal

**Returns:** CapacitiveSensor object

---

### CapacitiveSensor.capacitiveSensor(sampleWindow)
**Description:** Reads the capacitive sensor value with specified resolution.
**Usage:** Get raw capacitive sensor readings for touch detection.
```cpp
long cs = cs_7_8.capacitiveSensor(80);  // 80 is the resolution (higher = more stable)
```
**Parameters:**
- `sampleWindow` (uint8_t): Number of sensor readings to average (10-255)

**Returns:** long (Raw capacitive value, higher = closer touch)

---

### CapacitiveSensor.reset_CS_AutoCal()
**Description:** Resets the capacitive sensor and disables auto-calibration temporarily.
**Usage:** Stop sensor readings after detecting a touch and recalibrate baseline.
```cpp
cs_7_8.reset_CS_AutoCal();
```
**Parameters:** None
**Returns:** void

---

## Custom Functions (User-Defined)

### CapacitiveSensorRead()
**Description:** Reads the capacitive sensor, accumulates values, and detects touch events.
**Usage:** Called in the main loop to monitor the capacitive sensor and trigger actions on threshold.
```cpp
void CapacitiveSensorRead() {
    long cs = cs_7_8.capacitiveSensor(80);
    if (cs > 100) {
        csSum += cs;
        if (csSum >= 3800) {
            BlinkLEDandTTLout();
            csSum = 0;
            cs_7_8.reset_CS_AutoCal();
        }
    } else {
        csSum = 0;
    }
}
```
**Parameters:** None
**Returns:** void
**Logic:**
- Reads capacitive sensor value
- If value exceeds 100, accumulates it in `csSum`
- When `csSum` reaches 3800, triggers touch detection
- Resets accumulators and recalibrates sensor

---

### BlinkLEDandTTLout()
**Description:** Sends a brief TTL pulse by blinking the LED and output pin.
**Usage:** Signal a touch detection event to external hardware.
```cpp
void BlinkLEDandTTLout() {
    digitalWrite(12, HIGH);
    delay(1);
    digitalWrite(12, LOW);
}
```
**Parameters:** None
**Returns:** void
**Output:** 1 millisecond HIGH pulse on pin 12

---

### DetectInputChange()
**Description:** Interrupt service routine (ISR) called when pin 3 state changes.
**Usage:** Quickly detect input state changes without blocking the main loop.
```cpp
void DetectInputChange() {
    InputChange = true;
    Serial.println("Change Detected");
}
```
**Parameters:** None
**Returns:** void
**Note:** This is an ISR and should be kept as short as possible. Uses `volatile` variable for safe communication with main loop.

---

### ServoMotorInOut()
**Description:** Moves the servo motor in or out based on input pin state.
**Usage:** Control servo position smoothly with 15ms delays between steps.
```cpp
void ServoMotorInOut() {
    if (InputChange == true) {
        InputState = digitalRead(3);
        if (InputState == HIGH) {
            for (i = CurrentServoMotorPosition; i <= ServoMotorInPosition; i += 1) {
                myservo.write(i); 
                delay(15);
            }
        } else {
            for (i = CurrentServoMotorPosition; i >= ServoMotorOutPosition; i -= 1) {
                myservo.write(i); 
                delay(15);
            }
        }
        CurrentServoMotorPosition = myservo.read();
        InputChange = false;
    }
}
```
**Parameters:** None
**Returns:** void
**Logic:**
- Moves servo smoothly from current position to target position
- HIGH input → move to `ServoMotorInPosition` (120°)
- LOW input → move to `ServoMotorOutPosition` (0°)
- 15ms delay ensures smooth servo movement

---

## Control Flow Summary

1. **Initialization (setup):**
   - Serial communication starts at 9600 baud
   - Pin 12 configured as LED output
   - Pin 3 configured as interrupt input with pull-up
   - Servo attached to pin 9
   - Servo moved to out position

2. **Main Loop (loop):**
   - Protects critical code with interrupt disable/enable
   - Reads capacitive sensor continuously
   - Manages servo position based on input changes

3. **Capacitive Sensing:**
   - Accumulates sensor readings until threshold (3800)
   - Triggers LED pulse when touch detected
   - Resets and recalibrates sensor

4. **Interrupt Handling:**
   - Pin 3 changes trigger `DetectInputChange()`
   - Sets flag to move servo in/out on next loop iteration

---

## Boolean Operators

Boolean operators are used to combine or modify logical conditions. They return either `true` or `false`.

### Logical AND (&&)
**Description:** Returns `true` only if both conditions are `true`.
**Usage:** Combine multiple conditions that all must be true.
```cpp
if (InputChange == true && InputState == HIGH) {
    // Code runs only if both InputChange is true AND InputState is HIGH
}
```
**Truth Table:**
- true && true = true
- true && false = false
- false && true = false
- false && false = false

---

### Logical OR (||)
**Description:** Returns `true` if at least one condition is `true`.
**Usage:** Execute code when any of multiple conditions is true.
```cpp
if (cs < 50 || csSum == 0) {
    // Code runs if cs is less than 50 OR csSum equals 0
}
```
**Truth Table:**
- true || true = true
- true || false = true
- false || true = true
- false || false = false

---

### Logical NOT (!)
**Description:** Inverts/negates a boolean value.
**Usage:** Check if something is NOT true or NOT false.
```cpp
if (!InputChange) {
    // Code runs if InputChange is false
}
// Same as: if (InputChange == false)
```
**Results:**
- !true = false
- !false = true

---

## Comparison Operators

Comparison operators compare two values and return a boolean result.

### Equal To (==)
**Description:** Returns `true` if both values are equal.
```cpp
if (InputState == HIGH) {
    // Execute if InputState equals HIGH
}
if (csSum >= 3800) {
    // Execute if csSum equals or exceeds 3800
}
```

---

### Not Equal To (!=)
**Description:** Returns `true` if values are not equal.
```cpp
if (CurrentServoMotorPosition != ServoMotorInPosition) {
    // Execute if positions are different
}
```

---

### Less Than (<)
**Description:** Returns `true` if left value is less than right value.
```cpp
for (i = CurrentServoMotorPosition; i <= ServoMotorInPosition; i += 1) {
    // Loop while i is less than or equal to ServoMotorInPosition
}
```

---

### Greater Than (>)
**Description:** Returns `true` if left value is greater than right value.
```cpp
if (cs > 100) {
    // Execute if cs is greater than 100
}
```

---

### Less Than or Equal To (<=)
**Description:** Returns `true` if left value is less than or equal to right value.
```cpp
for (i = CurrentServoMotorPosition; i <= ServoMotorInPosition; i += 1) {
    // Loop while i is less than or equal to target
}
```

---

### Greater Than or Equal To (>=)
**Description:** Returns `true` if left value is greater than or equal to right value.
```cpp
if (csSum >= 3800) {
    // Execute when accumulated sensor value reaches or exceeds threshold
}
```

---

## Boolean Examples in This Code

### Example 1: Simple Boolean Check
```cpp
if (InputChange == true) {
    // This checks if InputChange is true
    // The "== true" is explicit but optional
}
```

### Example 2: Combined Conditions with AND
```cpp
if (InputChange == true && InputState == HIGH) {
    // Both conditions must be true to execute
}
```

### Example 3: Threshold Detection with Multiple Operators
```cpp
if (cs > 100) {  // Greater than comparison
    csSum += cs;
    if (csSum >= 3800) {  // Greater than or equal comparison
        // Touch detected!
    }
} else {  // Opposite condition (implicitly: cs <= 100)
    csSum = 0;  // Reset
}
```

### Example 4: NOT Operator
```cpp
if (!InputChange) {
    // Execute if InputChange is false (NOT true)
}
```

---

## Data Types Used

- `int`: Integer (2 bytes, -32,768 to 32,767)
- `long`: Long integer (4 bytes, -2,147,483,648 to 2,147,483,647)
- `unsigned long`: Unsigned long (4 bytes, 0 to 4,294,967,295)
- `bool`: Boolean (true/false)
- `volatile bool`: Boolean that can change outside normal program flow (used with interrupts)
