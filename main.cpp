#include "raylib.h"
#include "raygui.h"
#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS

#include "Character.h"
#include "Item.h"
#include "Weapon.h"
#include "Armor.h"


#include "raylib.h"
#include "raylib.h"
#include <cstdio> // para sprintf
#include <iostream>

enum Direcao {
    BAIXO,
    ESQUERDA,
    DIREITA,
    CIMA
};

int main() {
    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "Boneco com animações por direção");
    SetTargetFPS(60);

    const int totalFrames = 24;
    Texture2D frames[totalFrames];

    // Carrega os 24 arquivos walk0.png até walk23.png
    for (int i = 0; i < totalFrames; i++) {
        char nome[32];
        sprintf(nome, "assets\\player\\PlayerWalk\\pwalk%d.png", i);
        frames[i] = LoadTexture(nome);
    }

    Vector2 pos = {screenWidth / 2.0f, screenHeight / 2.0f};
    const float velocidade = 200.0f;

    Direcao direcaoAtual = BAIXO;

    // Controle de animação
    float tempoFrame = 0;
    const float tempoPorFrame = 0.1f;
    int frameAtual = 0;

    // Intervalos de frames por direção
    const int frameInicio[] = { 0, 6, 12, 19 };
    const int frameFim[]    = { 5, 11, 18, 23 };

    while (!WindowShouldClose()) {
        float delta = GetFrameTime();
        bool andando = false;

        // Movimento e direção
        if (IsKeyDown(KEY_D)) {
            pos.x += velocidade * delta;
            direcaoAtual = DIREITA;
            andando = true;
        }
        if (IsKeyDown(KEY_A)) {
            pos.x -= velocidade * delta;
            direcaoAtual = ESQUERDA;
            andando = true;
        }
        if (IsKeyDown(KEY_W)) {
            pos.y -= velocidade * delta;
            direcaoAtual = CIMA;
            andando = true;
        }
        if (IsKeyDown(KEY_S)) {
            pos.y += velocidade * delta;
            direcaoAtual = BAIXO;
            andando = true;
        }

        // Atualização da animação
        if (andando) {
            tempoFrame += delta;
            if (tempoFrame >= tempoPorFrame) {
                tempoFrame = 0;
                frameAtual++;
                if (frameAtual > frameFim[direcaoAtual]) {
                    frameAtual = frameInicio[direcaoAtual];
                }
            }
            else if (frameAtual < frameInicio[direcaoAtual] || frameAtual > frameFim[direcaoAtual]) {
                frameAtual = frameInicio[direcaoAtual]; // Corrige se mudou de direção
            }
        } else {
            frameAtual = frameInicio[direcaoAtual]; // frame parado da direção
        }

        // Desenho
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTextureEx(frames[frameAtual], pos, 0.0f, 4.0f, WHITE);
        EndDrawing();
    }

    // Liberação de memória
    for (int i = 0; i < totalFrames; i++) {
        UnloadTexture(frames[i]);
    }

    CloseWindow();
    return 0;
}



