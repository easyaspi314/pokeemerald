Route112_CableCarStation_MapObjects: @ 8533C54
	object_event 1, MAP_OBJ_GFX_BEAUTY, 0, 0, 6, 6, 3, 8, 0, 0, 0, 0, Route112_CableCarStation_EventScript_22AB17, 0, 0, 0
	object_event 2, MAP_OBJ_GFX_CABLE_CAR, 0, 0, 6, 3, 3, 1, 0, 0, 0, 0, 0x0, 0, 0, 0

Route112_CableCarStation_MapWarps: @ 8533C84
	warp_def 6, 11, 0, 0, ROUTE_112
	warp_def 7, 11, 0, 1, ROUTE_112

Route112_CableCarStation_MapEvents:: @ 8533C94
	map_events Route112_CableCarStation_MapObjects, Route112_CableCarStation_MapWarps, 0x0, 0x0

