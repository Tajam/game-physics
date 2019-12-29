#include "Audio.h"

namespace tjm {

  std::map<std::string, sf::SoundBuffer*> Audio::soundCache;
  std::string Audio::playingMusic;
  sf::Music Audio::music;
  sf::Sound Audio::sound;

  void Audio::playSound(std::string fileName) {
    std::string path = "../assets/sounds/" + fileName;
    if (Audio::soundCache.find(fileName) != Audio::soundCache.end()) {
      Audio::sound.setBuffer(*Audio::soundCache[fileName]);
    } else {
      sf::SoundBuffer* buffer = new sf::SoundBuffer();
      if (buffer->loadFromFile(path.c_str())) {
        Audio::sound.setBuffer(*buffer);
        Audio::soundCache.insert(std::pair<std::string, sf::SoundBuffer*>(fileName, buffer));
      }
    }
    Audio::sound.play();
  }

  void Audio::playMusic(std::string fileName) {
    std::string path = "../assets/sounds/" + fileName;
    if (Audio::playingMusic != fileName) {
      Audio::playingMusic = fileName;
      Audio::music.stop();
      Audio::music.openFromFile(path.c_str());
      Audio::music.setLoop(true);
      Audio::music.setVolume(25.f);
      Audio::music.play();
    }
  }

}