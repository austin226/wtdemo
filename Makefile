all:
	mkdir -p ./lib
	cd wavelib; make
	cp wavelib/libwavelib.a lib/libwavelib.a

clean:
	cd wavelib; make clean
	rm -f lib/*.a
