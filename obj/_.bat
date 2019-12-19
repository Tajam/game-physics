@echo off
echo Linking objects
echo  - Building main.exe
g++ *.o -o ../bin/main.exe -L ../src/Box2D -L ../src/SFML/lib -lBox2D -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
