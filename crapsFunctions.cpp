#include <random>


/**
 * simulates the roll of two dice and gives you the combined total
 */
// int32_t DiceRoll(void)

/**
 * simulates a game of craps (non casino style)
 */
// bool crapsGame(void)

class dice {
 public:
  dice(uint32_t sides) {
    this->sides = sides;
  }
  uint32_t roll() {
    return (rand() % sides) + 1;
  }


 private:
  uint32_t sides;
};



