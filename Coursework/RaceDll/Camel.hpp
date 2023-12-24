#pragma once
#include "TerrestrialTransport.hpp"

namespace Race {
	class RACE_API Camel : public TerrestrialTransport {
	public:
		Camel();

	public:
		virtual double calculate_race_time(double length) override;

	};
}