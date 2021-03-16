#include "global.h"
#include "gba/syscall.h"

extern u8 gUnk_03007FFA;

void BgAffineSet(struct BgAffineSrcData* src, struct BgAffineDstData* dest, s32 count) {
    asm("svc 0xe" ::"r"(src), "r"(dest), "r"(count));
}

void CpuSet(const void* src, void* dest, u32 control) {
    asm("svc 0xb" ::"r"(src), "r"(dest), "r"(control));
}

s32 Div(s32 dividend, s32 divisor) {
    register s32 quotient asm("r0");
    register s32 remainder asm("r1");
    asm("svc #0x6" : "=r"(quotient), "=r"(remainder) : "r"(dividend), "r"(divisor));
    return quotient;
}

s32 Mod(s32 dividend, s32 divisor) {
    register s32 quotient asm("r0");
    register s32 remainder asm("r1");
    asm("svc #0x6" : "=r"(quotient), "=r"(remainder) : "r"(dividend), "r"(divisor));
    return remainder;
}

void LZ77UnCompVram(const void* src, void* dest) {
    asm("svc 0x12" ::"r"(src), "r"(dest));
}

void LZ77UnCompWram(const void* src, void* dest) {
    asm("svc 0x11" ::"r"(src), "r"(dest));
}

void ObjAffineSet(struct ObjAffineSrcData* src, void* dest, s32 count, s32 offset) {
    asm("svc 0xf" ::"r"(src), "r"(dest), "r"(count), "r"(offset));
}

void RegisterRamReset(u32 resetFlags) {
    asm("svc 0x1" ::"r"(resetFlags));
}

void SoundBiasReset(void) {
    asm("svc 0x19" ::"r"(0));
}

void SoundBiasSet(void) {
    asm("svc 0x19" ::"r"(1));
}

u16 Sqrt(u32 num) {
    u16 ret;
    asm("svc 8" : "=r"(ret) : "r"(num));
    return ret;
}

void VBlankIntrWait(void) {
    register u32 r2 asm("r2") = 0;
    asm("svc 0x5" ::"r"(r2));
}

__attribute__((naked)) void SoftReset(u32 resetFlags) {
    register u8* ptr asm("r3") = (u8*)0x04000208;
    register u32 zero asm("r2") = 0;
    register u8* sp asm("sp");

    *ptr = zero;
    ptr = &gUnk_03007FFA;
    asm("mov r2, #0x0");
    *ptr = zero;
    sp = ptr - 0xfa;
    asm("svc 0x1" ::"r"(resetFlags));
    asm("svc 0" ::"r"(resetFlags));
}
