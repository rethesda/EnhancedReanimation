#pragma once

class Settings : public REX::TSingleton<Settings>
{
public:
	void Load()
	{
		const auto store = REX::FIniSettingStore::GetSingleton();
		store->Init(path.data(), "");

		store->Load();
		store->Save();
	}

	// members
	static constexpr auto path = R"(Data\SKSE\Plugins\po3_EnhancedReanimation.ini)"sv;

	REX::TIniSetting<bool> fastTravel{ "Settings", "bFixFastTravel", true };
	REX::TIniSetting<bool> npcCombat{ "Settings", "bReanimatedNecromancersCanCast", true };
	REX::TIniSetting<bool> decapitateCheck{ "Settings", "bReanimateDecapitatedNPCs", true };

	REX::TIniSetting<bool> rideHorse{ "Riding", "bRideReanimatedMounts", true };
	REX::TIniSetting<bool> patchHorse{ "Riding", "bPatchSpellsForMounts", true };
};
