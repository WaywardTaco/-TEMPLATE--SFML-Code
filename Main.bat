
IF EXIST Main.o DEL /F Main.o
IF EXIST Main.exe DEL /F Main.exe
g++ -std=gnu++11 -c main.cpp -ILibrary/SFML-2.5.1/include -DSFML_STATIC
g++ -std=gnu++11 -Wall Main.o -o Main -LLibrary/SFML-2.5.1/lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -lsfml-main

IF EXIST Main.exe cls
IF EXIST Main.exe CALL Main.exe
