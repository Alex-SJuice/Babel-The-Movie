//gcc main.c -o main.exe -IC:\raylib\w64devkit\include -LC:\raylib\w64devkit\lib -lraylib -lopengl32 -lgdi32 -lwinmm
#include "raylib.h"
#include <stdlib.h>
#include <time.h>

int main(void) {
	const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Babel: The Movie");

    SetTargetFPS(60);

    srand(time(NULL));
    
    while (!WindowShouldClose()) {
    	BeginDrawing();
    	for(int x = 0; x < screenWidth; x++) {
    		for(int y = 0; y < screenHeight; y++) {
    			DrawPixel(x, y, ColorFromHSV((float)rand()/RAND_MAX * 360, (float)rand()/RAND_MAX, (float)rand()/RAND_MAX));
    		}
    	}
    	EndDrawing();
    }
}