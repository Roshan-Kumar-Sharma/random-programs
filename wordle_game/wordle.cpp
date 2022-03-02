#include<iostream>
#include<ctime>
#include<fstream>
#include<iomanip>
#include<cmath>
#include<cstdlib>

using namespace std;

const char correct = '!';
const char wrong = '&';
const char incorrect = '_';

int countWords(string fileName){
	ifstream fin;
	int numberOfWords;
	string word;

	fin.open(fileName);

	numberOfWords = 0;
	while (fin)
	{
		getline(fin, word);

		if (word.length() != 0)
			numberOfWords++;
	}

	fin.close();

	return numberOfWords;
}

void loadWords(string fileName, string *words)
{
	ifstream fin;
	string word;

	fin.open(fileName);

	int i = 0;
	while (fin)
	{
		getline(fin, word);

		if (word.length() != 0)
			words[i++] = word;
	}

	fin.close();
	return;
}

int selectRandomWordIndex(int numberOfWords){
	int randomIndex;

	srand(time(0));

	randomIndex = rand() % numberOfWords;

	return randomIndex;
}



bool doesWordExist(string *words, int numberOfWords, string guessedWord){
	int i;

	i = 0;
	while(i < numberOfWords){
		if(words[i] == guessedWord)
			return true;
		i++;
	}

	return false;
}

string checkLetter(char guessWordChar, char mysteryWordChar, int *letters){
	if (guessWordChar == mysteryWordChar)
	{
		return "!";
	}
	else
	{
		if (letters[guessWordChar - 97])
		{
			return "&";
		}
		else
		{
			return "_";
		}
	}
}

string createSymbolicString(int *letters, string guessedWord, string mysteryWord){
	int len, i;
	string symbolicString = "";

	len = guessedWord.length();

	i = 0;
	while(i < len){
		symbolicString += checkLetter(guessedWord[i], mysteryWord[i], letters);
		
		i++;
	}
	return symbolicString;
}

void displayCurrent(string *guessedWords, int guessNum, int guessLimit, bool doesExist){
	if(!doesExist){
		cout << "That word is not in the word list" << endl;
		return;
	}

	for(int i=0; i < guessLimit * 2; i+=2){
		if (guessedWords[i + 1].length() == 0)
			cout << "-----" << endl;
		else if (guessedWords[i + 1] != "-1")
		{
			cout << guessedWords[i] << endl;
			cout << guessedWords[i + 1] << endl;
		}
	}
	return;
}

bool checkWin(string mysteryWord, string guessedWord){
	if(mysteryWord == guessedWord)
		return true;
	return false;
}

string guessWord(){
	string guessedWord;

	cout << "What word would you like to guess?" << endl;
	cin >> guessedWord;

	return guessedWord;
}

void startGame(string *words, int numberOfWords, int randomIndex, int guessLimit)
{
	int guessNum, i, len;
	bool doesExist, hasWon;
	string mysteryWord, guessedWord, symbolicString;
	string guessedWords[guessLimit * 2] = {""};
	int letters[26] = {0};

	mysteryWord = words[randomIndex];

	len = mysteryWord.length();

	i = 0;
	while (i < len)
	{
		letters[mysteryWord[i] - 97] = 1;
		i++;
	}

	guessNum = 0;
	while (guessNum < (guessLimit * 2))
	{
		guessedWord = guessWord();
		guessedWords[guessNum] = guessedWord;

		doesExist = doesWordExist(words, numberOfWords, guessedWord);

		if(doesExist){
			symbolicString = createSymbolicString(letters, guessedWord, mysteryWord);

			guessedWords[guessNum + 1] = symbolicString;

			hasWon = checkWin(mysteryWord, guessedWord);
			
			guessNum += 2;
		}
		else{
			hasWon = false;
		}

		displayCurrent(guessedWords, guessNum, guessLimit, doesExist);

		if(hasWon){
			cout << "Congrats you won!" << endl;
			cout << "The correct word was: " << mysteryWord << endl;
			return;
		}
	}

	cout << "Sorry, you lost" << endl;
	cout << "The correct word was: " << mysteryWord << endl;

	return;
}

int main(){
	string randomWord, fileName, anotherGame;
	int numberOfWords, randomIndex, guessLimit;

	fileName = "proj1_data.txt";
	guessLimit = 6;

	numberOfWords = countWords(fileName);

	string words[numberOfWords];

	loadWords(fileName, words);

	cout << "Your file was imported!" << endl;
	cout << numberOfWords << " words imported." << endl;

	do{
		cout << "Ok. I am thinking of a word with five letters." << endl;

		randomIndex = selectRandomWordIndex(numberOfWords);
		randomWord = words[randomIndex]; 

		startGame(words, numberOfWords, randomIndex, guessLimit);

		cout << "Another game? y/n" << endl;
		cin >> anotherGame;

	}while(anotherGame != "n");

	cout << "Thank you!" << endl;

	return 0;
}
