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
