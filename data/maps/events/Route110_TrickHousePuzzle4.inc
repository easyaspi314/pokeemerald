Route110_TrickHousePuzzle4_MapObjects: @ 853E338
	object_event 1, MAP_OBJ_GFX_GIRL_3, 0, 0, 2, 2, 3, 8, 0, 0, 1, 1, Route110_TrickHousePuzzle4_EventScript_26C87E, 0, 0, 0
	object_event 2, MAP_OBJ_GFX_GIRL_3, 0, 0, 14, 7, 3, 9, 0, 0, 1, 2, Route110_TrickHousePuzzle4_EventScript_26C8AC, 0, 0, 0
	object_event 3, MAP_OBJ_GFX_BLACK_BELT, 0, 0, 2, 14, 3, 10, 0, 0, 1, 2, Route110_TrickHousePuzzle4_EventScript_26C895, 0, 0, 0
	object_event 4, MAP_OBJ_GFX_ITEM_BALL, 0, 0, 2, 5, 3, 1, 0, 0, 0, 0, Route110_TrickHousePuzzle4_EventScript_29144F, 1065, 0, 0
	object_event 5, MAP_OBJ_GFX_PUSHABLE_BOULDER, 0, 0, 13, 3, 3, 1, 0, 0, 0, 0, Route110_TrickHousePuzzle4_EventScript_2908BA, 17, 0, 0
	object_event 6, MAP_OBJ_GFX_PUSHABLE_BOULDER, 0, 0, 12, 5, 3, 1, 0, 0, 0, 0, Route110_TrickHousePuzzle4_EventScript_2908BA, 18, 0, 0
	object_event 7, MAP_OBJ_GFX_PUSHABLE_BOULDER, 0, 0, 5, 16, 3, 1, 0, 0, 0, 0, Route110_TrickHousePuzzle4_EventScript_2908BA, 19, 0, 0
	object_event 8, MAP_OBJ_GFX_PUSHABLE_BOULDER, 0, 0, 4, 6, 3, 1, 0, 0, 0, 0, Route110_TrickHousePuzzle4_EventScript_2908BA, 20, 0, 0
	object_event 9, MAP_OBJ_GFX_PUSHABLE_BOULDER, 0, 0, 12, 2, 3, 1, 0, 0, 0, 0, Route110_TrickHousePuzzle4_EventScript_2908BA, 21, 0, 0
	object_event 10, MAP_OBJ_GFX_PUSHABLE_BOULDER, 0, 0, 5, 7, 3, 1, 0, 0, 0, 0, Route110_TrickHousePuzzle4_EventScript_2908BA, 22, 0, 0
	object_event 11, MAP_OBJ_GFX_PUSHABLE_BOULDER, 0, 0, 9, 3, 3, 1, 0, 0, 0, 0, Route110_TrickHousePuzzle4_EventScript_2908BA, 23, 0, 0
	object_event 12, MAP_OBJ_GFX_PUSHABLE_BOULDER, 0, 0, 10, 12, 3, 1, 0, 0, 0, 0, Route110_TrickHousePuzzle4_EventScript_2908BA, 24, 0, 0
	object_event 13, MAP_OBJ_GFX_PUSHABLE_BOULDER, 0, 0, 14, 2, 3, 1, 0, 0, 0, 0, Route110_TrickHousePuzzle4_EventScript_2908BA, 25, 0, 0
	object_event 14, MAP_OBJ_GFX_PUSHABLE_BOULDER, 0, 0, 10, 15, 3, 1, 0, 0, 0, 0, Route110_TrickHousePuzzle4_EventScript_2908BA, 26, 0, 0

Route110_TrickHousePuzzle4_MapWarps: @ 853E488
	warp_def 0, 21, 3, 2, ROUTE_110_TRICK_HOUSE_ENTRANCE
	warp_def 1, 21, 3, 2, ROUTE_110_TRICK_HOUSE_ENTRANCE
	warp_def 13, 1, 3, 0, ROUTE_110_TRICK_HOUSE_END

Route110_TrickHousePuzzle4_MapBGEvents: @ 853E4A0
	bg_event 14, 13, 0, 0, 0, Route110_TrickHousePuzzle4_EventScript_26C861

Route110_TrickHousePuzzle4_MapEvents:: @ 853E4AC
	map_events Route110_TrickHousePuzzle4_MapObjects, Route110_TrickHousePuzzle4_MapWarps, 0x0, Route110_TrickHousePuzzle4_MapBGEvents

