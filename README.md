# IOT Based Water Level Monitoring and Alert System

## Description
The IOT Based Water Level Monitoring and Alert System is an advanced solution designed to address the urgent problems of water scarcity and waste. It utilizes modern sensors and microprocessors to accurately monitor water levels in storage tanks and provides real-time alerts to users. It is an innovative system that will inform users about the level of liquid and prevent it from overflowing; it also indicates water volume, and percentage. To demonstrate this, the system makes use of containers, where ultrasonic sensors are placed over the containers to detect the liquid level and compare it with the container’s depth. The system makes use of an ESP32 microcontroller (it uses to control the system and sending data over the wireless network), an LCD screen, an Ultrasonic Sensor, and two led (for detect the water Empty and full level). The LCD screen is used to display the status of the level of liquid in the containers. The liquid level is shown in the format as numeric, gauge, chart and table to analysis the data for further use. In this system,we are using two LEDs that indicate the status of water full and empty signal and also show the status on the webpage which we can access in real time.

## Table of Contents
1. [Introduction](#introduction)
2. [Problem Statement](#problem-statement)
3. [Benefits of the Project](#benefits-of-the-project)
4. [System Requirements](#system-requirements)
5. [Working of the Project](#working-of-the-project)
6. [Visualization and Monitoring](#visualization-and-monitoring)
7. [Output](#output)
8. [Steps to Configure the Project](#steps-to-configure-the-project)
9. [Conclusion](#conclusion)

## Introduction
The urgent global issues of water scarcity and waste demand innovative solutions. The urgent problems of water scarcity and waste in today's global environment call for creative solutions. Water conservation is more important than ever because the world's population is growing every minute. Conventional water management systems frequently rely significantly on human resources to provide round-the-clock control, which can be time-consuming and prone to error. Here’s our solution: an advanced water level monitoring and alert system that's meant to make this operation as simple and efficient as possible for humans. The System aims to simplify water management by providing accurate monitoring and real-time alerts.

## Problem Statement
Wasting water is a growing concern, especially in countries like India. This project addresses the need for efficient water management through embedded systems.

## Benefits of the Project
- Efficient control of water pump functions
- Reduction in electricity consumption
- Uninterrupted water supply
- Prevention of tank overfilling
- Optimal water supply during peak hours

## System Requirements
### Components Required:
- Ultrasonic Sensor
- ESP32 Microcontroller
- LCD 16*2 Display
- ThingSpeak & Arduino IDE Software

## Working of the Project
One IoT-based solution for water level monitoring is the IOT Based Water Level Monitoring and Alert System. Its main goal is to notify consumers in a timely manner when liquid levels are about to cross critical thresholds, either from overflow or depletion. The system uses ultrasonic sensors that are positioned strategically above water tanks or containers to detect and compare liquid level and container depth with accuracy. The system utilizes ultrasonic sensors to measure water levels accurately. Data is collected and analyzed by the ESP32 microcontroller, which communicates with the ThingSpeak software for remote monitoring and alerts.

## Visualization and Monitoring
The system gives users several options for keeping an eye on the condition of their water tanks. Users can access real-time data and receive alerts via a mobile app, allowing them to quickly address any issues that arise. In addition, the system offers visual graphs and charts to track water levels and usage over time, making it easy for users to make informed decisions about their water consumption.

## Output
The system fetches real-time data and displays it numerically, graphically, and in tabular format. Users can monitor and manage their water supply effectively. Immediate visual information regarding water levels is available on an LCD panel. Users can easily see the current water levels without needing to access a separate device or interface. To further enhance user comprehension, the IOT Based Water Level Monitoring and Alert System utilizes a graphical representative webpage that fetches the data and shows it in the format of a numeric, gauge, chart, and table. This allows users to easily monitor and interpret the water levels in real-time.

## Steps to Configure the Project
1. **Hardware Setup:**
    - Connect the ultrasonic sensor to the ESP32 microcontroller according to the circuit diagram.
    - Connect the LCD display to the ESP32 microcontroller.
2. **Software Setup:**
    - Install the necessary libraries for the ESP32 microcontroller and the LCD display. All the necessary library are included in the "Water level Monitoring System --> Lib".
    - Configure the ESP32 microcontroller with the required settings.
3. **ThingSpeak Integration:**
    - Create a ThingSpeak account and set up a channel for data logging.
    - Copy the required details as API Key, and Channel ID for further use in the code.
4. **Upload Code:**
    - Paste your necessary details in your code like Wi-Fi credentials, API key, channel ID.
    - According to your tank height, length and breath, Do the same changes in your code as well.
    - Upload the project code(Water level Monitoring system --> src --> main.cpp ) to the ESP32 microcontroller using the Arduino IDE or any other compatible IDE.
5. **Test the System:**
    - Power on the system and ensure that the hardware components are functioning correctly.
    - Monitor the data output on the LCD display and verify that data is being logged on ThingSpeak, as well as the Webpage for better visualization.
    - For Webpage, you have to configure your webapge with your Thingspeak, add your API Key, and channel ID.

## Conclusion
The Water Level Monitoring and Alert System offers an innovative solution to water management challenges. It promotes efficient resource utilization and contributes to environmental sustainability. By leveraging technology, we can build a better future for generations to come.

