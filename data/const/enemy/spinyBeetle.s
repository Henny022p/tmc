	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata
    .align 2

	.incbin "baserom.gba", 0x0CEBDC, 0x000010

gUnk_080CEBEC:: @ 080CEBEC 
	.4byte sub_080337BC
	.4byte sub_080337D4
	.4byte sub_08001324
	.4byte sub_0804A7D4
	.4byte sub_08033870
	.4byte nullsub_159

gUnk_080CEC04:: @ 080CEC04
	.4byte sub_08033890
	.4byte sub_08033958
	.4byte sub_08033A7C
	.4byte sub_08033ACC
	.4byte sub_08033B44
	.4byte sub_08033C94

gUnk_080CEC1C:: @ 080CEC1C
	.incbin "baserom.gba", 0x0CEC1C, 0x0000008
