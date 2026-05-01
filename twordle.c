//Author: Delvon Phillips
//Purpose: Project 10
//Date: 4/30/2026

#include <stdio.h>
#include <stdbool.h>


void loadWord(char word[]);
void LowerCase(char str[]);
int stringLength(char str[]);
bool ValidGuess(char guess[]);
bool isLetter(char c);
bool CorrectPosition(char guess[], char word[], int index);
bool inWord(char guessChar, char word[]);
void displayGuesses(char guesses[][6], int count, char word[]);
bool checkWin(char guess[], char word[]);

int main() {
	char word[6];
	char guess[100];
	char guesses[6][6];

	int guessCount = 0;
	bool won = false;

	loadWord(word);

		while (guessCount < 6 && !won) {
			printf("Enter guess #%d: ", guessCount + 1);
			scanf("%s", guess);

			LowerCase(guess);

			if (!ValidGuess(guess)) {
				printf("Invalid guess. Try again.\n");
			continue;
			}

			for (int i = 0; i < 6; i++) {
				guesses[guessCount][i] = guess[i];
			}

			guessCount++;

			displayGuesses(guesses, guessCount, word);

			if (checkWin(guess, word)) {
				won = true;
			}
		}

		if (won) {
			printf("You guessed the word!\n");
		} 

		else {
			printf("Out of guesses! The word was: %s\n", word);
		}

return 0;
}

void loadWord(char word[]) {
	FILE *file = fopen("word.txt", "r");
	fscanf(file, "%s", word);
	fclose(file);
	
	LowerCase(word);
}

void LowerCase(char str[]) {
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] = str[i] + 32;
		}
	}
}

int stringLength(char str[]) {
	int count = 0;
	while (str[count] != '\0') {
		count++;
	}
	return count;
}

bool isLetter(char c) {
	return (c >= 'a' && c <= 'z');
}

bool ValidGuess(char guess[]) {
	if (stringLength(guess) != 5) {
	return false;
}

	for (int i = 0; i < 5; i++) {
		if (!isLetter(guess[i])) {
			return false;
		}
	}

	return true;
}

bool CorrectPosition(char guess[], char word[], int index) {
	return guess[index] == word[index];
}

void displayGuesses(char guesses[][6], int count, char word[]) {
	for (int i = 0; i < count; i++) {

		for (int j = 0; j < 5; j++) {
			if (CorrectPosition(guesses[i], word, j)) {
				printf("%c", guesses[i][j] - 32); // uppercase
			} 
			else {
				printf("%c", guesses[i][j]);
			}
		}
		printf("\n");


		for (int j = 0; j < 5; j++) {
			if (!CorrectPosition(guesses[i], word, j) &&
				inWord(guesses[i][j], word)) {
				printf("^");
			} 
			else {
				printf(" ");
			}
		}
	printf("\n");
	}
}

bool checkWin(char guess[], char word[]) {
	for (int i = 0; i < 5; i++) {
		if (guess[i] != word[i]) {
			return false;
		}
	}
return true;
}

bool inWord(char guessChar, char word[]) {
	for (int i = 0; i < 5; i++) {
		if (guessChar == word[i]) {
		return true;
		}
	}
return false;
}



