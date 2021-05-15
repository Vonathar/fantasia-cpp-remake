#ifndef _STAGE_H_
#define _STAGE_H_

#include "enum/stage_name.h"
#include <iostream>

using std::string;

class Stage {

 public:
  StageName get_stage () const;
  void set_stage (StageName stage);
  bool is_next_stage_unlocked () const;
  void set_is_next_stage_unlocked (bool is_next_stage_unlocked);
  int get_kills_for_next_stage () const;
  void set_kills_for_next_stage (int kills_for_next_stage);

 private:
  StageName stage_;
  bool is_next_stage_unlocked_;
  int kills_for_next_stage_;
};

#endif//_STAGE_H_
