#pragma once

#include "RE/BSExtraData/BSExtraData.h"
#include "RE/BSExtraData/Enums/ExtraDataTypes.h"


namespace RE
{
	class ExtraNorthRotation : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraNorthRotation;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kNorthRotation;


		virtual ~ExtraNorthRotation();	// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	 // 01 - { return kNorthRotation; }


		// members
		float  northRot;  // 10
		UInt32 pad14;	  // 14
	};
	STATIC_ASSERT(sizeof(ExtraNorthRotation) == 0x18);
}
