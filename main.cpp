#include <cstdio>
#include "raylib.h"

int main()
{
    int width = 640;
    int height = 480;

    InitWindow(width, height, "Geometry War");

    while (true)
    {
        BeginDrawing();
        ClearBackground(WHITE); //  To avoid Black Flickering
        EndDrawing();
    }
}