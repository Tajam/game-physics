/*******************************************
Course : TGD2251 Game Physics
Session: Trimester 2, 2019/20
ID and Name: 1161303917 OO JIN HENG
Contacts   : 0123482077 oojinheng@gmail.com
*******************************************/

#ifndef GAMEFAILOBJECT_H
#define GAMEFAILOBJECT_H

#include "../../GameObject.h"

namespace tjm {
  class LabelObject;
  class GameRoom;

  class GameFailObject : public GameObject {
    public:
      // structs
      GameFailObject(GameRoom* room);
      ~GameFailObject();

      // overrides
      void setup();
      void update(int64_t deltaTime);
      void onDraw(Camera* camera, int64_t deltaTime);
    private:
      // fields
      GameRoom* room;
      bool pressed;
      int alpha;
      int maxOption;
      int selectedOption;
      int64_t maxEntryTiming;
      int64_t entryTiming;
      int64_t maxTiming;
      int64_t timing;
      LabelObject* messageLabel;
      std::vector<LabelObject*> optionObjects;

      // methods
      void runOption(int option);
  };
}

#endif