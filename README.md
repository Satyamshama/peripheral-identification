# Peripheral Identification and Operations Project

# Overview

This project is designed to detect and identify peripheral devices connected to a Linux system, including USB, Bluetooth, and Wi-Fi devices. It also provides operations such as mounting, unmounting, ejecting, and configuring Bluetooth devices.

# Features

Peripheral Detection

List all connected USB, Bluetooth, and Wi-Fi devices.

Device Information Retrieval

Get detailed information about detected peripherals.

# Device Operations

Mount, unmount, and eject devices.

Configure Bluetooth devices (pair, trust, and connect).

# Technologies Used

Programming Language: C

Linux Utilities: lsusb, bluetoothctl, iwconfig, mount, umount, eject

Build Tool: gcc

# Project Structure

├── include/ <br>
│   ├── device_detection.h      # Function declarations for device detection <br>
│   ├── device_info.h           # Function declarations for detailed info retrieval <br>
│   ├── device_operations.h     # Function declarations for device operations <br>
│ <br>
├── src/ <br>
│   ├── device_detection.c      # Implementation of peripheral detection <br>
│   ├── device_info.c           # Implementation of detailed info retrieval <br>
│   ├── device_operations.c     # Implementation of mounting/unmounting/ejecting <br>
│   ├── main.c                  # Entry point of the program <br>
│<br>
├── README.md                   # Project documentation <br>
├── Makefile                     # Compilation instructions <br>

# Installation & Usage

1. Clone the Repository

git clone https://github.com/YOUR_GITHUB_USERNAME/peripheral-identification.git
cd peripheral-identification

2. Compile the Program

gcc -o peripheral main.c src/*.c -I include

3. Run the Program

./peripheral

# Team Members

Satyam Sharma (B22CS047)

Jaiswal Aditya Ranjit (B22CS025)

Lakavat Umesh Chandra (B22CS029)

Neielotpal Rao (B20EE038)

# Future Enhancements

Implement a GUI for better user interaction.

Add support for detecting more peripheral types.

Improve error handling and logging.
