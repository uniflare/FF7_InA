/* ----------
Function: InA_fnc_insLightHeliAttack

Description:
    A function to spawn a helicopter with crew to attack an area

Parameters:
    - Center Location (Position)

Optional:
    - Minimum distance from the center to spawn (Number)
    - Maximum distance from center to place move/guard waypoint (Number)
	- Number to spawn (Number)
	- Time to delay the spawning (Number)

Example:
   
    [[0,0,0], 3000, 250, 1, 0] spawn InA_fnc_insLightHeliAttack

Returns:
    Nil

Author:
    Newsparta
---------- */

// ---------- PARAMETERS ----------

params ["_center",["_min", 3000, [0]], ["_wpMax", 250, [0]], ["_s", 1, [0]], ["_delay", 0, [0]],["_awareness", "SAFE", [""]],["_speed", "LIMITED", [""]]];

// ---------- MAIN ----------
private ["_pos","_heli","_group","_wp"];

sleep _delay;

	for "_x" from 1 to _s do {
		
		_accepted = false;
		while {!_accepted} do {
		
			_pos = [_center, _min, (_min + 250), 3, 0, 20, 0] call BIS_fnc_findSafePos;
	
			_isNear = false;

			{
				if ((_x distance _pos) < 500) then {
					_isNear = true;
				};
			} forEach (allPlayers - entities "HeadlessClient_F");
			
			if !(_isNear) then {
				_accepted = true;
			};
		};
		
		if (count _pos > 2) exitWith {};
		_heli = objNull;
		if (supplier == "BLU") then {
			_heli = createVehicle [(selectRandom INS_LIGHT_HELI_AH_BLU), _pos, [], 0, "FLY"];
			[
				_heli,
				INS_LIGHT_HELI_AH_BLU_TEX,
				INS_LIGHT_HELI_AH_BLU_ANI
			] call BIS_fnc_initVehicle;
		} else {
			_heli = createVehicle [(selectRandom INS_LIGHT_HELI_AH_OPF), _pos, [], 0, "FLY"];
			[
				_heli,
				INS_LIGHT_HELI_AH_OPF_TEX,
				INS_LIGHT_HELI_AH_OPF_ANI
			] call BIS_fnc_initVehicle;
		};
		
		_group = [
			_pos,
			INDEPENDENT, 
			[
				(selectRandom INS_INF_SINGLE),
				(selectRandom INS_INF_SINGLE),
				(selectRandom INS_INF_SINGLE),
				(selectRandom INS_INF_SINGLE)
			]
		] call BIS_fnc_spawnGroup;
		((units _group) select 0) moveInAny _heli;
		((units _group) select 1) moveInAny _heli;
		((units _group) select 2) moveInAny _heli;
		((units _group) select 3) moveInAny _heli;
	
		_wp = _group addWaypoint [_center, _wpMax];
		_wp setWaypointType "GUARD";
		_wp setWaypointSpeed _speed;
		_wp setWaypointBehaviour _awareness;
		[units _group] call InA_fnc_insCustomize;
	
		{
			_unit = _x;
			{
				_unit removeMagazines _x;
			} forEach magazines _unit;

			removeBackpackGlobal _x;
			
			removeAllWeapons _x;
			
			if (supplier == "OPF") then {
			
				_choice = INS_MG_OPF call BIS_fnc_selectRandom;
				_x addBackpack (INS_BACKPACKS call BIS_fnc_selectRandom);
				for "_i" from 1 to 6 do {_x addMagazine (_choice select 1);};
				_x addWeapon (_choice select 0);
			} else {
				_choice = INS_MG_BLU call BIS_fnc_selectRandom;
				_x addBackpack (INS_BACKPACKS call BIS_fnc_selectRandom);
				for "_i" from 1 to 6 do {_x addMagazine (_choice select 1);};
				_x addWeapon (_choice select 0);
			};
		} forEach (units _group);
	};