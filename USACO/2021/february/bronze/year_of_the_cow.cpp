/*
 * TheMartian0x48
 */

#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<string> Animal{"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};
  unordered_map<string, int> animal;
  for (int i = 0; i < 12; i++) {
    animal[Animal[i]] = i;
  }
  unordered_map<string, string> year;
  unordered_map<string, int> yob;

  year["Bessie"] = "Ox";
  yob["Bessie"] = 0;

  string s, name1, name2, order, yr;
  int n; cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> name1; 
    cin >> s; cin >> s;
    cin >> order; 
    cin >> yr;
    cin >> s; cin >> s;
    cin >> name2;

    year[name1] = yr;
    int x = animal[year[name2]];
    int y = animal[year[name1]];
    int diff;
    if (order == "next") {
      if (x < y)
        diff = y - x;
      else 
        diff = 12 + y - x;
      yob[name1] = yob[name2] + diff;
    } else {
      if (y < x) {
        diff = x - y;
      } else {
        diff = 12 - y + x;
      }
      yob[name1] = yob[name2] - diff;
    }
  }
  cout << abs(yob["Bessie"] - yob["Elsie"]);
}
