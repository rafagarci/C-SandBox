// Prints all prime numbers up to 1000
#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    for (int i = 2; i < 1000; i++)
    {
        bool prime = true;
        for (int j = 2; j <= int(floor(sqrt(i * 1.0))); j++)
        {
            if (i % j == 0)
            {
                prime = false;
                break;
            }
        }
        if (prime)
        {
            cout << i << endl;
        }
    }
}
