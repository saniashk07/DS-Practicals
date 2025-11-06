#include <iostream>
#include <cctype>
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

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

void infixToPostfix(char infix[], char postfix[]) {
    Stack s;
    int i = 0, k = 0;

    while (infix[i] != '\0') {
        char c = infix[i];

        if (isalnum(c))
            postfix[k++] = c;
        else if (c == '(')
            s.push(c);
        else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(')
                postfix[k++] = s.pop();
            s.pop();
        }
        else if (isOperator(c)) {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(c))
                postfix[k++] = s.pop();
            s.push(c);
        }
        i++;
    }

    while (!s.isEmpty())
        postfix[k++] = s.pop();

    postfix[k] = '\0';
}

int main() {
    char infix[100], postfix[100];
    cout << "Enter infix expression: ";
    cin >> infix;

    infixToPostfix(infix, postfix);

    cout << "Postfix expression: " << postfix << endl;

    return 0;
}

