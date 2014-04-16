@echo off

echo Building project...
rem liballegro-5.0.10-monolith-md.a
gcc src/main.c -o bin/dd.exe -lallegro-5.0.10-monolith-md

echo Finished
