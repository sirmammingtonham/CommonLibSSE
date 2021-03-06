#pragma once

#include "RE/BSExtraData/BSExtraData.h"
#include "RE/BSExtraData/Enums/ExtraDataTypes.h"
#include "RE/NetImmerse/NiSmartPointer.h"


namespace RE
{
	class BSMultiBoundRoom;


	class ExtraRoom : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraRoom;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kRoom;


		virtual ~ExtraRoom();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kRoom; }


		// members
		NiPointer<BSMultiBoundRoom> room;  // 10
	};
	STATIC_ASSERT(sizeof(ExtraRoom) == 0x18);
}
