@echo off
echo Build all sources
for %%p in (
  src/Audio/
  src/Camera/
  src/Collision/
  src/GameObject/
  src/GameObject/Objects/
  src/Room/
  src/Room/Rooms/
  src/Textures/
  src/
  obj/
) do (
  cd %%p
  call _
  cd %~dp0
)