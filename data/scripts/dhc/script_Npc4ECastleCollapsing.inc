@ DHC NPC4E Castle collapsing
SCRIPT_START script_Npc4ECastleCollapsing
	Wait 0x003c
	PlayBgm BGM_CASTLE_COLLAPSE
	StartPlayerScript script_PlayerStonesFall
	WaitForSyncFlagAndClear 0x00000006
	EzloMessage 0x1646
	WaitUntilTextboxCloses
	SetSyncFlag 0x00000001
	StartPlayerScript script_PlayerCastleCollapsing
	CameraTargetPlayer
	SetFadeTime 0x0004
	_0807E80C 0x00000000
	WaitForFadeFinish
	CallWithArg DeleteManager36, 0x00000001
	_0807F0C8 0x0000, 0x0000
	SetLocalFlag 0x0079
	CallWithArg sub_0806DA1C, 0x00000002
	Call sub_0807DF50
	EnablePlayerControl
	DoPostScriptAction 0x0006
SCRIPT_END