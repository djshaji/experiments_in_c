all:	main lib plugin
main:
	g++ -fPIC main.cxx -ldl -o shaji -L/home/djshaji/Desktop/Projects/shaji++ -lplugin
plugin:
	g++ -fPIC -shared plugin.c -o libplugin.so
lib:
	g++ -fPIC -shared lib.c -o lib.so
amp:
	g++ -fPIC -shared amp.c -o ampx.so
