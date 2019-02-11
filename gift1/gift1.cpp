/*
ID: samiurk1
TASK: gift1
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
  ifstream fin("gift1.in");
  ofstream fout("gift1.out");
  
  int group_size;
  fin >> group_size;

  string name;
  // Note: data duplication here. Idea: string_view?
  vector<string> group;
  unordered_map<string, int> balances;
  for (int i = 0; i < group_size; ++i) {
    fin >> name;
    group.push_back(name);
    balances[name] = 0;
  }

  // Lesson: Don't overcomplicate. Simple = good/okay.
  int total_gift_amount, num_people_receiving, individual_gift;
  for (int i = 0; i < group_size; ++i) {
    fin >> name >> total_gift_amount >> num_people_receiving;
    balances[name] -= total_gift_amount;
    if (num_people_receiving == 0)
      continue;
    individual_gift = (int)floor(total_gift_amount / num_people_receiving);
    balances[name] += total_gift_amount - (individual_gift * num_people_receiving);
    for (int j = 0; j < num_people_receiving; ++j) {
      fin >> name;
      balances[name] += individual_gift;
    }
  }

  for (auto& name : group) {
    fout << name << " " << balances[name] << endl;
  }
  return 0;
}
