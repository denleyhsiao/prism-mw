#include "my_math.h"
#include "prism-mw/fifo_scheduler.h"
#include "prism-mw/round_robin_dispatcher.h"
#include <memory>

MyMath::MyMath(int rhs, int lhs)
{
  set(rhs, lhs);
}

void MyMath::set(int rhs, int lhs)
{
  this->rhs = rhs;
  this->lhs = lhs;
}

void MyMath::start(bool sync /* = false */)
{
  sync ? syncStart() : asyncStart();
}

void MyMath::syncStart()
{
  doStart();
}

void MyMath::asyncStart()
{
  doStart();
}

void MyMath::doStart()
{
  std::shared_ptr<Scheduler> scheduler(std::make_shared<FIFOScheduler>(5));
  std::shared_ptr<Dispatcher> dispatcher(std::make_shared<RoundRobinDispatcher>(10, scheduler));
}

void MyMath::stop()
{
}

int MyMath::add()
{
  return rhs + lhs;
}
