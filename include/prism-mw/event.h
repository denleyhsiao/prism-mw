#ifndef __PRISM_MW_EVENT_H__
#define __PRISM_MW_EVENT_H__

#include <memory>
#include <string>
#include <map>

class Object;
class Event
{
public:
  Event(const char* name);
  const char* getName() const;
  std::shared_ptr<Object> get(const char* key) const;
  void add(const char* key, std::shared_ptr<Object> value);

private:
  typedef std::map<const char*, std::shared_ptr<Object> > params_type;
  bool has(const char* key) const;
  std::string name;
  params_type params;
};

#endif
