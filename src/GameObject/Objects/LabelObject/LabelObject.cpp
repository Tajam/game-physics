#include "LabelObject.h"

namespace tjm {
  LabelObject::LabelObject(Room* room) :  GameObject(room) {
    _haveBody = false;
    _haveSprite = false;
    font = new sf::Font();
    text = new sf::Text();
    setTag("ui");
    haveShadow = false;
  }

  LabelObject::~LabelObject() {
    delete font;
    font = nullptr;
    delete text;
    text = nullptr;
    if (haveShadow) {
      delete sText;
      sText = nullptr;
    }
  }

  void LabelObject::setFont(std::string fileName) {
    font->loadFromFile(fileName.c_str());
    text->setFont(*font);
  }

  void LabelObject::setText(std::string message) {
    text->setString(message);
    if (haveShadow) {
      sText->setString(message);
    }
  }

  void LabelObject::setColor(sf::Color color) {
    text->setFillColor(color);
  }

  void LabelObject::setSize(unsigned int size) {
    text->setCharacterSize(size);
    sf::FloatRect textRect = text->getLocalBounds();
    text->setOrigin(textRect.left + textRect.width / 2.0f, textRect.top  + textRect.height / 2.0f);
    if (haveShadow) {
      sText->setCharacterSize(size);
      sf::FloatRect textRect = sText->getLocalBounds();
      sText->setOrigin(textRect.left + textRect.width / 2.0f, textRect.top  + textRect.height / 2.0f);
    }
  }

  void LabelObject::setStyle(sf::Uint32 style) {
    text->setStyle(style);
    if (haveShadow) {
      sText->setStyle(style);
    }
  }

  void LabelObject::setOrientation(float rotation, sf::Vector2f position) {
    sf::FloatRect textRect = text->getLocalBounds();
    text->setOrigin(textRect.left + textRect.width / 2.0f, textRect.top  + textRect.height / 2.0f);
    text->setRotation(rotation);
    text->setPosition(position);
    if (haveShadow) {
      sf::FloatRect textRect = sText->getLocalBounds();
      sText->setOrigin(textRect.left + textRect.width / 2.0f, textRect.top  + textRect.height / 2.0f);
      sText->setRotation(rotation);
      sText->setPosition(position.x + offset, position.y + offset);
    }
  }

  void LabelObject::setOrientation(sf::Vector2f position) {
    setOrientation(text->getRotation(), position);
  }

  void LabelObject::setOrientation(float rotation) {
    setOrientation(rotation, text->getPosition());
  }

  LabelObject* LabelObject::makeDefault(std::string text, unsigned int size, sf::Vector2f position, sf::Color color) {
    setFont("../assets/fonts/Jupiter.ttf");
    setText(text);
    setColor(color);
    setSize(size);
    setOrientation(0, position);
    getRoom()->Instantiate(this);
    return this;
  }

  sf::Text* LabelObject::getText() {
    return text;
  }

  void LabelObject::makeShadow(int offset) {
    haveShadow = true;
    this->offset = offset;
    sText = new sf::Text(*text);
    sText->setFillColor(sf::Color(50, 50, 50));
    int posX = text->getPosition().x;
    int posY = text->getPosition().y;
    sText->setPosition(posX + offset, posY + offset);
  }

  void LabelObject::onDraw(Camera* camera, int64_t deltaTime) {
    if (haveShadow) {
      camera->draw(*sText);
    }
    camera->draw(*text);
  }
}