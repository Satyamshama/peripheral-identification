#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/device_info.h"

void list_detailed_usb_devices() {
    FILE *fp = popen("lsusb", "r");
    if (fp == NULL) {
        perror("Failed to run lsusb command");
        return;
    }

    char line[256];
    printf("Connected USB Devices (Detailed Information):\n");
    while (fgets(line, sizeof(line), fp) != NULL) {
        if (strstr(line, "root hub") == NULL && strstr(line, "Quanta Computer") == NULL && strstr(line, "AX201") == NULL) {
            char *id_start = strstr(line, "ID ");
            if (id_start != NULL) {
                id_start += 3;
                char vendor_product_id[10];
                strncpy(vendor_product_id, id_start, 9);
                vendor_product_id[9] = '\0';

                char command[256];
                snprintf(command, sizeof(command), "lsusb -v -d %s", vendor_product_id);

                FILE *detail_fp = popen(command, "r");
                if (detail_fp == NULL) {
                    perror("Failed to run lsusb -v command");
                    continue;
                }

                char detail_line[1024];
                while (fgets(detail_line, sizeof(detail_line), detail_fp) != NULL) {
                    printf("%s", detail_line);
                }
                fclose(detail_fp);

                printf("\n------------------------------------------------------------\n");
            }
        }
    }

    fclose(fp);
}

void list_bluetooth_devices_info() {
    FILE *fp = popen("bluetoothctl devices", "r");
    if (fp == NULL) {
        perror("Failed to run bluetoothctl command");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), fp) != NULL) {
        char device_address[256];
        if (sscanf(line, "Device %s", device_address) == 1) {
            printf("\nFetching details for Bluetooth device: %s\n", device_address);

            char command[512];
            snprintf(command, sizeof(command), "bluetoothctl info %s", device_address);
            FILE *info_fp = popen(command, "r");
            if (info_fp == NULL) {
                perror("Failed to get detailed Bluetooth device info");
                continue;
            }

            while (fgets(line, sizeof(line), info_fp) != NULL) {
                printf("%s", line);
            }
            fclose(info_fp);
        }
    }

    fclose(fp);
}

void list_wifi_devices_info() {
    FILE *fp = popen("iwconfig", "r");
    if (fp == NULL) {
        perror("Failed to run iwconfig command");
        return;
    }

    char line[256];
    printf("\nConnected Wi-Fi Devices:\n");
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
    }

    fclose(fp);
}
