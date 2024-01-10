#include "pch.h"
#include "Eagle.hpp"

namespace Race {
	Eagle::Eagle() : AirTransport(8, TransportType::Air, 6)
	{

	}
	Eagle::~Eagle()
	{
	}
	double Eagle::calculate_race_time(double length)
	{
		return (length - length * static_cast<double>(_get_coeff()) / 100) / static_cast<double>(_get_speed());
	}
}