FallarborTown_BattleTentLobby_MapScripts:: @ 81FFE66
	map_script 2, FallarborTown_BattleTentLobby_MapScript2_1FFE85
	map_script 4, FallarborTown_BattleTentLobby_MapScript2_1FFE71
	.byte 0

FallarborTown_BattleTentLobby_MapScript2_1FFE71: @ 81FFE71
	map_script_2 VAR_0x4001, 0, FallarborTown_BattleTentLobby_EventScript_1FFE7B
	.2byte 0

FallarborTown_BattleTentLobby_EventScript_1FFE7B:: @ 81FFE7B
	setvar VAR_0x4001, 1
	turnobject 255, 2
	end

FallarborTown_BattleTentLobby_MapScript2_1FFE85: @ 81FFE85
	map_script_2 VAR_0x4000, 0, FallarborTown_BattleTentLobby_EventScript_1FFEAF
	map_script_2 VAR_0x4000, 1, FallarborTown_BattleTentLobby_EventScript_1FFEB8
	map_script_2 VAR_0x4000, 2, FallarborTown_BattleTentLobby_EventScript_1FFFCD
	map_script_2 VAR_0x4000, 3, FallarborTown_BattleTentLobby_EventScript_1FFEED
	map_script_2 VAR_0x4000, 4, FallarborTown_BattleTentLobby_EventScript_1FFF93
	.2byte 0

FallarborTown_BattleTentLobby_EventScript_1FFEAF:: @ 81FFEAF
	setvar VAR_0x8004, 0
	special sub_81A1780
	end

FallarborTown_BattleTentLobby_EventScript_1FFEB8:: @ 81FFEB8
	lockall
	msgbox FallarborTown_BattleTentLobby_Text_2C4DED, 4
	closemessage
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 0
	special sub_81A1780
	setvar VAR_0x4000, 255
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 0
	special sub_81A1780
	releaseall
	end

FallarborTown_BattleTentLobby_EventScript_1FFEED:: @ 81FFEED
	lockall
	msgbox FallarborTown_BattleTentLobby_Text_2C4EC3, 4
	message FallarborTown_BattleTentLobby_Text_2C4EFF
	waitmessage
	setvar VAR_0x8004, 4
	special sub_81B9B80
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 0
	special sub_81A1780
	setvar VAR_0x8004, 3
	setvar VAR_0x8005, 0
	special sub_81B9B80
	playse SE_SAVE
	waitse

FallarborTown_BattleTentLobby_EventScript_1FFF27:: @ 81FFF27
	msgbox FallarborTown_BattleTentLobby_Text_2C4F22, 4
	setvar VAR_0x8004, 5
	special sub_81B9B80
	switch VAR_RESULT
	case 0, FallarborTown_BattleTentLobby_EventScript_1FFF73
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 0
	special sub_81A1780
	message FallarborTown_BattleTentLobby_Text_2C4F69
	waitmessage
	playfanfare MUS_FANFA4
	waitfanfare
	msgbox FallarborTown_BattleTentLobby_Text_2C501F, 4
	closemessage
	setvar VAR_0x4000, 255
	releaseall
	end

FallarborTown_BattleTentLobby_EventScript_1FFF73:: @ 81FFF73
	msgbox FallarborTown_BattleTentLobby_Text_2C4F83, 4
	waitmessage
	closemessage
	setvar VAR_0x4000, 255
	releaseall
	end

FallarborTown_BattleTentLobby_EventScript_1FFF84:: @ 81FFF84
	lockall
	msgbox FallarborTown_BattleTentLobby_Text_2C4EC3, 4
	goto FallarborTown_BattleTentLobby_EventScript_1FFF27
	end

FallarborTown_BattleTentLobby_EventScript_1FFF93:: @ 81FFF93
	lockall
	message FallarborTown_BattleTentLobby_Text_2C4FD7
	waitmessage
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 0
	special sub_81A1780
	setvar VAR_0x8004, 3
	setvar VAR_0x8005, 0
	special sub_81B9B80
	playse SE_SAVE
	waitse
	msgbox FallarborTown_BattleTentLobby_Text_2C501F, 4
	closemessage
	setvar VAR_0x4000, 255
	releaseall
	end

FallarborTown_BattleTentLobby_EventScript_1FFFCD:: @ 81FFFCD
	lockall
	message FallarborTown_BattleTentLobby_Text_2C504C
	waitmessage
	setvar VAR_0x8004, 3
	setvar VAR_0x8005, 1
	special sub_81B9B80
	playse SE_SAVE
	waitse
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 3
	setvar VAR_0x8006, 0
	special sub_81A1780
	setvar VAR_0x4000, 255
	goto FallarborTown_BattleTentLobby_EventScript_20013C

FallarborTown_BattleTentLobby_EventScript_200001:: @ 8200001
	lock
	faceplayer
	setvar VAR_0x8004, 1
	special sub_81B9B80
	compare VAR_RESULT, 0
	goto_if 5, FallarborTown_BattleTentLobby_EventScript_1FFF84
	special copy_player_party_to_sav1
	msgbox FallarborTown_BattleTentLobby_Text_2C47EB, 4

FallarborTown_BattleTentLobby_EventScript_200021:: @ 8200021
	message FallarborTown_BattleTentLobby_Text_2C4843
	waitmessage
	multichoice 17, 6, 23, 0
	switch VAR_RESULT
	case 0, FallarborTown_BattleTentLobby_EventScript_20005D
	case 1, FallarborTown_BattleTentLobby_EventScript_200169
	case 2, FallarborTown_BattleTentLobby_EventScript_2001C5
	case 127, FallarborTown_BattleTentLobby_EventScript_2001C5

FallarborTown_BattleTentLobby_EventScript_20005D:: @ 820005D
	setvar VAR_FRONTIER_FACILITY, 3
	setvar VAR_0x40CE, 0
	setvar VAR_RESULT, 2
	setvar VAR_0x8004, 15
	special sub_81A1780
	compare VAR_0x8004, 1
	goto_eq FallarborTown_BattleTentLobby_EventScript_200176
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 2
	special sub_81A1780
	msgbox FallarborTown_BattleTentLobby_Text_2C4BC8, 4
	fadescreen 1
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 3
	special sub_80F9490
	waitstate
	compare VAR_RESULT, 0
	goto_eq FallarborTown_BattleTentLobby_EventScript_2001C2
	msgbox FallarborTown_BattleTentLobby_Text_2C4B35, 5
	switch VAR_RESULT
	case 0, FallarborTown_BattleTentLobby_EventScript_2001C2
	case 1, FallarborTown_BattleTentLobby_EventScript_2000E2
	case 127, FallarborTown_BattleTentLobby_EventScript_2001C2

FallarborTown_BattleTentLobby_EventScript_2000E2:: @ 82000E2
	setvar VAR_0x4000, 0
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 4
	special sub_81A1780
	setvar VAR_0x8004, 0
	special sub_81B9B80
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 1
	special sub_81A1780
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 3
	setvar VAR_0x8006, 0
	special sub_81A1780
	special copy_player_party_from_sav1
	closemessage
	delay 2
	call FallarborTown_BattleTentLobby_EventScript_27134F
	setvar VAR_0x4000, 255
	compare VAR_RESULT, 0
	goto_eq FallarborTown_BattleTentLobby_EventScript_2001AB

FallarborTown_BattleTentLobby_EventScript_20013C:: @ 820013C
	special copy_player_party_to_sav1
	setvar VAR_0x8004, 3
	setvar VAR_0x8005, 3
	special sub_81A1780
	msgbox FallarborTown_BattleTentLobby_Text_2C4DC3, 4
	closemessage
	call FallarborTown_BattleTentLobby_EventScript_2001CF
	warp FALLARBOR_TOWN_BATTLE_TENT_CORRIDOR, 255, 2, 7
	setvar VAR_0x4000, 0
	waitstate
	end

FallarborTown_BattleTentLobby_EventScript_200169:: @ 8200169
	msgbox FallarborTown_BattleTentLobby_Text_2C48AC, 4
	goto FallarborTown_BattleTentLobby_EventScript_200021

FallarborTown_BattleTentLobby_EventScript_200176:: @ 8200176
	switch VAR_RESULT
	case 0, FallarborTown_BattleTentLobby_EventScript_200191
	case 1, FallarborTown_BattleTentLobby_EventScript_20019E

FallarborTown_BattleTentLobby_EventScript_200191:: @ 8200191
	msgbox FallarborTown_BattleTentLobby_Text_2C4BFA, 4
	goto FallarborTown_BattleTentLobby_EventScript_2001CD

FallarborTown_BattleTentLobby_EventScript_20019E:: @ 820019E
	msgbox FallarborTown_BattleTentLobby_Text_2C4CC0, 4
	goto FallarborTown_BattleTentLobby_EventScript_2001CD

FallarborTown_BattleTentLobby_EventScript_2001AB:: @ 82001AB
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 0
	special sub_81A1780
	goto FallarborTown_BattleTentLobby_EventScript_2001C5

FallarborTown_BattleTentLobby_EventScript_2001C2:: @ 82001C2
	special copy_player_party_from_sav1

FallarborTown_BattleTentLobby_EventScript_2001C5:: @ 82001C5
	msgbox FallarborTown_BattleTentLobby_Text_2C487F, 4

FallarborTown_BattleTentLobby_EventScript_2001CD:: @ 82001CD
	release
	end

FallarborTown_BattleTentLobby_EventScript_2001CF:: @ 82001CF
	applymovement 1, FallarborTown_BattleTentLobby_Movement_2001FE
	applymovement 255, FallarborTown_BattleTentLobby_Movement_200205
	waitmovement 0
	opendoor 6, 1
	waitdooranim
	applymovement 1, FallarborTown_BattleTentLobby_Movement_200202
	applymovement 255, FallarborTown_BattleTentLobby_Movement_200209
	waitmovement 0
	closedoor 6, 1
	waitdooranim
	return

FallarborTown_BattleTentLobby_Movement_2001FE: @ 82001FE
	step_up
	step_up
	step_up
	step_end

FallarborTown_BattleTentLobby_Movement_200202: @ 8200202
	step_up
	step_54
	step_end

FallarborTown_BattleTentLobby_Movement_200205: @ 8200205
	step_up
	step_up
	step_up
	step_end

FallarborTown_BattleTentLobby_Movement_200209: @ 8200209
	step_up
	step_up
	step_54
	step_end

FallarborTown_BattleTentLobby_EventScript_20020D:: @ 820020D
	msgbox FallarborTown_BattleTentLobby_Text_20045A, 2
	end

FallarborTown_BattleTentLobby_EventScript_200216:: @ 8200216
	msgbox FallarborTown_BattleTentLobby_Text_200304, 2
	end

FallarborTown_BattleTentLobby_EventScript_20021F:: @ 820021F
	msgbox FallarborTown_BattleTentLobby_Text_200382, 2
	end

FallarborTown_BattleTentLobby_EventScript_200228:: @ 8200228
	lock
	faceplayer
	checkflag FLAG_0x1CD
	goto_eq FallarborTown_BattleTentLobby_EventScript_200245
	msgbox FallarborTown_BattleTentLobby_Text_200501, 4
	addvar VAR_0x40D1, 1
	setflag FLAG_0x1CD
	release
	end

FallarborTown_BattleTentLobby_EventScript_200245:: @ 8200245
	msgbox FallarborTown_BattleTentLobby_Text_200653, 4
	release
	end

FallarborTown_BattleTentLobby_EventScript_20024F:: @ 820024F
	lockall
	msgbox FallarborTown_BattleTentLobby_Text_256DB8, 4
	goto FallarborTown_BattleTentLobby_EventScript_20025E
	end

FallarborTown_BattleTentLobby_EventScript_20025E:: @ 820025E
	message FallarborTown_BattleTentLobby_Text_256DDF
	waitmessage
	multichoice 17, 0, 112, 0
	switch VAR_RESULT
	case 0, FallarborTown_BattleTentLobby_EventScript_2002BC
	case 1, FallarborTown_BattleTentLobby_EventScript_2002CA
	case 2, FallarborTown_BattleTentLobby_EventScript_2002D8
	case 3, FallarborTown_BattleTentLobby_EventScript_2002E6
	case 4, FallarborTown_BattleTentLobby_EventScript_2002F4
	case 5, FallarborTown_BattleTentLobby_EventScript_200302
	case 127, FallarborTown_BattleTentLobby_EventScript_200302
	end

FallarborTown_BattleTentLobby_EventScript_2002BC:: @ 82002BC
	msgbox FallarborTown_BattleTentLobby_Text_2C67CD, 4
	goto FallarborTown_BattleTentLobby_EventScript_20025E
	end

FallarborTown_BattleTentLobby_EventScript_2002CA:: @ 82002CA
	msgbox FallarborTown_BattleTentLobby_Text_256E02, 4
	goto FallarborTown_BattleTentLobby_EventScript_20025E
	end

FallarborTown_BattleTentLobby_EventScript_2002D8:: @ 82002D8
	msgbox FallarborTown_BattleTentLobby_Text_256F43, 4
	goto FallarborTown_BattleTentLobby_EventScript_20025E
	end

FallarborTown_BattleTentLobby_EventScript_2002E6:: @ 82002E6
	msgbox FallarborTown_BattleTentLobby_Text_256FF2, 4
	goto FallarborTown_BattleTentLobby_EventScript_20025E
	end

FallarborTown_BattleTentLobby_EventScript_2002F4:: @ 82002F4
	msgbox FallarborTown_BattleTentLobby_Text_257202, 4
	goto FallarborTown_BattleTentLobby_EventScript_20025E
	end

FallarborTown_BattleTentLobby_EventScript_200302:: @ 8200302
	releaseall
	end

FallarborTown_BattleTentLobby_Text_200304: @ 8200304
	.string "Fufufufufu.\p"
	.string "I’m going to make everyone think\n"
	.string "I’m just a kid and let them play down.\p"
	.string "Then, I’ll shock them and grab\n"
	.string "the title!$"

FallarborTown_BattleTentLobby_Text_200382: @ 8200382
	.string "You know how BATTLE TENTS offer\n"
	.string "different events in different towns?\p"
	.string "My favorite is definitely the BATTLE\n"
	.string "TENT in FALLARBOR TOWN.\p"
	.string "I think it’s fantastic how TRAINERS\n"
	.string "try to win with all their faith in\l"
	.string "their POKéMON.$"

FallarborTown_BattleTentLobby_Text_20045A: @ 820045A
	.string "I heard something about some tent,\n"
	.string "so I came to camp out.\p"
	.string "I didn’t know that tents these days\n"
	.string "are so luxurious!\p"
	.string "Since I’m here, I may as well try\n"
	.string "my hand at battling!$"

FallarborTown_BattleTentLobby_Text_200501: @ 8200501
	.string "SCOTT: Hi, {PLAYER}{KUN}!\n"
	.string "So you came out to this BATTLE TENT!\p"
	.string "The people in these parts tend to be\n"
	.string "easygoing and laid-back.\p"
	.string "But, you see, what I’m looking for are\n"
	.string "people with…\p"
	.string "How should I say this?\p"
	.string "Someone bursting with the desire\n"
	.string "and the drive to win.\p"
	.string "If there were a TRAINER like that,\n"
	.string "I’d immediately…\p"
	.string "Whoops! Never mind!\n"
	.string "Keep working at it!$"

FallarborTown_BattleTentLobby_Text_200653: @ 8200653
	.string "SCOTT: Instead of wasting your\n"
	.string "time with the likes of me, why not\l"
	.string "make a challenge?$"

