#include "doctest.h"
#include "League.hpp"
#include "stats.hpp"
#include "Team.hpp"
using namespace std;
using namespace ariel;
TEST_CASE("Teams tests"){
    std::vector<Team*> myTeams;
    // CHECK_THROWS(myTeam.push_back(new Team("",0)));
    // CHECK_THROWS(myTeam.push_back(new Team("\r",0)));
    // CHECK_THROWS(myTeam.push_back(new Team("\n",0)));
    // CHECK_THROWS(myTeam.push_back(new Team("\t",0)));
    // CHECK_THROWS(myTeam.push_back(new Team("\r",0)));
    // CHECK_THROWS(myTeam.push_back(new Team(" ",0)));
    myTeams.push_back(new Team("Golden State Warriors", 1));
    myTeams.push_back(new Team("Boston Celtics", 0.4));
    myTeams.push_back(new Team("Brooklyn Nets", 0.5));
    myTeams.push_back(new Team("Denver Nuggets", 0.3));
    myTeams.push_back(new Team("Philadelphia 76ers", 0.4));
    myTeams.push_back(new Team("Minnesota Timberwolves", 0.5));
    myTeams.push_back(new Team("Chicago Bulls", 0.3));
    myTeams.push_back(new Team("Portland Trail Blazers", 0.2));
    myTeams.push_back(new Team("LA Clippers", 0.5));
    myTeams.push_back(new Team("Los Angeles Lakers", 1));
    myTeams.push_back(new Team("Milwaukee Bucks", 0.7));
    myTeams.push_back(new Team("Atlanta Hawks", 0.3));
    myTeams.push_back(new Team("Charlotte Hornets", 0.2));
    myTeams.push_back(new Team("Miami Heat", 0.6));
    myTeams.push_back(new Team("Phoenix Suns", 0.8));
    myTeams.push_back(new Team("Dallas Mavericks", 0.6));
    myTeams.push_back(new Team("Memphis Grizzlies", 0.5));
    myTeams.push_back(new Team("Utah Jazz", 0.3));
    myTeams.push_back(new Team("Washington Wizards", 0));
    myTeams.push_back(new Team("Oklahoma City Thunder", 0.1));

    

    League l(myTeams);
    l.start_league();
    stats stat{l};
    Team* t = stat.find_longest_streak();
    cout << stat;

    

}