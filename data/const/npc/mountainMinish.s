	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata
    .align 2

gUnk_08111284:: @ 08111284
	.incbin "baserom.gba", 0x111284, 0x0000080

gUnk_08111304:: @ 08111304
	.incbin "baserom.gba", 0x111304, 0x0000009

gUnk_0811130D:: @ 0811130D
	.incbin "baserom.gba", 0x11130D, 0x0000001

gUnk_0811130E:: @ 0811130E
	.incbin "baserom.gba", 0x11130E, 0x0000001

gUnk_0811130F:: @ 0811130F
	.incbin "baserom.gba", 0x11130F, 0x0000009

gUnk_08111318:: @ 08111318
	.incbin "baserom.gba", 0x111318, 0x0000006

gUnk_0811131E:: @ 0811131E
	.incbin "baserom.gba", 0x11131E, 0x0000025

gUnk_08111343:: @ 08111343
	.incbin "baserom.gba", 0x111343, 0x0000015

gUnk_08111358:: @ 08111358
	.incbin "baserom.gba", 0x111358, 0x0000010

gUnk_08111368:: @ 08111368
	.4byte sub_08067E60
	.4byte sub_08067E88
	.4byte sub_08067EE8

gUnk_08111374:: @ 08111374
	.incbin "baserom.gba", 0x111374, 0x0000006

gUnk_0811137A:: @ 0811137A
	.incbin "baserom.gba", 0x11137A, 0x0000006
