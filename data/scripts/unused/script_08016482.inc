@ TODO UNUSED?
SCRIPT_START script_08016482
	FadeInvert
	Nop2 0x0080
	DoFade4
	DoFade5
	DoFade6
	DoFade7
	_0807E800 0x00000000
	_0807E80C 0x00000000
	_0807E858_0
	SetPlayerIdle
	EnablePlayerControl
	DisablePlayerControl
	SetPlayerAction 0x00005408
	StartPlayerScript script_08016384
	SetPlayerAnimation 0x03a0
	_0807E8E4_0
	_0807E8E4_1
	_0807E8E4_2
	_0807E8E4_3
	SetAction 0x0004
	SetIntVariable 0x00000000
	SetVariableToFrame
	SetAnimation 0x0000
	TriggerInteract
	_0807E974 0x0600
	_0807E9D4
	_0807E9DC
	_0807E9E4 0x0000
	_0807EA88 0x0001
	WaitUntilTextboxCloses
	MessageFromTarget 0x0601
	MessageNoOverlap 0x0601
	MessageFromTargetPos_1 0x0601
	MessageFromTargetTable 0x0601, 0x0602, 0x0603
	MessageNoOverlapVar 
	EzloMessage 0x0602
	_0807EB38
	SetAnimationState 0x0000
	_0807EB4C 0x0000, 0x0000
	FacePlayer
	FaceAwayFromPlayer
	SetEntityDirection 0x0000
	SetEntityDirectionWithAnimationState 0x0000
	SetEntitySpeed 0x0100
	SetEntityVelocity 0x00018000
	SetEntityPositionRelative 0x0000, 0x0000
	MoveEntityToPlayer
	Nop3
	WalkForward 0x0010
	WalkNorth 0x0020
	WalkEast 0x0030
	WalkSouth 0x0040
	WalkWest 0x0050
	_0807ED24 0x0000, 0x0000, 0x0000
	_0807EDD4 0x0000, 0x0000
	_0807EE04 0x0000, 0x0000
	_0807EE30
	_0807EEB4
	_0807EEF4 0xfff0, 0x0014
	DoPostScriptAction 0x0000
	DoPostScriptAction2 0x0001
	PlaySound SFX_METAL_CLINK
	PlayBgm BGM_MINISH_WOODS
	SoundReq 0x00000074
	StopBgm
	ModRupees 0xff38
	ModHealth 0x0010
	IncreaseMaxHealth
	GiveKinstone 0x0001
	GivePlayerItem 0x0001
	GetInventoryValue 0x0001
	_0807F078 0x0001, 0x0002
	_0807F088 0x0001
	CameraTargetEntity
	CameraTargetPlayer
	_0807F0B4 0x0007
	_0807F0C8 0x003c, 0x0003
SCRIPT_END
	.2byte 0x0000
