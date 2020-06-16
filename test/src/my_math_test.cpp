#include "my_math.h"
#include <gtest/gtest.h>

class MyMathTest : public testing::Test
{
protected:
  virtual void SetUp()
  {
    math.reset(new MyMath(10, 5));
    math->start();
  }
  virtual void TearDown()
  {
    math->stop();
    math.reset(nullptr);
  }

  std::unique_ptr<MyMath> math;
};

TEST_F(MyMathTest, add)
{
  ASSERT_EQ(15, math->add());
}
