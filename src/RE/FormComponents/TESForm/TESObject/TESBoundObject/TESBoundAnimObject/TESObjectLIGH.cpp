#include "RE/FormComponents/TESForm/TESObject/TESBoundObject/TESBoundAnimObject/TESObjectLIGH.h"


namespace RE
{
	bool TESObjectLIGH::CanBeCarried() const
	{
		return (data.flags & TES_LIGHT_FLAGS::kCanCarry) != TES_LIGHT_FLAGS::kNone;
	}
}
