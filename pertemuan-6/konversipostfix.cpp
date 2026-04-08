#include <bits/stdc++.h>
#include <cctype>

using namespace std;

// Cek apakah char adalah operator matematika
bool isOperator(char c) {
  return (c == '+' || c == '-' || c == '/' || c == '^' || c == '*');
}

// Menentukan prioritas operator matematika
int precedence(char c) {
  switch (c) {
  case '^':
    return 3;
  case '*':
  case '/':
    return 2;
  case '+':
  case '-':
    return 1;
  default:
    return 0;
  }
}

// Merubah notasi infix -> posfix
string infixToPostfix(string infix) {
  stack<char> st;
  string res = "";

  for (int i = 0; i < infix.length(); i++) {
    char c = infix[i];
    if (isalnum(c)) {
      res += c;
      continue;
    }
    if (c == '(') {
      st.push(c);
      continue;
    }

    if (c == ')') {
      while (!st.empty() && st.top() != '(') {
        res += st.top();
        st.pop();
      }
      if (!st.empty())
        st.pop();
      continue;
    }

    if (isOperator(c)) {
      while (!st.empty() && precedence(st.top()) >= precedence(c)) {
        res += st.top();
        st.pop();
      }
      st.push(c);
    }
  }
  while (!st.empty()) {
    res += st.top();
    st.pop();
  }

  return res;
}

int main() {
  string infix;
  cout << "Masukkan ekspresi infix: ";
  cin >> infix;

  string postfix = infixToPostfix(infix);
  cout << "Postfix: " << postfix << endl;
  return 0;
}
