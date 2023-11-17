#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>

std::string chooseRandomWord() {
    std::string wordsdata[] = { "POINTER", "LANGUAGE", "ALGORITHM", "DATA STRUCTURE", "VARIABLE" };
            int rndm = rand() % (sizeof(wordsdata) / sizeof(wordsdata[0]));
                return wordsdata[rndm];
}

std::string scrambword(const std::string& word) {
                std::string scrambword = word;
            random_shuffle(scrambword.begin(), scrambword.end());
    return scrambword;
}

int main() {
        srand(static_cast<unsigned int>(time(0)));

        std::string secrtword = chooseRandomWord();
            std::string scrambledWord = scrambword(secrtword);
                std::string guessedaword;

                for (char charact : scrambledWord) {

                    std::cout << charact << ' ';
                }   

                std::cout << std::endl;

                    bool correct = false;

        for (int i = 0; i < 3; i++) {
                std::cout << "Guess the word: ";
                      std::cin >> guessedaword;

                       std::transform(guessedaword.begin(), guessedaword.end(), guessedaword.begin(), ::toupper);
                std::transform(secrtword.begin(), secrtword.end(), secrtword.begin(), ::toupper);

            if (guessedaword == secrtword) {

                std::cout << "You guessed the correct word! Congrats!: " << secrtword << std::endl;
                       break;

            }  else {

                std::cout << "Wrong! Try again." << std::endl;

            }

        }

        if (!correct) {

            std::cout << "Game Over! Correct answer is " << secrtword << std::endl;
        }

    return 0;
}
