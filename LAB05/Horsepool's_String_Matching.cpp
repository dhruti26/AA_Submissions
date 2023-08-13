#include <bits/stdc++.h>
using namespace std;
int findfun()
{
    string t = "JIM_SAW_ME_IN_A_BARBER_SHOP";
    string p = "BARBER";
    int n = t.size();
    int m = p.size();
    map<char, int> shift;
    for (char i = 'A'; i <= 'Z'; i++)
    {
        shift[i] = m;
    }

    shift['_'] = m; // shift value of _ is also m
    for (int i = 0; i <= m - 2; i++)
    {
        shift[p[i]] = m - i - 1;
    }
    for (auto ele : shift)
    {
        if (ele.second != m)
            cout << "Shift value of element " << ele.first << " is : " << ele.second << endl;
    }
    int j = 0;
    int i;
    while (j + m <= n)
    {
        if (p[m - 1] == t[j + m - 1])
        {
            i = m - 2;
            while (i >= 0 && p[i] == t[j + i])
            {
                i--;
            }
            if (i == -1)
            {
                // reach end of pattern match
                return j;
            }
        }
        j = j + shift[t[j + m - 1]];
    }
    return n;
}
int main()
{
    int x = findfun();
    cout << "Position of first occurence of Pattern in Text: " << x << endl;
}
