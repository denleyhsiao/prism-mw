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

void MyMath::start(bool sync /* = false */)
{
  sync ? syncStart() : asyncStart();
}

void MyMath::syncStart()
{
}

void MyMath::asyncStart()
{
}

void MyMath::stop()
{
}

int MyMath::add()
{
  return rhs + lhs;
}
