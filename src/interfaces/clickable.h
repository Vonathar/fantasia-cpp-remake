#ifndef _CLICKABLE_H_
#define _CLICKABLE_H_

#include <SFML/Graphics.hpp>

class Clickable
{
  public:
  virtual bool boundaries_contain(sf::Vector2f &pos) = 0;
};

#endif // _CLICKABLE_H_