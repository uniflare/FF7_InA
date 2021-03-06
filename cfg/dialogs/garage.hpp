class InA_Garage_Dialog
{
	idd = 9999;
	movingenable = false;
	
	class controls
	{
		class InA_Garage_Background_Army: RscFrame
		{
			idc = -1;
			x = 0.324371 * safezoneW + safezoneX;
			y = 0.313017 * safezoneH + safezoneY;
			w = 0.320265 * safezoneW;
			h = 0.351968 * safezoneH;
			type = CT_STATIC;
			style = ST_CENTER;
			colorBackground[] = {0.25,0.25,0.25,0.6};
		};
		class InA_Garage_HeaderFrame_Army: RscFrame
		{
			idc = -1;
			x = 0.324371 * safezoneW + safezoneX;
			y = 0.291019 * safezoneH + safezoneY;
			w = 0.320265 * safezoneW;
			h = 0.021998 * safezoneH;
			type = CT_STATIC;
			style = ST_CENTER;
			colorBackground[] = {0,0.5,1,0.8};
		};
		class InA_Garage_Listbox_1_Army: RscListbox
		{
			idc = 1500;
			x = 0.345033 * safezoneW + safezoneX;
			y = 0.379011 * safezoneH + safezoneY;
			w = 0.196292 * safezoneW;
			h = 0.175984 * safezoneH;
			colorBackground[] = {0,0,0,0.8};
			onLBSelChanged = "[lbCurSel 1500] call garageResources;";
		};
		class InA_Garage_Frame_1_Army: RscFrame
		{
			idc = -1;
			x = 0.551656 * safezoneW + safezoneX;
			y = 0.379011 * safezoneH + safezoneY;
			w = 0.072318 * safezoneW;
			h = 0.065994 * safezoneH;
			type = CT_STATIC;
			style = ST_CENTER;
			colorBackground[] = {0,0,0,0.8};
		};
		class InA_Garage_Frame_2_Army: RscFrame
		{
			idc = -1;
			x = 0.551656 * safezoneW + safezoneX;
			y = 0.489001 * safezoneH + safezoneY;
			w = 0.072318 * safezoneW;
			h = 0.065994 * safezoneH;
			type = CT_STATIC;
			style = ST_CENTER;
			colorBackground[] = {0,0,0,0.8};
		};
		class InA_Garage_Subheader_1: RscFrame
		{
			idc = -1;
			x = 0.551656 * safezoneW + safezoneX;
			y = 0.357013 * safezoneH + safezoneY;
			w = 0.072318 * safezoneW;
			h = 0.021998 * safezoneH;
			type = CT_STATIC;
			style = ST_CENTER;
			colorBackground[] = {0,0.5,1,0.8};
		};
		class InA_Garage_Subheader_2: RscFrame
		{
			idc = -1;
			x = 0.551656 * safezoneW + safezoneX;
			y = 0.467003 * safezoneH + safezoneY;
			w = 0.072318 * safezoneW;
			h = 0.021998 * safezoneH;
			type = CT_STATIC;
			style = ST_CENTER;
			colorBackground[] = {0,0.5,1,0.8};
		};
		class InA_Garage_Subheader_3: RscFrame
		{
			idc = -1;
			x = 0.345033 * safezoneW + safezoneX;
			y = 0.357013 * safezoneH + safezoneY;
			w = 0.196292 * safezoneW;
			h = 0.021998 * safezoneH;
			type = CT_STATIC;
			style = ST_CENTER;
			colorBackground[] = {0,0.5,1,0.8};
		};
		class InA_Garage_HeaderText: RscText
		{
			idc = -1;
			text = "Vehicle Menu";
			x = 0.324371 * safezoneW + safezoneX;
			y = 0.291019 * safezoneH + safezoneY;
			w = 0.0516557 * safezoneW;
			h = 0.021998 * safezoneH;
		};
		class InA_Garage_SubheaderText_1: RscText
		{
			idc = -1;
			text = "Cost";
			x = 0.551656 * safezoneW + safezoneX;
			y = 0.357013 * safezoneH + safezoneY;
			w = 0.0206623 * safezoneW;
			h = 0.021998 * safezoneH;
		};
		class InA_Garage_SubheaderText_2: RscText
		{
			idc = -1;
			text = "Stockpile";
			x = 0.551656 * safezoneW + safezoneX;
			y = 0.467003 * safezoneH + safezoneY;
			w = 0.0413246 * safezoneW;
			h = 0.021998 * safezoneH;
		};
		class InA_Garage_Button_1: RscButton
		{
			idc = 1600;
			text = "Requisition";
			x = 0.448344 * safezoneW + safezoneX;
			y = 0.576993 * safezoneH + safezoneY;
			w = 0.0516557 * safezoneW;
			h = 0.043996 * safezoneH;
			colorBackground[] = {0,0,0,0.8};
			action = "[lbCurSel 1500] call garageHandler;[]execVM 'defines\Vehicles\resourceUpdate.sqf';";
		};
		class InA_Garage_Button_2: RscButton
		{
			idc = 1601;
			text = "Close";
			x = 0.386357 * safezoneW + safezoneX;
			y = 0.576993 * safezoneH + safezoneY;
			w = 0.0516557 * safezoneW;
			h = 0.043996 * safezoneH;
			colorBackground[] = {0,0,0,0.8};
			action = "closeDialog 0";
		};
		class InA_Garage_InputText_1: RscText
		{
			idc = 1000;
			text = "0";
			x = 0.551656 * safezoneW + safezoneX;
			y = 0.379011 * safezoneH + safezoneY;
			w = 0.0206623 * safezoneW;
			h = 0.021998 * safezoneH;
		};
		class InA_Garage_InputText_2: RscText
		{
			idc = 1001;
			text = "0";
			x = 0.551656 * safezoneW + safezoneX;
			y = 0.401009 * safezoneH + safezoneY;
			w = 0.0206623 * safezoneW;
			h = 0.021998 * safezoneH;
		};
		class InA_Garage_InputText_3: RscText
		{
			idc = 1002;
			text = "0";
			x = 0.551656 * safezoneW + safezoneX;
			y = 0.423007 * safezoneH + safezoneY;
			w = 0.0206623 * safezoneW;
			h = 0.021998 * safezoneH;
		};
		class InA_Garage_InputText_4: RscText
		{
			idc = 1003;
			text = "0";
			x = 0.551656 * safezoneW + safezoneX;
			y = 0.489001 * safezoneH + safezoneY;
			w = 0.0206623 * safezoneW;
			h = 0.021998 * safezoneH;
		};
		class InA_Garage_InputText_5: RscText
		{
			idc = 1004;
			text = "0";
			x = 0.551656 * safezoneW + safezoneX;
			y = 0.510999 * safezoneH + safezoneY;
			w = 0.0206623 * safezoneW;
			h = 0.021998 * safezoneH;
		};
		class InA_Garage_InputText_6: RscText
		{
			idc = 1005;
			text = "0";
			x = 0.551656 * safezoneW + safezoneX;
			y = 0.532997 * safezoneH + safezoneY;
			w = 0.0206623 * safezoneW;
			h = 0.021998 * safezoneH;
		};
		class InA_Garage_Text_1: RscText
		{
			idc = -1;
			text = "Logistics";
			x = 0.582649 * safezoneW + safezoneX;
			y = 0.379011 * safezoneH + safezoneY;
			w = 0.0413246 * safezoneW;
			h = 0.021998 * safezoneH;
		};
		class InA_Garage_Text_3: RscText
		{
			idc = -1;
			text = "Supplies";
			x = 0.582649 * safezoneW + safezoneX;
			y = 0.423007 * safezoneH + safezoneY;
			w = 0.0413246 * safezoneW;
			h = 0.021998 * safezoneH;
		};
		class InA_Garage_Text_2: RscText
		{
			idc = -1;
			text = "Fuel";
			x = 0.582649 * safezoneW + safezoneX;
			y = 0.401009 * safezoneH + safezoneY;
			w = 0.0413246 * safezoneW;
			h = 0.021998 * safezoneH;
		};
		class InA_Garage_Text_4: RscText
		{
			idc = -1;
			text = "Logistics";
			x = 0.582649 * safezoneW + safezoneX;
			y = 0.489001 * safezoneH + safezoneY;
			w = 0.0413246 * safezoneW;
			h = 0.021998 * safezoneH;
		};
		class InA_Garage_Text_6: RscText
		{
			idc = -1;
			text = "Supplies";
			x = 0.582649 * safezoneW + safezoneX;
			y = 0.532997 * safezoneH + safezoneY;
			w = 0.0413246 * safezoneW;
			h = 0.021998 * safezoneH;
		};
		class InA_Garage_Text_5: RscText
		{
			idc = -1;
			text = "Fuel";
			x = 0.582649 * safezoneW + safezoneX;
			y = 0.510999 * safezoneH + safezoneY;
			w = 0.0413246 * safezoneW;
			h = 0.021998 * safezoneH;
		};
	};
};