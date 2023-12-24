#include "pch.h"
#include "Broom.hpp"

namespace Race {
	Broom::Broom() : AirTransport(20, TransportType::Air, 0)
	{

	}
	Broom::~Broom()
	{
	}
	double Broom::calculate_race_time(double length)
	{
		_set_coeff(length / 1000);

		return (length - length * static_cast<double>(_get_coeff()) / 100) / static_cast<double>(_get_speed());
	}
}