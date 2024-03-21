/***************************************
* Beni Nobel inganji
* File name: Game.h
* Description: This file contains the function prototypes and includes necessary libraries.
*****************************************/

// Include directives
#pragma once
#include <iostream>
#include "raylib.h"
#include "Ball.h"
#include "Paddle.h"
#include "Line.h"
#include "Scores.h"
using namespace std;

// SFML graphics library
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;

// Set up window dimensions and title
const int screen_width = 1280;   // Width of the game window
const int screen_height = 800;   // Height of the game window
const char* gameTitle = "VelocityVolley";  // Title of the game window

// Define colors for the game
Color Dark_Navy_blue = Color{ 0, 0, 25, 255 };
Color Light_Blue = Color{ 173, 216, 230, 255 };
Color Orange = Color{ 255, 165, 0, 255 };
Color Gray = Color{ 169, 169, 169, 255 };
Color Light_Gray = Color{ 192, 192, 192, 255 };
Color Lavender = Color{ 200, 160, 255, 255 };

// Declare function prototypes for functions defined in other source files
float clamp(float value, float min, float max); // Clamps a value between a minimum and maximum value
bool CheckCollisionCircleRectangle(float ballX, float ballY, float ballRadius, float rectX, float rectY, float rectWidth, float rectHeight); // Checks for collision between a circle and a rectangle
