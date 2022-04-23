#include "mgba.h"

#define REG_DEBUG_ENABLE ((vu16*)0x4FFF780)
#define REG_DEBUG_FLAGS ((vu16*)0x4FFF700)
#define REG_DEBUG_STRING ((char*)0x4FFF600)

bool32 mgba_open(void) {
    *REG_DEBUG_ENABLE = 0xC0DE;
    return *REG_DEBUG_ENABLE == 0x1DEA;
}

void mgba_close(void) {
    *REG_DEBUG_ENABLE = 0;
}

void mgba_puts(const char* message, MgbaLogLevel level) {
    strncpy(REG_DEBUG_STRING, message, 0x100);
    *REG_DEBUG_FLAGS = level | 0x100;
}

void mgba_print_int(const char* label, int number, MgbaLogLevel level) {
    static const char digits[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };
    int i;
    int len = strlen(label);
    if (len > 0x100 - 12) {
        len = 0x100 - 12;
    }
    strncpy(REG_DEBUG_STRING, label, len);
    REG_DEBUG_STRING[len] = '0';
    REG_DEBUG_STRING[len + 1] = 'x';
    for (i = 1; i <= 8; i++) {
        REG_DEBUG_STRING[len + i + 1] = digits[(number & (0xf << ((8 - i) * 4))) >> ((8 - i) * 4)];
    }
    REG_DEBUG_STRING[len + 10] = 0;
    *REG_DEBUG_FLAGS = level | 0x100;
}
