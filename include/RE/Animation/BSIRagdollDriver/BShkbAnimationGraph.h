#pragma once

#include "RE/Animation/BSIRagdollDriver/BSIRagdollDriver.h"
#include "RE/BSCore/BSFixedString.h"
#include "RE/BSCore/BSTArray.h"
#include "RE/BSCore/BSTEvent.h"
#include "RE/BSCore/BSTSmartPointer.h"
#include "RE/BSHavok/hkBaseObject/hkReferencedObject/hkbCharacter.h"
#include "RE/BSSystem/BSIntrusiveRefCounted.h"


namespace RE
{
	class bhkWorld;
	class BSFadeNode;
	class BShkFloatController;
	class BSTransformDeltaEvent;
	class hkbBehaviorGraph;
	struct BSAnimationGraphEvent;


	namespace BSResource
	{
		struct ID;
	}


	BSSmartPointer(BShkbAnimationGraph);


	class BShkbAnimationGraph :
		public BSIRagdollDriver,					   // 000
		public BSIntrusiveRefCounted,				   // 008
		public BSTEventSource<BSTransformDeltaEvent>,  // 010
		public BSTEventSource<BSAnimationGraphEvent>   // 068
	{
	public:
		inline static constexpr auto RTTI = RTTI_BShkbAnimationGraph;


		virtual ~BShkbAnimationGraph();	 // 00

		// override (BSIRagdollDriver)
		virtual void Unk_01(void) override;					// 01
		virtual void Unk_02(void) override;					// 02
		virtual void Unk_03(void) override;					// 03
		virtual void SetWorld(bhkWorld* a_world) override;	// 04 - { world = a_world; }
		virtual void Unk_05(void) override;					// 05
		virtual void Unk_06(void) override;					// 06
		virtual void Unk_07(void) override;					// 07
		virtual void Unk_08(void) override;					// 08
		virtual void Unk_09(void) override;					// 09
		virtual void Unk_0A(void) override;					// 0A
		virtual void Unk_0B(void) override;					// 0B
		virtual void Unk_0C(void) override;					// 0C
		virtual void Unk_0D(void) override;					// 0D

		template <class T>
		[[nodiscard]] inline BSTEventSource<T>* GetEventSource()
		{
			return static_cast<BSTEventSource<T>*>(this);
		}

		template <class T>
		inline void AddEventSink(BSTEventSink<T>* a_eventSink)
		{
			GetEventSource<T>()->AddEventSink(a_eventSink);
		}

		template <class T>
		inline void RemoveEventSink(BSTEventSink<T>* a_eventSink)
		{
			GetEventSource<T>()->RemoveEventSink(a_eventSink);
		}


		// members
		hkbCharacter				   characterInstance;			 // 0C0
		BSTArray<void*>				   unk160;						 // 160
		BSTArray<BShkFloatController*> unk178;						 // 178
		BSTArray<void*>				   unk190;						 // 190
		BSTSmallArray<void*>		   unk1A8;						 // 1A8
		BSTSmallArray<UInt8>		   unk1C0;						 // 1C0
		UInt64						   unk1D8;						 // 1D8
		UInt64						   unk1E0;						 // 1E0
		float						   interpolationTimeOffsets[2];	 // 1E8
		BSFixedString				   projectName;					 // 1F0
		BSResource::ID*				   unk1F8;						 // 1F8
		void*						   unk200;						 // 200 - BShkbHkxDB::ProjectDBData*
		hkbBehaviorGraph*			   behaviourGraph;				 // 208
		UInt64						   unk210;						 // 210
		BSFadeNode*					   unk218;						 // 218
		UInt64						   unk220;						 // 220
		UInt64						   unk228;						 // 228
		UInt64						   unk230;						 // 230
		bhkWorld*					   physicsWorld;				 // 238
		UInt32						   unk240;						 // 240
		UInt16						   unk244;						 // 244
		UInt8						   unk246;						 // 246
		UInt8						   unk247;						 // 247
		UInt16						   unk248;						 // 248
		UInt16						   unk24A;						 // 24A
		UInt32						   unk24C;						 // 24C
	};
	STATIC_ASSERT(sizeof(BShkbAnimationGraph) == 0x250);
}
