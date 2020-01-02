# Game Physics Project #1

This repository contains the assignment project for Game Physics (TGD 2251) subject which is fully or completely, without any assistance from any lecturers or students in Multimedia University, done by me (Oo Jin Heng 1161303917). The project is developed with the language, C++, with additional allowed third party library, [Box2D](https://github.com/erincatto/Box2D) and [SFML](https://github.com/SFML/SFML) only. The graphical and audio assets are taken online. To keep the project portable, the sources and library files of Box2D and SFML are included in this project.

This is my full info and contact. Please do not hesitate to contact me for any question or clarification.
```
  Name: Oo Jin Heng
    ID: 1161303917
Mobile: 012-3482077
 Email: oojinheng@gmail.com
```

The header comment for every source file
```
/*******************************************
Course : TGD2251 Game Physics
Session: Trimester 2, 2019/20
ID and Name: 1161303917 OO JIN HENG
Contacts   : 0123482077 oojinheng@gmail.com
*******************************************/
```

## Requirements

OS: Window 10 (Home)

Compiler: [MinGW Build 7.3.0 (32-bit)](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/7.3.0/threads-posix/dwarf/i686-7.3.0-release-posix-dwarf-rt_v5-rev0.7z/download)

**The G++ compiler version must match the requirement as SFML [depends on it](https://www.sfml-dev.org/download/sfml/2.5.1/)**

Disclaimer:

> The listed requirements above are based on the only tested environment during the development. Machine that meet the requirement or not, might or might not be able to build the project or run the program successfully. There is no guarantee.

## Building

In the command line terminal, move to the root folder of the project and execute `build`. The built executable can be found in `/bin` folder. The executable must remain in the folder to run. The game can also start by executing `run` at the root folder.

The executable file building mechanism is simple. The build batch file iterate through all the hardcoded path and execute another batch file that contains commands for compilation to create object files. Some sub-folder also contain the same type of batch file to create object files for its child folder's source code. Lastly, all the object files are linked together to make the final executable.

## Game Guide

### Controls

This is a simplified version. See documentation for detailed version.

| Scene                    | Controls                        |
|                 ---:     | :---                            |
| **Main menu**            | Up, down and enter              |
| **Level selection menu** | Up, down, left, right and enter |
| **Playing the level**    | Left, rigth, down and spacebar  |
| **Game over menu**       | Up, down and enter              |
| **Game clear menu**      | Just enter                      |

### Game rules

Each level will start within a 2 seconds margin time. Once the level starts, the players have only 10 seconds of time to swim to the exit of the level. If the players failed to do so, the whole level needs to restart. Otherwise, players will move on to the next level.

Consuming an air bubble will reset the 10 seconds timing which allow the players to travel longer distances in the level. Moreover, collecting a coin will grant players more scores upon completion of the level.

All the traps and enemies in game will kill players immediately upon contact. So beware.

## Personal Thought

It's fun to make a game using lower level libraries (Compared to nowadays game engine). I am really enjoying designing the object oriented programming structures, laying down all the classes and make the project file structure clean and nice. It is a good experience. However, this assignment is actually quite off topic from the knowledge we are expecting from this subject.

First off, take a glance at the project mark sheet. As a game development specialized student, I quickly realize that most of the mark for the project are for the game design skills and pure coding, structuring skills rather than the implementation of actual physics into game (30 + 34 vs 6). Even worse, the aesthetic aspect for the game worth more mark than the physics itself (10 vs 6).

Lastly, from a game designer standpoint, judging a game is fun to play or not is very subjective. Different people have different interest and taste for game. This is why we have so many type of games in this market because you can never make one single game that can statisfy 100% of the people in this world. Therefore, it is not fair to have a mark for this aspect.

In a nutshell, at this stage, my impression for this subject is a disaster. It is basically a normal highschool physics class for the lecture and a mixture of game design fundamental and object oriented programming course for the assignment project.