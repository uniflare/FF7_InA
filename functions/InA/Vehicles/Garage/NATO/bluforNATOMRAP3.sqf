if (vehicleParked) exitWith {
	["Headquarters", "Please clear the garage before requisitioning more vehicles."] remoteExec ["FF7_fnc_formatHint", ID, false];
};

_afford = false;

if (LogV >= 2) then {
	if (LogM >= 50) then {
		if (LogF >= 200) then {
			_afford = true;
		};
	};
};

if (_afford) then {

	["VEHICLE REQUSITIONED", ""] remoteExec ["FF7_fnc_formatHint", ID, false];

	_veh = createVehicle ["B_MRAP_01_F", getMarkerPos "garageSpawn", [], 0, "CAN_COLLIDE"];
	_veh setDir (markerDir "garageSpawn");
	clearBackpackCargoGlobal _veh;
	clearMagazineCargoGlobal _veh;
	clearWeaponCargoGlobal _veh;
	clearItemCargoGlobal _veh;
	
	playerVehicles pushBack _veh;
	utilitySmallVehicles pushBack _veh;
	
	LogV = LogV - 2;
	LogM = LogM - 50;
	LogF = LogF - 200;

} else {
	["Headquarters", "You do not have the logistical supplies to field this vehicle."] remoteExec ["FF7_fnc_formatHint", ID, false];
};