#include "raylib.h"

/**
 * Taken from raylib [textures] example - Background scrolling
 * https://www.raylib.com/examples.html
 */

int main(int argc, char* argv[])
{

	// Initialization
    //--------------------------------------------------------------------------------------
    // const int screenWidth = GetScreenWidth();
    // const int screenHeight = GetScreenHeight();
    const int screenWidth = 652*2;
    const int screenHeight = 358*2;

    InitWindow(screenWidth, screenHeight, "raylib [textures] example - background scrolling");

    // ToggleFullscreen();

    // NOTE: Be careful, background width must be equal or bigger than screen width
    // if not, texture should be draw more than two times for scrolling effect
    Texture2D background = LoadTexture("bu.webp.jpeg");

    float scrollingBack = 0.0f;

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        scrollingBack -= 5.0f;

        // NOTE: Texture is scaled twice its size, so it sould be considered on scrolling
        if (scrollingBack <= -background.width*2) scrollingBack = 0;
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(GetColor(0x052c46ff));

            // Draw background image twice
            // NOTE: Texture is scaled twice its size
            DrawTextureEx(background, (Vector2){ scrollingBack, 0 }, 0.0f, 2.0f, WHITE);
            DrawTextureEx(background, (Vector2){ background.width*2 + scrollingBack, 0 }, 0.0f, 2.0f, WHITE);

            DrawText("BACKGROUND SCROLLING & PARALLAX", 10, 10, 20, RED);
            DrawText("(c) Cyberpunk Street Environment by Luis Zuno (@ansimuz)", screenWidth - 330, screenHeight - 20, 10, RAYWHITE);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(background);  // Unload background texture

    CloseWindow();              // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

