#include <iostream>
#include "nlohmann/json.hpp"
#include <fstream>
#include <string>
#include <vector>
using namespace std;
class InfoFilm{
    using json = nlohmann::json;
    ifstream file;
    map<string, json> archive;
public:
    InfoFilm(vector<string>& _path){
        for (auto& i : _path){
            file.open(i);
            if (!file.is_open()){
                cout << "fine no open\n";
            }else{
                string nameFilm;
                int start = i.rfind('/', i.size()) + 1;
                int end = i.find('.', start);
                int count = end - start;
                nameFilm = i.substr(start, count);
                archive.insert({nameFilm, json(nullptr)});
                const auto& itr = archive.find(nameFilm);
                file >> itr->second;
            }
            file.close();
        }
    }
    void searchActors(string _name){
        for (auto film : archive){
            if (auto actr = film.second["actors"].find(_name); actr != film.second["actors"].end()){
                cout << "film " << film.second["name"] << endl;
                cout << "person " << actr.value() << endl;
            }
        }
    }
};
int main(){
    vector<string> path = {"../film/dune.json",
                           "../film/avengers.json",
                           "../film/back_to_the_future.json",
                           "../film/main_character.json",
                           "../film/iron_man.json"};
    InfoFilm archive(path);
    archive.searchActors("Jon Favreau");
    return 0;
}

