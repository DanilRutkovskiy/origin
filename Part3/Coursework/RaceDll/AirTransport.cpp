#include "pch.h"
#include "AirTransport.hpp"


namespace Race {
	AirTransport::AirTransport(int speed, TransportType type, int coeff) : Transport(speed, type), m_coeff{coeff}
	{
	}
	void AirTransport::_set_coeff(int coeff)
	{
		m_coeff = coeff;
	}
	int AirTransport::_get_coeff()
	{
		return m_coeff;
	}
}