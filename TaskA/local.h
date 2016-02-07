#pragma once

// Boilerplate code for cseri.
// See: https://github.com/cseri/codeforces-template
// (c) MIT License, see COPYING

#include "../third_party/prettycc/pretty.hpp"

PRETTY_DEFAULT_DECORATION(std::vector<T>, "[", ", ", "]", class T)
PRETTY_DEFAULT_DECORATION(std::deque<T>, "[", ", ", "]", class T)
PRETTY_DEFAULT_DECORATION(std::set<T>, "{", ", ", "}", class T)
PRETTY_DEFAULT_DECORATION(std::unordered_set<T>, "{", ", ", "}", class T)
// TODO: Decorate maps.

#define PRINT(x) \
  std::cout << "  "#x": " << (x) << std::endl; \
  std::cerr << "  "#x": " << (x) << std::endl

// For user interaction. Including the whole windows.h can have massive side
// effects (new types, etc.) so we're better off with these declarations.
extern "C" {
  short __stdcall GetAsyncKeyState(_In_ int vKey);
}
#define VK_LCONTROL 0xA2

bool is_file_exist(string fileName) {
  ifstream infile(fileName);
  return static_cast<bool>(infile);
}

int solve_fncheck(string fileName) {
  if (!is_file_exist(fileName + ".txt")) {
    cerr << "File " << fileName.c_str() << ".txt does not extits." << endl;
    return 0;
  }
  cerr << "Solving " << fileName.c_str() << ".txt:" << endl;
  return solve(fileName);
}

int local_main(int argc, char* argv[]) {
  int ret = 0;

  if (GetAsyncKeyState(VK_LCONTROL) < 0) {
    cout << "Enter testcase to run: ";
    string taskName;
    getline(cin, taskName);
    ret = solve_fncheck(taskName);
  } else {
    const int N = 5;
    for (int i = 1; i <= N; ++i) {
      ret = solve_fncheck(to_string(i));
      if (ret != 0)
        break;
    }
  }

  cerr << "Press ENTER to continue . . ." << endl;
  string dummy;
  getline(cin, dummy);

  return ret;
}
