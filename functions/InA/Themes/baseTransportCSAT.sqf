private ["_array","_veh", "_group"];

if !(initialized) then {
	initialized = true;
};

baseType = "CSAT";
publicVariable "baseType";
supplier = "BLU";
publicVariable "supplier";
LogV = 4;
LogM = 150 + (5 * (count (call BIS_fnc_listPlayers)));
LogF = 400;

["HQ", "Headquarters", "Base Theme Selected."] remoteExec ["FF7_fnc_globalHintStruct", 0];

// ---------- GEAR BASICS ----------

call compile preprocessFileLineNumbers "functions\InA\Gear\gearWipe.sqf";

// ---------- Base defence ----------
