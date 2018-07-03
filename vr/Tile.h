
#include "string.h"
#include <iostream>

namespace mine{

  struct Tile{
      public:
         Tile(){}
         float x;
         float y;
         std::string tileType;
         Tile(const Tile&) = delete;
         Tile& operator=(const Tile&) =delete;


  };

}