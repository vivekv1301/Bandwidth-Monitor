# 📊 Bandwidth Monitor Simulation (SFML)

This project is a **C++ visual simulation** that mimics bandwidth usage across multiple network connections using the **SFML (Simple and Fast Multimedia Library)**. While it doesn’t interact with real network traffic, it provides a dynamic graphical representation of how bandwidth might be distributed across connections—ideal for learning, demos, or teaching network concepts.

## 🚀 Features

- Simulates multiple network connections with random data transfer rates
- Displays animated bar graphs representing each connection’s bandwidth
- Real-time updates every second
- Uses Object-Oriented Programming (OOP) principles
- Built with C++ and SFML for efficient rendering and graphics

## 🧠 Concept Overview

This simulation demonstrates how bandwidth might look across different connections:

- **Connections** are simulated objects.
- Each has a randomly generated **transfer rate**.
- A **bar graph** visualizes these rates.
- The graph updates every second, mimicking real-time bandwidth monitoring.
- **SFML** handles the windowing, drawing, and font rendering.

This is ideal for educational purposes where actual network monitoring is either too complex or unnecessary.

## 🛠️ Dependencies

Make sure you have the following installed:

- **C++17 or later**
- **SFML 2.5+**

Install SFML on Ubuntu:
```bash
sudo apt install libsfml-dev
sudo apt update
```

📦 Build Instructions

1. Clone the repository:
```bash
git clone https://github.com/vivekv1301/bandwidth-monitor-sfml.git
cd bandwidth-monitor-sfml
```

2. Compile the code:
```bash
g++ -std=c++17 -o oop_monitor main.cpp -lsfml-graphics -lsfml-window -lsfml-system ./oop_monitor
```

4. Run the simulation:
```bash
./oop_monitor
```
🧩 Project Structure
```bash
.
├── main.cpp            # Source code for simulation
├── README.md           # Project documentation
```
🖼️ Screenshot
![image](https://github.com/user-attachments/assets/e64e9044-be12-4434-aa1b-c7da05f6764c)
![image](https://github.com/user-attachments/assets/8763e47d-fbf3-4e21-aa0e-9d4ff2adb8ef)
![image](https://github.com/user-attachments/assets/6cd8e747-3f6a-4a23-9fb7-e7f1e3d5d58e)

🔍 Example Output

Every second, the window updates with new bar heights:
```bash
Conn-1: 3795 B/s
Conn-2: 4210 B/s
Conn-3: 1350 B/s
Conn-4: 2789 B/s
Conn-5: 4932 B/s
```
📘 Learning Objectives

    Use SFML for 2D graphics in C++

    Apply OOP principles like encapsulation and separation of concerns

    Simulate real-world concepts like network behavior in an offline setting

👨‍💻 Developed by vivekv1301

    Built for educational purposes to simulate and visualize bandwidth usage using SFML and C++.
    
