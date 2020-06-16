#ifndef __PRISM_MW_DISPATCHER_H__
#define __PRISM_MW_DISPATCHER_H__

class Dispatcher
{
public:
  virtual ~Dispatcher() {}
  virtual void start() = 0;
  virtual void stop() = 0;
  virtual void shutdown() = 0;
};

#endif
