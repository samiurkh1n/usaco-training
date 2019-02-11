/*
ID: samiurk1
TASK: ride
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int ComputeScore(const string& name) {
  int score = 1;
  // LESSON: Check character. Ensure its alphanumerical.
  for (char character : name) {
    score *= ((int)character - 64);
  }
  return score;
}

bool DoesGroupLeave(const string& comet, const string& group) {
  return ( (ComputeScore(comet) % 47) == (ComputeScore(group) % 47) );
}

int main() {
  ifstream fin("ride.in");
  ofstream fout("ride.out");
  string comet, group;
  fin >> comet >> group;
  bool leave = DoesGroupLeave(comet, group);
  if (leave)
    fout << "GO" << endl;
  else
    fout << "STAY" << endl;
  return 0;
}
