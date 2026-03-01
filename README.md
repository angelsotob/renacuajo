# 🤖 Renacuajo - BQ Printbot Robot

Software project for the **Renacuajo Printbot (BQ)** robot developed using Arduino.

This repository contains the base code for motion control, line following, buzzer melodies, and Bluetooth communication.

---

## 📌 Features

- 🚗 Continuous rotation servo wheel control  
- 🎵 Melody playback (Harry Potter Theme & Happy Birthday)  
- 🛣️ Line following using IR sensors  
- 📡 Bluetooth communication (subroutine included)  
- 🔘 Physical button activation  

---

## 🧠 Technologies Used

- Arduino (C/C++)
- Libraries:
  - `Servo.h`
  - `SoftwareSerial.h`

---

## 🔌 Pin Configuration

| Component        | Pin |
|------------------|-----|
| Left Wheel       | 6   |
| Right Wheel      | 9   |
| Left IR Sensor   | 2   |
| Right IR Sensor  | 3   |
| Button           | 4   |
| Buzzer           | 13  |

---

## 🎵 Included Melodies

- Harry Potter Theme  
- Happy Birthday  

Notes and durations are defined as constants for easy modification.

---

## 🚀 How to Use

1. Open `renacuajo.ino` in the Arduino IDE.
2. Select the appropriate board.
3. Connect the robot via USB.
4. Upload the program.
5. Press the physical button to start the main routine.

---

## 📂 Project Structure

```
├── LICENSE
├── README.md
└──  renacuajo.ino
```

---

## 🛠️ Core Functionalities

### Movement
- Move forward  
- Move backward  
- Turn left / right  
- Stop  

### Line Following
IR sensors detect black/white surfaces and adjust movement accordingly.

### Buzzer
Plays melodies using `tone()` and `noTone()`.

### Bluetooth (Prepared)
Subroutine ready to receive external commands.

---

## 📜 License

MIT License  

Author: Ángel Soto Boullosa  
Initial Date: 01/11/2019  

---

## ✨ Possible Future Improvements

- Full Bluetooth control system  
- Replace `delay()` with `millis()` for non-blocking execution  
- Implement a state machine architecture  
- Add technical documentation and wiring diagrams  