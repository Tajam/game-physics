@echo off
echo    Building all game objects
for %%p in (
  CoinObject/
  EndingPointObject/
  GameClearObject/
  GameFailObject/
  LabelObject/
  LevelSelectController/
  PlayerObject/
  StartingPointObject/
  StartRoomController/
  TileMasterObject/
  TrapObject/
  WallMasterObject/
) do (
  cd %%p
  call _
  cd %~dp0
)