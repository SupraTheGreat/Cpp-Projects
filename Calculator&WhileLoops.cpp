#include <iostream>
#include <string>

using namespace std;
// Calculator & While Loops

// This function checks if num1 and num2 are numbers or not.
string solve( string s ) {
   for( int i = 0; i < s.length(); i++ ) {
      if( !isdigit( s[i] )) {
         return "False";
      }
   }
   return "True";
}

int checkOperator(int answer, int one, int two, char opr){

    if(opr != '+' && opr != '-' && opr != '*' && opr != '/') {
        /* While loops take a condition and keep executing the code within them until
        the condition is satisfied. */
        while (opr != '+' && opr != '-' && opr != '*' && opr != '/') {
            cout << "INVALID OPERATOR. Enter the operator again: ";
            cin >> opr;
        }
    }
    if(opr == '+'){
        answer = one + two;
        cout << "The operator is " << opr << endl;
    } else if(opr == '-'){
        answer = one - two;
        cout << "The operator is " << opr << endl;
    } else if(opr == '*'){
        answer = one * two;
        cout << "The operator is " << opr << endl;
    } else if(opr == '/'){
        answer = one / two;
        cout << "The operator is " << opr << endl;
    }
    return answer;
}



int main()
{
    string num1, num2;
    int result;
    char op;

    cout << "Enter the first number: ";
    cin >> num1;

    if (solve(num1) == "False"){
        while (solve(num1) == "False"){
          cout << "INVALID INPUT. Enter the first number again: ";
          cin >> num1;
        }
    }

    cout << "Enter the second number: ";
    cin >> num2;

    if (solve(num2) == "False"){
        while (solve(num2) == "False"){
          cout << "INVALID INPUT. Enter the second number again: ";
          cin >> num2;
        }
    }

    cout << "Enter the operator: ";
    cin >> op;

    int num3 = stoi(num1);
    int num4 = stoi(num2);
    result = checkOperator(result, num3, num4, op);

    cout << "The first number is " << num3 << endl;
    cout << "The second number is " << num4 << endl;
    cout << "The result is " << result << "." << endl;

    return 0;
}
