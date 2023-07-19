run: main
	@./main

main: main.o ./Zoning/zoning.o ./LibrairieGraphique/libisentlib.a
	gcc -Wall main.o zoning.o -o main ./LibrairieGraphique/libisentlib.a -lm -lglut -lGL -lX11

main.o: main.c ./LibrairieGraphique/GfxLib.h ./LibrairieGraphique/BmpLib.h ./LibrairieGraphique/ESLib.h
	gcc -Wall -c main.c

./Zoning/zoning.o: ./Zoning/zoning.c ./LibrairieGraphique/GfxLib.h ./LibrairieGraphique/BmpLib.h ./LibrairieGraphique/ESLib.h
		gcc -Wall -c ./Zoning/zoning.c

clean:
	rm *.o  main zoning
