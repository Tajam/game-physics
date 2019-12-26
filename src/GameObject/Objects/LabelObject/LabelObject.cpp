#include "LabelObject.h"

namespace tjm {
  LabelObject::LabelObject(Room* room, bool haveSprite) :  GameObject(room) {
    _haveBody = false;
    _haveSprite = haveSprite;
  }

  LabelObject::~LabelObject() {
    delete font;
    font = NULL;
    delete text;
    text = NULL;
  }

  void LabelObject::setFont(std::string fileName) {
    font = new sf::Font();
    font->loadFromFile(fileName.c_str());
    text = new sf::Text();
    text->setFont(*font);
  }

  sf::Text* LabelObject::getText() {
    return text;
  }

  void LabelObject::onDraw(Camera* camera, int64_t deltaTime) {
    camera->draw(*text);
  }
}