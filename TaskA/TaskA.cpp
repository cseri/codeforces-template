
#pragma region *** Contest lib header ***

// Boilerplate code for cseri.
// See: https://github.com/cseri/codeforces-template

#define _CRT_SECURE_NO_WARNINGS

// C
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cassert>
// Containers
#include <string>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
// Streams
#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
// Other
#include <algorithm>
#include <functional>
#include <utility>
#include <memory>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

#ifndef ONLINE_JUDGE
#include "local.h"
#else
#define PRINT(x)
#endif

#pragma endregion

struct Task {

  /// @returns like the main function.
  int solve(string filePrefix) {
#ifndef ONLINE_JUDGE
#define cin f
    ifstream f(filePrefix + ".txt");
    freopen((filePrefix + ".out").c_str(), "w", stdout);
    //freopen((filePrefix + ".err").c_str(), "w", stderr);
#endif

    ll n = -1;
    cin >> n;
    PRINT(n);

    vector<ll> vec(n);
    for (int i = 0; i < n; ++i) {
      cin >> vec[i];
    }
    PRINT(vec);

    ll sol = 0;
    for (int i = 0; i < n; ++i) {
      sol += vec[i];
    }

    cout << sol << endl;
#ifndef ONLINE_JUDGE
    cerr << sol << endl;
#endif
    return 0;
  }

};

#pragma region *** Contest lib footer ***

int solve(std::string s) {
  Task t;
  return t.solve(s);
}

int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(false);
  return solve("");
}

#pragma endregion
