// hangman.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
//change
bool hangman_checkguess(std::string &word, std::string &display, char guess, int &characters_remaining) {
    bool correct_guess = false;
    for (int i = 0; i<word.length(); i++) {
        if (guess == word[i]) {
            if (word[i] != display[i]) {
                display[i] = word[i];
                correct_guess = true;
                characters_remaining--;
            }
        }
    }
    return correct_guess;
}
/*
    Hangman minigame

    Put word and attempt to guess the characters


*/
void hangman(std::string word) {
    //Init variables
    int tries = 6;
    int characters_remaining = word.length();
    std::string display = std::string(word.length(), '*'); //word with undiscovered characters as * (ex. word = ***d)

    std::cout << "Welcome to Hangman minigame!\n\n\n";
    while (tries > 0 && characters_remaining > 0) {

        std::cout << "Word is " << display << "\n";
        std::cout << "Guess a character: ";
        char guess;
        std::cin >> guess;
        bool is_correct = hangman_checkguess(word, display, guess, characters_remaining);

        if (is_correct) {
            std::cout << guess << " is correct!\n\n";
        }
        else {
            tries--;
            std::cout << guess << " is not part of the remaining characters.\n";
            std::cout << tries << " attempts remaining.\n\n";
        }
    }
    if (characters_remaining == 0) {
        std::cout << "You have won!\n";
    }
    else if (tries == 0) {
        std::cout << "You have lost.\n";
    }
    
    std::cout << "The word was : " << word << "\n";

    
    
}

int main()
{
    std::string word;
    std::cout << "Hello World\n";
    while (true) {
        std::cout << "PLay hangman with word: ";
        std::cin >> word;
        hangman(word);
    }
}



