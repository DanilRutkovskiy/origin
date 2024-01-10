#include "pch.h"
#include "Camel.hpp"

namespace Race {
	Camel::Camel() : TerrestrialTransport(10, TransportType::Terrestrial, 5, 30)
	{
	}
	double Camel::calculate_race_time(double length)
	{
		int rest_count = 0;
		double ret = 0;
		while (length > 0) {
			length -= _get_speed() * _get_mov_time();
			ret += _get_mov_time();
			if (rest_count == 0)
			{
				ret += 5;
			}
			else
			{
				ret += 8;
			}
			rest_count++;
		}

		if (length < 0) {
			ret += length / _get_speed();
			if (rest_count == 1) {
				ret -= 5;
			}
			else {
				ret -= 8;
			}
		}

		return ret;
	}
}