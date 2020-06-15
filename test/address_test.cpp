#include "prism-mw/address.h"
#include <gtest/gtest.h>

static const long long ADDRESS_ID = 1;

class AddressTest : public testing::Test
{
protected:
  virtual void SetUp()
  {
    address.reset(new Address(ADDRESS_ID));
  }
  virtual void TearDown()
  {
    address.reset(nullptr);
  }

  std::unique_ptr<Address> address;
};

TEST_F(AddressTest, getId)
{
  ASSERT_EQ(ADDRESS_ID, address->getId());
}
