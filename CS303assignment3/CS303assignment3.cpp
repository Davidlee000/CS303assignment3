
#include <iostream>
#include "header.h"
using namespace std;
int main()
{
    ExpressionManager em;
    string expression;
    cout << "Enter an infix expression: ";
    getline(cin, expression);
    string result = em.convertExpression(expression);
    cout << "Result: " << result << endl;
    return 0;
}



