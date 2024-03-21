/***************************************
* Beni Nobel inganji
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
    void playHitSound();

    // Function to play the hit sound
    void playScoreSound();

private:
    SoundBuffer hitBuffer; // Sound buffer for shoot sound
    Sound hitSound;// Sound object for shoot sound
    SoundBuffer scoreBuffer; // Sound buffer for hit sound
    Sound scoreSound; // Sound object for hit sound
};
