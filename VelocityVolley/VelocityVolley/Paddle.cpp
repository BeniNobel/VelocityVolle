/***************************************
* Beni Nobel inganji
* File name: Ball.cpp
* Description: This file contains the function definitions for the Paddle class.
*****************************************/

// Include directives
#include "Game.h"

/**
  Limits the paddle's vertical movement to stay within the top and bottom screen boundaries.
*/
void Paddle::limitPaddleRange() {
    // Ensure the paddle cannot go above the top of the screen
    if (paddle_y <= 0) {
        paddle_y = 0;
    }

    // Ensure the paddle cannot go below the bottom of the screen
    if (paddle_y + paddle_height >= GetScreenHeight()) {
        paddle_y = GetScreenHeight() - paddle_height;
    }
}

// Getter functions

/**
  Returns the width of the paddle.
  @return - width of the paddle
*/
float Paddle::getPaddleWidth() const {
    return paddle_width;
}

/**
  Returns the height of the paddle.
  @return - height of the paddle
*/
float Paddle::getPaddleHeight() const {
    return paddle_height;
}

/**
  Returns the x-coordinate of the paddle.
  @return - x-coordinate of the paddle
*/
float Paddle::getPaddleX() const {
    return paddle_x;
}

/**
  Returns the y-coordinate of the paddle.
  @return - y-coordinate of the paddle
*/
float Paddle::getPaddleY() const {
    return paddle_y;
}

/**
  Returns the speed of the paddle.
  @return - speed of the paddle
*/
int Paddle::getPaddleSpeed() const {
    return paddle_speed;
}

/**
  Returns the segment of the paddle.
  @return - segment of the paddle
*/
int Paddle::getSegment() const {
    return segment;
}

/**
  Returns the roundness of the paddle.
  @return - roundness of the paddle

*/
float Paddle::getRoundness() const {
    return roundness;
}

/**
  Returns the color of the paddle.
  @return - color of the paddle
*/
Color Paddle::getPaddleColor() const {
    return paddle_color;
}

// Setter functions

/**
  Sets the width of the paddle.
  @param width - width of the paddle
*/
void Paddle::setPaddleWidth(float width) {
    paddle_width = width;
}

/**
  Sets the height of the paddle.
  @param height - height of the paddle
*/
void Paddle::setPaddleHeight(float height) {
    paddle_height = height;
}

/**
  Sets the x-coordinate of the paddle.
  @param x - x-coordinate of the paddle
*/
void Paddle::setPaddleX(float x) {
    paddle_x = x;
}

/**
  Sets the y-coordinate of the paddle.
  @param y - y-coordinate of the paddle
*/
void Paddle::setPaddleY(float y) {
    paddle_y = y;
}

/**
  Sets the speed of the paddle.
  @param speed - speed of the paddle
*/
void Paddle::setPaddleSpeed(int speed) {
    paddle_speed = speed;
}

/**
  Sets the segment of the paddle.
  @param s - segment of the paddle
*/
void Paddle::setSegment(int s) {
    segment = s;
}

/**
  Sets the roundness of the paddle.
  @param r - roundness of the paddle
*/
void Paddle::setRoundness(float r) {
    roundness = r;
}

/**
  Sets the color of the paddle.
  @param color - color of the paddle
*/
void Paddle::setPaddleColor(Color color) {
    paddle_color = color;
}


/**
  Draws the player-controlled paddle on the screen using a rounded rectangle.
*/
void Paddle::drawPaddle() {
    // Draw the rounded rectangle representing the paddle
    DrawRectangleRounded({ paddle_x, paddle_y, paddle_width, paddle_height }, roundness, segment, paddle_color);
}

/**
  Updates the position of the player-controlled paddle based on keyboard input (UP and DOWN keys).
*/
void Paddle::updatePaddle() {
    // Move the paddle up if the UP key is pressed
    if (IsKeyDown(KEY_UP)) {
        paddle_y = paddle_y - paddle_speed;
    }

    // Move the paddle down if the DOWN key is pressed
    if (IsKeyDown(KEY_DOWN)) {
        paddle_y = paddle_y + paddle_speed;
    }

    // Limit the paddle's range to stay within the screen boundaries
    limitPaddleRange();
}

/**
  Updates the position of the AI-controlled paddle based on the vertical position of the ball.
*/
void AIPaddle::updatePaddleAI(int ball_y) {
    // Calculate the target position for the AI paddle
    float targetPosition = ball_y - paddle_height / 2;

    // Gradually adjust the AI paddle's position towards the target
    if (paddle_y < targetPosition) {
        paddle_y = fmin(paddle_y + paddle_speed, targetPosition);
    }
    // If the current position is above the target, move down
    else if (paddle_y > targetPosition) {
        paddle_y = fmax(paddle_y - paddle_speed, targetPosition);
    }

    // Limit the AI paddle's range to stay within the screen boundaries
    limitPaddleRange();
}