//gcc main.c -o main.exe -IC:\raylib\w64devkit\include -LC:\raylib\w64devkit\lib -lraylib -lopengl32 -lgdi32 -lwinmm
#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

__uint128_t g_lehmer64_state;

uint64_t lehmer64() {
  g_lehmer64_state *= 0xda942042e4dd58b5;
  return g_lehmer64_state >> 64;
}


int main(int argc, char *argv[]) {
	if (argc <= 3) {
		printf("NOT ENOUGH ARGUMENTS (width height framerate)");
		return 1;
	}

	const int screenWidth = atoi(argv[1]);
    const int screenHeight = atoi(argv[2]);

    g_lehmer64_state = (__uint128_t)time(NULL);

    InitWindow(screenWidth, screenHeight, "Babel: The Movie");
    SetTargetFPS(atoi(argv[3]));
    
    while (!WindowShouldClose()) {
    	printf("%d\n", GetFPS());

    	BeginDrawing();
    	for(int x = 0; x < screenWidth; x++) {
            for(int y = 0; y < screenHeight; y++) {
                DrawPixel(x, y, ColorFromHSV( (float)lehmer64()*5.421010862427522e-20f  * 360, 
                                            (float)lehmer64()*5.421010862427522e-20f , 
                                            (float)lehmer64()*5.421010862427522e-20f ));
            }
        }
 		
    	EndDrawing();
    }
    return 0;
}