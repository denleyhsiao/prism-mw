#include "prism-mw/fifo_scheduler.h"
#include "prism-mw/event.h"

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
