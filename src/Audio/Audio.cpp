#include "Audio.h"

namespace tjm {

  std::map<std::string, sf::SoundBuffer*> Audio::soundCache;

  Audio::Audio(std::string fileName, bool isMusic) {
    if (isMusic) {
      this->music = new sf::Music();
      this->music->openFromFile(fileName.c_str());
    } else {
      this->sound = new sf::Sound();
      if (Audio::soundCache.find(fileName) != Audio::soundCache.end()) {
        this->sound->setBuffer(*Audio::soundCache[fileName]);
      } else {
        sf::SoundBuffer* buffer = new sf::SoundBuffer();
        if (buffer->loadFromFile(fileName.c_str())) {
          this->sound->setBuffer(*buffer);
          Audio::soundCache.insert(std::pair<std::string, sf::SoundBuffer*>(fileName, buffer));
        }
      }
    }
  }

  Audio::Audio(std::string fileName): Audio::Audio(fileName, false) { }

  Audio::~Audio() {
    delete sound;
    delete music;
    sound = NULL;
    music = NULL;
  }

  sf::Music* Audio::getMusic() {
    if (isMusic) {
      return music;
    }
    return NULL;
  }

  sf::Sound* Audio::getSound() {
    if (!isMusic) {
      return sound;
    }
    return NULL;
  }

}