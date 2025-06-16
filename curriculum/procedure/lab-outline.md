# Coding Workshop: LCD, Ultrasonic Sensor, and PWM LED Integration

This lab introduces students to a basic hardware-software system using an LCD display, an ultrasonic distance sensor, and an LED — all wired to a breadboard and programmed using Arduino. Students will build a system where components interact and generate real-time data for future analysis.

---

## Phase 1: LCD Screen Setup

**Objective:** Display text on a 16x2 LCD screen using appropriate libraries and wiring.

### Steps:
1. **Library Walkthrough & Setup**
   - Introduce the `LiquidCrystal_I2C` library.
   - Explain the role of I2C adapters and 4-pin communication.
   - Include instructions for installing the library via Arduino Library Manager.

2. **Wiring the LCD**
   - Connect the 4-pin LCD (VCC, GND, SDA, SCL) to the Arduino.
   - Note: I2C pins may vary by board (e.g., A4/A5 on Uno).

3. **Setting Global Variables & Initializing**
   - Define a global `LiquidCrystal_I2C` object.
   - In `setup()`, call:
     ```cpp
     lcd.begin(16, 2);
     lcd.backlight();
     lcd.print("System Ready");
     ```

---

## Phase 2: Ultrasonic Sensor and LED with PWM

**Objective:** Use an ultrasonic sensor to measure distance and dynamically control LED brightness using PWM.

### Steps:

1. **Wiring Components**
   - **Ultrasonic Sensor:** Connect VCC, GND, TRIG, and ECHO to digital pins.
   - **LED (with Resistor):** Connect the LED anode to a PWM-capable digital pin via a 220Ω resistor; cathode to GND.

2. **Ultrasonic Sensor Setup**
   - Define `TRIG` and `ECHO` pins.
   - Write a function that measures distance using `digitalWrite()` and `pulseIn()`:
     ```cpp
     long duration = pulseIn(echoPin, HIGH);
     float distance = duration * 0.034 / 2;
     ```

3. **Component Interactions**
   - **Sensor → LCD**
     - Display the current distance (e.g., in cm) on the LCD.
   - **Sensor → LED via PWM**
     - Map distance to LED brightness using `analogWrite()`:
       ```cpp
       int brightness = map(distance, 5, 50, 255, 0);
       brightness = constrain(brightness, 0, 255);
       analogWrite(ledPin, brightness);
       ```
     - Shorter distance → Brighter LED.

4. **Serial Monitoring**
   - Print time, distance, and brightness to the Serial Monitor for debugging:
     ```cpp
     Serial.print(millis());
     Serial.print(", ");
     Serial.print(distance);
     Serial.print(" cm, ");
     Serial.println(brightness);
     ```

---

## Phase 3: Exporting Data

**Objective:** Export real-time sensor data for use in future analysis.

### Steps:

1. **Format Serial Output**
   - Use comma-separated values:
     ```
     Time (ms), Distance (cm), Brightness
     ```

2. **Export as CSV**
   - Use Arduino Serial Monitor or a terminal like CoolTerm to capture output.
   - Copy the data and save it as a `.csv` file.

3. **Extension: Data Analysis Lab**
   - Preview how students will later analyze this dataset.
   - Suggest tasks like plotting distance over time or identifying noise.

---

## Learning Outcomes

By the end of this lab, students will be able to:
- Wire and initialize LCD, ultrasonic, and LED components.
- Display real-time data on an LCD screen.
- Use ultrasonic data to control LED brightness via PWM.
- Collect and export serial data as a `.csv`.
- Understand basic component interaction and data-driven hardware control.

---

**Next Steps:** In the following lab, students will load their exported `.csv` files into a data analysis environment (e.g., Excel or Colab) and perform basic visualization and statistics.

---

