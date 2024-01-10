#pragma once
#include "TerrestrialTransport.hpp"

namespace Race {
	class RACE_API AllTerrainBoots : public TerrestrialTransport {
	public:
		AllTerrainBoots();

	public:
		virtual double calculate_race_time(double length) override;

	};
}