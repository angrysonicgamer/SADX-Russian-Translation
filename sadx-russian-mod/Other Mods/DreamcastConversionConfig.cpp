#include "stdafx.h"
#include "DreamcastConversionConfig.h"
#include "..\LoadedMods.h"
#include "IniFile.hpp"

bool DreamcastConversionConfig::EnableStationSquare;

void DreamcastConversionConfig::Read(const HelperFunctions& helperFunctions)
{
	if (LoadedMods::DreamcastConversion == nullptr) return;

	auto dreamcastConversion = helperFunctions.Mods->find("sadx-dreamcast-conversion");
	IniFile dreamcastConversionConfig(std::string(dreamcastConversion->Folder) + "\\config.ini");

	EnableStationSquare = dreamcastConversionConfig.getBool("Levels", "EnableStationSquare", true);
}