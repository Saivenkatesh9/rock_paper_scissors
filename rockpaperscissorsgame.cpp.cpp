#include <iostream>
#include <cstdlib>
#include <ctime>

// Define preprocessor constants for ROCK, PAPER and SCISSORS which will 
// represent with the integers 1-3.  We'll randomly select an integer from 
// 1-3 to represent the "AI move".  Using these constants in our program also
// makes it easier to read than directly using 1,2,3. 
#define ROCK 1
#define PAPER 2
#define SCISSORS 3

using namespace std;

int main()
{
  // possibility of different sequences of random numbers each time the program
  // is executed.
  srand((unsigned int) time(NULL));
  
  // player_throw stores the player's throw, ai_throw stores the AI's throw, 
  // and draw keeps track of whether the game ended in a draw or not (if draw
  // is true the game ended in a draw, in which case the game is played again)
  int player_throw = 0;
  int ai_throw = 0;
  bool draw = false;
  
  // Continually play the game until there is a winner
  do
  {
    // Prompt the user to enter their throw, store it into player_throw
    cout << "Select your throw." << endl;
    cout << "1) Rock" << endl;
    cout << "2) Paper" << endl;
    cout << "3) Scissors" << endl;
    cout << "Selection: ";
    cin >> player_throw;
    
    // Output an endl (newline) to separate the user input from the game output
    cout << endl;
    
    ai_throw = (rand() % 3) + 1;
    
    // Output the AI throw so the player knows what it is
    if (ai_throw == ROCK)
    {
      cout << "AI throws ROCK." << endl;
    }
    else if (ai_throw == PAPER)
    {
      cout << "AI throws PAPER." << endl;
    }
    else if (ai_throw == SCISSORS)
    {
      cout << "AI throws SCISSORS." << endl;
    }
    
    // We'll set draw to false, and only set it to true if there is a draw
    draw = false;
    
    if (player_throw == ai_throw)
    {
      draw = true;
      cout << "Draw! Play again!" << endl;
    }
    else if (player_throw == ROCK && ai_throw == SCISSORS)
    {
      cout << "ROCK beats SCISSORS! YOU WIN." << endl;
    }
    else if (player_throw == ROCK && ai_throw == PAPER)
    {
      cout << "PAPER beats ROCK! YOU LOSE." << endl;
    }
    else if (player_throw == PAPER && ai_throw == ROCK)
    {
      cout << "PAPER beats ROCK! YOU WIN." << endl;
    }
    else if (player_throw == PAPER && ai_throw == SCISSORS)
    {
      cout << "SCISSORS beats PAPER! YOU LOSE." << endl;
    }
    else if (player_throw == SCISSORS && ai_throw == PAPER)
    {
      cout << "SCISSORS beats PAPER! YOU WIN." << endl;
    }
    else if (player_throw == SCISSORS && ai_throw == ROCK)
    {
      cout << "ROCK beats SCISSORS! YOU LOSE." << endl;
    }
    
    // Output an endl (newline) to separate the game output from the user 
    // input in the case that the game is played again
    cout << endl;

  } while (draw);

  return 0;
}