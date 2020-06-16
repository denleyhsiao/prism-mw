#include "my_math.h"

MyMath::MyMath(int rhs, int lhs)
{
  set(rhs, lhs);
}

void MyMath::set(int rhs, int lhs)
{
  this->rhs = rhs;
  this->lhs = lhs;
}

int MyMath::add()
{
  return rhs + lhs;
}
