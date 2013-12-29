#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/mount.h>
#include <stdarg.h>

int fdid;
#define __AURORA__
#define AURORA_VERSION 1.0

typedef struct {
char *package_path;
int recovery_api;
FILE *recovery_pipe;
float aurora_version;
} package;

#define DEVICE(x) !strcmp(pkg->device, x )
#define KERNEL(x) !strcmp(pkg->kernel, x )

#define extract_file(x, y) extract_zip_entry(pkg->package_path, x , y );

#define mount(x, y, z) __aurora_mount( x ,  y , z )
#define umount(x) __aurora_umount( x )
