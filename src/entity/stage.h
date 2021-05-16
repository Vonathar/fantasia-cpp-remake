#ifndef _STAGE_H_
#define _STAGE_H_

#include "../enum/stage_name.h"
#include <iostream>

using std::string;

class Stage {

 public:
  StageName name;
  bool is_next_stage_unlocked;
  int kills_for_next_stage;
};

#endif//_STAGE_H_
