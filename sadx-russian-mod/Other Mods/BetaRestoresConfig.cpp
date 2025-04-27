#include "stdafx.h"
#include "BetaRestoresConfig.h"
#include "..\LoadedMods.h"
#include "IniFile.hpp"

bool BetaRestoresConfig::BigBetaHotel;

void BetaRestoresConfig::Read(const HelperFunctions& helperFunctions)
{
	if (LoadedMods::BetaRestores == nullptr) return;

	auto betaRestoresMod = helperFunctions.Mods->find_by_dll(LoadedMods::BetaRestores);
	IniFile betaRestoresConfig(std::string(betaRestoresMod->Folder) + "\\config.ini");

	BigBetaHotel = betaRestoresConfig.getBool("Options1", "BigBetaHotel", false);
}