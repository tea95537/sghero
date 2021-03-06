#ifndef SG_MESSAGE_H
#define SG_MESSAGE_H

#include "cocos2d.h"
#include "SGHash.h"
#include "SGMessageHandler.h"
#include "SGValue.h"
USING_NS_CC;
class SGMessageHandler;
class SGMessage {
public:
  explicit SGMessage(unsigned int what = 0, SGMessageHandler* handle = NULL);
  ~SGMessage();

  bool cleanItems();
  void setWhat(unsigned int what);
  unsigned int what() const;

  void setInt(const char* name, int value);
  void setFloat(const char* name, float value);
  void setPtr(const char* name, void* value);
  bool getInt(const char* name, int* value);
  bool getFloat(const char* name, float* value);
  bool getPtr(const char* name, void** value);

  void post();

private:
  unsigned int __what;
  SGMessageHandler* __handler;

  std::map<SGHash, SGValue*> __items;

};

#endif