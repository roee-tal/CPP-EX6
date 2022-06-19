#pragma once
#include <iostream>
#include <vector>
#include "Schedule.hpp"
#include "Team.hpp"
#include "Game.hpp"
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>
std::random_device rd{};
std::mt19937 gen{rd()};
std::normal_distribution<> hom{77,22};
std::normal_distribution<> awa{75,25};
using namespace std;

namespace ariel{
    class Game{
        public:
        Team* home;
        Team* away;

        Game(Team* home,Team* away):home(home), away(away){}
        
        void play(){
            int homeRand = round(hom(gen));
            int awayRand = round(awa(gen));
            homeRand += round(home->talent * 10);
            awayRand += round(away->talent * 10);
            home->score_pts += homeRand;
            home->score_gets += awayRand;
            away->score_pts += awayRand;
            away->score_gets += homeRand;
            if(homeRand>awayRand){
                home->wins++;
                away->loses++;
                check_streak(home, away);
            }
            else{
                away->wins++;
                home->loses++;
                check_streak(away, home);
            }
        }

    void check_streak(Team* winning, Team *loser){
        winning->win_streak++;
        loser->loss_streak++;
        int streak = loser->win_streak;
        if (streak > loser->big_win_streak){
            loser->big_win_streak = streak;
            
        }
        int streak2 = winning->loss_streak;
        if (streak2 > winning->big_loss_streak){
            winning->big_loss_streak = streak2;
            
        }
        winning->loss_streak = 0;
                
    }
    };
}