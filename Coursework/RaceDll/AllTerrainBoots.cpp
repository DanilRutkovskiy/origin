#include "pch.h"
#include "AllTerrainBoots.hpp"

namespace Race {
	AllTerrainBoots::AllTerrainBoots() : TerrestrialTransport(10, TransportType::Terrestrial, 10, 60)
	{
	}
	double AllTerrainBoots::calculate_race_time(double length)
	{
		int rest_count = 0;
		double ret = 0;
		while (length > 0) {
			length -= _get_speed() * _get_mov_time();
			ret += _get_mov_time();
			if (rest_count == 0)
			{
				ret += 10;
			}
			else
			{
				ret += 5;
			}
			rest_count++;
		}

		if (length < 0) {
			ret += length / _get_speed();
			if (rest_count == 1) {
				ret -= 10;
			}
			else {
				ret -= 5; 
			}
		}
		
		return ret;
	}
}