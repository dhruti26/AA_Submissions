#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> theta_table = {
    // for (a,b) go to state (first element for a,second element for b )
    {1, 0}, // current state  0 - then for a go to state 1,for b go to state 0
    {1, 2}, // current state  1
    {1, 3}, // current state  2
    {1, 0}  // current state  3
};

void FiniteAutomata(string text, string pattern)
{
    int q = 0;
    int n = text.length();
    int m = pattern.length();
    // zero based indexing
    for (int i = 0; i < n; i++)
    {
        if (text[i] == 'a')
            q = theta_table[q].first; // q=>theta_table(q,ch)
        else if (text[i] == 'b')
            q = theta_table[q].second;
        if (q == m)
            cout << "Pattern matched at index :"
                 << " " << i - m + 1 << endl;
    }
}
int main()
{
    string text, pattern;

    cout << "Enter a Text : " << endl;
    cin >> text;

    cout << "Enter Pattern : " << endl;
    cin >> pattern;

    FiniteAutomata(text, pattern);
    return 0;
}
