#include <bits/stdc++.h>
 
using namespace std;
 
pair<int, int> a[1000];
 
int main() {
  int n; cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].first >> a[i].second;
    if (i >= 3) {
      bool check = 1;
      for (int j = i-2; j <= i; ++j)
        if (a[j].first != a[j].second)
          check = 0;
      if (check) {
        cout << "Yes";
        return 0;
      }
    }
  }
  cout << "No";
  return 0;
}