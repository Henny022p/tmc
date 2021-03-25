	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata
    .align 2

gUnk_080CFF78:: @ 080CFF78
	.4byte sub_0803C180
	.4byte sub_0803C198
	.4byte sub_08001324
	.4byte sub_0804A7D4
	.4byte sub_08001242
	.4byte nullsub_168

gUnk_080CFF90:: @ 080CFF90
	.4byte sub_0803C1E0
	.4byte sub_0803C234
	.4byte sub_0803C2DC
	.4byte sub_0803C344
	.4byte sub_0803C400

gUnk_080CFFA4:: @ 080CFFA4
	.incbin "baserom.gba", 0x0CFFA4, 0x0000008

gUnk_080CFFAC:: @ 080CFFAC
	.incbin "baserom.gba", 0x0CFFAC, 0x0000010

gUnk_080CFFBC:: @ 080CFFBC
	.incbin "baserom.gba", 0x0CFFBC, 0x0000008

gUnk_080CFFC4:: @ 080CFFC4
	.incbin "baserom.gba", 0x0CFFC4, 0x0000008

