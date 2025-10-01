#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

// Function to determine precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3; // Added for exponentiation precedence
    return 0;
}

// Function to convert infix to postfix
string infixToPostfix(const string& infix) {
    stack<char> operators;
    string postfix;
    
    for (char ch : infix) {
        if (isalnum(ch)) {
            postfix += ch; // Append operand to output
        } else if (ch == '(') {
            operators.push(ch);
        } else if (ch == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop(); // Pop '('
        } else {
            while (!operators.empty() && precedence(operators.top()) >= precedence(ch)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(ch);
        }
    }
    
    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

// Function to convert infix to prefix
string infixToPrefix(const string& infix) {
    string reversedInfix(infix.rbegin(), infix.rend());
    
    for (char& ch : reversedInfix) {
        if (ch == '(') ch = ')';
        else if (ch == ')') ch = '(';
    }
    
    string postfix = infixToPostfix(reversedInfix);
    
    return string(postfix.rbegin(), postfix.rend());
}

// Function to convert postfix to infix
string postfixToInfix(const string& postfix) {
    stack<string> operands;
    
    for (char ch : postfix) {
        if (isalnum(ch)) {
            operands.push(string(1, ch));
        } else {
            string op2 = operands.top(); operands.pop();
            string op1 = operands.top(); operands.pop();
            string expression = "(" + op1 + ch + op2 + ")";
            operands.push(expression);
        }
    }
    
    return operands.top();
}

// Function to convert prefix to infix
string prefixToInfix(const string& prefix) {
    stack<string> operands;
    
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char ch = prefix[i];
        if (isalnum(ch)) {
            operands.push(string(1, ch));
        } else {
            string op1 = operands.top(); operands.pop();
            string op2 = operands.top(); operands.pop();
            string expression = "(" + op1 + ch + op2 + ")";
            operands.push(expression);
        }
    }
    
    return operands.top();
}

// Main function
int main() {
    // Predefined inputs
    string infix = "A+B*(C^D-E)";
    cout << "Infix: " << infix << endl;
    
    string postfix = infixToPostfix(infix);
    cout << "Infix to Postfix: " << postfix << endl;

    string prefix = infixToPrefix(infix);
    cout << "Infix to Prefix: " << prefix << endl;

    postfix = "ABCD^E-*"; // Example postfix
    string infixFromPostfix = postfixToInfix(postfix);
    cout << "Postfix to Infix: " << infixFromPostfix << endl;

    prefix = "*+AB-CD"; // Example prefix
    string infixFromPrefix = prefixToInfix(prefix);
    cout << "Prefix to Infix: " << infixFromPrefix << endl;

    return 0;
}
/*  Notation Overview
Infix: The standard arithmetic notation where operators are between operands, e.g., A + B.
Prefix (Polish Notation): Operators precede their operands, e.g., + A B.
Postfix (Reverse Polish Notation): Operators follow their operands, e.g., A B +.
Conversion Mechanism
Infix to Postfix: Use a stack to hold operators and ensure correct order and precedence.
Infix to Prefix: Reverse the infix expression, convert it to postfix, and then reverse the postfix result.
Postfix to Infix: Use a stack to construct the infix expression while iterating through the postfix expression.
Prefix to Infix: Use a stack to construct the infix expression while iterating through the prefix expression in reverse.
*/
/*   Infix: A+B*(C^D-E)
Infix to Postfix: ABCD^E-*+
Infix to Prefix: +A*B-^CDE
Postfix to Infix: (B*((C^D)-E))
Prefix to Infix: ((A+B)*(C-D))
*/