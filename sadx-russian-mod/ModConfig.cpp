#include "stdafx.h"
#include "SADXModLoader.h"
#include <IniFile.hpp>
#include "Funcs.h"

void SetConfigFile(const char* path, const HelperFunctions& helperFunctions)
{
	std::string TGS_Selectors = "Vanilla";
	std::string DreamcastChaoIcon = "DX";
	std::string StartButton = "Start";
	bool ExtraGGHelp = false;
	std::string StageBorder = "US";

	char pathbuf[MAX_PATH];
	HMODULE DConv = GetModuleHandle(L"DCMods_Main");			// Init Dreamcast Conversion dll	
	
	#pragma region Ini Configuration
	const IniFile* config = new IniFile(std::string(path) + "\\config.ini");

	TGS_Selectors = config->getString("Customs", "TGS_Selectors", "Vanilla");
	StartButton = config->getString("Customs", "StartButton", "Start");	
	StageBorder = config->getString("Customs", "StageBorder", "US");

	DreamcastChaoIcon = config->getString("Customs", "DreamcastChaoIcon", "DX");
	ExtraGGHelp = config->getBool("Extra", "ExtraGGHelp", false);
	
	// TGS
	if (TGS_Selectors == "TGS") {
		ReplacePVM("B_CHNAM_E", "B_CHNAM_E_TGS");
		ReplacePVM("AVA_METAL_SONIC", "AVA_METAL_SONIC_TGS");
	}
	else if (TGS_Selectors == "Vanilla") {
		ReplacePVM("B_CHNAM_E", "B_CHNAM_E_HD");
		ReplacePVM("AVA_METAL_SONIC", "AVA_METAL_SONIC_DX");
	}

	// Start Button Prompt
	if (StartButton == "Enter") {
		if (DConv != nullptr)
			ReplacePVM("PRESSSTART", "PRESSSTART_ENTER");
		else
			ReplacePVM("PRESSSTART", "PRESSSTART_DX_Enter_HD_RUS");

		ReplacePVM("AVA_GTITLE0_E", "AVA_GTITLE0_E_HD_ENTER");
		ReplacePVM("AVA_GTITLE0_DC_HD", "AVA_GTITLE0_DC_HD_ENTER");
	}
	else if (StartButton == "Start") {
		if (DConv != nullptr)
			ReplacePVM("PRESSSTART", "PRESSSTART_Start");
		else
			ReplacePVM("PRESSSTART", "PRESSSTART_DX_START_HD_RUS");

		ReplacePVM("AVA_GTITLE0_E", "AVA_GTITLE0_E_HD_START");
		ReplacePVM("AVA_GTITLE0_DC_HD", "AVA_GTITLE0_DC_HD_START");
	}
	
	// Stage Border Variations
	#pragma region Stages name PVRs
	if (StageBorder == "US") {
		ReplacePNG_StageE("A_STAGE01_E");			// Amy		| Twinkle Park
		ReplacePNG_StageE("A_STAGE02_E");			// Amy		| Hot Shelter
		ReplacePNG_StageE("A_STAGE03_E");			// Amy		| Final Egg
		ReplacePNG_StageE("B_STAGE01_E");			// Big		| Twinkle Park
		ReplacePNG_StageE("B_STAGE02_E");			// Big		| Icecap
		ReplacePNG_StageE("B_STAGE03_E");			// Big		| Emerald Coast
		ReplacePNG_StageE("B_STAGE04_E");			// Big		| Hot Shelter
		ReplacePNG_StageE("E_STAGE01_E");			// E102		| Final Egg
		ReplacePNG_StageE("E_STAGE02_E");			// E102		| Emerald Coast
		ReplacePNG_StageE("E_STAGE03_E");			// E102		| Windy Valley
		ReplacePNG_StageE("E_STAGE04_E");			// E102		| Red Mountain
		ReplacePNG_StageE("E_STAGE05_E");			// E102		| Hot Shelter
		ReplacePNG_StageE("K_STAGE01_E");			// Knuckles	| Speed Highway
		ReplacePNG_StageE("K_STAGE02_E");			// Knuckles	| Casinopolis
		ReplacePNG_StageE("K_STAGE03_E");			// Knuckles	| Red Mountain
		ReplacePNG_StageE("K_STAGE04_E");			// Knuckles	| Lost World
		ReplacePNG_StageE("K_STAGE05_E");			// Knuckles	| Sky Deck
		ReplacePNG_StageE("M_STAGE01_E");			// Tails	| Windy Valley
		ReplacePNG_StageE("M_STAGE02_E");			// Tails	| Casinopolis
		ReplacePNG_StageE("M_STAGE03_E");			// Tails	| Icecap
		ReplacePNG_StageE("M_STAGE04_E");			// Tails	| Sky Deck
		ReplacePNG_StageE("M_STAGE05_E");			// Tails	| Speed Highway
		ReplacePNG_StageE("ST_STAGE01_E");			// Minigame	| Sky Chase 1
		ReplacePNG_StageE("ST_STAGE02_E");			// Minigame	| Sky Chase 2
		ReplacePNG_StageE("ST_STAGE03_E");			// Minigame	| Twinkle Circuit
		ReplacePNG_StageE("ST_STAGE04_E");			// Minigame	| Sans Hill
		ReplacePNG_StageE("ST_STAGE05_E");			// Minigame	| Hedgehog Hammer
		ReplacePNG_StageE("S_STAGE01_E");			// Sonic	| Emerald Coast
		ReplacePNG_StageE("S_STAGE02_E");			// Sonic	| Windy Valley
		ReplacePNG_StageE("S_STAGE03_E");			// Sonic	| Casinopolis
		ReplacePNG_StageE("S_STAGE04_E");			// Sonic	| Icecap
		ReplacePNG_StageE("S_STAGE05_E");			// Sonic	| Twinkle Park
		ReplacePNG_StageE("S_STAGE06_E");			// Sonic	| Speed Highway
		ReplacePNG_StageE("S_STAGE07_E");			// Sonic	| Red Mountain
		ReplacePNG_StageE("S_STAGE08_E");			// Sonic	| Sky Deck
		ReplacePNG_StageE("S_STAGE09_E");			// Sonic	| Lost World
		ReplacePNG_StageE("S_STAGE10_E");			// Sonic	| Final Egg
		ReplacePNG_StageE("T_EGGCARRIER_E");		// Field	| Egg Carrier
		ReplacePNG_StageE("T_MISTICRUIN_E");		// Field	| Mystic Ruins
		ReplacePNG_StageE("T_STATIONSQUARE_E");		// Field	| Station Square
	}

	else if (StageBorder == "JP") {
		ReplacePNG_StageJ("A_STAGE01_E");			// Amy		| Twinkle Park
		ReplacePNG_StageJ("A_STAGE02_E");			// Amy		| Hot Shelter
		ReplacePNG_StageJ("A_STAGE03_E");			// Amy		| Final Egg
		ReplacePNG_StageJ("B_STAGE01_E");			// Big		| Twinkle Park
		ReplacePNG_StageJ("B_STAGE02_E");			// Big		| Icecap
		ReplacePNG_StageJ("B_STAGE03_E");			// Big		| Emerald Coast
		ReplacePNG_StageJ("B_STAGE04_E");			// Big		| Hot Shelter
		ReplacePNG_StageJ("E_STAGE01_E");			// E102		| Final Egg
		ReplacePNG_StageJ("E_STAGE02_E");			// E102		| Emerald Coast
		ReplacePNG_StageJ("E_STAGE03_E");			// E102		| Windy Valley
		ReplacePNG_StageJ("E_STAGE04_E");			// E102		| Red Mountain
		ReplacePNG_StageJ("E_STAGE05_E");			// E102		| Hot Shelter
		ReplacePNG_StageJ("K_STAGE01_E");			// Knuckles	| Speed Highway
		ReplacePNG_StageJ("K_STAGE02_E");			// Knuckles	| Casinopolis
		ReplacePNG_StageJ("K_STAGE03_E");			// Knuckles	| Red Mountain
		ReplacePNG_StageJ("K_STAGE04_E");			// Knuckles	| Lost World
		ReplacePNG_StageJ("K_STAGE05_E");			// Knuckles	| Sky Deck
		ReplacePNG_StageJ("M_STAGE01_E");			// Tails	| Windy Valley
		ReplacePNG_StageJ("M_STAGE02_E");			// Tails	| Casinopolis
		ReplacePNG_StageJ("M_STAGE03_E");			// Tails	| Icecap
		ReplacePNG_StageJ("M_STAGE04_E");			// Tails	| Sky Deck
		ReplacePNG_StageJ("M_STAGE05_E");			// Tails	| Speed Highway
		ReplacePNG_StageJ("ST_STAGE01_E");			// Minigame	| Sky Chase 1
		ReplacePNG_StageJ("ST_STAGE02_E");			// Minigame	| Sky Chase 2
		ReplacePNG_StageJ("ST_STAGE03_E");			// Minigame	| Twinkle Circuit
		ReplacePNG_StageJ("ST_STAGE04_E");			// Minigame	| Sans Hill
		ReplacePNG_StageJ("ST_STAGE05_E");			// Minigame	| Hedgehog Hammer
		ReplacePNG_StageJ("S_STAGE01_E");			// Sonic	| Emerald Coast
		ReplacePNG_StageJ("S_STAGE02_E");			// Sonic	| Windy Valley
		ReplacePNG_StageJ("S_STAGE03_E");			// Sonic	| Casinopolis
		ReplacePNG_StageJ("S_STAGE04_E");			// Sonic	| Icecap
		ReplacePNG_StageJ("S_STAGE05_E");			// Sonic	| Twinkle Park
		ReplacePNG_StageJ("S_STAGE06_E");			// Sonic	| Speed Highway
		ReplacePNG_StageJ("S_STAGE07_E");			// Sonic	| Red Mountain
		ReplacePNG_StageJ("S_STAGE08_E");			// Sonic	| Sky Deck
		ReplacePNG_StageJ("S_STAGE09_E");			// Sonic	| Lost World
		ReplacePNG_StageJ("S_STAGE10_E");			// Sonic	| Final Egg
		ReplacePNG_StageJ("T_EGGCARRIER_E");		// Field	| Egg Carrier
		ReplacePNG_StageJ("T_MISTICRUIN_E");		// Field	| Mystic Ruins
		ReplacePNG_StageJ("T_STATIONSQUARE_E");		// Field	| Station Square
	}
	#pragma endregion

	// Chao Garden Icon
	if (DreamcastChaoIcon == "DC")
	{
		ReplacePVM("CHAO_OBJECT", "CHAO_OBJECT_DC");
		ReplacePVM("AL_DX_OBJ_CMN", "AL_DX_OBJ_CMN_DC");
	}
	else if (DreamcastChaoIcon == "DX") {
		ReplacePVM("CHAO_OBJECT", "CHAO_OBJECT_DX");
		ReplacePVM("AL_DX_OBJ_CMN", "AL_DX_OBJ_CMN_DX");
	}

	// Alternative GG Game help
	if (!ExtraGGHelp) {
		ReplacePVM("GG_TEXLIST_FR", "GG_TEXLIST_FR_Rus");
	}
	else {
		ReplacePVM("GG_TEXLIST_FR", "GG_TEXLIST_FR_Rus_Alt");
	}

#pragma endregion
}