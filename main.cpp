#include "raylib.h"

#define CANVAS_WIDTH 640
#define CANVAS_HEIGHT 480

void DrawGameWindow()
{
    InitWindow(CANVAS_WIDTH, CANVAS_HEIGHT, "Geometry War");
}

int main()
{
    DrawGameWindow();

    int circleStartPositionX = CANVAS_WIDTH * 0.2f;
    int circleStartPositionY = CANVAS_HEIGHT / 2;

    int circlePositionX = circleStartPositionX;
    int circlePositionY = circleStartPositionY;
    int circleRadius = 24;
    int playerSpeed = 10;

    int enemyPositionX = 500;
    int enemyPostionY = 0;
    int enemySquareSize = 50;
    int enemySpeed = 5;

    int safetySquareSize = 100;
    int safetyPositionX = CANVAS_WIDTH - (safetySquareSize / 2);
    int safetyPositionY = (CANVAS_HEIGHT / 2) - (safetySquareSize / 2);

    bool catchByEnemy = false;
    bool arriveSafety = false;

    int level = 0;

    SetTargetFPS(60);
    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(WHITE);

        if (catchByEnemy)
        {
            DrawText("Game Over!", 180, 200, 60, RED);
        }
        else
        {
            int leftCircleX = circlePositionX - circleRadius;
            int rightCircleY = circlePositionX + circleRadius;
            int upCircleY = circlePositionY - circleRadius;
            int botCircleY = circlePositionY + circleRadius;

            int leftEnemyX = enemyPositionX;
            int rightEnemyX = enemyPositionX + enemySquareSize;
            int upEnemyY = enemyPostionY;
            int botEnemyY = enemyPostionY + enemySquareSize;
            catchByEnemy =
                (botEnemyY >= upCircleY) &&
                (upEnemyY <= botCircleY) &&
                (rightEnemyX >= leftCircleX) &&
                (leftEnemyX <= rightCircleY);

            int leftSafetyX = safetyPositionX;
            arriveSafety = (leftSafetyX <= rightCircleY);

            if (arriveSafety)
            {
                level++;
                circlePositionX = circleStartPositionX;
                circlePositionY = circleStartPositionY;
                if (enemySpeed > 0)
                {
                    enemySpeed++;
                }
                else
                {
                    enemySpeed--;
                }
            }

            DrawCircle(circlePositionX, circlePositionY, circleRadius, BLUE);
            DrawRectangle(enemyPositionX, enemyPostionY, enemySquareSize, enemySquareSize, RED);
            DrawRectangle(safetyPositionX, safetyPositionY, safetySquareSize, safetySquareSize, BLUE);

            DrawText(TextFormat("Level: %i", level), 10, 10, 20, LIME);

            enemyPostionY += enemySpeed;
            if (enemyPostionY > CANVAS_HEIGHT || enemyPostionY < 0)
            {
                enemySpeed = -enemySpeed;
            }

            if (IsKeyDown(KEY_D) && circlePositionX < CANVAS_WIDTH - circleRadius)
            {
                circlePositionX += playerSpeed;
            }
            if (IsKeyDown(KEY_A) && circlePositionX > 0 + circleRadius)
            {
                circlePositionX -= playerSpeed;
            }
        }
        
        EndDrawing();
    }
}