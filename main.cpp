#include <raylib.h>
#include "Ball.hpp"
#include <vector>
#include <random>

int amount = 10;
int windowHeight = 1800;
int windowLength = 800;
int frameRate = 60;
int speedRange = 10;

int randomNumber(int min, int max) {
     std::random_device rd;
     std::mt19937 gen(rd());
     std::uniform_int_distribution<> dis(min, max);

     return dis(gen);
}

int main() {
     SetTraceLogLevel(LOG_ERROR);
     InitWindow(windowHeight, windowLength, "Ball Animation");
     SetTargetFPS(frameRate);

     std::vector<Ball> balls;
     std::vector<Color> colors = {RED, BLUE, GREEN, YELLOW, ORANGE, PURPLE};

     for(int i = 0; i < amount; i++) {
          Color color = colors[i % colors.size()];
          float radius = randomNumber(5, 100);
          float positionX = randomNumber(radius + 1, GetScreenWidth() - radius - 1);
          float positionY = randomNumber(radius + 1, GetScreenHeight() - radius - 1);
          float velocityX = randomNumber(-speedRange, speedRange);
          float velocityY = randomNumber(-speedRange, speedRange);

          Ball ballElement = Ball(radius, {positionX, positionY}, {velocityX, velocityY}, color);
          balls.push_back(ballElement);
     }

     while(!WindowShouldClose()) {
          BeginDrawing();

          ClearBackground(LIGHTGRAY);

          for(int i = 0; i < balls.size(); i++) {
               balls[i].update();
               balls[i].checkCollision();
               balls[i].draw();
          }

          EndDrawing();
     }

     CloseWindow();

     return 0;
}