# ESPHome Projects

This repository contains a collection of projects leveraging the ESP32 microcontroller and ESPHome integration with Home Assistant. Each project is organized as a standalone module, making it easy to explore and adapt for your own smart home setups.

## Project Structure

Each project in this repository follows the same directory structure for consistency and ease of navigation:

Config: Contains YAML configuration files used for ESPHome integration with Home Assistant.

Firmware: Includes any additional firmware files required for the specific project.

PCB: Houses PCB design files for hardware components of the project.

3D: Contains CAD files for any 3D-printed elements required by the project.

## Current Projects

### MotionDetector

A motion detection system using ESP32 and ESPHome to seamlessly integrate with Home Assistant.

Features include:

* Real-time motion detection

* Customizable alerts through Home Assistant

## Getting Started

1. Clone this repo and navigate to the desired project folder

2. Flash the ESP32 with ESPHome as per ESPHome's documentation: https://esphome.io/guides/getting_started_hassio

* I've had the best experiance with plugging the ESP32 into the raspberry pi running HAOS

3. Install the ESPHome plug in

4. Configure the device with WiFi credentials and paste in yaml

5. Flash the device with the project yaml

6. Assemble and test

## Requirements

* ESPHome installed and configured

* ESP32 microcontroller

* Home Assistant OS instance

* Relevant hardware components (specific to each project)
