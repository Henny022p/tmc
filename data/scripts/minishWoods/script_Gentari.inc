@ Gentari at beginning
SCRIPT_START script_Gentari
	BeginBlock
	DoPostScriptAction 0x000a
	SetAnimationState 0x0004
	EndBlock
script_0800C780:
	TriggerInteract
	SetPlayerIdle
	Call sub_0807DF28
	StartPlayerScript script_PlayerAtGentari
	WaitForSyncFlagAndClear 0x00000001
	CheckInventory1 0x0040
	JumpIf script_0800C824
	CheckInventory1 0x005b
	JumpIf script_0800C7C0
	SetAnimation 0x0008
	MessageFromTarget 0x2122
	WaitUntilTextboxCloses
	DoPostScriptAction 0x0000
	Call sub_0807DF50
	EnablePlayerControl
	Jump script_0800C780
script_0800C7C0:
	SetAnimation 0x0008
	CheckLocalFlag 0x0081
	JumpIf script_0800C80A
	MessageFromTarget 0x1130
	WaitUntilTextboxCloses
	EzloMessage 0x1131
	WaitUntilTextboxCloses
	FaceAwayFromPlayer 
	MessageFromTarget 0x1132
	WaitUntilTextboxCloses
	SetIntVariable 0x00000103
	Call LoadMenu
	MessageFromTarget 0x1133
	WaitUntilTextboxCloses
	Wait 0x000a
	DoPostScriptAction 0x0000
	SetLocalFlag 0x0081
	Call sub_0807DF50
	EnablePlayerControl
	Jump script_0800C780
script_0800C80A:
	MessageFromTarget 0x1133
	WaitUntilTextboxCloses
	Wait 0x000a
	SetAnimation 0x0000
	Call sub_0807DF50
	EnablePlayerControl
	Jump script_0800C780
script_0800C824:
	SetAnimation 0x0008
	CheckLocalFlag 0x0083
	JumpIf script_0800C8AE
	MessageFromTarget 0x1135
	WaitUntilTextboxCloses
	SetEntitySpeed 0x0040
	_0807EDD4 0x0038, 0x0044
	DoPostScriptAction 0x0000
	Wait 0x000f
	SetLocalFlag 0x0083
	Wait 0x003c
	PlaySound SFX_SECRET
	Wait 0x003c
	FacePlayer 
	FaceAwayFromPlayer 
	MessageFromTarget 0x1136
	WaitUntilTextboxCloses
	EzloMessage 0x1137
	WaitUntilTextboxCloses
	Wait 0x000a
	SetAnimationState 0x0004
	DoPostScriptAction 0x0000
	Call sub_0807DF50
	EnablePlayerControl
script_0800C87C:
	TriggerInteract
	SetPlayerIdle
	Call sub_0807DF28
	FacePlayer
	SetIntVariable 0x00000008
	Call sub_0807F3D8
	MessageFromTarget 0x1136
	WaitUntilTextboxCloses
	Wait 0x000a
	DoPostScriptAction 0x0000
	Call sub_0807DF50
	EnablePlayerControl
	Jump script_0800C87C
script_0800C8AE:
	MessageFromTarget 0x1136
	WaitUntilTextboxCloses
	Wait 0x000a
	DoPostScriptAction 0x0000
	Call sub_0807DF50
	EnablePlayerControl
	Jump script_0800C780