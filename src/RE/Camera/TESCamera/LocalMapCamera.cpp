#include "RE/Camera/TESCamera/LocalMapCamera.h"

#include "RE/BSMain/SettingCollection/INISettingCollection.h"
#include "RE/NetImmerse/NiRefObject/NiObject/NiObjectNET/NiAVObject/NiCamera.h"


namespace RE
{
	LocalMapCamera::LocalMapCamera(float a_zRotation)
	{
		Ctor(a_zRotation);
	}


	void LocalMapCamera::SetAreaBounds(NiPoint3& a_maxExtent, NiPoint3& a_minExtent)
	{
		auto ini = INISettingCollection::GetSingleton();
		auto fMapLocalHeight = ini ? ini->GetSetting("fMapLocalHeight:MapMenu") : nullptr;

		minExtent = a_minExtent;
		maxExtent = a_maxExtent;
		maxExtent.z += fMapLocalHeight ? fMapLocalHeight->GetFloat() : 0.0;
	}


	void LocalMapCamera::SetDefaultStateInitialPosition(NiPoint3& a_position)
	{
		auto ini = INISettingCollection::GetSingleton();
		auto fMapLocalHeight = ini ? ini->GetSetting("fMapLocalHeight:MapMenu") : nullptr;

		defaultState->initialPosition = a_position;
		defaultState->initialPosition.z += fMapLocalHeight ? fMapLocalHeight->GetFloat() : 0.0;
	}


	void LocalMapCamera::SetDefaultStateMinFrustumDimensions(float a_width, float a_height)
	{
		defaultState->minFrustumHalfWidth = a_width / 2.0F;
		defaultState->minFrustumHalfHeight = a_height / 2.0F;
	}


	void LocalMapCamera::SetDefaultStateTranslation(float a_x, float a_y, float a_z)
	{
		defaultState->translation.x = a_x - defaultState->initialPosition.x;
		defaultState->translation.y = a_y - defaultState->initialPosition.y;
		defaultState->translation.z = a_z - defaultState->initialPosition.z;
	}


	void LocalMapCamera::SetNorthRotation(float a_northRotation)
	{
		using func_t = decltype(&LocalMapCamera::SetNorthRotation);
		REL::Offset<func_t> func(Offset::LocalMapCamera::SetNorthRotation);
		return func(this, a_northRotation);
	}


	LocalMapCamera* LocalMapCamera::Ctor(float a_zRotation)
	{
		using func_t = decltype(&LocalMapCamera::Ctor);
		REL::Offset<func_t> func(Offset::LocalMapCamera::Ctor);
		return func(this, a_zRotation);
	}
}
