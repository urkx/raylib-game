#include "raylib.h"
#include <stdio.h>

/**
 * Taken from raylib [textures] example - Background scrolling
 * https://www.raylib.com/examples.html
 */

int main(int argc, char* argv[])
{

	// Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();
    //const int screenWidth = 652*2;
    //const int screenHeight = 358*2;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "Calendario vacaciones");

    // ToggleFullscreen();

    // NOTE: Be careful, background width must be equal or bigger than screen width
    // if not, texture should be draw more than two times for scrolling effect
    Texture2D background = LoadTexture("2025-lista.jpg");
    Texture2D header = LoadTexture("2025-header.jpg");

    float scrollingBack = 0.0f;
    float headerInit = 0.0f;

    const int verticalOffset = 100; 

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        scrollingBack -= 2.5f;

        // NOTE: Texture is scaled twice its size, so it sould be considered on scrolling
        if (scrollingBack <= -background.width) scrollingBack = 0;
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(GetColor(0x052c46ff));

            // Draw background image twice
            // NOTE: Texture is scaled twice its size
            DrawTextureEx(background, (Vector2){ scrollingBack + 357.0f, verticalOffset }, 0.0f, 1.0f, WHITE);
            DrawTextureEx(background, (Vector2){ background.width + scrollingBack + 357.0f, verticalOffset }, 0.0f, 1.0f, WHITE);
            DrawTextureEx(header, (Vector2){ headerInit, verticalOffset }, 0.0f, 1.0f, WHITE);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(background);  // Unload background texture
    UnloadTexture(header);

    CloseWindow();              // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

