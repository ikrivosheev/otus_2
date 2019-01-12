#ifndef VERSION_H
#define VERSION_H

#include "config.h"

struct {
    int major;
    int minor;
    int patch;
} version = { 
    .major=PROJECT_VERSION_MAJOR, 
    .minor=PROJECT_VERSION_MINOR,
    .patch=PROJECT_VERSION_PATCH
};

int major_version();
int minor_version();
int patch_version();

#endif
