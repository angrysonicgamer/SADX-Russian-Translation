﻿#include "stdafx.h"
#include "ModConfig.h"
#include "LoadedMods.h"
#include "CustomSubTimings.h"
#include "ExtraSubs.h"
#include "LoadTextures.h"
#include "IniFile.hpp"
#include <fstream>


// Warning messages

void DisplayMessage(std::wstring message)
{
	MessageBox(NULL, message.c_str(), L"Предупреждение", MB_OK | MB_ICONWARNING | MB_DEFBUTTON2);
}

std::wstring JPVoiceMessage =
	L"Мод принудительно включает японскую озвучку.\n\n"
	L"Это сделано из-за того, что между\n"
	L"японской и английской версией озвучки игры\n"
	L"есть значительные расхождения в некоторых катсценах\n"
	L"(другую реплику произносит другой персонаж).\n\n"
	L"Вы можете отключить эту функцию в настройках\n"
	L"к моду с переводом.\n"
	L"При следующем запуске это сообщение не появится.";

std::wstring CutsceneEditingModsMessage =
	L"У вас включён один из модов, изменяющих катсцены:\n\n"
	L"– Tweaked Cutscenes;\n"
	L"– Cream the Rabbit in SA1 Dreamcast Style;\n"
	L"– Rouge the Bat in SA1 Dreamcast Style.\n\n"
	L"Во избежание конфликтов с этими модами\n"
	L"опция \"Изменённые тайминги субтитров\"\n"
	L"не будет применена.";


// Config reading

std::string Config::TGS_Selectors;
std::string Config::StageTitlesStyle;
std::string Config::BossTitlesStyle;

bool Config::EditedCutsceneTimings;
bool Config::ForceJPVoice;

bool Config::EnableExtraSubtitles;
bool Config::DisableMenuExtraSubs;
bool Config::DisplaySESubtitles;

std::string Config::DreamcastChaoIcon;
std::string Config::AltSonicTeamLogo;
bool Config::AltGGHelp;
bool Config::EnableObjTextures;


void Config::Read(const char* path)
{
	const IniFile* config = new IniFile(std::string(path) + "\\config.ini");

	TGS_Selectors = config->getString("DisplaySettings", "TGS_Selectors", "Vanilla");
	StageTitlesStyle = config->getString("DisplaySettings", "StageBorder", "JP");
	BossTitlesStyle = config->getString("DisplaySettings", "BossFontStyle", "HD GUI");

	EditedCutsceneTimings = config->getBool("SubsAndVoices", "EditedTimings", true);
	ForceJPVoice = config->getBool("SubsAndVoices", "ForcedJapVoices", true);

	EnableExtraSubtitles = config->getBool("ExtraSubtitles", "EnableExtraSubs", true);
	DisableMenuExtraSubs = config->getBool("ExtraSubtitles", "DisableMenuExtraSubs", false);
	DisplaySESubtitles = config->getBool("ExtraSubtitles", "DisplaySESubtitles", false);

	DreamcastChaoIcon = config->getString("Extra", "DreamcastChaoIcon", "DX");	
	AltSonicTeamLogo = config->getString("Extra", "ExtraSonicTeamLogo", "Disable");
	AltGGHelp = config->getBool("Extra", "ExtraGGHelp", false);
	EnableObjTextures = config->getBool("Extra", "EnableObjTextures", false);

	delete config;
}

void InitCustomCutsceneTimings(const char* path, const HelperFunctions& helperFunctions)
{
	std::wstring modpath(path, path + strlen(path));
	std::wstring editedTimings = L"\\edited_timings.ini";	

	if (Config::EditedCutsceneTimings)
	{
		if (LoadedMods::TweakedCutscenes || LoadedMods::Cream || LoadedMods::Rouge)
		{
			DisplayMessage(CutsceneEditingModsMessage);
		}
		else
		{
			helperFunctions.LoadEXEData((modpath + editedTimings).c_str(), modpath.c_str());
			SetCustomCutsceneTimings(path, helperFunctions);
		}
	}
}

/*void InitJPVoiceFlag(const char* path)
{
	// Обработка форса происходит в основном файле мода (mod.cpp), в файле конфига обрабатывается 
	// только вывод сообщения и обработка флаг-файла

	std::string flagPath = "\\jap-voice-flag";

	if (!Config::ForceJPVoice)	// Если опция форса выключена (то есть не форсируется яп)
		remove((path + flagPath).c_str());	// Удалить нахер флаг
	else
	{
		std::ifstream flagFile(path + flagPath);

		// При отсутствии флаг-файла 
		if (!flagFile)
		{
			DisplayMessage(JPVoiceMessage);
			std::ofstream flagFileOut(path + flagPath);	// Создать флаг-файл
			flagFileOut.close();
		}
	}
}*/

void LoadAlternateSonicTeamFMV(const HelperFunctions& helperFunctions)
{
	if (Config::AltSonicTeamLogo == "Black")
	{
		ReplaceFMV("SONICTEAM", "SONICTEAM_Black");
	}		
	else if (Config::AltSonicTeamLogo == "White")
	{
		ReplaceFMV("SONICTEAM", "SONICTEAM_White");
	}		
}


void Config::Init(const char* path, const HelperFunctions& helperFunctions)
{
	Read(path);
	
	//LoadTitleScreenButton(path, helperFunctions);	

	InitCustomCutsceneTimings(path, helperFunctions);
	//InitJPVoiceFlag(path);

	if (AltSonicTeamLogo != "Disable")
	{
		LoadAlternateSonicTeamFMV(helperFunctions);
	}

	if (EnableExtraSubtitles)
	{
		InitExtraSubs();
	}
}