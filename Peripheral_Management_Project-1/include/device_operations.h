#ifndef DEVICE_OPERATIONS_H
#define DEVICE_OPERATIONS_H

void mount_device(const char *device, const char *mount_point);
void unmount_device(const char *mount_point);
void eject_device(const char *device);
void configure_bluetooth(const char *device_address);

#endif // DEVICE_OPERATIONS_H
