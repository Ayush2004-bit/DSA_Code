#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string addLargeNumbers(string num1, string num2) {
    // Make sure num1 is the longer one
    if (num2.size() > num1.size())
        swap(num1, num2);

    // Reverse both strings
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    string result = "";
    int carry = 0;

    // Add digits one by one
    for (int i = 0; i < num1.size(); i++) {
        int n1 = num1[i] - '0';
        int n2 = (i < num2.size()) ? num2[i] - '0' : 0;
        int sum = n1 + n2 + carry;

        result.push_back((sum % 10) + '0');
        carry = sum / 10;
    }

    // If there’s any carry left
    if (carry)
        result.push_back(carry + '0');

    // Reverse the result to get the final answer
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string num1, num2;
    cout << "Enter first large number: ";
    cin >> num1;
    cout << "Enter second large number: ";
    cin >> num2;

    cout << "Sum: " << addLargeNumbers(num1, num2) << endl;
    return 0;
}
