#include "prism-mw/address.h"

Address::Address(long long id) : id(id)
{

}

long long Address::getId() const
{
  return id;
}
