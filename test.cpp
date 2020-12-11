#include <iostream>
#include <ctime>
#include "nuttiest/nuttiest.hpp"
#include "crapsFunctions.cpp"

using namespace std;
using namespace nuttiest;

int main() {
  srand(time(0));
  section("dice") {
    unit_test("roll (6)") {
      dice d(6);
      uint32_t roll1 = d.roll();
      assert_ge(roll1, 1);
      assert_le(roll1, 6);
    }
    unit_test("roll (24)") {
      dice d(24);
      uint32_t roll1 = d.roll();
      assert_ge(roll1, 1);
      assert_le(roll1, 24);
    }
  }
  section("firstTurn") {
    unit_test("First turn (7) is a Win") {
      assert_eq(TurnOutcome::Win, firstTurn(7));
    }
    unit_test("First turn (3) is a Lose") {
      assert_eq(TurnOutcome::Lose, firstTurn(3));
    }
    unit_test("First turn (9) is a Continue") {
      assert_eq(TurnOutcome::Continue, firstTurn(9));
    }
  }
  section("subsequentTurn") {
    unit_test("A roll of (5) with a target of (5) is a Win") {
      assert_eq(TurnOutcome::Win, subsequentTurn(5,5));
    }
    unit_test("A roll of (7) with a target of (5) is a lose") {
      assert_eq(TurnOutcome::Lose, subsequentTurn(7,5));
    }
    unit_test("A roll of (8) with a target of (5) is a Continue") {
      assert_eq(TurnOutcome::Continue, subsequentTurn(8,5));
    }
  }
  summary();
}

