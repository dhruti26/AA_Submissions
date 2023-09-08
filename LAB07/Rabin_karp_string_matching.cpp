#include <bits/stdc++.h>
using namespace std;
int power(int a, int x, int y)
{
    // calculating a^x % q
    int res = 1;
    for (int i = 1; i <= x; i++)
    {
        res = (res * a) % y;
    }
    return res;
}

void rabin_karp_matcher(string T, string P, int d, int q)
{
    int n = T.length();
    int m = P.length();

    int p = 0, t0 = 0;

    // choose pattern and text window of length m
    for (int i = 0; i < m; i++)
    {
        //  do P[i] - '0', bcoz pattern is string of numbers
        p = (d * p + (P[i] - '0')) % q;

        // cout << p << " ";
        t0 = (d * t0 + (T[i] - '0')) % q;
        // cout << t0 << " ";
    }
    // h=d^m-1 % q
    int h = power(d, m - 1, q);
    int j;

    for (int s = 0; s <= (n - m); s++)
    {
        // cout << p << " " << t0 << endl;
        if (p == t0)
        {
            // t0 = text window keeps on changing
            for (j = 0; j < m; j++)
            {
                if (T[s + j] != P[j])
                {
                    break;
                }
            }
            // cout << "j is : " << j << " " << m << endl;
            if (j == m)
                cout << "Pattern found with shift : " << s << endl;
        }

        if (s < n - m)
        {
            t0 = (d * (t0 - (T[s] - '0') * h) + (T[s + m] - '0')) % q;
        }
        while (t0 < 0)
            t0 = t0 + q;
    }
}
int main()
{
    string T = "2359023141567399";
    string P = "31415";
    // can take any long prime number
    int q = 13;

    int d = 10;
    cout << "Rabin Karp's Algorithm" << endl;
    rabin_karp_matcher(T, P, d, q);
    return 0;
}
