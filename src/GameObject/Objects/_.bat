@echo off
echo    Building all game objects
for %%p in (
  PlayerObject/
  LabelObject/
  LevelSelectController/
  StartingPointObject/
  StartRoomController/
  TileMasterObject/
  WallMasterObject/
) do (
  cd %%p
  call _
  cd %~dp0
)