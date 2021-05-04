// Problem: Represent a given a number as sum of minimum possible psuedobinary numbers

// Algorithm: We find a new number m such that if for a place in given number n, 
// the digit is non-zero then the digit in that place in m is 1 otherwise zero.
// Then we will print this number m and subtract m from n. 
// We will keep repeating these steps until n is greater than zero.
#include <bits/stdc++.h>
using namespace std;

int n,
    counter = 0;
vector<int> resultArray;

void freopenFile()
{
    freopen("FBIN.inp", "r", stdin);
    freopen("FBIN.out", "w", stdout);
}

void readData()
{
    cin >> n;
}

void writeData()
{
    cout << counter << "\n";
    for (int i = 0; i <= resultArray.size() - 1; i++)
        cout << resultArray[i] << " ";
}

void psuedoBinary(int n)
{
    while (n > 0)
    {
        // m is a number that has same number of digits as n,
        // but has 1 in place of non-zero digits
        // and 0 in place of 0 digits
        int temp = n,
            m = 0,
            p = 1;
        while (temp)
        {
            int rem = temp % 10;
            temp /= 10;

            if (rem != 0)
                m += p;
        
            p *= 10;
        }

        resultArray.push_back(m);

        // Subtract m from n
        n -= m;
        counter++;
    }
}

// Driver code
int main()
{
    freopenFile();
    readData();
    psuedoBinary(n);
    writeData();
    return 0;
}