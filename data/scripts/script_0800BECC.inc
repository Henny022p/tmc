SCRIPT_START script_0800BECC
	BeginBlock 
	_0807EB44 0x0000
	_0807E930 0x0000
	DoPostScriptAction 0x0008
	SetEntitySpeed 0x0080
	Call sub_0807F348
	EndBlock 
	WaitForSomething2 0x00000002
	DoPostScriptAction 0x0007
	CallWithArg sub_0807F4F8, 0x000001b8
	Wait 0x001e
	TextboxNoOverlap 0x0e0e
	_0807EA94 
	_0807E5F8 0x0000000c
	WaitForSomething2 0x00000002
	SetEntitySpeed 0x0100
	_0807EDD4 0x0088, 0x0178
	Wait 0x000f
	_0807E5F8 0x0000000c
	DoPostScriptAction 0x000f
	_0807E930 0x0008
	Wait 0x00f0
	Call sub_08054968
SCRIPT_END
