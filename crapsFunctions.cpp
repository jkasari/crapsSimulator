#include <random>

/**
 * behives like a die, use the .roll function to generate a virtual roll.
 */
// class dice

/**
 * takes the number of turns you want to track and the number of games you want
 * to simulate. it then returns the results in a int arr. This arr size is
 * decided by the number of turns you want to map.
 */
//int** rawResults crapsGame(const int32_t numOfGames, const int32_t turnsToMap)

/**
 * this takes the results genarated from |crapsGame| and displays them in a readable format.
 */
//void displayResults(int** rawResults)

class dice {
 public:
  dice(uint32_t sides) { this->sides = sides; }
  uint32_t roll() { return (rand() % sides) + 1; }

 private:
  uint32_t sides;
};
