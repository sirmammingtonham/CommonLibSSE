#pragma once

#include "RE/BSCore/BSFixedString.h"
#include "RE/BSCore/BSTObjectDictionary.h"
#include "RE/BSCore/BSTSmartPointer.h"
#include "RE/BSSystem/BSIntrusiveRefCounted.h"


namespace RE
{
	template <class Handler, class Parameter>
	class IHandlerFunctor :
		public BSIntrusiveRefCounted  // 08
	{
	public:
		IHandlerFunctor() = default;
		virtual ~IHandlerFunctor() = default;  // 00

		// add
		virtual bool ExecuteHandler(Handler& a_handler, const Parameter& a_parameter) = 0;

		inline bool operator()(Handler& a_handler, const Parameter& a_parameter)
		{
			return ExecuteHandler(a_handler, a_parameter);
		}


		// members
		UInt32 pad0C;  // 0C
	};
	//STATIC_ASSERT(sizeof(IHandlerFunctor) == 0x10);


	class Actor;
	using AnimHandler = IHandlerFunctor<Actor, BSFixedString>;
	STATIC_ASSERT(sizeof(AnimHandler) == 0x10);


	template <class T, class Key>
	class HandlerCreationMissPolicy
	{
	public:
		virtual ~HandlerCreationMissPolicy();  // 00
	};
	//STATIC_ASSERT(sizeof(HandlerCreationMissPolicy) == 0x8);


	template <class T, class Key>
	class NoInitializationPolicy
	{
	public:
		virtual ~NoInitializationPolicy();	// 00
	};
	//STATIC_ASSERT(sizeof(NoInitializationPolicy) == 0x8);


	class HandlerDictionary :
		public BSTObjectDictionary<
			BSTSmartPointer<AnimHandler>,
			BSFixedString,
			HandlerCreationMissPolicy,
			NoInitializationPolicy>
	{
	public:
		static HandlerDictionary* GetSingleton();
	};
	STATIC_ASSERT(sizeof(HandlerDictionary) == 0x50);
}
