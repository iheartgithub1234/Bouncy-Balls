#include <raylib.h>
#include <vector>

class Ball {
     public:
          int radius;
          Vector2 position;
          Vector2 velocity;
          Color color;

          Ball(int radius, Vector2 position, Vector2 velocity, Color color);

          void update();

          void checkCollision();

          void draw();
};