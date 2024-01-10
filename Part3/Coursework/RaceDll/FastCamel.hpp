#pragma once
#include "TerrestrialTransport.hpp"

namespace Race {
	class RACE_API FastCamel : public TerrestrialTransport {
	public:
		FastCamel();

	public:
		virtual double calculate_race_time(double length) override;

	};
}