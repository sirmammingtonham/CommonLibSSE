#pragma once

#include "RE/BSHavok/Enums/hkpPhantomType.h"
#include "RE/BSHavok/hkArray.h"
#include "RE/BSHavok/hkBaseObject/hkReferencedObject/hkpWorldObject/hkpWorldObject.h"


namespace RE
{
	class hkAabb;
	class hkpCollidable;
	class hkpPhantomListener;
	class hkpPhantomOverlapListener;


	class hkpPhantom : public hkpWorldObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_hkpPhantom;


		virtual ~hkpPhantom();	// 00

		// override (hkpWorldObject)
		virtual void CalcContentStatistics(hkStatisticsCollector* a_collector, const hkClass* a_class) const override;	// 02

		// add
		virtual hkpPhantomType GetType() const = 0;													 // 06
		virtual void		   CalcAabb(hkAabb& a_aabb) = 0;										 // 07
		virtual void		   AddOverlappingCollidable(hkpCollidable* a_collidable) = 0;			 // 08
		virtual bool		   IsOverlappingCollidableAdded(const hkpCollidable* a_collidable) = 0;	 // 09
		virtual void		   RemoveOverlappingCollidable(hkpCollidable* a_collidable) = 0;		 // 0A
		virtual void		   EnsureDeterministicOrder() = 0;										 // 0B
		virtual hkpPhantom*	   Clone() const = 0;													 // 0C
		virtual void		   UpdateShapeCollectionFilter();										 // 0D - { return; }
		virtual void		   DeallocateInternalArrays();											 // 0E


		// members
		hkArray<hkpPhantomOverlapListener*> overlapListeners;  // D0
		hkArray<hkpPhantomListener*>		phantomListeners;  // E0
	};
	STATIC_ASSERT(sizeof(hkpPhantom) == 0xF0);
}
