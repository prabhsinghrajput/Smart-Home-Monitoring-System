🏠 Smart Home Environment Monitoring System
🌐 Overview

The Smart Home Environment Monitoring System is an IoT-based project designed to monitor real-time environmental parameters such as temperature, humidity, and flame detection using a NodeMCU (ESP8266) microcontroller.
It connects to the Blynk IoT Cloud, allowing users to visualize data and control connected devices remotely through a mobile or web dashboard.

⚙️ Key Features

🌡️ Real-time temperature and humidity monitoring using DHT11 sensor

🔥 Flame detection and alert notification via Blynk Cloud

💡 Remote LED control using Blynk app (manual or automatic)

☁️ Wireless data transmission using Wi-Fi (ESP8266)

📱 User-friendly mobile/web dashboard for visualization and control

🧠 Components Used
Component	Description
NodeMCU (ESP8266)	Main microcontroller with built-in Wi-Fi
DHT11 Sensor	Measures temperature and humidity
IR Flame Sensor	Detects fire or infrared radiation
LED (5mm) + 220Ω Resistor	Visual indicator and alert
Breadboard MB-102	For circuit connections
5V Adapter (1A/2A)	Power supply for the NodeMCU and sensors
💻 Software & Tools

Arduino IDE – for programming NodeMCU

Blynk Cloud Console / Mobile App – for IoT dashboard

C / C++ – programming language

GitHub – version control and project hosting

🔌 Circuit Connections
Component	NodeMCU Pin
DHT11 Sensor	D2
Flame Sensor	D5
LED	D1
Relay (optional)	D6
Power (5V, GND)	VIN, GND
📶 How It Works

The NodeMCU connects to the Wi-Fi network and then to Blynk Cloud using authentication credentials.

The DHT11 sensor measures temperature and humidity, while the flame sensor detects any fire or IR radiation.

All readings are sent to the Blynk dashboard via virtual pins (V0, V1, V2).

Users can monitor the environment in real-time and toggle the LED (V4) using the Blynk switch widget.

If a flame is detected, the LED automatically turns ON and an alert is displayed on the dashboard.

📊 Blynk Dashboard Setup
Datastream	Type	Function
V0	Numeric	Temperature (°C)
V1	Numeric	Humidity (%)
V2	LED Widget	Flame Detection Indicator
V4	Switch	LED / Relay Control
📸 Block Diagram

System Flow:
DHT11 & Flame Sensor → NodeMCU (ESP8266) → Wi-Fi → Blynk Cloud → Dashboard & User Control

🔔 Future Enhancements

Add Firebase / ThingSpeak for data logging.

Include buzzer alerts for flame detection.

Use DHT22 or BME280 for higher accuracy.

Implement email / SMS alerts via Blynk Automations.

🧾 Project Details

Project Title: IoT-Based Smart Environment Monitoring System

Developed By: Prabhjot Singh 

Team Members: — Simran,Shalika

Department: Electronics and Communication Engineering

Institution: —

Year: 2025

🧠 Learning Outcomes

Understanding IoT concepts and cloud connectivity.

Practical experience in NodeMCU and sensor interfacing.

Working knowledge of Blynk Cloud and real-time data visualization.

Application of embedded C programming for automation.

📎 Repository Structure
Smart-Home-Monitoring-System/
│
├── sketch_nov5a.ino              # Arduino Code
├── project_report_iot_prabh.pdf  # Final Project Report
└── README.md                     # Project Documentation (this file)

📧 Contact

If you have any questions or suggestions, feel free to reach out:
📩 Email: [your-email@example.com
]
💻 GitHub: https://github.com/prabhsinghrajput
