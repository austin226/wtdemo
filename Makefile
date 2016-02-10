all:
	mkdir -p ./lib
	cd wavelib; make
	cp wavelib/libwavelib.a lib/libwavelib.a
	gcc -o wtdemo main.c lib/libwavelib.a

clean:
	cd wavelib; make clean
	rm -f lib/*.a
	rm ./wtdemo
