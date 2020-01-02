/*******************************************
Course : TGD2251 Game Physics
Session: Trimester 2, 2019/20
ID and Name: 1161303917 OO JIN HENG
Contacts   : 0123482077 oojinheng@gmail.com
*******************************************/

#ifndef GAMECLEAROBJECT_H
#define GAMECLEAROBJECT_H

#include "../../GameObject.h"

namespace tjm {
  class LabelObject;
  class GameRoom;

  class GameClearObject : public GameObject {
    public:
      // structs
      GameClearObject(GameRoom* room, int score);
      ~GameClearObject();

      // overrides
      void setup();
      void update(int64_t deltaTime);
      void onDraw(Camera* camera, int64_t deltaTime);
    private:
      // fields
      GameRoom* room;
      bool pressed;
      int alpha;
      int score;
      int64_t maxEntryTiming;
      int64_t entryTiming;
      int64_t maxTiming;
      int64_t timing;
      LabelObject* messageLabel;
      LabelObject* scoreLabel;
      LabelObject* continueLabel;
  };
}

#endif