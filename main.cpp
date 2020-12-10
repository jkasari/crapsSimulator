#include <iostream>
#include <iomanip>
#include <ctime>
#include "crapsFunctions.cpp"

using namespace std;

int main(int argc, char** argv) {
  srand(time(0));

  if(argc != 3) {
    cout << "This program expects exactly two arguements" << endl;
    cout << endl;
    cout << " 1.) The number of turns to map." << endl;
    cout << endl;
    cout << " 2.) The number of games to play." << endl;
    return 0;
  }

  cout << fixed;
  cout << setprecision(4);

  const uint32_t numOfGames = stol(argv[2]);
  const uint32_t turnsToMap = stol(argv[1]);
  const uint32_t width = 7;

  uint32_t* results = crapsGame(numOfGames, turnsToMap);
  for(int i = 0; i < (turnsToMap + 1); ++i) {
    cout.width(width);
    cout << right;
    cout << static_cast<double>(results[i]) / numOfGames * 100 << "%" << endl;
  }
  uint32_t total = 0;
  for(int i = 0; i < (turnsToMap + 1); ++i) {
    total += results[i];
  }
  cout.width(width);
  cout << right;
  cout << static_cast<double>(total) / numOfGames * 100 << "%" << endl;

  delete[] results;
  results = nullptr;
}