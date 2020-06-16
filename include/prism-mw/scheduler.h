#ifndef __PRISM_MW_SCHEDULER_H__
#define __PRISM_MW_SCHEDULER_H__

#include <memory>

class Event;
class Scheduler
{
public:
  virtual ~Scheduler() {}
  virtual std::shared_ptr<Event> get() = 0;
  virtual void add(std::shared_ptr<Event> event) = 0;
};

#endif
