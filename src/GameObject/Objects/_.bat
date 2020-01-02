@echo off
echo    Building all game objects
for %%p in (
  AirBubbleObject/
  CoinObject/
  DoorObject/
  DynamicWallObject/
  EndingPointObject/
  EnemyObject/
  GameClearObject/
  GameFailObject/
  LabelObject/
  LevelSelectController/
  PlayerObject/
  StartingPointObject/
  StartRoomController/
  SwitchObject/
  TileMasterObject/
  TimerDisplayObject/
  TrapObject/
  WallMasterObject/
) do (
  cd %%p
  call _
  cd %~dp0
)