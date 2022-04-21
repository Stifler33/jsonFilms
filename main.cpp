#include <iostream>
#include "nlohmann/json.hpp"
#include <fstream>
#include <map>
int main() {
    using json = nlohmann::json;
    json info;
    std::ofstream file ("../film/name_Film.json");
    info["name"] = "Main character";
    info["country"] = "USA";
    info["date_creation"] = "10.08.2021";
    info["studios"] = "20th Century Fox";
    info["Scenario"] = {"Matt Lieberman" , "Zak Penn"};
    info["Director"] = "Shawn Levy";
    info["Producer"] = {"Greg Berlanti", "Dan Cohen", "Ryan Reynolds"};
    info["actors"] = {{"Guy", "Ryan Reynolds"},
                      {"Millie / Molotovgirl", "Jodie Comer"},
                      {"one", std::pair<std::string, std::string> {{"Guy"}, {"Ryan Reynolds"}}},
                      {"two", std::pair<std::string, std::string> {{"Millie / Molotovgirl"}, {"Jodie Comer"}}}
    };
    file << info;
    std::pair<std::string, std::string> i = info["actors"]["one"];
    std::cout << i.first;
    std::cout << info.dump(4) << std::endl;
    return 0;
}
