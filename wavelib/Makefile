libwavelib: wavelib
	ar rcs libwavelib.a obj/*.o

wavelib: wtmath src/wavelib.h src/wavelib.c
	gcc -c src/wavelib.c -o obj/wavelib.o

wtmath: wavefilt src/wtmath.h src/wtmath.c
	gcc -c src/wtmath.c -o obj/wtmath.o

wavefilt: conv src/wavefilt.h src/wavefilt.c
	gcc -c src/wavefilt.c -o obj/wavefilt.o

conv: real src/conv.h src/conv.c
	gcc -c src/conv.c -o obj/conv.o

real: hsfft src/real.h src/real.c
	gcc -c src/real.c -o obj/real.o

hsfft: src/hsfft.h src/hsfft.c
	mkdir -p ./obj
	gcc -c src/hsfft.c -o obj/hsfft.o

clean:
	rm -f obj/*.o
	rm -f libwavelib.a
