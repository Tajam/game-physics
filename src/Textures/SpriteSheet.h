/*******************************************
Course : TGD2251 Game Physics
Session: Trimester 2, 2019/20
ID and Name: 1161303917 OO JIN HENG
Contacts   : 0123482077 oojinheng@gmail.com
*******************************************/

#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#include <string>
#include <vector>
#include "../SFML/Graphics.hpp"
#include "SpriteLoader.h"

namespace tjm {
  class SpriteSheet {
    public:
      // struct
      SpriteSheet(SpriteLoader loader);

      // setters
      void setInterval(int64_t miliseconds);
      void setFrame(int index);
      void setLoop(bool loop);
      void setTimeline(int start, int end, int jump);
      void flipLeft();
      void flipRight();

      // getters
      sf::Sprite getSprite();
      bool isPlaying();

      // methods
      void play();
      void stop();
      void step(int64_t timeDelta);

    private:
      // fields
      std::vector<sf::IntRect> rects;
      sf::Sprite sprite;

      // chrono
      int64_t interval;
      int64_t timing;

      // frames
      int index;
      int start;
      int end;
      int jump;

      // stats
      bool playing;
      bool loop;
  };
}

#endif