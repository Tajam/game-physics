/*******************************************
Course : TGD2251 Game Physics
Session: Trimester 2, 2019/20
ID and Name: 1161303917 OO JIN HENG
Contacts   : 0123482077 oojinheng@gmail.com
*******************************************/

#ifndef LABELOBJECT_H
#define LABELOBJECT_H

#include "../../GameObject.h"

namespace tjm {
  class LabelObject : public GameObject {
    public:
      // structs
      LabelObject(Room* room);
      ~LabelObject();
      
      // setter
      void setFont(std::string fileName);
      void setText(std::string message);
      void setColor(sf::Color color);
      void setSize(unsigned int size);
      void setStyle(sf::Uint32 style);
      void setOrientation(float rotation, sf::Vector2f position);
      void setOrientation(sf::Vector2f position);
      void setOrientation(float rotation);
      void makeShadow(int offset);
      LabelObject* makeDefault(std::string text, unsigned int size, sf::Vector2f position, sf::Color color);
     

      // getter
      sf::Text* getText();

      // overrides
      void onDraw(Camera* camera, int64_t deltaTime);

    private:
      // fields
      sf::Font* font;
      sf::Text* text;
      sf::Text* sText;
      bool haveShadow;
      int offset;
  };
}

#endif