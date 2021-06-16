#ifndef _PLAYER_RANK_H_
#define _PLAYER_RANK_H_

#include <iostream>
#include <map>

struct PlayerRank
{
  public:
  std::string name;
  std::map<int, std::string> requirements{
      {19, "Rogue"},      {49, "Hunter"},     {79, "Mercenary"},
      {99, "Fighter"},    {119, "Soldier"},   {149, "Assassin"},
      {179, "Champion"},  {199, "Knight"},    {229, "Templar"},
      {249, "Slayer"},    {269, "Berserker"}, {299, "Hero"},
      {INT64_MAX, "Legend"}};
};

#endif //_PLAYER_RANK_H_
