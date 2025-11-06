#include <iostream>
using namespace std;

#define SIZE 100

class Stack {
    char arr[SIZE];
    int top;

public:
    Stack() { top = -1; }

    void push(char c) {
        if (top == SIZE - 1)
            cout << "Stack Overflow\n";
        else
            arr[++top] = c;
    }

    char pop() {
        if (top == -1)
            return '\0';
        else
            return arr[top--];
    }

    char peek() {
        if (top == -1)
            return '\0';
        else
            return arr[top];
    }

    bool isEmpty() {
        return (top == -1);
    }
};

bool isMatchingPair(char open, char close) {
    return ((open == '(' && close == ')') ||
            (open == '{' && close == '}') ||
            (open == '[' && close == ']'));
}

bool isBalanced(char expr[]) {
    Stack s;
    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];
        if (ch == '(' || ch == '{' || ch == '[')
            s.push(ch);
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.isEmpty())
                return false;
            if (!isMatchingPair(s.pop(), ch))
                return false;
        }
    }
    return s.isEmpty();
}

int main() {
    char expr[100];
    cout << "Enter an expression: ";
    cin >> expr;

    if (isBalanced(expr))
        cout << "Expression is well parenthesized.\n";
    else
        cout << "Expression is NOT well parenthesized.\n";

    return 0;
}}

