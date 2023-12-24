#pragma once
#include "Transport.hpp"

namespace Race {
	class RACE_API TerrestrialTransport : public Transport {
	protected:
		TerrestrialTransport(int speed, TransportType type, int resting_time, int mov_time);

	protected:
		int _get_mov_time();

	private:
		int m_rest_time;
		int m_mov_time;
		int m_rest_count;
	};

}