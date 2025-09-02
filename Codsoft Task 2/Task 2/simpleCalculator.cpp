#include <iostream>
using namespace std;

int main()
{
    double n1, n2;
    char op;
    cout << "Enter the opertaor (+ - * /) : ";
    cin >> op;

    cout << "Enter the two number : ";
    cin >> n1 >> n2;

    switch (op)
    {
    case '+':
        cout << n1 << " " << op << " " << n2 << " = " << n1 + n2 << endl;
        break;

    case '-':
        cout << n1 << " " << op << " " << n2 << " = " << n1 - n2 << endl;
        break;

    case '*':
        cout << n1 << " " << op << " " << n2 << " = " << n1 * n2 << endl;
        break;

    case '/':
        if (n2 == 0)
        {
            cout << "Does not perform division";
        }
        else
        {
            cout << n1 << " " << op << " " << n2 << " = " << n1 / n2 << endl;
        }
        break;

    default:
        cout << "Invalid operator please enter valid operator";
        break;
    }

    return 0;
}