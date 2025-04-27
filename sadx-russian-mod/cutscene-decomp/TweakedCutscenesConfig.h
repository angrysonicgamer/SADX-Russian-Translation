#pragma once

class TweakedCutscenesConfig
{
public:
	static bool TenseCrashMusic;
	static bool MuffledAmy;
	static bool SkipSecondJump;
	static bool RemoveOutroRun;
	static bool KnucklesWalk;
	static bool BetaDash;
	static bool CrazyRobo;
	static bool WorriedTails;

	static void Read(const HelperFunctions& helperFunctions);
};