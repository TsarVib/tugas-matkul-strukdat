#include <bits/stdc++.h>
using namespace std;

bool isOperator(string token) {
  return (token == "+" || token == "-" || token == "*" || token == "/" ||
          token == "^");
}

int evaluatePostfix(string exp) {
  stack<int> st;
  stringstream ss(exp);
  string token;

  while (ss >> token) {
    if (!isOperator(token)) {
      st.push(stoi(token));
      continue;
    }
    int val2 = st.top();
    st.pop();
    int val1 = st.top();
    st.pop();

    if (token == "+")
      st.push(val1 + val2);
    else if (token == "-")
      st.push(val1 - val2);
    else if (token == "*")
      st.push(val1 * val2);
    else if (token == "/")
      st.push(val1 / val2);
    else if (token == "^")
      st.push(pow(val1, val2));
  }

  return st.top();
}

int main() {
  string postfix;

  cout << "Masukkan postfix (pisahkan dengan spasi): ";
  getline(cin, postfix);

  cout << "Hasil: " << evaluatePostfix(postfix) << endl;

  return 0;
}
