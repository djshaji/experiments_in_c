all:	main lib
main:
	g++ main.cxx -ldl -o shaji

lib:
	g++ -fPIC -shared lib.c -o lib.so
