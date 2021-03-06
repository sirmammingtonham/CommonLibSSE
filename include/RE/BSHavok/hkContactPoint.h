#pragma once

#include "RE/BSHavok/hkVector4.h"


namespace RE
{
	class hkContactPoint
	{
	public:
		hkVector4 position;			 // 00
		hkVector4 separatingNormal;	 // 10
	};
	STATIC_ASSERT(sizeof(hkContactPoint) == 0x20);
}
