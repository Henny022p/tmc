@ 2nd to 5th Goron in 6th Goron cutscene
SCRIPT_START script_Goron2Kinstone6
	BeginBlock
	SetAnimationState 0x0004
	SetAnimation 0x0008
	Call SetPriorityMessage
	EndBlock
	WaitForFadeFinish
	Wait 0x00f0
	SetAnimation 0x0000
	SetAnimationState 0x0006
	Wait 0x003c
	WaitUntilTextboxCloses
	SetAnimation 0x0008
	Wait 0x003c
	SetSyncFlag 0x00000001
script_0800C244:
	SetAnimationState 0x0004
script_0800C248:
	CheckRoomFlag 0x00ff
	JumpIfNot script_0800C248
	SetSyncFlag 0x00000002
	Call sub_08054F64
	SetAnimation 0x0000
	DoPostScriptAction 0x0004
	Wait 0x003c
	MessageNoOverlap 0x0e18
	WaitUntilTextboxCloses
	SetSyncFlag 0x00000002
	Call sub_08054F64
	DoPostScriptAction 0x000f
	SetAnimation 0x0008
	Wait 0x0168
	SetAnimationState 0x0004
	SetAnimation 0x0000
	Wait 0x003c
	Call sub_08054F64
	SetEntitySpeed 0x0080
	_0807EEF4 0x0000, 0xffe0
SCRIPT_END