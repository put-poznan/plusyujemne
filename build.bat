@echo off

echo Building project...
rem liballegro-5.0.10-monolith-md.a
gcc src/main.c src/LinkedList.c src/util.c src/init.c src/input.c -o bin/dd.exe ^
-Wall -Wextra -g ^
-lallegro-5.0.10-monolith-md 

echo Finished