#include <cctype>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char op) {
  if (op == '^')
    return 3;
  else if (op == '.' || op == '/')
    return 2;
  else if (op == '+' || op == '-')
    return 1;
  else
    return 0;
}

bool isOperator(char c) {
  return (c == '+' || c == '-' || c == '.' || c == '/' || c == '^');
}

string infixToPostfix(string infix) {
  stack<char> st;
  string postfix = "";

  for (int i = 0; i < infix.length(); i++) {
    char c = infix[i];

    if (isalnum(c)) {
      postfix += c;
      postfix += " ";
      continue;
    }
    if (c == '(') {
      st.push(c);
      continue;
    }
    if (c == ')') {
      while (!st.empty() && st.top() != '(') {
        postfix += st.top();
        postfix += " ";
        st.pop();
      }
      if (!st.empty())
        st.pop();
      continue;
    }
    if (isOperator(c)) {
      while (!st.empty() && precedence(st.top()) >= precedence(c)) {
        postfix += st.top();
        postfix += " ";
        st.pop();
      }
      st.push(c);
      continue;
    }
  }

  while (!st.empty()) {
    postfix += st.top();
    postfix += " ";
    st.pop();
  }

  return postfix;
}

int main() {
  string infix = "a + (2 . b ^ 3) / (f − g) + d . h";

  cout << "Jawaban: " << infixToPostfix(infix) << endl;
  return 0;
}
