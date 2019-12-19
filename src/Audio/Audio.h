#ifndef AUDIO_H
#define AUDIO_H

#include <string>
#include <map>
#include "../SFML/Audio.hpp"

namespace tjm {
  class Audio {
    public:
      // methods
      Audio(std::string fileName, bool isMusic);
      Audio(std::string);
      ~Audio();
      sf::Sound* getSound();
      sf::Music* getMusic();

    private:
      // cache
      static std::map<std::string, sf::SoundBuffer*> soundCache;

      // fields
      bool isMusic;
      sf::Sound* sound;
      sf::Music* music;

  };
}

#endif