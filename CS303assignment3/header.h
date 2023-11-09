#pragma once

#include <stack>
#include <string>
using namespace std;
class ExpressionManager {
public:
    ExpressionManager();
    bool isBalanced(string expression);
    string infixToPostfix(string expression);
    string convertExpression(string expression);
private:
    int precedence(char ch);
    bool isOperator(char ch);
    bool isOpenParentheses(char ch);
    bool isCloseParentheses(char ch);
    bool isMatchingPair(char open, char close);
};
