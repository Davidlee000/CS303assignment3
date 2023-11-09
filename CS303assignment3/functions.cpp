#include "header.h"
using namespace std;
ExpressionManager::ExpressionManager() {}

int ExpressionManager::precedence(char ch) {
    switch (ch) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    default:
        return -1;
    }
}

bool ExpressionManager::isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%';
}

bool ExpressionManager::isOpenParentheses(char ch) {
    return ch == '(' || ch == '{' || ch == '[';
}

bool ExpressionManager::isCloseParentheses(char ch) {
    return ch == ')' || ch == '}' || ch == ']';
}

bool ExpressionManager::isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') || (open == '{' && close == '}') || (open == '[' && close == ']');
}

bool ExpressionManager::isBalanced(string expression) {
    stack<char> s;
    for (char& ch : expression) {
        if (isOpenParentheses(ch)) {
            s.push(ch);
        }
        else if (isCloseParentheses(ch)) {
            if (s.empty() || !isMatchingPair(s.top(), ch)) {
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}

string ExpressionManager::infixToPostfix(string expression) {
    stack<char> s;
    string postfix;
    for (char& ch : expression) {
        if (isOperator(ch)) {
            while (!s.empty() && precedence(s.top()) >= precedence(ch)) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
        else if (isOpenParentheses(ch)) {
            s.push(ch);
        }
        else if (isCloseParentheses(ch)) {
            while (!s.empty() && !isOpenParentheses(s.top())) {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
        else {
            postfix += ch;
        }
    }
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}

string ExpressionManager::convertExpression(string expression) {
    if (!isBalanced(expression)) {
        return "Invalid expression";
    }
    else {
        return infixToPostfix(expression);
    }
}





