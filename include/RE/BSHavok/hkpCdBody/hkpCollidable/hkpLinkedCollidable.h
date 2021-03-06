#pragma once

#include "RE/BSHavok/hkArray.h"
#include "RE/BSHavok/hkpCdBody/hkpCollidable/hkpCollidable.h"


namespace RE
{
	struct hkpAgentNnEntry;


	class hkpLinkedCollidable : public hkpCollidable
	{
	public:
		struct CollisionEntry
		{
		public:
			// members
			hkpAgentNnEntry*	 agentEntry;  // 00
			hkpLinkedCollidable* partner;	  // 08
		};
		STATIC_ASSERT(sizeof(CollisionEntry) == 0x10);


		// members
		hkArray<CollisionEntry> collisionEntries;  // 70
	};
	STATIC_ASSERT(sizeof(hkpLinkedCollidable) == 0x80);
}
