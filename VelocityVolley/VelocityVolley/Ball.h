/***************************************
* Beni Nobel inganji
* File name: Ball.h
* Description: This file contains the declaration of the Ball class.
*****************************************/

// Header guard to prevent multiple inclusion
#pragma once
#include "Game.h"

// Class definition for the Ball
class Ball {
public:

    // Function to draw the ball
    void drawBall();

    // Function to update the ball's position
    void updateBall();

    // Function to reset the ball's position
    void resetBall();

    // Setter functions

    // Function to set the x-coordinate of the ball
    void setBallX(float x);

    // Function to set the y-coordinate of the ball
    void setBallY(float y);

    // Function to set the speed of the ball in the x direction
    void setSpeedX(float speedX);

    // Function to set the speed of the ball in the y direction
    void setSpeedY(float speedY);

    // Function to set the radius of the ball
    void setBallRadius(int radius);

    // Function to set the color of the ball
    void setBallColor(Color color);

    // Getter functions

    // Function to get the x-coordinate of the ball
    float getBallX() const;

    // Function to get the y-coordinate of the ball
    float getBallY() const;

    // Function to get the speed of the ball in the x direction
    float getSpeedX() const;

    // Function to get the speed of the ball in the y direction
    float getSpeedY() const;

    // Function to get the radius of the ball
    int getBallRadius() const;

    // Function to get the color of the ball
    Color getBallColor() const;

private:
    float ball_x;       // x-coordinate of the ball
    float ball_y;       // y-coordinate of the ball
    float speed_x;      // speed of the ball in the x direction
    float speed_y;      // speed of the ball in the y direction
    int ball_radius;    // radius of the ball
    Color ball_color;   // color of the ball
};