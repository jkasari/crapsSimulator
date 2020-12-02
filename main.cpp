#include <iostream>
#include <ctime>
#include "crapsFunctions.cpp"

using namespace std;

int main() {
  srand(time(0));

  dice d(6);
  for(int i = 0; i < 5; ++i) {
    cout << d.roll() << endl;
  }
  cout << "-------------" << endl;
  dice d2(24);
  for(int i = 0; i < 5; ++i) {
    cout << d2.roll() << endl;
  }
  return 0;
}
