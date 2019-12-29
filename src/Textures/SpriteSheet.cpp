#include "SpriteSheet.h"

namespace tjm {
  SpriteSheet::SpriteSheet(SpriteLoader loader) {
    rects = loader.getRect();
    sprite = loader.getSprite();
    timing = 0;
    interval = 166667;
    index = 0;
    start = 0;
    end = rects.size() - 1;
    jump = 1;
    playing = false;
    sprite.setOrigin(rects[index].width / 2, rects[index].height / 2);
  }

  void SpriteSheet::setInterval(int64_t miliseconds) {
    interval = miliseconds;
  }

  void SpriteSheet::setFrame(int index) {
    this->index = index;
  }

  void SpriteSheet::setLoop(bool loop) {
    this->loop = loop;
  }

  void SpriteSheet::setTimeline(int start, int end, int jump) {
    if (start < 0) {
      this->start = 0;
    } else {
      this->start = start;
    }
    
    if (end >= rects.size()) {
      this->end = rects.size() - 1;
    } else {
      this->end = end;
    }
    
    this->jump = jump;
  }

  void SpriteSheet::flipLeft() {
    sprite.setScale(-1, 1);
  }

  void SpriteSheet::flipRight() {
    sprite.setScale(1, 1);
  }

  sf::Sprite SpriteSheet::getSprite() {
    sprite.setTextureRect(rects[index]);
    return sprite;
  }

  bool SpriteSheet::isPlaying() {
    return playing;
  }

  void SpriteSheet::play() {
    playing = true;
  }

  void SpriteSheet::stop() {
    playing = false;
    timing = 0;
    index = start;
  }

  void SpriteSheet::step(int64_t timeDelta) {
    if (!playing) {
      return;
    }
    timing += timeDelta;
    while (timing >= interval) {
      timing -= interval;
      index += jump;
      if (index > end) {
        if (loop) {
          index = start;
        } else {
          stop();
        }
      }
    }
  }
}