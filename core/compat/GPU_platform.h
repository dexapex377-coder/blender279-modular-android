#ifndef __GPU_PLATFORM_H__
#define __GPU_PLATFORM_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    GPU_PLATFORM_UNKNOWN = 0,
    GPU_PLATFORM_WINDOWS = 1,
    GPU_PLATFORM_MAC = 2,
    GPU_PLATFORM_LINUX = 3,
    GPU_PLATFORM_IOS = 4,
    GPU_PLATFORM_ANDROID = 5,
} eGPUPlatform;

typedef enum {
    GPU_DEVICE_UNKNOWN = 0,
    GPU_DEVICE_NVIDIA = 1,
    GPU_DEVICE_ATI = 2,
    GPU_DEVICE_INTEL = 3,
    GPU_DEVICE_APPLE = 4,
    GPU_DEVICE_SOFTWARE = 5,
} eGPUDevice;

typedef enum {
    GPU_OS_UNKNOWN = 0,
    GPU_OS_WIN = 1,
    GPU_OS_MAC = 2,
    GPU_OS_UNIX = 3,
} eGPUOSType;

typedef enum {
    GPU_DRIVER_UNKNOWN = 0,
    GPU_DRIVER_OFFICIAL = 1,
    GPU_DRIVER_OPENSOURCE = 2,
    GPU_DRIVER_SOFTWARE = 3,
} eGPUDriverType;

typedef enum {
    GPU_BACKEND_UNKNOWN = 0,
    GPU_BACKEND_OPENGL = 1,
    GPU_BACKEND_VULKAN = 2,
    GPU_BACKEND_METAL = 3,
} eGPUBackendType;

eGPUPlatform GPU_platform(void);
eGPUDevice GPU_device(void);
eGPUOSType GPU_os_type(void);
eGPUDriverType GPU_driver_type(void);
eGPUBackendType GPU_backend_type(void);
int GPU_platform_support(void);

#ifdef __cplusplus
}
#endif

#endif
