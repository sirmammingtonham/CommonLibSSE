#include "RE/Inventory/InventoryChanges.h"


namespace RE
{
	InventoryChanges::InventoryChanges() :
		InventoryChanges(nullptr)
	{}


	InventoryChanges::InventoryChanges(TESObjectREFR* a_ref) :
		entryList(nullptr),
		owner(nullptr),
		totalWeight(0.0),
		armorWeight(0.0),
		unk19(0),
		unk1A(0),
		unk1B(0),
		unk1C(0)
	{
		Ctor(a_ref);
	}


	InventoryChanges::~InventoryChanges()
	{
		Dtor();
		memzero(this);
	}


	void InventoryChanges::AddEntryData(InventoryEntryData* a_entry)
	{
		if (!entryList) {
			entryList = new std::remove_pointer_t<decltype(entryList)>;
		}

		entryList->push_front(a_entry);
		changed = true;
	}


	UInt16 InventoryChanges::GetNextUniqueID()
	{
		using func_t = decltype(&InventoryChanges::GetNextUniqueID);
		REL::Offset<func_t> func(Offset::InventoryChanges::GetNextUniqueID);
		return func(this);
	}


	void InventoryChanges::SendContainerChangedEvent(ExtraDataList* a_itemExtraList, TESObjectREFR* a_fromRefr, TESForm* a_item, SInt32 a_count)
	{
		using func_t = decltype(&InventoryChanges::SendContainerChangedEvent);
		REL::Offset<func_t> func(Offset::InventoryChanges::SendContainerChangedEvent);
		return func(this, a_itemExtraList, a_fromRefr, a_item, a_count);
	}


	void InventoryChanges::SetUniqueID(ExtraDataList* a_itemList, TESForm* a_oldForm, TESForm* a_newForm)
	{
		using func_t = decltype(&InventoryChanges::SetUniqueID);
		REL::Offset<func_t> func(Offset::InventoryChanges::SetUniqueID);
		return func(this, a_itemList, a_oldForm, a_newForm);
	}


	void InventoryChanges::InitFromContainerExtra()
	{
		using func_t = decltype(&InventoryChanges::InitFromContainerExtra);
		REL::Offset<func_t> func = REL::ID(15890);
		return func(this);
	}


	void InventoryChanges::InitLeveledItems()
	{
		using func_t = decltype(&InventoryChanges::InitLeveledItems);
		REL::Offset<func_t> func = REL::ID(15889);
		return func(this);
	}


	void InventoryChanges::InitScripts()
	{
		using func_t = decltype(&InventoryChanges::InitScripts);
		REL::Offset<func_t> func = REL::ID(15829);
		return func(this);
	}


	InventoryChanges* InventoryChanges::Ctor(TESObjectREFR* a_ref)
	{
		using func_t = decltype(&InventoryChanges::Ctor);
		REL::Offset<func_t> func = REL::ID(15812);
		return func(this, a_ref);
	}


	void InventoryChanges::Dtor()
	{
		using func_t = decltype(&InventoryChanges::Dtor);
		REL::Offset<func_t> func = REL::ID(15813);
		return func(this);
	}
}
