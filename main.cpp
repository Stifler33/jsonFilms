#include <iostream>
#include "nlohmann/json.hpp"
#include <fstream>
int main() {
    using json = nlohmann::json;
    json info;
    std::ofstream file ("..\\film\\main_character.json");
    if (!file.is_open()){
        std::cout << "non file\n";
        return 0;
    }
    info["name"] = "Main character";
    info["country"] = "USA";
    info["date_creation"] = "10.08.2021";
    info["studios"] = "20th Century Fox";
    info["Scenario"] = {"Matt Lieberman" , "Zak Penn"};
    info["Director"] = "Shawn Levy";
    info["Producer"] = {"Greg Berlanti", "Dan Cohen", "Ryan Reynolds"};
    info["actors"] = {{"Guy", "Ryan Reynolds"},
                      {"Millie / Molotovgirl", "Jodie Comer"},
                      {"Buddy", "Lil Rel Howery"},
                      {"Antwan", "Taika Waititi"},
                              {"Revenjamin Buttons", "Channing Tatum"}
    };
    file << info;
    std::cout << info.dump(4) << std::endl;
    return 0;
}
