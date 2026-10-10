#include "game/Peds/CPlayerPed.h"
// Force compilation of the public isolated caller wrappers and auxiliary transcription.
auto rangeApi=&reiv::game::CPlayerPed::ActInRangeIsolated;
auto requestApi=&reiv::game::CPlayerPed::RequestActionIsolated;
auto selectionApi=&reiv::game::player_action_selection::Select;
auto eitherApi=&reiv::game::CPlayerPed::TestEitherPredicate;
auto pairFirstApi=&reiv::game::CPlayerPed::DispatchPairFirstRaw;
auto pairSecondApi=&reiv::game::CPlayerPed::DispatchPairSecondRaw;
auto relatedApi=&reiv::game::CPlayerPed::DispatchRelatedRaw;
auto allowedApi=&reiv::game::CPlayerPed::TestActionAllowed;
auto relatedFlagsApi=&reiv::game::CPlayerPed::UpdateRelatedFlagsRaw;
