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

  summary();
}

