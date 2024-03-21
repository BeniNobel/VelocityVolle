/***************************************
* Beni Nobel inganji
* File name: Sound.cpp
* Description: This file contains the implementation of the SoundManager class
*****************************************/

// Include the game header file which contains necessary declarations and definitions
#include "Game.h"

// Constructor for the SoundManager class
SoundManager::SoundManager() {
    // Load sound buffers and set up sounds
    if (!hitBuffer.loadFromFile("hit.mp3")) {
        // Handle error loading hit sound file
        cout << "Error loading hit sound file" << endl;
    }
    hitSound.setBuffer(hitBuffer);

    if (!scoreBuffer.loadFromFile("score.mp3")) {
        // Handle error loading score sound file
        cout << "Error loading score sound file" << endl;
    }
    scoreSound.setBuffer(scoreBuffer);
}

// Function to play the shoot sound
void SoundManager::playHitSound() {
    hitSound.play();
}

// Function to play the hit sound
void SoundManager::playScoreSound() {
    scoreSound.play();
}
