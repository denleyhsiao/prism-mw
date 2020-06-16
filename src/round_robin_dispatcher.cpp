#include "prism-mw/round_robin_dispatcher.h"
#include "prism-mw/scheduler.h"

RoundRobinDispatcher::RoundRobinDispatcher(unsigned int count, std::shared_ptr<Scheduler> scheduler) : scheduler(scheduler), count(count)
{

}

void RoundRobinDispatcher::start()
{

}

void RoundRobinDispatcher::stop()
{

}

void RoundRobinDispatcher::shutdown()
{

}
