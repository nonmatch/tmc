@ After ToD OBJECT_69 Cutscene
SCRIPT_START script_Object69AfterToD
	SetPlayerIdle
script_0800AFB2:
	EndBlock
	BeginBlock
	Call sub_0807FBB4
	ComparePlayerAction 0x0001
	JumpIfNot script_0800AFB2
	EndBlock
	Call sub_0807DF28
	EzloMessage 0x1c04
	WaitUntilTextboxCloses
	SetLocalFlagByBank 0x0100, 0x0004
	Call sub_0807DF50
	EnablePlayerControl
	DoPostScriptAction 0x0006
SCRIPT_END
	.2byte 0x0000
