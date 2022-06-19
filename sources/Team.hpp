#pragma once
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;


namespace ariel{
    class Team{
        public:
        string name;
        double talent;
        int wins;
        int loses;
        int score_pts;
        int score_gets;
        int win_streak;
        int loss_streak;
        int big_win_streak;
        int big_loss_streak;


        Team(string name, double talent){
            if(name==" " || name =="\n" || talent < 0 || talent >1){
                throw invalid_argument("name or talent is not legal");
            }
            this->talent = talent;
            this->name = name;
            wins = 0;
            loses = 0;
            score_pts = 0;
            score_gets = 0;
            win_streak = 0;
            loss_streak = 0;
            big_win_streak=0;
            big_loss_streak=0;
        }

        bool operator==(const Team& o)const{
            return this->name == o.name;
        }
        bool operator!=(const Team& o)const{
            return this->name != o.name;
        }
    };
}