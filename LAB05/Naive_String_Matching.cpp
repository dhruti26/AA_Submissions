#include <bits/stdc++.h>
#include <string>
using namespace std;
int main()
{
    string target;
    string pattern;
    cout << "Enter your target string : ";
    cin >> target;
    cout << "Enter your pattern string : ";
    cin >> pattern;
    int tlen = target.size();
    int plen = pattern.size();
    int i;
    int j;
    for (int shift = 0; shift <= tlen - plen; shift++)
    {
        i = 0;
        j = 0;
        while (j < plen && target[shift + i] == pattern[j])
        {
            i++;
            j++;
        }

        if (j == plen)
        {
            cout << "Pattern occurs with shift : " << shift << endl;
        }
    }
    return 0;
}
