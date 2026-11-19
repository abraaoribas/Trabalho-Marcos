#include "raylib.h"

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Pixel Rush");

    Vector2 ballPosition = { 400, 350 };

    float velocidade = 250.0f;
    float movimentoPista = 0.0f;

    const int pistaX = 200;
    const int pistaLargura = 400;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();

        if (IsKeyDown(KEY_D)) ballPosition.x += velocidade * dt;
        if (IsKeyDown(KEY_A)) ballPosition.x -= velocidade * dt;
        if (IsKeyDown(KEY_W)) ballPosition.y -= velocidade * dt;
        if (IsKeyDown(KEY_S)) ballPosition.y += velocidade * dt;

        if (ballPosition.x < pistaX + 20)
            ballPosition.x = pistaX + 20;

        if (ballPosition.x > pistaX + pistaLargura - 20)
            ballPosition.x = pistaX + pistaLargura - 20;

        if (ballPosition.y < 20)
            ballPosition.y = 20;

        if (ballPosition.y > screenHeight - 20)
            ballPosition.y = screenHeight - 20;

        movimentoPista += 200.0f * dt;

        if (movimentoPista >= 80)
            movimentoPista -= 80;

        BeginDrawing();

            ClearBackground(DARKGREEN);

            DrawRectangle(pistaX, 0, pistaLargura, screenHeight, DARKGRAY);

            DrawRectangle(pistaX, 0, 6, screenHeight, WHITE);
            DrawRectangle(pistaX + pistaLargura - 6, 0, 6, screenHeight, WHITE);

            for (int y = -80; y < screenHeight; y += 80)
            {
                DrawRectangle(330, y + (int)movimentoPista, 6, 40, RAYWHITE);
                DrawRectangle(465, y + (int)movimentoPista, 6, 40, RAYWHITE);
            }

            DrawCircleV(ballPosition, 20, RED);

            DrawText("PIXEL RUSH", 10, 10, 25, WHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
