//
// File: Main.cpp
// Description: Poker Dice Game, calculate the score from a throw of five dice.
// Scores are assigned to different categories for singles, three of a kind,
// four of a kind, five of a kind, full house, and straight. Created: Sun, April
// 9 2023 Author: Noah Sanderson mail: Noahs6423@student.vvc.edu
//
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Add all occurences of goal value
int CheckSingles(vector<int> &diceValues, int goal) {
  int value = 0;
  for (int i = 0; i < 5; ++i) {
    if (diceValues[i] == goal) {
      value += diceValues[i];
    }
  }
  return value;
}

// Check for three of a kind (score = 30)
int CheckThreeOfKind(vector<int> &diceValues) {
  for (int i = 0; i < 3; ++i) {
    if (diceValues[i] == diceValues[i + 1] &&
        diceValues[i] == diceValues[i + 2]) {
      return 30;
    }
  }
  return -1;
}

// Check for four of a kind (score = 40)
int CheckFourOfKind(vector<int> &diceValues) {
  for (int i = 0; i < 2; ++i) {
    if (diceValues[i] == diceValues[i + 1] &&
        diceValues[i] == diceValues[i + 2] &&
        diceValues[i] == diceValues[i + 3]) {
      return 40;
    }
  }
  return -1;
}

// Check for five of a kind (score = 50)
int CheckFiveOfKind(vector<int> &diceValues) {
  if (diceValues[0] == diceValues[4]) {
    return 50;
  }
  return -1;
}

// Check for full house (score = 35)
int CheckFullHouse(vector<int> &diceValues) {
  if (diceValues[0] == diceValues[1] && diceValues[2] == diceValues[4] ||
      diceValues[0] == diceValues[2] && diceValues[3] == diceValues[4]) {
    return 35;
  }
  return -1;
}

// Check for straight (score = 45)
int CheckStraight(vector<int> &diceValues) {

  if (diceValues[0] == 1 && diceValues[1] == 2 && diceValues[2] == 3 &&
          diceValues[3] == 4 && diceValues[4] == 5 ||
      diceValues[0] == 2 && diceValues[1] == 3 && diceValues[2] == 4 &&
          diceValues[3] == 5 && diceValues[4] == 6) {
    return 45;
  }
  return -1;
}

// Find high score
int FindHighScore(vector<int> &diceValues) {
  if (CheckFiveOfKind(diceValues) != -1) {
    return CheckFiveOfKind(diceValues);
  } else if (CheckStraight(diceValues) != -1) {
    return CheckStraight(diceValues);
  } else if (CheckFourOfKind(diceValues) != -1) {
    return CheckFourOfKind(diceValues);
  } else if (CheckFullHouse(diceValues) != -1) {
    return CheckFullHouse(diceValues);
  } else if (CheckThreeOfKind(diceValues) != -1) {
    return CheckThreeOfKind(diceValues);
  }
  int maxVal = 0;
  for (int i = 1; i <= 6; ++i) {
    if (CheckSingles(diceValues, i) > maxVal) {
      maxVal = CheckSingles(diceValues, i);
    }
  }
  return maxVal;
}

int main() {
  vector<int> diceValues(5);
  int highScore = 0;

  // Fill array with five values from input
  for (int i = 0; i < 5; ++i) {
    cin >> diceValues.at(i);
  }

  // Place values in ascending order
  sort(diceValues.begin(), diceValues.end());

  // Find high score and output
  highScore = FindHighScore(diceValues);
  cout << "High score: " << highScore << endl;

  return 0;
}
