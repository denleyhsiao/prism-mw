#ifndef __PRISM_MW_ROUND_ROBIN_DISPATCHER_H__
#define __PRISM_MW_ROUND_ROBIN_DISPATCHER_H__

#include "prism-mw/dispatcher.h"
#include <memory>

class Scheduler;
class RoundRobinDispatcher : public Dispatcher
{
public:
  RoundRobinDispatcher(unsigned int count, std::shared_ptr<Scheduler> scheduler);
  virtual void start() override;
  virtual void stop() override;
  virtual void shutdown() override;

private:
  unsigned int count;
  std::shared_ptr<Scheduler> scheduler;
};

#endif
