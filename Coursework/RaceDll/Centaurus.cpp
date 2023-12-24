#include "pch.h"
#include "Centaurus.hpp"

namespace Race {
	Centaurus::Centaurus() : TerrestrialTransport(10, TransportType::Terrestrial, 2, 8)
	{
	}
	double Centaurus::calculate_race_time(double length)
	{
		int rest_count = 0;
		double ret = 0;
		while (length > 0) {
			length -= _get_speed() * _get_mov_time();
			ret += _get_mov_time();
			if (rest_count == 0)
			{
				ret += 2;
			}
			rest_count++;
		}

		if (length < 0) {
			ret += length / _get_speed();
			if (rest_count > 0) {
				ret -= 2;
			}
		}

		return ret;
	}
}