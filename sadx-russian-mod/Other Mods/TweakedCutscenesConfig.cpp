#include "stdafx.h"
#include "TweakedCutscenesConfig.h"
#include "..\LoadedMods.h"
#include "IniFile.hpp"

bool TweakedCutscenesConfig::SkipSecondJump;
bool TweakedCutscenesConfig::BetaDash;

void TweakedCutscenesConfig::Read(const HelperFunctions& helperFunctions)
{
	if (LoadedMods::TweakedCutscenes == nullptr) return; // эту строчку можно убрать, если функция будет явно вызываться после проверки того, что сам мод загружен, как я сделал сейчас (см. ModConfig.cpp)
	
	auto tweakedCutscenes = helperFunctions.Mods->find("sadx.tweaked-cutscenes");
	IniFile tweakedCutscenesConfig(std::string(tweakedCutscenes->Folder) + "\\config.ini");

	SkipSecondJump = tweakedCutscenesConfig.getBool("", "skipSecondJump", true);
	BetaDash = tweakedCutscenesConfig.getBool("", "betaDash", false);
}