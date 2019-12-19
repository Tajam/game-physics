@echo off
echo    Building all game objects
for %%p in (
  TestObject/
) do (
  cd TestObject/
  call _
  cd %~dp0
)