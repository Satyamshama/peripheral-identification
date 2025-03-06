#include <stdio.h>
#include "../include/device_detection.h"
#include "../include/device_info.h"
#include "../include/device_operations.h"

int main() {
    int choice;
    char device[100];
    char mount_point[100];

    while (1) {
        // Main Menu
        printf("\nSelect an operation:\n");
        printf("1. List Connected Devices\n");
        printf("2. List Detailed Device Information\n");
        printf("3. Perform Device Operations\n");
        printf("4. Exit\n");  // Add an option to exit the program
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                list_usb_devices();
                list_bluetooth_devices();
                list_wifi_devices();
                break;
            case 2:
                list_detailed_usb_devices();
                list_bluetooth_devices_info();
                list_wifi_devices_info();
                break;
            case 3:
                // Device Operations Menu
                printf("\n1. Mount Device\n");
                printf("2. Unmount Device\n");
                printf("3. Eject Device\n");
                printf("4. Configure Bluetooth Device\n");
                printf("Enter your choice (1-4): ");
                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        printf("Enter device path (e.g., /dev/sdb1): ");
                        scanf("%s", device);
                        printf("Enter mount point (e.g., /mnt/usb): ");
                        scanf("%s", mount_point);
                        mount_device(device, mount_point);
                        break;
                    case 2:
                        printf("Enter mount point to unmount (e.g., /mnt/usb): ");
                        scanf("%s", mount_point);
                        unmount_device(mount_point);
                        break;
                    case 3:
                        printf("Enter device path to eject (e.g., /dev/sdb): ");
                        scanf("%s", device);
                        eject_device(device);
                        break;
                    case 4:
                        printf("Enter Bluetooth device address (e.g., XX:XX:XX:XX:XX:XX): ");
                        scanf("%s", device);
                        configure_bluetooth(device);
                        break;
                    default:
                        printf("Invalid choice.\n");
                        break;
                }
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                return 0;  // Exit the program
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}
