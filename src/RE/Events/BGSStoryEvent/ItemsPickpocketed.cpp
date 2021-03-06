#include "RE/Events/BGSStoryEvent/ItemsPickpocketed.h"


namespace RE
{
	BSTEventSource<ItemsPickpocketed::Event>* ItemsPickpocketed::GetEventSource()
	{
		using func_t = decltype(&ItemsPickpocketed::GetEventSource);
		REL::Offset<func_t> func(Offset::ItemsPickpocketed::GetEventSource);
		return func();
	}


	void ItemsPickpocketed::SendEvent(SInt32 a_numItems)
	{
		Event e = { a_numItems, 0 };
		auto source = GetEventSource();
		if (source) {
			source->SendEvent(std::addressof(e));
		}
	}
}
