#include <iostream>
#include "nlohmann/json.hpp"
#include <fstream>
int main() {
    using json = nlohmann::json;
    json info;
    std::ofstream file ("infoFilms.txt");
    info["name"] = "Back to the Future";
    info["country"] = "USA";
    info["date_creation"] = "03.07.1985";
    info["studios"] = "Universal";
    info["Scenario"] = {"Robert Zemekis", "Bob Gale"};
    info["Director"] = "Robert Zemeckis";
    info["Producer"] = {"Neil Canton", "Bob Gale", "Kathleen Kennedy", "Frank Marshall", "Steven Spielberg"};
    info["actors"] = {{"Marty_McFly", "Michael J. Fox"},
                      {"Dr._Emmett_Brown", "Christopher Lloyd"},
                      {"Lorraine_Baines", "Lea Thompson"},
                      {"Biff_Tannen", "Thomas F. Wilson"}
    };
    file << info;
    std::cout << info.dump(4) << std::endl;
    return 0;
}
