#include "pch.h"
#include "Transport.hpp"

namespace Race {
	Transport::~Transport()
	{
	}
	TransportType Transport::get_type()
	{
		return m_type;
	}
	void Transport::_set_speed(int speed)
	{
		m_speed = speed;
	}
	int Transport::_get_speed()
	{
		return m_speed;
	}
	Transport::Transport(int speed, TransportType type) : m_speed(speed), m_type(type)
	{
	}
}