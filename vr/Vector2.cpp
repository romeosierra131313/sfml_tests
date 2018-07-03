#include"Vector2.h"

namespace mine{
Vector2::Vector2(){}

bool operator<(const Vector2 &c1, const Vector2 &c2){
    return c1.x + c1.y  < c2.x + c2.y  ;
}
}