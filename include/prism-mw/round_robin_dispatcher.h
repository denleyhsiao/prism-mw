#ifndef __PRISM_MW_ROUND_ROBIN_DISPATCHER_H__
#define __PRISM_MW_ROUND_ROBIN_DISPATCHER_H__

#include "prism-mw/dispatcher.h"

class RoundRobinDispatcher : public Dispatcher
{
public:
  RoundRobinDispatcher(unsigned int count);
  virtual void start() override;
  virtual void stop() override;
  virtual void shutdown() override;

private:
  unsigned int count;
};

#endif
