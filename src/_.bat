@echo off
echo    Building all main objects
echo    - Building Game.o
g++ -c Game.cpp -o ../obj/Game.o -I .
echo    - Building Program.o
g++ -c Program.cpp -o ../obj/Program.o -I .