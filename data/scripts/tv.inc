EventScript_27EE0B:: @ 827EE0B
	lockall
	incrementgamestat 44
	special ResetTVShowState
	specialvar VAR_RESULT, CheckForBigMovieOrEmergencyNewsOnTV
	compare VAR_RESULT, 2
	goto_eq EventScript_27EE9A
	compare VAR_RESULT, 1
	goto_eq EventScript_27EEA4
	checkflag FLAG_SYS_TV_START
	goto_if 0, EventScript_27EE8A
	checkflag FLAG_SYS_TV_WATCH
	goto_eq EventScript_27EE8A
	specialvar VAR_RESULT, IsTVShowInSearchOfTrainersAiring
	compare VAR_RESULT, 1
	goto_eq EventScript_27EEFF
	goto EventScript_27EEE9
	end

EventScript_27EE54:: @ 827EE54
	specialvar VAR_0x8004, special_0x44
	compare VAR_0x8004, 255
	goto_eq EventScript_27EED8
	specialvar VAR_RESULT, special_0x4a
	compare VAR_RESULT, 255
	goto_eq EventScript_27EED8
	copyvar VAR_0x8004, VAR_RESULT
	specialvar VAR_RESULT, special_0x45
	compare VAR_RESULT, 0
	goto_if 5, EventScript_27EEBA
	end

EventScript_27EE8A:: @ 827EE8A
	special GetMomOrDadStringForTVMessage
	msgbox gUnknown_08272BCF, 4
	special TurnOffTVScreen
	releaseall
	end

EventScript_27EE9A:: @ 827EE9A
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F7F0F, 4
	releaseall
	end

EventScript_27EEA4:: @ 827EEA4
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F826F, 4
	special InitRoamer
	clearflag FLAG_SYS_TV_LATI
	setflag FLAG_0x0FF
	special TurnOffTVScreen
	releaseall
	end

EventScript_27EEBA:: @ 827EEBA
	special DoTVShow
	waitmessage
	waitbuttonpress
	compare VAR_RESULT, 1
	goto_if 5, EventScript_27EEBA
	goto EventScript_27EED0
	end

EventScript_27EED0:: @ 827EED0
	special TurnOffTVScreen
	setflag FLAG_SYS_TV_WATCH
	releaseall
	end

EventScript_27EED8:: @ 827EED8
	special GetMomOrDadStringForTVMessage
	msgbox gUnknown_08272BCF, 4
	goto EventScript_27EED0
	end

EventScript_27EEE9:: @ 827EEE9
	special DoPokeNews
	compare VAR_RESULT, 0
	goto_eq EventScript_27EE54
	waitmessage
	waitbuttonpress
	goto EventScript_27EED0
	end

EventScript_27EEFF:: @ 827EEFF
	special DoTVShowInSearchOfTrainers
	waitmessage
	waitbuttonpress
	compare VAR_RESULT, 0
	goto_eq EventScript_27EEFF
	goto EventScript_27EED0
	end
