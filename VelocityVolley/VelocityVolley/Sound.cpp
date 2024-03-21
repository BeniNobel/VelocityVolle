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
    if (!shootBuffer.loadFromFile("shoot.mp3")) {
        // Handle error loading shoot sound file
        cout << "Error loading shoot sound file" << endl;
    }
    shootSound.setBuffer(shootBuffer);

    if (!hitBuffer.loadFromFile("hit.mp3")) {
        cout << "Error loading hit sound file" << endl;
    }
    hitSound.setBuffer(hitBuffer);
}

// Function to play the shoot sound
void SoundManager::playShootSound() {
    shootSound.play();
}

// Function to play the hit sound
void SoundManager::playHitSound() {
    hitSound.play();
}
