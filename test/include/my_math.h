#ifndef __PRISM_MW_TEST_MY_MATH_H__
#define __PRISM_MW_TEST_MY_MATH_H__

class MyMath
{
public:
  MyMath(int rhs, int lhs);
  void start(bool sync  = false);
  void stop();
  int add();

private:
  void set(int rhs, int lhs);
  void syncStart();
  void asyncStart();
  void doStart();
  int rhs;
  int lhs;
};

#endif
