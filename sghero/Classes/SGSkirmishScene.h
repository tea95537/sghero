#ifndef SG_SKIRMISH_SCENE_H
#define SG_SKIRMISH_SCENE_H

#include "cocos2d.h"
#include "SGSkirmishSceneHero.h"
USING_NS_CC;
#include "tinyxml2/tinyxml2.h"

class SGSkirmishScene : public Layer
{
public:
  static Scene* createScene();

  CREATE_FUNC(SGSkirmishScene);
  virtual bool init();
  void update(float dt);
  virtual void onExit();

  bool onTouchBegan(Touch *touch, Event *unused_event) { return  true; };
  void onTouchMoved(Touch *touch, Event *unused_event);
private:
  bool parseSkirmishSceneXmlFile(const char* file);
  bool parseSkirmishSettings(tinyxml2::XMLElement* setting);
  bool parseSkrimishEvents(tinyxml2::XMLElement* events);


  void onHandleSettingMap(tinyxml2::XMLElement* setting);
  void onHandleHeroAdd(tinyxml2::XMLElement* setting, SGSkirmishSceneHero::HERO_SIDE side);
  
  void onHandleEventDialog(tinyxml2::XMLElement* event);

  Vec2 mapPos2OpenGLPos(Vec2 origin);

  EventListenerTouchOneByOne* __event_listener;
  
  typedef std::list<tinyxml2::XMLElement*> SGSkirmishSceneEventList;
  SGSkirmishSceneEventList __event_list;

};

#endif