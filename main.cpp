#include <iostream>
#include <ctime>
#include "crapsFunctions.cpp"

using namespace std;

int main() {
  srand(time(0));

//  dice d(6);
//  for (int i = 0; i < 5; ++i) {
    //  cout << d.roll() << endl;
//  }
//  // cout << "-------------" << endl;
//  dice d2(24);
//  for (int i = 0; i < 5; ++i) {
    // cout << d2.roll() << endl;
//  }
//
//  int numDice = 10;
//  dice** myDice = new dice*[numDice];
//  for (int i = 0; i < numDice; ++i) {
//    myDice[i] = new dice(i + 1);
//  }
//  for (int i = 0; i < numDice; ++i) {
//    cout << myDice[i]->roll();
//    cout << "--->" << (i + 1) << "Sided Dice" << endl;
//  }
//
//  for (int i = 0; i < numDice; ++i) {
//    delete myDice[i];
//    myDice[i] = nullptr;
//  }
//  delete[] myDice;
//  myDice = nullptr;
//  return 0;

  int32_t* results = crapsGame(1000000, 10);
  for(int i = 0; i < 11; ++i) {
    cout << results[i] / 10000 << "%" << endl;
  }
  int32_t total = 0;
  for(int i = 0; i < 11; ++i) {
    total += results[i];
  }
  cout << total / 10000 << "%" << endl;
}