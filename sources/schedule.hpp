// #pragma once
// #include <iostream>
// #include <vector>
// #include "Team.hpp"
// #include "Game.hpp"
// #include <vector>


// using namespace std;

// namespace ariel{
//     class Schedule{
//         vector <Team*> team_to_draw;

//         vector<Game*> draw_games(vector<Team*> games){
//             vector<Game*>ans;
//             for(int i=0;i<games.size();i++){
//                 for(int j=i+1;j<games.size();j++){
//                     // Game g1(games.at((unsigned int)i),games.at((unsigned int)j));
//                     // Game g2(games.at((unsigned int)j),games.at((unsigned int)i));
//                     ans.push_back(new Game(games.at((unsigned int)i),games.at((unsigned int)j)));
//                     ans.push_back(new Game(games.at((unsigned int)j),games.at((unsigned int)i)));
//                 }
//             }
//             return ans;
//         }

//     };
// }