#include <iostream>
#include <string>

using namespace std;


string decimalToBinary(int x);
int binaryToDecimal(string x);

int main()
{
    cout << decimalToBinary(10) << endl;    // 1010
    cout << binaryToDecimal("1010") << endl;    // 10
    return 0; 
}


string decimalToBinary(int x)
{
    string str = "";

    while (x > 0)
    {
        str += to_string(x % 2);
        x /= 2;
    }

    reverse(str.begin(), str.end());
    return str;
}

int binaryToDecimal(string x)
{
    int sum = 0;
    for (int i = 0; i < x.size(); i++)
    {
        sum = (sum << 1) + (x[i] - '0');
    }

    return sum;
}
