/***************************************
* Beni Nobel inganji
* Due Week 9
* Programming Assignment 2
* File name: Sound.h
* Description: This file contains the declaration of the Sound class
*****************************************/

// Include directives
#pragma once // Include guard to ensure this header file is only included once
#include "Game.h" // Include the game header file which contains necessary declarations and definitions

class SoundManager {
public:
    // Constructor
    SoundManager();

    // Function to play the shoot sound
    void playShootSound();

    // Function to play the hit sound
    void playHitSound();

private:
    SoundBuffer shootBuffer; // Sound buffer for shoot sound
    Sound shootSound;// Sound object for shoot sound
    SoundBuffer hitBuffer; // Sound buffer for hit sound
    Sound hitSound; // Sound object for hit sound
};
