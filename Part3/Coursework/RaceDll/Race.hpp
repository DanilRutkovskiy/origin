#pragma once
#include "MACROS.hpp"

namespace Race{
	struct RaceData;
	enum class RACE_API RaceType {
		Empty,
		Terrestrial,
		Air,
		AllTypes
	};
	enum class RACE_API TransportName {
		AllTerrainBoots,
		Camel,
		Centaurus,
		FastCamel,
		AirCarpet,
		Broom,
		Eagle
	};
	enum class RACE_API AddTransportRet {
		Success,
		AlreadyAdded,
		WrongRaceType
	};
	struct RACE_API TransportTime
	{
		TransportName m_name;
		double m_race_time;
	};

	class RACE_API Race {
	public:
		Race();
		Race(RaceType type, int length);
		Race(const Race&);
		~Race();
		const Race& operator = (const Race& race);

	public:
		AddTransportRet add_transport(TransportName name);
		int ts_count();
		TransportTime* calculate_race_time(int& arr_size);

	private:
		RaceType m_type;
		int m_length;
		RaceData* m_data;
		TransportTime* m_calculated_race;
	};
}