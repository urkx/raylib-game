#include "raylib.h"

int main(int argc, char* argv[])
{

	int screenX = 300;
	int screenY = 500;

	InitWindow(screenX, screenY, "La ventana");

	SetTargetFPS(60);

	while(!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(RAYWHITE);

		DrawText("Hey", 190, 200, 20, LIGHTGRAY);

		EndDrawing();
	}

	CloseWindow();

	return 0;
}

