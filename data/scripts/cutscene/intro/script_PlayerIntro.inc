@ Intro Player
SCRIPT_START script_PlayerIntro
	BeginBlock
	Call sub_0807DF28
	SetPlayerIdle
	SetLocalFlag 0x0046
	EndBlock
	WaitForFadeFinish
	Wait 0x001e
	@ Wake up message
	MessageFromTarget 0x1005
	WaitUntilTextboxCloses
	Wait 0x003c
	Call sub_0807529C
	Wait 0x003c
	@ Exclamation mark
	DoPostScriptAction 0x0014
	Wait 0x001e
	@ Give control to the player?
	Call sub_08053250
	EnablePlayerControl
	Call sub_0807DF50
	Call ResetPlayerAnimationAndAction
SCRIPT_END