#include "RE/Events/ScriptEvent/ScriptEventSourceHolder.h"

#include "RE/FormComponents/TESForm/TESObjectREFR/TESObjectREFR.h"


namespace RE
{
	ScriptEventSourceHolder* ScriptEventSourceHolder::GetSingleton()
	{
		using func_t = decltype(&ScriptEventSourceHolder::GetSingleton);
		REL::Offset<func_t> func(Offset::ScriptEventSourceHolder::GetSingleton);
		return func();
	}


	void ScriptEventSourceHolder::SendActivateEvent(NiPointer<TESObjectREFR>& a_target, NiPointer<TESObjectREFR>& a_caster)
	{
		using func_t = decltype(&ScriptEventSourceHolder::SendActivateEvent);
		REL::Offset<func_t> func(Offset::ScriptEventSourceHolder::SendActivateEvent);
		return func(this, a_target, a_caster);
	}
}
