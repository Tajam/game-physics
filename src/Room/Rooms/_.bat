@echo off
echo    Building all rooms
for %%p in (
  CreditRoom/
  GameRoom/
  LevelRoom/
  StartRoom/
) do (
  cd %%p
  call _
  cd %~dp0
)