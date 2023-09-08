#include <bits/stdc++.h>
#include <cmath>
using namespace std;

struct Point
{
    int x;
    int y;
} P[3];

int main()
{
    cout << "Closest pair of points" << endl;
    P[1].x = 2;
    P[1].y = 2;
    P[2].x = 4;
    P[2].y = 4;
    P[3].x = 5;
    P[3].y = 6;
    int n = 3;
    int dmin = INT_MAX, ans_i = 0, ans_j = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int x1 = P[i].x;
            int y1 = P[i].y;
            int x2 = P[j].x;
            int y2 = P[j].y;

            int X = x1 - x2;
            int Y = y1 - y2;
            int d = pow(X, 2) + pow(Y, 2);

            if (d < dmin)
            {
                dmin = d;
                ans_i = i;
                ans_j = j;
            }
        }
    }
    cout << "Minimum distance between points are : " << dmin << endl;
    cout << "The points are : " << ans_i << " and " << ans_j;
    return 0;
}
