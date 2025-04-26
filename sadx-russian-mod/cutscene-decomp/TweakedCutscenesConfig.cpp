#include "stdafx.h"
#include "TweakedCutscenesConfig.h"
#include "..\LoadedMods.h"
#include "IniFile.hpp"


// я хз, что именно из всего этого тебе реально нужно и когда, поэтому выпишу все и сделаю статическими

bool TweakedCutscenesConfig::TenseCrashMusic;
bool TweakedCutscenesConfig::MuffledAmy;
bool TweakedCutscenesConfig::SkipSecondJump;
bool TweakedCutscenesConfig::RemoveOutroRun;
bool TweakedCutscenesConfig::KnucklesWalk;
bool TweakedCutscenesConfig::BetaDash;
bool TweakedCutscenesConfig::CrazyRobo;
bool TweakedCutscenesConfig::WorriedTails;


void TweakedCutscenesConfig::Read(const HelperFunctions& helperFunctions)
{
	if (LoadedMods::TweakedCutscenes == nullptr) return; // эту строчку можно убрать, если функция будет явно вызываться после проверки того, что сам мод загружен, как я сделал сейчас (см. ModConfig.cpp)
	
	auto tweakedCutscenes = helperFunctions.Mods->find("sadx.tweaked-cutscenes");
	IniFile tweakedCutscenesConfig(std::string(tweakedCutscenes->Folder) + "\\config.ini");

	TenseCrashMusic = tweakedCutscenesConfig.getBool("", "tenseCrashMusic", false);
	MuffledAmy = tweakedCutscenesConfig.getBool("", "muffledAmy", true);
	SkipSecondJump = tweakedCutscenesConfig.getBool("", "skipSecondJump", true);
	RemoveOutroRun = tweakedCutscenesConfig.getBool("", "removeOutroRun", false);
	KnucklesWalk = tweakedCutscenesConfig.getBool("", "knucklesWalk", true);
	BetaDash = tweakedCutscenesConfig.getBool("", "betaDash", false);
	CrazyRobo = tweakedCutscenesConfig.getBool("", "crazyRobo", false);
	WorriedTails = tweakedCutscenesConfig.getBool("", "worriedTails", false);
}