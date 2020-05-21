# Haiway

Haiway Edge computing OS with microservice and RestFUL API 

## What is Haiway

Haiway is a real-time priority-based microkernel RTOS with microservice and RestFUL API that provides the trusted reliability and performance for embedded system while also allowing multiple operating systems to safely co-exist on the same System on Chip (SoC). 

Haiway defines a device hypervisor reference stack and an architecture for running multiple software subsystems, managed securely, on a consolidated system by means of a virtual machine manager. Haiway can be used as a Type 1 reference hypervisor stack, running directly on the bare-metal hardware, and is suitable for a variety of IoT and embedded device solutions. Haiway addresses the gap that currently exists between datacenter hypervisors, and hard partitioning hypervisors. The hypervisor architecture partitions the system into different functional domains, with carefully selected guest OS sharing optimizations for IoT and embedded devices.

Haiway is also designed as a real-time priority-based microkernel RTOS, currently support ARMv8-A MCU.

#### Supported hardware

- [x] Marvell espressobin

- [x] Raspberry 3B

- [x] Raspberry 4

- [x] Khadas VIM3

- [x] STM32

- [x] ESP32

  Haiway can be easily ported to other armv8-a based platform.

#### Supported OSes

- [x] Linux 
- [x] Ubuntu
- [x] Android
- [x] zephyr
- [x] XNU (ios kernel)

## On Linux
### For ESP32
setup: source scripts/setup.sh ESP32 LINUX
build: source scripts/esp32/esp32_build.sh
flash: source scripts/esp32/esp32_flash.sh
monitor: source scripts/esp32/esp32_monitor.sh

## On MacOS
### For ESP32
setup: source scripts/setup.sh ESP32 MAC
build: source scripts/esp32/esp32_build.sh
flash: source scripts/esp32/esp32_flash.sh
monitor: source scripts/esp32/esp32_monitor.sh

## Documentation

1. [Microservice List](http://39.105.15.119:8072/dist/microservice.html)
2. [Low-Code Development Platform Fucnction List](http://39.105.15.119:8072/dist/block.html)
