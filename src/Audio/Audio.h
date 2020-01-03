/*******************************************
Course : TGD2251 Game Physics
Session: Trimester 2, 2019/20
ID and Name: 1161303917 OO JIN HENG
Contacts   : 0123482077 oojinheng@gmail.com
*******************************************/

#ifndef AUDIO_H
#define AUDIO_H

#include <string>
#include <map>
#include "../SFML/Audio.hpp"

namespace tjm {
  class Audio {
    public:
      // methods
      static void playSound(std::string fileName);
      static void playMusic(std::string fileName);

    private:
      // fields
      static std::map<std::string, sf::SoundBuffer*> soundCache;
      static sf::Music music;
      static std::vector<sf::Sound> sounds;
      static std::string playingMusic;
      static int soundCounter;

  };
}

#endif