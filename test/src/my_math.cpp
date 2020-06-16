#include "my_math.h"

MyMath::MyMath(int rhs, int lhs) : rhs(rhs), lhs(lhs)
{

}

int MyMath::add()
{
  return rhs + lhs;
}
