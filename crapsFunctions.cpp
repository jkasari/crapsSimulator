#include <random>

/**
 * behives like a die, use the .roll function to generate a virtual roll.
 */
class dice {
 public:
  dice(uint32_t sides) { this->sides = sides; }
  uint32_t roll() { return (rand() % sides) + 1; }

 private:
  uint32_t sides;
};

/**
 * takes a dice roll a counter number, and a target. It then returns a 1 if you
 * won, a 0 to continue to the next turn or a 2 if you lost.
 */
int32_t crapsTurn(int32_t roll, int32_t turnCounter, int32_t target) {
  if (turnCounter == 0) {
    if (roll == 2 || roll == 3 || roll == 12) {
      return 2;
    } else if (roll == 7 || roll == 11) {
      return 1;
    }
  }
  if (turnCounter != 0) {
    if (roll == target) {
      return 1;
    }
    if (roll == 7) {
      return 2;
    }
  }
  return 0;
}

/**
 * takes the number of turns you want to track and the number of games you want
 * to simulate. it then returns the results in a int arr. This arr size is
 * decided by the number of turns you want to map.
 */
int32_t* crapsGame(const int32_t numOfGames, const int32_t turnsToMap) {
  dice crapsDice1(6);
  dice crapsDice2(6);
  int32_t target = 0;
  int32_t turnCounter = 0;
  int32_t* rawResults = new int32_t[turnsToMap + 1];
  for (int i = 0; i < numOfGames;) {
    int32_t roll = crapsDice1.roll() + crapsDice2.roll();
    if(turnCounter == 0){
      target = roll;
    }
    if(turnCounter > turnsToMap){
      turnCounter = (turnsToMap + 1);
    }
    if(crapsTurn(roll, turnCounter, target) == 2) {
    turnCounter = 0;
    ++i;
    continue;
    }
    if(crapsTurn(roll, turnCounter, target) == 1) {
    rawResults[turnCounter] +=1;
    turnCounter = 0;
    ++i;
    continue;
    }
    if(crapsTurn(roll, turnCounter, target) == 0) {
    ++turnCounter;
    continue;
    }
  }
  return rawResults;
  delete[] rawResults;
  rawResults = nullptr;
}

/**
 * this takes the results genarated from |crapsGame| and displays them in a
 * readable format.
 */
// void displayResults(int** rawResults)
