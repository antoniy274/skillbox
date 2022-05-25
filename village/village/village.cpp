#include <iostream>
#include <vector>

enum houseType {
    HOUSE = 1,
    GARAGE,
    BARN,
    BATH,
};

enum roomType {
    BEDROOM = 1,
    KITCHEN,
    BATHROOM,
    LIVING_ROOM,
    CHILDREN_ROOM,
};

struct Room {
    int square = 0;
    roomType type;
};

struct Floor {
    int height = 0;
    std::vector<Room> rooms;
};

struct House {
    int square = 0;
    std::vector<Floor> floors;
    bool isOvenAvailable = false;
};

struct Garage {
    int square = 0;
};

struct Barn {
    int square = 0;
};

struct Bath {
    int square = 0;
    bool isOvenAvailable = false;
};

struct Plot {
    int id = 0;
    std::vector<House> houses;
    std::vector<Garage> garages;
    std::vector<Barn> barns;
    std::vector<Bath> baths;
};

int main()
{
    int PlotCount;
    int BuildingsCount;
    int FloorsCount;
    std::vector<Plot> plots;

    std::cout << "Input the number of plots in village\n";
    std::cin >> PlotCount;

    for (int i = 0; i < PlotCount; ++i) {
        Plot plot;
        plot.id = i;

        std::cout << "Input the number of buildings in " << plots[i].id << " plot\n";
        std::cin >> BuildingsCount;

        for (int j = 0; j < BuildingsCount; ++j) {
            std::cout << "Select the type of building, would you like to add:\n"
                << "1. Dwelling house\n"
                << "2. Garage\n"
                << "3. Barn\n"
                << "4. Bath\n";
            int answer;
            std::cin >> answer;
            if (answer == houseType::HOUSE) {
                House house;

                std::cout << "Input the house square:\n";
                std::cin >> house.square;
                std::cout << "Is oven available?\n[y|n]\n";
                char answer;
                std::cin >> answer;

                if (answer == 'y' || answer == 'Y') {
                    house.isOvenAvailable = true;
                }
                else if (answer == 'n' || answer == 'N') {
                    house.isOvenAvailable = false;
                }

                std::cout << "Input the floors count\n";
                std::cin >> FloorsCount;

                for (int k = 0; k < FloorsCount; ++k) {
                    Floor floor;

                    std::cout << "Input the floor " << k + 1 << " height\n";
                    std::cin >> floor.height;

                    std::cout << "Input the room count\n";
                    int roomCount;
                    std::cin >> roomCount;

                    for (int l = 0; l < roomCount; ++l) {
                        Room room;
                        int type;

                        std::cout << "Input the room " << l + 1 << " square\n";
                        std::cin >> room.square;
                        std::cout << "Select the room type\n"
                            << "1. Bedroom\n"
                            << "2. Kitchen\n"
                            << "3. Bathroom\n"
                            << "4. Living room\n"
                            << "5. Children room\n";
                        std::cin >> type;
                        room.type = (roomType)type;

                        floor.rooms.push_back(room);
                    }
                    house.floors.push_back(floor);
                }
                plot.houses.push_back(house);
                break;
            }
            else if (answer == houseType::GARAGE) {
                Garage garage;

                std::cout << "Input garage square\n";
                std::cin >> garage.square;
                plot.garages.push_back(garage);
                break;
            }
            else if (answer == houseType::BARN) {
                Barn barn;
                std::cout << "Input barn square\n";
                std::cin >> barn.square;
                plot.barns.push_back(barn);
                break;
            }
            else if (answer == houseType::BATH) {
                Bath bath;
                std::cout << "Input bath square\n";
                std::cin >> bath.square;
                std::cout << "Is oven available?\n";

                char answer;
                std::cin >> answer;

                if (answer == 'y' || answer == 'Y') {
                    bath.isOvenAvailable = true;
                }
                else if (answer == 'n' || answer == 'N') {
                    bath.isOvenAvailable = false;
                }

                plot.baths.push_back(bath);
                break;
            }
        }
        plots.push_back(plot);
    }
}
