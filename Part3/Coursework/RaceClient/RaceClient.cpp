#include <iostream>
#include <string>
#include "../RaceDll/Race.hpp"

enum class GameStage {
    Start,
    Registration,
    Race,
    Quit
};

Race::Race create_race();
void registrate_transport(Race::Race& race);

int main()
{
    std::cout << "Welcome to race simulator!" << std::endl;

    GameStage stage = GameStage::Start;
    Race::Race race;
    while (stage != GameStage::Quit) {
        switch (stage) {
        case GameStage::Start:
        {
            race = create_race();
            stage = GameStage::Registration;
            break;
        }
        case GameStage::Registration:
        {
            registrate_transport(race);

            std::cout << "1. Registrate transport" << std::endl
                << "2. Start race" << std::endl
                << "Choose action: ";

            int act;
            std::cin >> act;

            switch (act)
            {
            case 1:
            {
                continue;
                break;
            }
            case 2:
            {
                stage = GameStage::Race;
                break;
            }
            default:
                std::cout << "Wrong command!" << std::endl;
                break;
            }
            break;
        }
        case GameStage::Race:
        {
            int arr_size;
            Race::TransportTime* race_results = race.calculate_race_time(arr_size);
            std::cout << "Race results: " << std::endl;
            for (int i = 0; i < arr_size; i++) {
                Race::TransportName name = race_results[i].m_name;
                double transport_time = race_results[i].m_race_time;
                std::string name_str;
                switch (name) {
                case Race::TransportName::AirCarpet: {
                    name_str = "AirCarpet";
                    break;
                }
                case Race::TransportName::AllTerrainBoots: {
                    name_str = "AllTerrainBoots";
                    break;
                }
                case Race::TransportName::Broom: {
                    name_str = "Broom";
                    break;
                }
                case Race::TransportName::Camel: {
                    name_str = "Camel";
                    break;
                }
                case Race::TransportName::Centaurus: {
                    name_str = "Centaurus";
                    break;
                }
                case Race::TransportName::Eagle: {
                    name_str = "Eagle";
                    break;
                }
                case Race::TransportName::FastCamel: {
                    name_str = "FastCamel";
                    break;
                }
                }

                std::cout << i << ". " << name_str << " time: " << transport_time << std::endl;
            }
            int ans = -1;
            std::cout << "Another race? 1 - Yes, Any other character - no: ";
            std::cin >> ans;
            if (ans == 1) {
                stage = GameStage::Start;
            }
            else
            {
                stage = GameStage::Quit;
            }
            break;
        }
        }
    }

    return 0;
}

Race::Race create_race() {
    std::cout << "1. Terrestrial trasnsport race" << std::endl
        << "2. Air transport race" << std::endl
        << "3. All transport types Race" << std::endl
        << "Choose race type: ";

    int in_num;
    std::cin >> in_num;
    Race::RaceType type;
    switch (in_num) {
    case 1:
    {
        std::cout << "Terrestrial race is chosen" << std::endl;
        type = Race::RaceType::Terrestrial;
        break;
    }
    case 2:
    {
        std::cout << "Air race is chosen" << std::endl;
        type = Race::RaceType::Air;
        break;
    }
    case 3:
    {
        std::cout << "All transport race is chosen" << std::endl;
        type = Race::RaceType::AllTypes;
        break;
    }
    default:
    {
        std::cout << "Wrong race type! " << "All transport race is set." << std::endl;
        type = Race::RaceType::AllTypes;
        break;
    }
    }

    std::cout << "Set race length: ";
    int length = 0;
    std::cin >> length;

    return Race::Race{ type, length };
}

void registrate_transport(Race::Race& race) {
    bool add = true;
    while (race.ts_count() < 2 || add) {
        std::cout << "Registrate transport: " << std::endl
            << "1. Air carper" << std::endl
            << "2. Broom" << std::endl
            << "3. Eagle" << std::endl
            << "4. AllTerrainBoots" << std::endl
            << "5. Camel" << std::endl
            << "6. Centaurus" << std::endl
            << "7. FastCamel" << std::endl
            << "0. End registration" << std::endl;

        std::cout << "Choose transport, or press 0 to end the registration process: ";
        int num;
        std::cin >> num;
        Race::TransportName transport;
        switch (num) {
        case 1:
        {
            transport = Race::TransportName::AirCarpet;
            break;
        }
        case 2:
        {
            transport = Race::TransportName::Broom;
            break;
        }
        case 3:
        {
            transport = Race::TransportName::Eagle;
            break;
        }
        case 4:
        {
            transport = Race::TransportName::AllTerrainBoots;
            break;
        }
        case 5:
        {
            transport = Race::TransportName::Camel;
            break;
        }
        case 6:
        {
            transport = Race::TransportName::Centaurus;
            break;
        }
        case 7:
        {
            transport = Race::TransportName::FastCamel;
            break;
        }
        case 0:
        {
            if (race.ts_count() < 2) {
                std::cout << "Not enough transports to start a race!" << std::endl;
                continue;
            }
            add = false;
            break;
        }
        default:
        {
            std::cout << "Wrong input!" << std::endl;
            continue;
            break;
        }
        }

        if (!add)
            return;

        auto ret = race.add_transport(transport);
        if (ret == Race::AddTransportRet::Success) {
            std::cout << "Transport added!" << std::endl;
            continue;
        }
        if (ret == Race::AddTransportRet::AlreadyAdded) {
            std::cout << "This transport already added!" << std::endl;
            continue;
        }
        if (ret == Race::AddTransportRet::WrongRaceType) {
            std::cout << "Wrong transport for this race type!" << std::endl;
            continue;
        }
    }
}