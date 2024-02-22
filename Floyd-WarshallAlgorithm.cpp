#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int i, k, j, a[n][n];
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                cin >> a[i][j];

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                for (k = 0; k < n; k++)
                {

                    // cout<<a[i][j]<< "  "<<a[i][k]<<"  "<<a[j][k]<<" " <<t<<endl;

                    if (a[i][k] + a[k][j] < a[i][j])
                        a[i][j] = a[i][k] + a[k][j];
                    // cout<<a[i][j]<< "  "<<a[i][k]<<"  "<<a[j][k]<<" " <<t<<endl;
                    // cout<<endl;
                }
            }
        }
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
                cout << a[i][j] << " ";

            cout << endl;
        }
    }
}
