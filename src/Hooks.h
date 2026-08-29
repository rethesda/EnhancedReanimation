#pragma once

namespace EnhancedReanimation
{
	namespace NPCCombatCast
	{
		void Install();
	};

	namespace DecapitateCheck
	{
		void Install();
	}

	namespace FastTravel
	{
		using EventResult = RE::BSEventNotifyControl;

		class LocationChangeHandler final :
			public REX ::TSingleton<LocationChangeHandler>,
			public RE::BSTEventSink<RE::MenuOpenCloseEvent>
		{
		protected:
			EventResult ProcessEvent(const RE::MenuOpenCloseEvent* a_event, RE::BSTEventSource<RE::MenuOpenCloseEvent>*) override;

		private:
			static inline constexpr float followDistSquared = 160000.0f;
		};

		void Register();
	}

	namespace Riding
	{
		namespace Name
		{
			void Install();
		}

		namespace StolenTag
		{
			void Install();
		}

		namespace RaceReanimateCheck
		{
			void Install();
		}

		void Install();
	}

	void InstallOnPostLoad();

	void InstallOnDataLoad();
}
