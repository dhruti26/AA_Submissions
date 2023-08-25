#include <bits/stdc++.h>
using namespace std;

int knapsack(int profit[], int wt[], int ind, int c, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (profit[0] <= c)
        {
            return profit[0];
        }
        else
            return 0;
    }
    if (dp[ind][c] != -1)
        return dp[ind][c];

    int notTake = 0 + knapsack(profit, wt, ind - 1, c, dp);
    int take = 0;
    if (wt[ind] <= c)
    {
        take = profit[ind] + knapsack(profit, wt, ind, c - wt[ind], dp);
    }
    return dp[ind][c] = max(take, notTake);
}

int main()
{
    cout << "Subset Sum Reduction to 0/1 Knapsack" << endl;
    int S[] = {4, 3, 6, 8, 5, 9};
    int sum = 23;
    // eg-2
    //  int S[]={3,2,7,1};
    //  int sum=6;
    int n = 6;
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

    // max profit>=sum
    if (sum <= knapsack(S, S, n - 1, sum, dp))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}
