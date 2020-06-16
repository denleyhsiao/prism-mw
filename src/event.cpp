#include "prism-mw/event.h"
#include <cassert>

Event::Event(const char* name) : name(name)
{

}

const char* Event::getName() const
{
  return name.c_str();
}

bool Event::has(const char* key) const
{
  return (params.find(key) != params.end());
}

std::shared_ptr<Object> Event::get(const char* key) const
{
  assert(has(key));
  return params.find(key)->second;
}

void Event::add(const char* key, std::shared_ptr<Object> value)
{
  assert(!has(key));
  params.insert(std::make_pair(key, value));
}
