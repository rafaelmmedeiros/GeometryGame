#include <cstdio>
#include "raylib.h"

int main()
{
    const int width = 640;
    const int height = 480;

    InitWindow(width, height, "Geometry War");

    int circleX = width * 0.2f;
    int circleY = height / 2;

    int speed = 10;
    int challengeSpeed = 10;
    int level = 0;

    int rectPositionY = 0;

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        if (IsKeyDown(KEY_D) && circleX < width)
        {
            circleX += speed;
        }
        if (IsKeyDown(KEY_A) && circleX > 0)
        {
            circleX -= speed;
        }
        if (IsKeyDown(KEY_W) && circleY > 0)
        {
            circleY -= speed;
        }
        if (IsKeyDown(KEY_S) && circleY < height)
        {
            circleY += speed;
        }

        rectPositionY += challengeSpeed;

        // RESET RECT POSITION
        if (rectPositionY == height)
        {
            rectPositionY = 0;
        }

        BeginDrawing();
        ClearBackground(WHITE); //  To avoid Black Flickering

        DrawCircle(circleX, circleY, 25, BLUE);

        DrawRectangle(width / 5 * 4, rectPositionY, 50, 50, RED);

        DrawText(TextFormat("Level: %i", level), 20, 2, 22, BLACK);

        EndDrawing();
    }
}