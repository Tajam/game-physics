#include "LabelObject.h"

namespace tjm {
  LabelObject::LabelObject(Room* room) :  GameObject(room) {
    _haveBody = false;
    _haveSprite = false;
    font = new sf::Font();
    text = new sf::Text();
    setTag("ui");
  }

  LabelObject::~LabelObject() {
    delete font;
    font = nullptr;
    delete text;
    text = nullptr;
  }

  void LabelObject::setFont(std::string fileName) {
    font->loadFromFile(fileName.c_str());
    text->setFont(*font);
  }

  void LabelObject::setText(std::string message) {
    text->setString(message);
  }

  void LabelObject::setColor(sf::Color color) {
    text->setFillColor(color);
  }

  void LabelObject::setSize(unsigned int size) {
    text->setCharacterSize(size);
    sf::FloatRect textRect = text->getLocalBounds();
    text->setOrigin(textRect.left + textRect.width / 2.0f, textRect.top  + textRect.height / 2.0f);
  }

  void LabelObject::setStyle(sf::Uint32 style) {
    text->setStyle(style);
  }

  void LabelObject::setOrientation(float rotation, sf::Vector2f position) {
    sf::FloatRect textRect = text->getLocalBounds();
    text->setOrigin(textRect.left + textRect.width / 2.0f, textRect.top  + textRect.height / 2.0f);
    text->setRotation(rotation);
    text->setPosition(position);
  }

  void LabelObject::setOrientation(sf::Vector2f position) {
    setOrientation(text->getRotation(), position);
  }

  void LabelObject::setOrientation(float rotation) {
    setOrientation(rotation, text->getPosition());
  }

  sf::Text* LabelObject::getText() {
    return text;
  }

  void LabelObject::onDraw(Camera* camera, int64_t deltaTime) {
    camera->draw(*text);
  }
}