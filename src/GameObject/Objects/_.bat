@echo off
echo    Building all game objects
for %%p in (
  LabelObject/
  TestObject/
  TestObject2/
) do (
  cd %%p
  call _
  cd %~dp0
)