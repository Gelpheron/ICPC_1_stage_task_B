// ICPC B.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int t, n, ans = 0;
    cin >> t;
    vector<int> p;
    for (int i = 0; i < t; i++)
    {
        ans = 0;
        cin >> n;
        p.resize(n);
        for (int j = 0; j < n; j++)
        {
            cin >> p[j];
        }
        for (int j = 0; j < n; j++)
        {
            vector <int> pre(j+1);
            vector <int> su(n-j);
            //pre
            pre[j] = 0;
            for (int k = j-1; k >-1; k--)
            {
                if (p[k] < p[j])
                {
                    pre[k] = pre[k+1] + 1;
                }
                else
                {
                    pre[k] = pre[k + 1];
                }
            }
            //su
            su[0] = 0;
            for (int k = j+1; k < n; k++)
            {
                if (p[k] < p[j])
                {
                    su[k-j] = su[k - 1 -j] + 1;
                }
                else
                {
                    su[k-j] = su[k - 1 -j];
                }
            }
            //&&&&&&&&&&&&
            for (int i = 0; i <= j; i++)
            {
                for (int w = 0; w < n - j; w++)
                {
                    if (su[w] == (j - i) - pre[i])
                    {
                        ans++;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
