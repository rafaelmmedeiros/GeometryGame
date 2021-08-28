#include <cstdio>
#include "raylib.h"

#define CANVAS_WIDTH 640
#define CANVAS_HEIGHT 480

int main()
{
    //  Circle Start Point
    int circleX = CANVAS_WIDTH * 0.2f;
    int circleY = CANVAS_HEIGHT / 2;

    int level = 0;

    int circleSpeed = 10;
    int circleRadius = 24;

    int squareSpeed = 10;
    int rectPositionY = 0;
    bool IsGoindDown = true;

    InitWindow(CANVAS_WIDTH, CANVAS_HEIGHT, "Geometry War");

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        //  USER CONTROL INTERFACE
        if (IsKeyDown(KEY_D) && circleX < CANVAS_WIDTH - circleRadius)
        {
            circleX += circleSpeed;
        }
        if (IsKeyDown(KEY_A) && circleX > 0 + circleRadius)
        {
            circleX -= circleSpeed;
        }
        if (IsKeyDown(KEY_W) && circleY > 0 + circleRadius)
        {
            circleY -= circleSpeed;
        }
        if (IsKeyDown(KEY_S) && circleY < CANVAS_HEIGHT - circleRadius)
        {
            circleY += circleSpeed;
        }

        //  SQUARE BEHAVIOR
        if (IsGoindDown)
        {
            rectPositionY += squareSpeed;
            if (rectPositionY == CANVAS_HEIGHT)
            {
                IsGoindDown = !IsGoindDown;
            }
        }

        if (!IsGoindDown)
        {
            rectPositionY -= squareSpeed;
            if (rectPositionY == 0)
            {
                IsGoindDown = !IsGoindDown;
            }
        }

        //  CANVAS DRAWNING
        BeginDrawing();
        ClearBackground(WHITE); //  To avoid Black Flickering

        DrawCircle(circleX, circleY, circleRadius, BLUE);

        DrawRectangle(CANVAS_WIDTH / 5 * 4, rectPositionY, 50, 50, RED);

        DrawText(TextFormat("Level: %i", level), 20, 2, 22, BLACK);

        EndDrawing();
    }
}