	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata
    .align 2

gUnk_08121440:: @ 08121440
	.4byte sub_0808BB30
	.4byte sub_0808BC3C
	.4byte sub_0808BD14

gUnk_0812144C:: @ 0812144C
	.incbin "baserom.gba", 0x12144C, 0x0000028

gUnk_08121474:: @ 08121474
	.incbin "baserom.gba", 0x121474, 0x000000C
