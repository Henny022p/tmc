	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata
    .align 2

gUnk_081145B4:: @ 081145B4
	.4byte sub_0806E4B8
	.4byte sub_0806E4EC
	.4byte sub_0806E564
	.4byte sub_0806E5E4
	.4byte sub_0806E648

gUnk_081145C8:: @ 081145C8
	.incbin "baserom.gba", 0x1145C8, 0x0000008

gUnk_081145D0:: @ 081145D0
	.incbin "baserom.gba", 0x1145D0, 0x0000004
