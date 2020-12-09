#include <random>

/**
 * behives like a die, use the .roll function to generate a virtual roll.
 */
class dice {
 public:
  dice(const uint32_t sides) { this->sides = sides; }
  uint32_t roll() const { return (rand() % sides) + 1; }

 private:
  uint32_t sides;
};

enum class TurnOutcome {
  Continue,
  Win,
  Lose,
};

/**
 * simulates the first turn of a craps game.
 */
TurnOutcome firstTurn(const uint32_t roll) {
  switch (roll) {
    case 2:
    case 3:
    case 12:
      return TurnOutcome::Lose;
    case 7:
    case 11:
      return TurnOutcome::Win;
    default:
      return TurnOutcome::Continue;
  }
}

TurnOutcome subsequentTurn(const uint32_t roll, const uint32_t target) {
  if (roll == 7) {
    return TurnOutcome::Lose;
  } else if (roll == target) {
    return TurnOutcome::Win;
  }
  return TurnOutcome::Continue;
}

/**
 * takes the number of turns you want to track and the number of games you want
 * to simulate. it then returns the results in a int arr. This arr size is
 * decided by the number of turns you want to map.
 */
uint32_t* crapsGame(const uint32_t numOfGames, const uint32_t turnsToMap) {
  const dice crapsDice1(6);
  const dice crapsDice2(6);
  uint32_t* rawResults = new uint32_t[turnsToMap + 1];

  for (int gameNum = 0; gameNum < numOfGames; ++gameNum) {
    uint32_t turnCounter = 0;
    uint32_t roll = crapsDice1.roll() + crapsDice2.roll();
    TurnOutcome outcome = firstTurn(roll);

    if (outcome == TurnOutcome::Win) {
      rawResults[0] += 1;
    }

    uint32_t target = roll;

    while (outcome == TurnOutcome::Continue) {
      ++turnCounter;
      roll = crapsDice1.roll() + crapsDice2.roll();
      outcome = subsequentTurn(roll, target);
      if (outcome == TurnOutcome::Win) {
        rawResults[std::min(turnCounter, turnsToMap)] += 1;
      }
    }
  }

  return rawResults;
}

/**
 * this takes the results genarated from |crapsGame| and displays them in a
 * readable format.
 */
// void displayResults(int* rawResults, int32_t numOfGames, ) {
