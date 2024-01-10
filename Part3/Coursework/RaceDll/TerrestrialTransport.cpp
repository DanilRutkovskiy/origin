#include "pch.h"
#include "TerrestrialTransport.hpp"

namespace Race {
	TerrestrialTransport::TerrestrialTransport(int speed, TransportType type, int resting_time, int mov_time) : 
		Transport(speed, type), m_rest_time{ resting_time }, m_mov_time{ mov_time }, m_rest_count{0}
	{
	}
	int TerrestrialTransport::_get_mov_time()
	{
		return m_mov_time;
	}
}