	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata
    .align 2

gUnk_08124798:: @ 08124798
	.4byte sub_0809F4DC
	.4byte sub_0809F700

gUnk_081247A0:: @ 081247A0
	.4byte sub_0809F514
	.4byte sub_0809F548
	.4byte sub_0809F5B0

gUnk_081247AC:: @ 081247AC
	.4byte sub_0809F5DC
	.4byte sub_0809F5F0
	.4byte sub_0809F61C
	.4byte sub_0809F69C
	.4byte sub_0809F6CC

gUnk_081247C0:: @ 081247C0
	.incbin "baserom.gba", 0x1247C0, 0x0000008

gUnk_081247C8:: @ 081247C8
	.incbin "baserom.gba", 0x1247C8, 0x0000008

gUnk_081247D0:: @ 081247D0
	.incbin "baserom.gba", 0x1247D0, 0x0000028
