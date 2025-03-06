#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/device_operations.h"

void mount_device(const char *device, const char *mount_point) {
    char command[256];
    snprintf(command, sizeof(command), "sudo mount %s %s", device, mount_point);
    printf("Mounting device %s at %s...\n", device, mount_point);
    system(command);
    printf("Device mounted successfully");
}

void unmount_device(const char *mount_point) {
    char command[256];
    snprintf(command, sizeof(command), "sudo umount %s", mount_point);
    printf("Unmounting device from %s...\n", mount_point);
    system(command);
    printf("Device Unmounted successfully");
}

void eject_device(const char *device) {
    char command[256];
    snprintf(command, sizeof(command), "sudo eject %s", device);
    printf("Ejecting device %s...\n", device);
   
    system(command);
     printf("Device ejected successfully");
}

void configure_bluetooth(const char *device_address) {
    char command[256];

    // Step 1: Pair the device
    snprintf(command, sizeof(command), "bluetoothctl pair %s", device_address);
    printf("Pairing Bluetooth device %s...\n", device_address);
    system(command);
    printf("Device paired successfully");

    // Step 2: Trust the device (optional, for automatic reconnection)
    snprintf(command, sizeof(command), "bluetoothctl trust %s", device_address);
    printf("Trusting Bluetooth device %s...\n", device_address);
    system(command);
    printf("Device trusted successfully");

    // Step 3: Connect to the device
    snprintf(command, sizeof(command), "bluetoothctl connect %s", device_address);
    printf("Connecting to Bluetooth device %s...\n", device_address);
    system(command);
    printf("Device connected successfully");
}



// mount | grep '^/dev' it lists down all the devices who device path starts with /dev and lists all their mounting points
// if you want to customize your mounting point - first make directiory , you made /mnt/usb
// then you used it as mounting point
// again run same command to list mounting point , you can see your device mounted on that new path
// to eject the device you just need to enter the device path
//for configuring with the bluetooth devices one first needs to pair up with the device
// then run the following command on to bash
/// i) bluetoothctl, ii) scan on , take out mac address from here iii) exit
// once you have extracted the mac address give it as input to your code , it will automatically connect to that device
