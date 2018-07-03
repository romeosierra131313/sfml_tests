#include <iostream>

namespace mine{

  struct Vector2{
      public:
         Vector2(){}
         float x;
         float y;
         Vector2(const Vector2&) = delete;
         Vector2& operator=(const Vector2&) =delete;
 
       std::ostream& operator<<(std::ostream &output, const Vector2 &c);
       bool operator<(const Vector2& lhs, const Vector2& rhs);
   


  };
         


