#pragma once
#include <iostream>
#include <vector>
#include "Schedule.hpp"
#include "Team.hpp"
#include "Game.hpp"
#include <vector>
// #include <iomanip>
// #include <string>
// #include <map>
// #include <random>
// #include <cmath>
// std::random_device rd{};
// std::mt19937 gen{rd()};
// std::normal_distribution<> hom{77,22};
// std::normal_distribution<> awa{75,25};
// constexpr int h_score = 55;
// constexpr int a_score = 50;
// constexpr int score_high = 100;



using namespace std;

namespace ariel{
    class League{
        public:
        vector <Team*> teams;

        League(vector <Team*> clubs){
            for(int i=0;i<clubs.size();i++){
                this->teams.push_back(clubs.at((unsigned int)i));
            }
        }

        ~League(){
            for(int i=0;i<teams.size();i++){
                delete teams.at((unsigned int)i);
            }
        }

        vector<Game*> draw_games(vector<Team*> games){
            vector<Game*>ans;
            for(int i=0;i<games.size();i++){
                for(int j=i+1;j<games.size();j++){
                    ans.push_back(new Game(games.at((unsigned int)i),games.at((unsigned int)j)));
                    ans.push_back(new Game(games.at((unsigned int)j),games.at((unsigned int)i)));
                }
            }
            return ans;
        }
        void start_league(){
            vector<Game*> g = draw_games(teams);
            for(int i=0;i<g.size();i++){
                g.at((unsigned int)i)->play();
            }
        }

        vector<Team*> get_teams(){
            return teams;
        }    


    };
}