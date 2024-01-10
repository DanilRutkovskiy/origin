#pragma once
#include "TerrestrialTransport.hpp"

namespace Race {
	class RACE_API Centaurus : public TerrestrialTransport {
	public:
		Centaurus();

	public:
		virtual double calculate_race_time(double length) override;

	};
}