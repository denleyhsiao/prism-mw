#ifndef __PRISM_MW_FIFO_SCHEDULER_H__
#define __PRISM_MW_FIFO_SCHEDULER_H__

#include "prism-mw/scheduler.h"

class FIFOScheduler : public Scheduler
{
public:
  FIFOScheduler(unsigned int count);
  virtual std::shared_ptr<Event> get() override;
  virtual void add(std::shared_ptr<Event> event) override;

private:
  unsigned int count;
};

#endif
