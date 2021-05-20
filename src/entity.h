#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "SFML/Graphics.hpp"

class Entity
{
  public:
  virtual void render(sf::RenderTarget &target) = 0;
};

#endif //_ENTITY_H_