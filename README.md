# VelocityVolley - Pong Game

VelocityVolley is a classic Pong game developed using C++ and the Raylib library. This simple yet entertaining game features a player-controlled paddle, an AI-controlled paddle, a bouncing ball, and scoring functionality. The name comes from my passion for playing Volleyball.

# Table of Contents

- [Description](#description)
- [Game Overview](#game-overview)
- [Features](#features)
- [How to play](#how-to-play)
    + [Player Controls](#player-controls)
    + [Game Rules](#game-rules)
- [Code Structures](#code-structure)
- [Game Logic](#game-logic)
    + [Game Loop](#game-loop)
    + [Player Input](#player-input)
    + [Scoring](#scoring)
    + [Colors](#colors)
    + [Functions](#functions)
        - [Clamp Function](#clamp-function)
        - [Collision Detection Function](#collision-detection-function)
    + [Raylib Setup](#raylib-setup)
    + [Game Dimensions](#game-dimensions)
    + [Future Improvements](#future-improvements)
- [Build and Run](#build-and-run)
- [Conclusion](#conclusion)
  

## Description

A simple Pong game implemented in C++ using the Raylib library. The game features a ball, player-controlled paddle, and AI-controlled paddle. The objective is to score points by bouncing the ball past the opponent's paddle.

## Game Overview

VelocityVolley is a Pong game where players control a paddle to hit a bouncing ball back and forth. The objective is to prevent the ball from reaching the opponent's side while scoring points by successfully hitting the ball past the opponent.

## Features

- Player-controlled paddle with keyboard input.
- AI-controlled paddle that reacts to the ball's position.
- Bouncing ball with realistic physics.
- Scoring system to track player and AI scores.
- Colorful Graphics using the Raylib lbrary.

## How to Play

- ### Player Controls:
  + Use the `UP` and `DOWN` arrow keys to move the player-controlled paddle up and down, respectively.

- ### Game Rules:
  + The game starts with the ball in the center of the screen.
  + The player and AI take turns hitting the ball.
  + Score points by hitting the ball past the opponent's paddle.
  + The game continues until the player decides to close the window.

## Code Structure

The game code is organized into several files:

- **Ball.cpp:**
    + Handles the drawing, updating, and resetting of the ball.
    + Defines functions for drawing the ball, updating its position, and resetting it.
- **Ball.h:**
    + Header file defining the **`Ball`** class.
    + Contains member variables for ball position, speed, radius, and color.
    + Declares functions for drawing, updating, and resetting the ball.
- **Game.cpp:**
    + Main game loop and logic.
    + Initializes game elements, such as the ball, player paddle, AI paddle, and middle line.
    + Handles collision detection and updates game elements.
    + Uses Raylib functions for drawing the line.
- **Line.cpp:**
    + Defines a **`Line`** class responsible for drawing a line on the screen.
    + Contains a function for drawing the line.
- **Line.h:**
    + Header file defining the **`Line`** class.
    + Contains member variables for line start and end positions, along with color.
    + Declares a function for drawing the line.
- **Paddle.cpp:**
    + Handles player-controlled paddle drawing, updating and limiting its movement.
    + Defines a function for limiting the paddles's movement within screen boundaries.
- **Paddle.h:**
    + Header file defining the **`Paddle`** class and its derived class **`CPUPaddle`**.
    + Contains member variables for paddle dimensions, position, speed, and color.
    + Declares functions for drawing and updating the player-controlled paddle.
    + **`CPUPaddle`** updates its position based on the ball's vertical position.
- **Scores.h:**
    + Declares global variables for player and AI scores.
    + Provides external declarations for these variables.

## Game Logic

- ### Game Loop:
    + The main game loop handles updating and drawing game elements.
    + Ball movement is updated, player paddle responds to keyboard, and the AI paddle tracks the ball.
    + Collision detection is performed with player and AI paddles, and ball reflections are implemented.
- ### Player Input:
    + Player controls the paddle using the `UP` and `DOWN` arrow keys.
- ### Scoring:
    + Player scores when the ball passes the AI paddle (reaches the right screen boundary).
    + AI scores when the ball passes the player paddle (reaches the left screen boundary).
- ### Colors:
    + *Defined Colors:*
        - Dark_Navy_blue, Light_Blue, Orange, Gray, Loght_Gray, Lavender
- ### Functions:
    + #### Clamp Function:
        - Used for clamping a value between a specified minimum and maximum.
          ```c++

          /**
          @param value - the value to be clamped
          @param min - the minimum value allowed
          @param max - the maximum value allowed
          @return the clamped value
          */
          float clamp(float value, float min, float max) {
              if (value < min) return min;
              if (value > max) return max;
                return value;
          }

          ```
    + #### Collision Detection Function:
        - Checks collision between a circle (ball) and a rectangle (paddle).
          ```c++
          /**
          @param ballX - x-coordinate of the circle center
          @param ballY - y-coordinate of the circle center
          @param ballRadius - radius of the circle
          @param rectX - x-coordinate of the rectangle
          @param rectY - y-coordinate of the rectangle
          @param rectWidth - width of the rectangle
          @param rectHeight - height of the rectangle
          @return true if there is a collision, false otherwise
          **/
          
          bool CheckCollisionCircleRectangle(float ballX, float ballY, float ballRadius, float rectX, float rectY, float rectWidth, float rectHeight) {
            float closestX = clamp(ballX, rectX, rectX + rectWidth);
            float closestY = clamp(ballY, rectY, rectY + rectHeight);
        
            float distanceX = ballX - closestX;
            float distanceY = ballY - closestY;
        
            return (distanceX * distanceX + distanceY * distanceY) < (ballRadius * ballRadius);
          }

          ```
- ### Raylib Setup:
    + Initializes Raylib window and sets the target FPS.
      ```c++
      
      InitWindow(screen_width, screen_height, gameTitle);
      SetTargetFPS(60);
      
      ```
- ### Game Dimensions:
    + Game window dimensions set to 1280 x 800 pixels.
- ### Future Improvements:
    + Enhancements:
        - Implement more game features, such as paddle acceleration or power-ups.
        - Improve AI paddle behavior for a more challenging game.
  
## Build and Run

To build and run the game, follow these steps:

1. Make sure you have a C++ compiler and the Raylib library installed.
2. Clone the repository to your local machine.
3. Compile the source files using your preferred C++ compiler.
4. Run the compiled executable.

## Conclusion

+ **Objective:**
  + A classic Pong Game created using C++ and the Raylib library.
+ **Learning Points:**
  + Game loop implementation, collision detection, and AI behavior.
+ **Acknowledgement:**
  + Utilizes the Raylib library for graphics and input handling.
