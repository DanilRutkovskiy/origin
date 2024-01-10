#include "pch.h"
#include "AirCarpet.hpp"

namespace Race {
	AirCarpet::AirCarpet() : AirTransport(10, TransportType::Air, 0)
	{
	}
	AirCarpet::~AirCarpet()
	{
	}
	double AirCarpet::calculate_race_time(double length)
	{
		if (length < 1000) {
			_set_coeff(0);
		}
		else if (length < 5000) {
			_set_coeff(3);
		}
		else if (length < 10000) {
			_set_coeff(10);
		}
		else if (length >= 10000) {
			_set_coeff(5);
		}

		return (length - length * static_cast<double>(_get_coeff()) / 100) / static_cast<double>(_get_speed());
	}
}