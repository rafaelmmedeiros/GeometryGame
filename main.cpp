#include <cstdio>
#include "raylib.h"

int main()
{
    int width = 640;
    int height = 480;

    InitWindow(width, height, "Geometry War");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE); //  To avoid Black Flickering

        DrawCircle(width / 2, height / 2, 150, BLUE);
        DrawCircle(width / 2, height / 2, 100, RED);

        EndDrawing();
    }
}