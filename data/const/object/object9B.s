	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata
    .align 2


gUnk_081242D0:: @ 081242D0
	.4byte sub_0809E7C0
	.4byte sub_0809E7E0

gUnk_081242D8:: @ 081242D8
	.incbin "baserom.gba", 0x1242D8, 0x0000010
