#include <iostream>
using namespace std;

int main() {
    char operation;
    double num1, num2;

    cout << "Select operation:" << endl;
    cout << "a. Addition (+)" << endl;
    cout << "b. Subtraction (-)" << endl;
    cout << "c. Multiplication (*)" << endl;
    cout << "d. Division (/)" << endl;
    cout << "Enter your choice (a/b/c/d): ";
    cin >> operation;

    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    switch (operation) {
        case 'a':
        case '+':
            cout << "Result: " << num1 + num2 << endl;
            break;
        case 'b':
        case '-':
            cout << "Result: " << num1 - num2 << endl;
            break;
        case 'c':
        case '*':
            cout << "Result: " << num1 * num2 << endl;
            break;
        case 'd':
        case '/':
            if (num2 != 0) {
                cout << "Result: " << num1 / num2 << endl;
            } else {
                cout << "Error: Division by zero!" << endl;
            }
            break;
        default:
            cout << "Error: Invalid operation!" << endl;
            break;
    }

    return 0;
}