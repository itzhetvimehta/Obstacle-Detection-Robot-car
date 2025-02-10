# Obstacle-Detection-Robot-car

## Overview
The Obstacle Detection Robot is an autonomous robotic system designed to navigate its environment while avoiding obstacles using an ultrasonic sensor (HC-SR04) and a servo motor. It uses an Arduino microcontroller to process distance data and control motor movements accordingly.

## Components Used
- **Arduino Board**
- **HC-SR04 Ultrasonic Sensor** (for obstacle detection)
- **Servo Motor** (to scan left and right for obstacle-free paths)
- **DC Motors** (for movement)
- **Motor Driver Module**
- **Power Bank** (to power the system)
- **Connecting Wires**

## Pin Configuration
| Component | Pin | Description |
|-----------|-----|-------------|
| Ultrasonic Sensor | 11 | Trigger Pin |
| Ultrasonic Sensor | 12 | Echo Pin |
| Left Motor | 4, 5 | Control Pins |
| Right Motor | 6, 7 | Control Pins |
| Servo Motor | 9 | Control Pin |

## Working Mechanism
1. The robot moves forward if no obstacle is detected within 15 cm.
2. If an obstacle is detected within 10 cm, the robot stops and scans left and right using the servo motor.
3. It calculates distances in both directions and chooses the path with more free space.
4. The robot moves in the chosen direction to avoid the obstacle.
5. If both sides have equal space, it defaults to turning right.
6. The process repeats as the robot continues navigating its environment.

## Code Explanation
- The `setup()` function initializes pins and the servo motor.
- The `loop()` function continuously checks for obstacles using the ultrasonic sensor.
- The `getDistance()` function calculates the distance from obstacles using the HC-SR04.
- The `stopMotors()` function stops the motors when necessary.

## Power Supply
The robot is powered using a **power bank**, ensuring a steady power supply for the Arduino and connected components.

## Usage Instructions
1. Connect all components as per the wiring diagram.
2. Upload the provided Arduino code to the board.
3. Place the robot on a flat surface and turn on the power bank.
4. Observe the robot as it navigates its surroundings, avoiding obstacles.

## Future Improvements
- Implement obstacle mapping for more efficient navigation.
- Add an additional sensor for better accuracy.
- Use an advanced motor driver for smoother control.

## License
This project is open-source, and modifications are encouraged to enhance functionality.

---
Developed for autonomous obstacle detection and avoidance.

