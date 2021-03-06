#pragma once

#include "RE/FormComponents/TESModel/TESModel.h"


namespace RE
{
	class TESModelPSA : public TESModel
	{
	public:
		inline static constexpr auto RTTI = RTTI_TESModelPSA;


		virtual ~TESModelPSA();	 // 00
	};
	STATIC_ASSERT(sizeof(TESModelPSA) == 0x28);
}
