#ifndef LABELOBJECT_H
#define LABELOBJECT_H

#include "../../GameObject.h"

namespace tjm {
  class LabelObject : public GameObject {
    public:
      // structs
      LabelObject(Room* room, bool haveSprite);
      ~LabelObject();
      
      // setter
      void setFont(std::string fileName);

      // getter
      sf::Text* getText();

      // overrides
      void onDraw(Camera* camera, int64_t deltaTime);

    private:
      // fields
      sf::Font* font;
      sf::Text* text;
  };
}

#endif