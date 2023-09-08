#include <bits/stdc++.h>
using namespace std;
int table[5];
void generate_table(string P)
{
    // here taken 0 based indexing-Pi[1] =>Pi[0]
    // shift starts from -1 (in 0 based indexing)instead of 0( 1 based indexing)
    table[0] = 1;
    int k = -1;
    int m = P.length();
    for (int q = 1; q < m; q++)
    {
        while (k > -1 && P[k + 1] != P[q])
        {
            k = table[k];
        }
        if (P[k + 1] == P[q])
        {
            k++;
        }
        table[q] = k;
    }
}
int main()
{
    cout << "KMP String Matching Algorithm" << endl;
    string T, P;
    cout << "Enter text :" << endl;
    cin >> T;
    cout << "Enter pattern :" << endl;
    cin >> P;
    int n = T.length();
    int m = P.length();
    generate_table(P);
    int q = -1;
    for (int i = 0; i < n; i++)
    {
        while (q > -1 && P[q + 1] != T[i])
        {
            q = table[q];
        }
        if (P[q + 1] == T[i])
        {
            q++;
        }
        if (q == m - 1)
        {
            cout << "Pattern occurs with shift : " << i - m << endl;
            q = table[q];
        }
    }
    return 0;
}
