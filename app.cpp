#include <iostream>
using namespace std;

struct stRoundScore
{
  bool user;
  bool computer;
  bool tie;
};

string choices[3] = {"Stone", "Paper", "Scissor"};

int readInput(string message)
{
  int inputNum;
  cout << message + "\n";
  cin >> inputNum;
  return inputNum;
}

int randomNumber(int From, int To)
{
  int randNum = rand() % (To - From + 1) + From;
  return randNum;
}

stRoundScore singlePlay()
{
  stRoundScore round;
  int userChoice, compChoice = randomNumber(1, 3);
  cout << "\n\n[1]Stone [2]Paper [3]Scissor" << endl;
  cout << "Enter your choice: ";
  cin >> userChoice;
  if (userChoice == compChoice)
  {
    cout << "You both choosed '" << choices[userChoice - 1] << "'. So, TIE" << endl;
    round.user = false;
    round.computer = false;
    round.tie = true;
  }
  else
  {
    if (((userChoice == 1) && (compChoice == 3)) ||
        ((userChoice == 2) && (compChoice == 1)) ||
        ((userChoice == 3) && (compChoice == 2)))
    {
      cout << "You choosed '" << choices[userChoice - 1]
           << "'\n Computer choosed '" << choices[compChoice - 1]
           << "' \n. So, you WIN!";
      round.user = true;
      round.computer = false;
      round.tie = false;
    }
    else
    {
      cout << "You choosed '" << choices[userChoice - 1]
           << "'\n Computer choosed '" << choices[compChoice - 1]
           << "' \n. So, you LOSE!";
      round.user = false;
      round.computer = true;
      round.tie = false;
    }
  }
  cout << endl;
  return round;
}

void printResults(stRoundScore playsArr[], int playsNo)
{
  short int userTotScore = 0,
            computerTotScore = 0,
            tieTotScore = 0;
  for (int i = 0; i < playsNo; ++i)
  {
    userTotScore += playsArr[i].user;
    computerTotScore += playsArr[i].computer;
    tieTotScore += playsArr[i].tie;
  }
  cout << "\n\n=== GAME OVER ====\n\n";
  cout << "Your Score: " << userTotScore << "\n"
       << "Computer Score: " << computerTotScore << "\n"
       << "Tie times: " << tieTotScore << "\n\n";

  if (userTotScore == computerTotScore)
  {
    cout << "Nobody wins: TIE" << endl;
  }
  else if (userTotScore > computerTotScore)
  {
    cout << "You WIN" << endl;
  }
  else
  {
    cout << "You LOSE" << endl;
  }
}

void game(stRoundScore playsArr[], int playsNo)
{
  for (int i = 0; i < playsNo; ++i)
  {
    playsArr[i] = singlePlay();
  }
  printResults(playsArr, playsNo);
}

int main()
{
  srand((unsigned)time(NULL));
  int playsNo = readInput("Please Enter The NO. of games you want to play");
  stRoundScore games[1024];
  game(games, playsNo);

  return 0;
}
