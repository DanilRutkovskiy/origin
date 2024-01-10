#pragma once
#include "MACROS.hpp"

namespace Race {

	enum class RACE_API TransportType {
		Terrestrial,
		Air
	};

	class RACE_API Transport {
	public:
		virtual ~Transport();

	public:
		virtual double calculate_race_time(double length) = 0;
		TransportType get_type();

	protected:
		void _set_speed(int);
		int _get_speed();

	protected:
		Transport(int speed, TransportType type);

	private:
		TransportType m_type;
		int m_speed;
	};
}