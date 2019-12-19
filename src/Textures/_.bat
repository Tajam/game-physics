@echo off
echo    Building all graphical objects
echo    - Building SpriteLoader.o
g++ -c SpriteLoader.cpp -o ../../obj/SpriteLoader.o -I ..
echo    - Building SpriteSheet.o
g++ -c SpriteSheet.cpp -o ../../obj/SpriteSheet.o -I ..