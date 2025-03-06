#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/device_detection.h"

void list_usb_devices() {
    FILE *fp = popen("lsusb", "r");
    if (fp == NULL) {
        perror("Failed to run lsusb command");
        return;
    }

    char line[256];
    printf("Connected USB Devices:\n");
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
    }

    fclose(fp);
}

void list_bluetooth_devices() {
    FILE *fp = popen("bluetoothctl devices", "r");
    if (fp == NULL) {
        perror("Failed to run bluetoothctl command");
        return;
    }

    char line[256];
    printf("\nConnected Bluetooth Devices:\n");
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
    }

    fclose(fp);
}

void list_wifi_devices() {
    FILE *fp = popen("iwconfig", "r");
    if (fp == NULL) {
        perror("Failed to run iwconfig command");
        return;
    }

    char line[256];
    printf("\nWi-Fi Device Information:\n");
    while (fgets(line, sizeof(line), fp) != NULL) {
        // Only print lines that contain Wi-Fi interface details
        if (strstr(line, "IEEE 802.11") != NULL) {
            printf("%s", line);
        }
    }

    fclose(fp);
}
