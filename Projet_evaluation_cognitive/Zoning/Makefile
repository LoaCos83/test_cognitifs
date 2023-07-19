run: zoning
	@./zoning

zoning: zoning.o ../LibrairieGraphique/libisentlib.a
	gcc -Wall zoning.o -o zoning ../LibrairieGraphique/libisentlib.a -lm -lglut -lGL -lX11

zoning.o: zoning.c ../LibrairieGraphique/GfxLib.h ../LibrairieGraphique/BmpLib.h ../LibrairieGraphique/ESLib.h
	gcc -Wall -c zoning.c

clean:
	rm zoning *.o
