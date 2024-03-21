/***************************************
* Beni Nobel inganji
* File name: Ball.h
* Description: This file contains the declaration of the Line class.
*****************************************/

// Include directives
#pragma once
#include "Game.h"

// Class definition for the Line
class Line {
public:
    // Setters

    // Function declaration for setting the start and end positions of the line
    void setStartPosX(float x);

    // Function declaration for setting the start and end positions of the line
    void setStartPosY(float y);

    // Function declaration for setting the start and end positions of the line
    void setEndPosX(float x);

    // Function declaration for setting the start and end positions of the line
    void setEndPosY(float y);

    // Function declaration for setting the color of the line
    void setColor(Color clr);

    // Getters

    // Function declaration for getting the start and end positions of the line
    float getStartPosX() const;

    // Function declaration for getting the start and end positions of the line
    float getStartPosY() const;

    // Function declaration for getting the start and end positions of the line
    float getEndPosX() const;

    // Function declaration for getting the start and end positions of the line
    float getEndPosY() const;

    // Function declaration for getting the color of the line
    Color getColor() const;

    // Function declaration for drawing the line
    void drawLine();

private:
    float startPosX;    // x-coordinate of the line start
    float startPosY;    // y-coordinate of the line start
    float endPosX;      // x-coordinate of the line end
    float endPosY;      // y-coordinate of the line end
    Color color;        // color of the line
};