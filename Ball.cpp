#include "Ball.hpp"
#include <vector>

Ball::Ball(int radius, Vector2 position, Vector2 velocity, Color color) {
     this->radius = radius;
     this->position = position;
     this->velocity = velocity;
     this->color = color;
}

void Ball::update() {
     position.x += velocity.x;
     position.y += velocity.y;
}

void Ball::checkCollision() {
     if(position.x - radius <= 0 || position.x + radius >= GetScreenWidth()) {
          velocity.x *= -1;
     }

     if(position.y - radius <= 0 || position.y + radius >= GetScreenHeight()) {
          velocity.y *= -1;
     }
}

void Ball::draw() {
     DrawCircle(position.x, position.y, radius, color);
}