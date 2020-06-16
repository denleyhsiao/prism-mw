#include "prism-mw/fifo_scheduler.h"

FIFOScheduler::FIFOScheduler(unsigned int count) : count(count)
{
}

std::shared_ptr<Event> FIFOScheduler::get()
{
  return nullptr;
}

void FIFOScheduler::add(std::shared_ptr<Event> event)
{

}
