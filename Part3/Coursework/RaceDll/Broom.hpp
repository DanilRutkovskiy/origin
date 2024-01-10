#pragma once
#include "AirTransport.hpp"

namespace Race {
	class RACE_API Broom : public AirTransport
	{
	public:
		Broom();
		~Broom();

	public:
		virtual double calculate_race_time(double length) override;
	};
}