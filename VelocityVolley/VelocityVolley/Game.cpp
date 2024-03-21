/***************************************
* Beni Nobel inganji
* File name: Game.cpp
* Description: This file contains the main function
*****************************************/

// Include directives
#include "Game.h"

/**
    This function is the entry point for the program.
*/
int main() {

    // Declare Ball object
    Ball draw_Ball;
    draw_Ball.setBallRadius(20);  // Radius of the ball
    draw_Ball.setBallX(static_cast<float>(screen_width) / 2);  // Initial x-coordinate of the ball
    draw_Ball.setBallY(static_cast<float>(screen_height) / 2); // Initial y-coordinate of the ball
    draw_Ball.setSpeedY(static_cast<float>(7));  // Initial speed of the ball in the x-direction
    draw_Ball.setSpeedY(static_cast<float>(7));  // Initial speed of the ball in the y-direction
    draw_Ball.setBallColor(Orange);  // Color of the ball

    // Declare player paddle
    Paddle player;
    player.setPaddleWidth(25);  // Width of the player's paddle
    player.setPaddleHeight(120);  // Height of the player's paddle
    player.setPaddleX(screen_width - (player.getPaddleWidth() + 10));  // Initial x-coordinate of the player's paddle
    player.setPaddleY(screen_height / 2 - player.getPaddleHeight() / 2);  // Initial y-coordinate of the player's paddle
    player.setPaddleSpeed(6);  // Speed of the player's paddle
    player.setSegment(0);  // Segment
    player.setRoundness(0.8);  // Roundness of the player's paddle
    player.setPaddleColor(Light_Blue);  // Color of the player's paddle

    // Declare Computer paddle
    AIPaddle paddleAI;
    paddleAI.setPaddleWidth(25);  // Width of the Computer's paddle
    paddleAI.setPaddleHeight(120);  // Height of the Computer's paddle
    paddleAI.setPaddleX(10);  // Initial x-coordinate of the Computer's paddle
    paddleAI.setPaddleY(screen_height / 2 - paddleAI.getPaddleHeight() / 2);  // Initial y-coordinate of the Computer's paddle
    paddleAI.setPaddleSpeed(6);  // Speed of the Computer's paddle
    paddleAI.setSegment(0);  // Segment
    paddleAI.setRoundness(0.8);  // Roundness of the Computer's paddle
    paddleAI.setPaddleColor(Light_Blue);  // Color of the Computer's paddle

    // Declare middle line
    Line middleLine;
    middleLine.setStartPosX(screen_width / 2);  // Start x-coordinate of the middle line
    middleLine.setStartPosY(0);  // Start y-coordinate of the middle line
    middleLine.setEndPosX(screen_width / 2);  // End x-coordinate of the middle line
    middleLine.setEndPosY(screen_height);  // End y-coordinate of the middle line
    middleLine.setColor(Gray);  // Color of the middle line

    // Initialize Raylib window and set target FPS
    InitWindow(screen_width, screen_height, gameTitle);
    SetTargetFPS(60);

    // Game loop
    while (!WindowShouldClose()) {
        BeginDrawing();

        // Update Ball position
        draw_Ball.updateBall();

        // Update Player paddle position
        player.updatePaddle();

        // Update Computer paddle position
        paddleAI.updatePaddleAI(draw_Ball.getBallY());

        // Check for collisions with paddles and reflect ball if necessary
        if (CheckCollisionCircleRectangle(draw_Ball.getBallY(), draw_Ball.getBallY(), draw_Ball.getBallRadius(),
            player.getPaddleX(), player.getPaddleY(), player.getPaddleWidth(), player.getPaddleHeight()))
        {
            draw_Ball.setSpeedX(-1);
        }

        if (CheckCollisionCircleRectangle(draw_Ball.getBallX(), draw_Ball.getBallY(), draw_Ball.getBallRadius(),
            paddleAI.getPaddleX(), paddleAI.getPaddleY(), paddleAI.getPaddleWidth(), paddleAI.getPaddleHeight()))
        {
            draw_Ball.setSpeedX(-1);
        }

        // Clear Background
        ClearBackground(Dark_Navy_blue);

        // Draw ai_Side with another color
        // DrawRectangle(screen_width / 2, 0, screen_width / 2, screen_height, Blue);

        // Draw a circle in the center
        DrawCircle(screen_width / 2, screen_height / 2, 150, Lavender);

        // Draw Ball
        draw_Ball.drawBall();

        // Draw Player paddle
        player.drawPaddle();

        // Draw Computer paddle
        paddleAI.drawPaddle();

        // Draw middle line
        middleLine.drawLine();

        // Draw Player_AI score
        DrawText(TextFormat("%i", static_cast<int>(ai_score)), screen_width / 4 - 20, 20, 80, Light_Gray);

        // Draw Player score
        DrawText(TextFormat("%i", static_cast<int>(player_score)), 3 * screen_width / 4 - 20, 20, 80, Light_Gray);

        // End drawing
        EndDrawing();
    }

    // Close Raylib window
    CloseWindow();
    return 0;
}