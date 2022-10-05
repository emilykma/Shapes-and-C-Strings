// game.cpp
// Hangman game illustrates string library functions, 
// character arrays, arrays of pointers, etc.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

// Prototype. we'll define this below.
int processGuess(char* word, const char* targetWord, char guess);

// Define an array of strings (since a string is just a char array)
//  and since string literals (e.g. "hi") evaluate to the starting address
//  of those characters, we really want an array of char *'s
const char* wordBank[] = {"computer", "president", "trojan", "program",
                          "coffee", "library", "football", "popcorn", 
                          "science", "engineer"};

const int numWords = 10;

int main(int argc, char* argv[])
{
  //------------- Do not modify this code --------------
  if(argc < 2){
    srand(time(0)); // use the time to get randomly chosen words each run
  }
  else {
    srand(atoi(argv[1])); // use the command line argument as the seed
  }

  // Pick a random word from the wordBank
  const char* targetWord = wordBank[rand() % numWords];

  int numTurns = 10; // variable to track how many turns remain

  char word[80];  // a blank array to use to build up the answer
                  // It should be initialized with *'s and then
                  //  change them to the actual letters when the 
                  //  user guesses the letter

  // More initialization code as needed
  char guess;
 
  // The game should continue until a word
  //  is guessed correctly, a '!' is entered,
  //  or 10 turns have elapsed without the word being guessed
 
 // initializing word with *s
 for (unsigned int i=0; i < strlen(targetWord); i++) {
   word[i] =+ '*'; 
 }

 while (numTurns != 0) {
   cout << numTurns << " guesses remain: ";
   for (unsigned int i=0; i <= strlen(targetWord); i++) {
     cout << word[i];
   }
   cout << endl;
   cout << "Enter a letter: " << endl;
   cin >> guess;

   // user correctly guesses the secret word 
   if (strncmp(word, targetWord, strlen(targetWord)) == 0) { 
      cout << "Win! " << numTurns << " guesses to spare." << endl;
      return 0;
   }

   if (processGuess(word, targetWord, guess) == 0) {
      numTurns--;
   }

   // user quits
   if (guess == '!') {
      cout << "Quit!" << endl;
    return 0;
  }

 }

  // Print out end of game status

  // user has run out of turns
   if (numTurns == 0) { 
    cout << "Lose! ";
      for (unsigned int i=0; i < strlen(targetWord); i++) {
        cout << word[i];
      }
   }
    
  return 0;
}

// Given the current version of the word, target/selected word, and
// the character that the user just guessed, change the word to 
// "turn on" any occurrences the guess character and return a count
// of how many occurrences of 'guess' were found
int processGuess(char* word, const char* targetWord, char guess)
{
  int match = 0; // count of how many times guess matches a character in word

  for (unsigned int i=0; i < strlen(targetWord); i++) {
    if (guess == targetWord[i] && word[i] == '*') { // if guess char is found in target word AND it has not been repeated
      word[i] = guess; // update word
      match++;
    }
    else { 
      continue;
    }
  }

  return match;

}