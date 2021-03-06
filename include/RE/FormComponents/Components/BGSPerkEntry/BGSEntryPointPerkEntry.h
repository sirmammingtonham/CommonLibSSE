#pragma once

#include "RE/FormComponents/Components/BGSPerkEntry/BGSPerkEntry.h"
#include "RE/FormComponents/Enums/FormTypes.h"
#include "RE/Memory/MemoryManager.h"


namespace RE
{
	class BGSEntryPointFunctionData;
	class TESCondition;


	class BGSEntryPointPerkEntry : public BGSPerkEntry
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSEntryPointPerkEntry;


		struct EntryData  // DATA
		{
		public:
			enum class Function : UInt8
			{
				kSetValue = 1,
				kAddValue = 2,
				kMultiplyValue = 3,
				kAddRangeToValue = 4,
				kAddActorValueMult = 5,
				kAbsoluteValue = 6,
				kNegativeAbsoluteValue = 7,
				kAddLeveledList = 8,
				kAddActivateChoice = 9,
				kSelectSpell = 10,
				kSelectText = 11,
				kSetToActorValueMult = 12,
				kMultiplyActorValueMult = 13,
				kMultiply1PlusActorValueMult = 14,
				kSetText = 15
			};


			// members
			EntryPoint entryPoint;	// 0
			Function   function;	// 1
			UInt8	   numArgs;		// 2
			UInt8	   unk3;		// 3
			UInt32	   unk4;		// 4
		};
		STATIC_ASSERT(sizeof(EntryData) == 0x8);


		// override (BGSPerkEntry)
		virtual bool	   CheckConditionFilters(UInt32 a_numArgs, void* a_args) override;	// 00
		virtual EntryPoint GetFunction() override;											// 01 - { return function; }
		virtual void*	   GetFunctionData() const override;								// 02 - { return functionData; }

		virtual ~BGSEntryPointPerkEntry();	// 03

		virtual PERK_ENTRY_TYPE GetType() const override;				   // 04 - { return kEntryPoint; }
		virtual void			ClearData() override;					   // 05
		virtual void			InitItem(TESFile* a_owner) override;	   // 06
		virtual bool			Load(TESFile* a_file) override;			   // 07
		virtual void			SetParent(BGSPerk* a_parent) override;	   // 08
		virtual UInt16			GetID() const override;					   // 09
		virtual void			ApplyPerkEntry(Actor* a_actor) override;   // 0A
		virtual void			RemovePerkEntry(Actor* a_actor) override;  // 0B

		bool IsEntryPoint(EntryPoint a_entryPoint) const;


		// members
		EntryData				   entryData;	  // 10 - DATA
		BGSEntryPointFunctionData* functionData;  // 18
		SimpleArray<TESCondition>  conditions;	  // 20
		BGSPerk*				   perk;		  // 28
	};
	STATIC_ASSERT(sizeof(BGSEntryPointPerkEntry) == 0x30);
}
