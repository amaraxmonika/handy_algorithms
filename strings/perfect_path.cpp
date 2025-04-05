
#include <sstream>
#include <string>
#include <vector>
#include <assert.h>
#include <iostream>

using namespace std;

string simplify_path(string path) {
  vector<string> stack;
  stringstream ss(path);

  string temp;
  // getline will append characters to temp until the delimiter '/' is encountered
  while (getline(ss, temp, '/')) {
    // If we are supposed to navigate back one directory, then remove the last
    // directory that was popped onto the stack.
    if (temp == "..") {
      if (!stack.empty()) {
        stack.pop_back();
      }
    } else if (temp != "." && !temp.empty()) {
      stack.push_back(temp);
    }
  }

  string res = "";
  for (auto str : stack) {
    res += "/" + str;
  }

  if (res.empty()) {
    return "/";
  } else {
    return res;
  }

}

string simplify_path_round_2(string path) {
  vector<string> stack;
  stringstream ss(path);

  string temp;
  while (getline(ss, temp, '/')) {
    stack.push_back(temp);
  }


  string res = "";
  int count = 0;
  // Navigate from back of list to the front
  while (!stack.empty()) {
    string current = stack.back();
    if (current == "..") {
      count++;
    } else if (current == ".") {
      continue;
    } else if (count <= 0){
      if (res.empty()) {
        res = current;
      } else {
        res = current + "/" + res;
      }
    } else {
      count--;
    }
    stack.pop_back();

  }

  return res;

}

int main (int argc, char *argv[]) {
  
  string test1 = "/this/is/a/test/string";
  assert(test1 == simplify_path(test1));

  string test2 = "/this/is/../..";
  assert("/" == simplify_path(test2));

  string test3 = "";
  assert("/" == simplify_path(test3));

  assert("/" == simplify_path("/////"));

  cout << "Round 2: " << simplify_path_round_2("/this/is/a/test/string") << endl;
  cout << "Round 2: " << simplify_path_round_2( "/this/is/../..") << endl;
  cout << "Round 2: " << simplify_path_round_2("/home/user/Documents/../Pictures") << endl;
  return 0;
}

