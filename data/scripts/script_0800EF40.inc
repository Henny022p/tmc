SCRIPT_START script_0800EF40
	BeginBlock 
	DoPostScriptAction 0x0007
	CheckGlobalFlag 0x001f
	JumpIf script_0800EF92
	EndBlock 
script_0800EF50:
	Call sub_080869A4
	JumpIfNot script_0800EF50
	_0807E864 
	CheckLocalFlagByOffset 0x0200, 0x006d
	JumpIf script_0800EF82
	TextboxNoOverlapFollow 0x4d01
	_0807EA94 
	StartPlayerScript script_0800EF9C
	WaitForSomething2 0x00000001
	Wait 0x000f
	_0807E878 
	Jump script_0800EF50
script_0800EF82:
	SetGlobalFlag 0x001f
	TextboxNoOverlapFollow 0x4d02
	_0807EA94 
	Wait 0x000f
	_0807E878 
script_0800EF92:
	Call sub_0808692C
SCRIPT_END
	.2byte 0x0000
