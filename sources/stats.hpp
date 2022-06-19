#pragma once
#include <iostream>
#include <vector>
#include "Schedule.hpp"
#include "Team.hpp"
#include "Game.hpp"
#include "League.hpp"
#include <algorithm>
#include <iomanip>

namespace ariel{
    class stats{
        public:
        League *l;

        stats(League &l):l(&l){
        }

        vector<Team*> top_table(const int num)const{
            vector <Team*>top;
            vector <Team*>t = l->get_teams();
            sort(t.begin(),t.end(),[](Team* a, Team* b){
                if(a->wins != b->wins)
                    return a->wins > b->wins;
                return (a->score_pts - a->score_gets) > (b->score_pts - b->score_gets);});
            for(int i=0;i<num;i++){
                top.push_back(t.at((unsigned int)i));
            }
            return top;
        }

    int find_longest_name(vector <Team*>top)const{
        string ans = top.at((unsigned int)0)->name;
        int len = ans.length();
        for(int i=0;i<top.size();i++){
            ans = top.at((unsigned int)i)->name;
            int len_temp = ans.length();
            if(len_temp>len){
                len = len_temp;
            }
        }
        return len;
    }

    Team* find_longest_streak()const{
        Team* s = l->teams.at((unsigned int)0);
        int ans = l->teams.at((unsigned int)0)->big_win_streak;
        for(int i=0;i<l->teams.size();i++){
            int len_temp = l->teams.at((unsigned int)i)->big_win_streak;
            if(len_temp>ans){
                ans = len_temp;
                s = l->teams.at((unsigned int)i);
            }
        }
        return s;
    }

    int find_dif(string name, int num)const{
        int l = name.length();
        return num - l;
    }

    friend std::ostream &operator<<(std::ostream &os, const stats &stats) {
        vector <Team*>top = stats.top_table(20);
        std::string toPrint;
        int longest = stats.find_longest_name(top);
        os << "team" << std::setw(longest+2) << "win" <<std::setw(5) << "lose" <<std::setw(5) << "pts" <<std::setw(9) << "pts_to" <<std::setw(5) << "dif" <<std::setw(7) << endl;
        os << "--------------------------------------------------" << endl;
        for(int i=0;i<top.size();i++){
            int t = stats.find_dif(top.at((unsigned int)i)->name, longest);
            os << (top.at((unsigned int)i))->name << std::setw(t+5);
            os << std::to_string(top.at((unsigned int)i)->wins) << std::setw(5);
            os << std::to_string(top.at((unsigned int)i)->loses) << "  |";
            os << std::to_string(top.at((unsigned int)i)->score_pts) << "  |";
            os << std::to_string(top.at((unsigned int)i)->score_gets) << "  |";
            os <<(top.at((unsigned int)i)->score_pts - top.at((unsigned int)i)->score_gets) << "\n";
        }
        os << toPrint;
        return os;
    }
    };
}