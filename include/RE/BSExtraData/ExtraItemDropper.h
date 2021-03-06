#pragma once

#include "RE/BSCore/BSPointerHandle.h"
#include "RE/BSExtraData/BSExtraData.h"
#include "RE/BSExtraData/Enums/ExtraDataTypes.h"


namespace RE
{
	class ExtraItemDropper : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraItemDropper;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kItemDropper;


		virtual ~ExtraItemDropper();  // 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kItemDropper; }


		// members
		ObjectRefHandle dropper;  // 10
		UInt32			pad14;	  // 14
	};
	STATIC_ASSERT(sizeof(ExtraItemDropper) == 0x18);
}
