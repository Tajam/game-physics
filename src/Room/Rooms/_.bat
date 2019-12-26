@echo off
echo    Building all rooms
for %%p in (
  StartRoom/
) do (
  cd %%p
  call _
  cd %~dp0
)