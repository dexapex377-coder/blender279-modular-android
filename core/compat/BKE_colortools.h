#ifndef __BKE_COLORTOOLS_H__
#define __BKE_COLORTOOLS_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ColorManagedViewSettings {
    int flag;
    int look;
    float exposure;
    float gamma;
    float rgb_curve;
    void *curve_mapping;
    int pad;
} ColorManagedViewSettings;

typedef struct ColorManagedDisplaySettings {
    int display_device;
} ColorManagedDisplaySettings;

typedef struct ColorManagedColorspaceSettings {
    char name[64];
} ColorManagedColorspaceSettings;

#ifdef __cplusplus
}
#endif

#endif
