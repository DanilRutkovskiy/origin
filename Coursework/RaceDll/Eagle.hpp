#pragma once
#include "AirTransport.hpp"

namespace Race {
	class RACE_API Eagle : public AirTransport {
	public:
		Eagle();
		~Eagle();

	public:
		virtual double calculate_race_time(double length) override;
	};
}