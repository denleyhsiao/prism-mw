#ifndef __PRISM_MW_ADDRESS_H__
#define __PRISM_MW_ADDRESS_H__

class Address
{
public:
	Address(long long id);
  long long getId() const;

private:
  long long id;
};

#endif
