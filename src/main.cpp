#include <Geode/Geode.hpp>
#include <Geode/modify/GameStatsManager.hpp>

using namespace geode::prelude;

// Practice Music Sync (the option that plays the level's real song in
// practice mode) is only gated behind the "Music Unlocker" shop item,
// which is GJItem #17. Reporting it as unlocked opens up the toggle in the
// pause menu's options, the toggle's logic, and the in-level sync.
class $modify(PracticeSyncStats, GameStatsManager) {
	bool isItemUnlocked(UnlockType type, int id) {
		if (type == UnlockType::GJItem && id == 17) {
			return true;
		}
		return GameStatsManager::isItemUnlocked(type, id);
	}
};

$on_mod(Loaded) {
	log::info("Practice Music Sync Unlocker loaded");
}
