/*******************************************
Course : TGD2251 Game Physics
Session: Trimester 2, 2019/20
ID and Name: 1161303917 OO JIN HENG
Contacts   : 0123482077 oojinheng@gmail.com
*******************************************/

#include "Audio.h"

namespace tjm {

  std::map<std::string, sf::SoundBuffer*> Audio::soundCache;
  std::string Audio::playingMusic;
  sf::Music Audio::music;
  std::vector<sf::Sound> Audio::sounds {
    sf::Sound(), sf::Sound(), sf::Sound()
  };
  int Audio::soundCounter = 0;

  void Audio::playSound(std::string fileName) {
    std::string path = "../assets/sounds/" + fileName;
    if (Audio::soundCache.find(fileName) != Audio::soundCache.end()) {
      Audio::sounds[Audio::soundCounter].setBuffer(*Audio::soundCache[fileName]);
    } else {
      sf::SoundBuffer* buffer = new sf::SoundBuffer();
      if (buffer->loadFromFile(path.c_str())) {
        Audio::sounds[Audio::soundCounter].setBuffer(*buffer);
        Audio::soundCache.insert(std::pair<std::string, sf::SoundBuffer*>(fileName, buffer));
      }
    }
    Audio::sounds[Audio::soundCounter].play();
    Audio::soundCounter++;
    if (Audio::soundCounter >= 3) {
      Audio::soundCounter = 0;
    }
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