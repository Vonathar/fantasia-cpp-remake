#ifndef _CLICKABLE_H_
#define _CLICKABLE_H_

namespace sf
{
class Clickable {

 public:
  virtual ~Clickable () = default;
  virtual void click () = 0;
};
}// namespace sf

#endif//_CLICKABLE_H_
