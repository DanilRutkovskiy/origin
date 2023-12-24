#pragma once
#include "AirTransport.hpp"

namespace Race {
	class RACE_API AirCarpet : public AirTransport {
	public:
		AirCarpet();
		~AirCarpet();
	public:
		virtual double calculate_race_time(double length);
	};
}