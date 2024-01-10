#pragma once
#include"Transport.hpp"

namespace Race {
	class RACE_API AirTransport : public Transport
	{
	protected:
		AirTransport(int speed, TransportType type, int coeff);
	protected:
		void _set_coeff(int coeff);
		int _get_coeff();
	private:
		int m_coeff;
	};
}