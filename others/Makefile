all:
	g++ -c src/*.cpp -c Vector2/*.cpp -std=c++14 -m64 -g -Wall -I include -I Vector2 && g++ *.o -o bin/debug/main -lSDL2main -lSDL2 -lSDL2_image
	g++ -c src/*.cpp -std=c++14 -m64 -O3 -Wall -I include && g++ *.o -o bin/release/main -s -lSDL2main -lSDL2 -lSDL2_image && ./bin/debug/main

debug:
	g++ -c src/*.cpp -c Vector2/*.cpp -std=c++14 -m64 -g -Wall -I include -I Vector2 && g++ *.o -o bin/debug/main -lSDL2main -lSDL2 -lSDL2_image && ./bin/debug/main

release:
	g++ -c src/*.cpp -c Vector2/*.cpp -std=c++14 -m64 -O3 -Wall -I include -I Vector2 && g++ *.o -o bin/release/main -s -lSDL2main -lSDL2 -lSDL2_image && ./bin/release/main
