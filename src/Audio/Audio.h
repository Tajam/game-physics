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
      static sf::Sound sound;
      static std::string playingMusic;

  };
}

#endif