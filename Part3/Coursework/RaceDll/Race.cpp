#include "pch.h"
#include "Race.hpp"
#include <memory>
#include <vector>
#include <unordered_map>
#include "Transport.hpp"
#include "AirCarpet.hpp"
#include "AllTerrainBoots.hpp"
#include "Broom.hpp"
#include "Camel.hpp"
#include "Centaurus.hpp"
#include "Eagle.hpp"
#include "FastCamel.hpp"

namespace Race {
	struct RaceData {
		std::unordered_map<TransportName, std::shared_ptr<Transport>> m_transports;
	};

	Race::Race() : m_type{ RaceType::Empty }, m_length{ 0 }, m_calculated_race{nullptr}
	{
		m_data = new RaceData();
	}

	Race::Race(RaceType type, int length) : m_type{ type }, m_length{length}, m_calculated_race{ nullptr }
	{
		m_data = new RaceData();
	}

	Race::Race(const Race& race) : m_type{ race.m_type }, m_length{ race.m_length }, m_calculated_race{ nullptr }
	{
		m_data = new RaceData();

		auto it = race.m_data->m_transports.begin();

		while (it != race.m_data->m_transports.end()) {
			m_data->m_transports.insert(std::make_pair(it->first, it->second));
		}
	}

	Race::~Race()
	{
		delete m_data;

		if(m_calculated_race != nullptr)
			delete[] m_calculated_race;
	}

	const Race& Race::operator=(const Race& race)
	{
		this->m_length = race.m_length;
		this->m_type = race.m_type;

		auto it = race.m_data->m_transports.begin();

		while (it != race.m_data->m_transports.end()) {
			m_data->m_transports.insert(std::make_pair(it->first, it->second));
		}

		return *this;
	}

	AddTransportRet Race::add_transport(TransportName name)
	{
		switch (name) {
			case TransportName::AirCarpet:
			{
				if ((m_type != RaceType::Air) && (m_type != RaceType::AllTypes))
					return AddTransportRet::WrongRaceType;
				if (m_data->m_transports.count(TransportName::AirCarpet) > 0)
					return AddTransportRet::AlreadyAdded;

				m_data->m_transports.insert(std::make_pair(TransportName::AirCarpet, std::shared_ptr<Transport>{ std::make_shared<AirCarpet>() }));
				break;
			}
			case TransportName::AllTerrainBoots:
			{
				if ((m_type != RaceType::Terrestrial) && (m_type != RaceType::AllTypes))
					return AddTransportRet::WrongRaceType;
				if (m_data->m_transports.count(TransportName::AllTerrainBoots) > 0)
					return AddTransportRet::AlreadyAdded;

				m_data->m_transports.insert(std::make_pair(TransportName::AllTerrainBoots, std::shared_ptr<Transport>{ std::make_shared<AllTerrainBoots>() }));
				break;
			}
			case TransportName::Broom:
			{
				if ((m_type != RaceType::Air) && (m_type != RaceType::AllTypes))
					return AddTransportRet::WrongRaceType;
				if (m_data->m_transports.count(TransportName::Broom) > 0)
					return AddTransportRet::AlreadyAdded;

				m_data->m_transports.insert(std::make_pair(TransportName::Broom, std::shared_ptr<Transport>{ std::make_shared<Broom>() }));
				break;
			}
			case TransportName::Camel:
			{
				if ((m_type != RaceType::Terrestrial) && (m_type != RaceType::AllTypes))
					return AddTransportRet::WrongRaceType;
				if (m_data->m_transports.count(TransportName::Camel) > 0)
					return AddTransportRet::AlreadyAdded;
		
				m_data->m_transports.insert(std::make_pair(TransportName::Camel, std::shared_ptr<Transport>{ std::make_shared<Camel>() }));
				break;
			}
			case TransportName::Centaurus:
			{
				if ((m_type != RaceType::Terrestrial) && (m_type != RaceType::AllTypes))
					return AddTransportRet::WrongRaceType;
				if (m_data->m_transports.count(TransportName::Centaurus) > 0)
					return AddTransportRet::AlreadyAdded;

				m_data->m_transports.insert(std::make_pair(TransportName::Centaurus, std::shared_ptr<Transport>{ std::make_shared<Centaurus>() }));
				break;
			}
			case TransportName::Eagle:
			{
				if ((m_type != RaceType::Air) && (m_type != RaceType::AllTypes))
					return AddTransportRet::WrongRaceType;
				if (m_data->m_transports.count(TransportName::Eagle) > 0)
					return AddTransportRet::AlreadyAdded;

				m_data->m_transports.insert(std::make_pair(TransportName::Eagle, std::shared_ptr<Transport>{ std::make_shared<Eagle>() }));
				break;
			}
			case TransportName::FastCamel:
			{
				if ((m_type != RaceType::Terrestrial) && (m_type != RaceType::AllTypes))
					return AddTransportRet::WrongRaceType;
				if (m_data->m_transports.count(TransportName::FastCamel) > 0)
					return AddTransportRet::AlreadyAdded;

				m_data->m_transports.insert(std::make_pair(TransportName::FastCamel, std::shared_ptr<Transport>{ std::make_shared<FastCamel>() }));
				break;
			}
		}
			
		return AddTransportRet::Success;
	}

	int Race::ts_count()
	{
		return m_data->m_transports.size();
	}
	TransportTime* Race::calculate_race_time(int& arr_size)
	{
		arr_size = m_data->m_transports.size();
		if (m_calculated_race != nullptr)
			delete[] m_calculated_race;

		m_calculated_race = new TransportTime[arr_size];
		int ind = 0;
		for (auto it : m_data->m_transports) {
			m_calculated_race[ind].m_name = it.first;
			m_calculated_race[ind].m_race_time = it.second->calculate_race_time(m_length);
			ind++;
		}

		return m_calculated_race;
	}
}

