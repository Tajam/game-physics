@echo off
echo    Building all rooms
for %%p in (
  CreditRoom/
  LevelRoom/
  StartRoom/
) do (
  cd %%p
  call _
  cd %~dp0
)