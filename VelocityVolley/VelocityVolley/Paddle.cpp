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

float Paddle::getPaddleWidth() const {
    return paddle_width;
}

float Paddle::getPaddleHeight() const {
    return paddle_height;
}

float Paddle::getPaddleX() const {
    return paddle_x;
}

float Paddle::getPaddleY() const {
    return paddle_y;
}

int Paddle::getPaddleSpeed() const {
    return paddle_speed;
}

int Paddle::getSegment() const {
    return segment;
}

float Paddle::getRoundness() const {
    return roundness;
}

Color Paddle::getPaddleColor() const {
    return paddle_color;
}

// Setter functions
void Paddle::setPaddleWidth(float width) {
    paddle_width = width;
}

void Paddle::setPaddleHeight(float height) {
    paddle_height = height;
}

void Paddle::setPaddleX(float x) {
    paddle_x = x;
}

void Paddle::setPaddleY(float y) {
    paddle_y = y;
}

void Paddle::setPaddleSpeed(int speed) {
    paddle_speed = speed;
}

void Paddle::setSegment(int s) {
    segment = s;
}

void Paddle::setRoundness(float r) {
    roundness = r;
}

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