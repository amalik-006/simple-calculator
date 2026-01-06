// ==== SIMPLE CALCULATOR ====

#include <iostream>
#include <limits>
using namespace std;

//Function Declarations
double add (double a, double b);
double subtract (double a, double b);
double multiply (double a, double b);
double divide (double a, double b, bool &valid);

int main() {
    int choice;
    double num1, num2, result;
    bool valid;

    do 
    {
        //Diaplay the Menu
        cout << "\n===== Simple Calculator =====\n";
        cout << "1. Add (+)\n";
        cout << "2. Subtract (-)\n";
        cout << "3. Multiply (x)\n";
        cout << "4. Divide (/)\n";
        cout << "0. Exit\n";
        cout << "Choose an option (0-4): ";
        cin >> choice;

        // Invalid Menu Input Handling
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Input! Please enter a valid number'";
            continue;
        }

        if (choice >=1 && choice <= 4)
        {
            cout << "Enter two  Numbers: ";
            cin >> num1 >> num2;

            //Handle Invalid Number Input
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid number input! \n";
                continue;
            }
        }

        //Handle User's Choice
        switch (choice)
        {
            case 1:
            result = add(num1, num2);
            cout << "Result: " << result << endl;
            break;

            case 2:
            result = subtract(num1, num2);
            cout << "Result: " << result << endl;
            break;

            case 3:
            result = multiply(num1, num2);
            cout << "Result: " << result << endl;
            break;

            case 4:
            result = divide(num1, num2, valid);
            if (valid)
            cout << "Result: " << result << endl;
            else 
            cout << "Error! Division by Zero is not Allowed.\n";
            break;

            case 0:
            cout << "Exiting Program. Goodbye!" << endl;
            break;

            default:
            cout << "Invalid choice. Please Try Again." << endl;
        }
    }
    while (choice != 0);  //Continue Looping until the user decides to exit the program

    return 0;
}

// ------------ FUNCTION DEFINTIONS ------------
double add (double a, double b)
{
    return a + b;
}

double subtract (double a, double b)
{
    return a - b;
}

double multiply (double a, double b)
{
    return a * b;
}

double divide (double a, double b, bool &valid)
{
    if (b == 0)
    {
        valid = false;
        return 0;
    }
    valid = true;
    return a / b;
}