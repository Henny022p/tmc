#ifndef TMC_MGBA_H
#define TMC_MGBA_H

#include "global.h"

typedef enum {
    MGBA_LOG_FATAL,
    MGBA_LOG_ERROR,
    MGBA_LOG_WARN,
    MGBA_LOG_INFO,
    MGBA_LOG_DEBUG
} MgbaLogLevel;

bool32 mgba_open(void);
void mgba_close(void);

void mgba_puts(const char* message, MgbaLogLevel level);
void mgba_print_int(const char* label, int number, MgbaLogLevel level);

#endif // TMC_MGBA_H
