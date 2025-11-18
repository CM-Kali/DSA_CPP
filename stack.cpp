#include <iostream>
#include <string.h>
using namespace std;

// Stack class using array
class Stack {
private:
    int arr[100];
    int top;
    
public:
    Stack() {
        top = -1;
    }
    
    // Push operation
    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << value << endl;
            return;
        }
        arr[++top] = value;
    }
    
    // Pop operation
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop" << endl;
            return -1;
        }
        return arr[top--];
    }
    
    // Top operation
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[top];
    }
    
    // Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }
    
    // Check if stack is full
    bool isFull() {
        return top == 99;
    }
    
    // Display stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        
        cout << "Stack (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// 1. Reverse string using stack
void reverseString(char str[]) {
    Stack s;
    int len = strlen(str);
    
    // Push all characters onto stack
    for (int i = 0; i < len; i++) {
        s.push(str[i]);
    }
    
    // Pop characters to get reversed string
    for (int i = 0; i < len; i++) {
        str[i] = s.pop();
    }
}

// 2. Balanced parentheses
bool isBalanced(char expr[]) {
    Stack s;
    int len = strlen(expr);
    
    for (int i = 0; i < len; i++) {
        char ch = expr[i];
        
        if (ch == '(' || ch == '[' || ch == '{') {
            s.push(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (s.isEmpty()) return false;
            
            char top = s.pop();
            
            if ((ch == ')' && top != '(') ||
                (ch == ']' && top != '[') ||
                (ch == '}' && top != '{')) {
                return false;
            }
        }
    }
    
    return s.isEmpty();
}

// 3. Next greater element
void nextGreater(int arr[], int n, int result[]) {
    Stack s;
    
    // Initialize result array with -1
    for (int i = 0; i < n; i++) {
        result[i] = -1;
    }
    
    // Traverse from right to left
    for (int i = n - 1; i >= 0; i--) {
        // Pop elements smaller than current
        while (!s.isEmpty() && s.peek() <= arr[i]) {
            s.pop();
        }
        
        // If stack not empty, next greater is at top
        if (!s.isEmpty()) {
            result[i] = s.peek();
        }
        
        s.push(arr[i]);
    }
}

// 4. Stock span problem
void stockSpan(int prices[], int n, int span[]) {
    Stack s; // stack to store indices
    
    span[0] = 1; // span of first day is always 1
    s.push(0);
    
    for (int i = 1; i < n; i++) {
        // Pop while stack not empty and price at top <= current price
        while (!s.isEmpty() && prices[s.peek()] <= prices[i]) {
            s.pop();
        }
        
        // If stack empty, current price is highest so far
        // Else calculate span
        span[i] = s.isEmpty() ? (i + 1) : (i - s.peek());
        
        s.push(i);
    }
}

// 5. Min Stack implementation
class MinStack {
private:
    Stack mainStack;
    Stack minStack;
    
public:
    void push(int value) {
        mainStack.push(value);
        
        if (minStack.isEmpty() || value <= minStack.peek()) {
            minStack.push(value);
        }
    }
    
    void pop() {
        if (mainStack.isEmpty()) return;
        
        if (mainStack.peek() == minStack.peek()) {
            minStack.pop();
        }
        mainStack.pop();
    }
    
    int top() {
        return mainStack.peek();
    }
    
    int getMin() {
        return minStack.peek();
    }
    
    bool isEmpty() {
        return mainStack.isEmpty();
    }
};

// 6. Postfix evaluation
int evaluatePostfix(char expr[]) {
    Stack s;
    int len = strlen(expr);
    
    for (int i = 0; i < len; i++) {
        char ch = expr[i];
        
        // If digit, push to stack
        if (ch >= '0' && ch <= '9') {
            s.push(ch - '0');
        }
        // If operator, pop two and apply operation
        else {
            int val2 = s.pop();
            int val1 = s.pop();
            
            switch(ch) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
            }
        }
    }
    
    return s.pop();
}

// 7. Infix to Postfix conversion
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    Stack s;
    int len = strlen(infix);
    int j = 0; // index for postfix
    
    for (int i = 0; i < len; i++) {
        char ch = infix[i];
        
        // If operand, add to output
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || 
            (ch >= '0' && ch <= '9')) {
            postfix[j++] = ch;
        }
        // If '(', push to stack
        else if (ch == '(') {
            s.push(ch);
        }
        // If ')', pop until '('
        else if (ch == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix[j++] = s.pop();
            }
            s.pop(); // Remove '('
        }
        // If operator
        else {
            while (!s.isEmpty() && precedence(ch) <= precedence(s.peek())) {
                postfix[j++] = s.pop();
            }
            s.push(ch);
        }
    }
    
    // Pop all remaining operators
    while (!s.isEmpty()) {
        postfix[j++] = s.pop();
    }
    
    postfix[j] = '\0'; // Null terminate the string
}

// Demo functions
void demoBasicStack() {
    cout << "=== BASIC STACK OPERATIONS ===" << endl;
    Stack s;
    
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    
    cout << "Top element: " << s.peek() << endl;
    
    s.pop();
    s.display();
    
    s.push(40);
    s.push(50);
    s.display();
}

void demoReverseString() {
    cout << "\n=== REVERSE STRING USING STACK ===" << endl;
    char str[] = "Hello";
    cout << "Original: " << str << endl;
    reverseString(str);
    cout << "Reversed: " << str << endl;
}

void demoBalancedParentheses() {
    cout << "\n=== BALANCED PARENTHESES ===" << endl;
    char expr1[] = "((a+b)*c)";
    char expr2[] = "((a+b)*c";
    char expr3[] = "[(a+b)*{c-d}]";
    
    cout << expr1 << " : " << (isBalanced(expr1) ? "Balanced" : "Not Balanced") << endl;
    cout << expr2 << " : " << (isBalanced(expr2) ? "Balanced" : "Not Balanced") << endl;
    cout << expr3 << " : " << (isBalanced(expr3) ? "Balanced" : "Not Balanced") << endl;
}

void demoNextGreater() {
    cout << "\n=== NEXT GREATER ELEMENT ===" << endl;
    int arr[] = {4, 5, 2, 10, 8};
    int n = 5;
    int result[5];
    
    nextGreater(arr, n, result);
    
    cout << "Array:   ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\nNGE:     ";
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}

void demoStockSpan() {
    cout << "\n=== STOCK SPAN PROBLEM ===" << endl;
    int prices[] = {100, 80, 60, 70, 60, 75, 85};
    int n = 7;
    int span[7];
    
    stockSpan(prices, n, span);
    
    cout << "Prices: ";
    for (int i = 0; i < n; i++) {
        cout << prices[i] << " ";
    }
    cout << "\nSpans:  ";
    for (int i = 0; i < n; i++) {
        cout << span[i] << " ";
    }
    cout << endl;
}

void demoMinStack() {
    cout << "\n=== MIN STACK ===" << endl;
    MinStack ms;
    
    ms.push(5);
    ms.push(2);
    ms.push(8);
    ms.push(1);
    ms.push(4);
    
    cout << "Current min: " << ms.getMin() << endl;
    ms.pop();
    cout << "After pop - Current min: " << ms.getMin() << endl;
    ms.pop();
    cout << "After pop - Current min: " << ms.getMin() << endl;
}

void demoPostfix() {
    cout << "\n=== POSTFIX EVALUATION ===" << endl;
    char expr[] = "23+45-*"; // (2+3)*(4-5) = 5*(-1) = -5
    cout << "Expression: " << expr << endl;
    cout << "Result: " << evaluatePostfix(expr) << endl;
}

void demoInfixToPostfix() {
    cout << "\n=== INFIX TO POSTFIX ===" << endl;
    char infix[] = "a+b*c";
    char postfix[100];
    
    infixToPostfix(infix, postfix);
    cout << "Infix: " << infix << endl;
    cout << "Postfix: " << postfix << endl;
}

int main() {
    demoBasicStack();
    demoReverseString();
    demoBalancedParentheses();
    demoNextGreater();
    demoStockSpan();
    demoMinStack();
    demoPostfix();
    demoInfixToPostfix();
    
    return 0;
}
