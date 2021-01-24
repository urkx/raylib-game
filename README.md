compilado de main.c: 

	- gcc -c main.c -o main.o -Wall -std=c99 -I/usr/local/include
	- gcc -o main main.o -Wall -std=c99 -I/usr/local/include -L/usr/local/lib -L/home/urko/projects/raylib/src  -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -DPLATFORM_DESKTOP
