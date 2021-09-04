class CfgPatches
{
	class CFToolsExtraLogging
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={
			"DZ_Data",
			"GameLabs_Scripts"
		};
	};
};

class CfgMods
{
	class HH_CFTools
	{
		dir="CFToolsExtraLogging";
		name="CFTools Extra Logging";
		author="@Lewk_io";
		version="0.1";
		extra=0;
		type="mod";
		dependencies[]={"Game", "World", "Mission"};
		class defs {
			class gameScriptModule {
				value="";
				files[]={"CFToolsExtraLogging/Scripts/3_Game"};
			};
			class worldScriptModule {
				value="";
				files[]={"CFToolsExtraLogging/Scripts/4_World"};
			};
			class missionScriptModule {
				value="";
				files[]={"CFToolsExtraLogging/Scripts/5_Mission"};
			};
		};
	};
};