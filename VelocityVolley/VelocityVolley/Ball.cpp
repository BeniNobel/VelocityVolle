/***************************************
* Beni Nobel inganji
* File name: Ball.cpp
* Description: This file contains the function definitions for the Ball class.
*****************************************/

// Include directives
#include "Game.h"

/**
  Draws the ball on the screen.
*/
void Ball::drawBall() {
    DrawCircle(ball_x, ball_y, ball_radius, ball_color);
}

/**
  Updates the ball's position based on its speed, checks for collisions with screen boundaries, updates scores, and resets the ball.
*/
void Ball::updateBall() {
    // Update the ball's position based on its speed
    ball_x += speed_x;
    ball_y += speed_y;

    // Check for collision with top or bottom screen boundaries and reverse speed if necessary
    if (ball_y + ball_radius >= GetScreenHeight() || ball_y - ball_radius <= 0) {
        speed_y *= -1;
    }

    // Check for collision with the right screen boundary (AI scores), update scores, and reset the ball
    if (ball_x + ball_radius >= GetScreenWidth()) {
        ai_score++;
        resetBall();
    }

    // Check for collision with the left screen boundary (Player scores), update scores, and reset the ball
    if (ball_x - ball_radius <= 0) {
        player_score++;
        resetBall();
    }
}

/**
  Resets the ball's position to the center of the screen and randomizes its speed direction.
*/
void Ball::resetBall() {
    // Reset the ball to the center of the screen
    ball_x = GetScreenWidth() / 2;
    ball_y = GetScreenHeight() / 2;

    // Define an array of two choices (-1 and 1) for randomizing speed direction
    int directionChoices[2] = { -1, 1 };

    // Randomly choose a direction for the ball's speed in the x and y directions
    speed_x *= directionChoices[GetRandomValue(0, 1)];
    speed_y *= directionChoices[GetRandomValue(0, 1)];
}

// Setter functions

/**
  Function to set the x-coordinate of the ball
*/
void Ball::setBallX(float x) {
    ball_x = x;
}

/**
  Function to set the y-coordinate of the ball
*/
void Ball::setBallY(float y) {
    ball_y = y;
}

/**
  Function to set the speed of the ball in the x direction
*/
void Ball::setSpeedX(float speedX) {
    speed_x = speedX;
}

/**
  Function to set the speed of the ball in the y direction
*/
void Ball::setSpeedY(float speedY) {
    speed_y = speedY;
}

/**
  Function to set the radius of the ball
*/
void Ball::setBallRadius(int radius) {
    ball_radius = radius;
}

/*
  Function to set the color of the ball
*/
void Ball::setBallColor(Color color) {
    ball_color = color;
}

// Getter functions

/**
  Function to get the x-coordinate of the ball
*/
float Ball::getBallX() const {
    return ball_x;
}


/**
  Function to get the y-coordinate of the ball
*/
float Ball::getBallY() const {
    return ball_y;
}

/**
  Function to get the speed of the ball in the x direction
*/
float Ball::getSpeedX() const {
    return speed_x;
}

/**
  Function to get the speed of the ball in the y direction
*/
float Ball::getSpeedY() const {
    return speed_y;
}

/**
  Function to get the radius of the ball
*/
int Ball::getBallRadius() const {
    return ball_radius;
}

/**
  Function to get the color of the ball
*/
Color Ball::getBallColor() const {
    return ball_color;
}
