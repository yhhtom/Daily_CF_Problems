#include <bits/stdc++.h>
#define int long long
#define mp make_pair
#define pb push_back
#define PII pair<int, int>
#define PDD pair<double, double>
#define all(x) x.begin(), x.end()
using namespace std;
void solve()
{
    int n;
    cin >> n;
    int x, y;
    cin >> x >> y;
    x--,y--;
    int k = 1 << n;
    vector<string> b(k, string(k, '.'));
    b[x][y] = '#';
    cout << "YES\n";
    auto f = [&](auto &self, int lx, int rx, int ly, int ry, int x, int y) -> void
    {
        if (lx + 2 == rx)
        {
            char c = 'B' + (lx / 2 + ly / 2) % 2;
            for (int i = lx; i < rx; i++)
            {
                for (int j = ly; j < ry; j++)
                {
                    if (b[i][j] == '.')
                        b[i][j] = c;
                }
            }
            return;
        }
        int mx = (lx + rx) / 2, my = (ly + ry) / 2;
        if (x < mx)
        {
            if (y < my)
            {
                b[mx][my] = 'A';
                b[mx - 1][my] = 'A';
                b[mx][my - 1] = 'A';
                self(self, lx, mx, ly, my, x, y);
                self(self, lx, mx, my, ry, mx - 1, my);
                self(self, mx, rx, ly, my, mx, my - 1);
                self(self, mx, rx, my, ry, mx, my);
            }
            else
            {
                b[mx][my] = 'A';
                b[mx - 1][my - 1] = 'A';
                b[mx][my - 1] = 'A';
                self(self, lx, mx, ly, my, mx - 1, my-1);
                self(self, lx, mx, my, ry, x, y);
                self(self, mx, rx, ly, my, mx, my - 1);
                self(self, mx, rx, my, ry, mx, my);
            }
        }
        else
        {
            if (y < my)
            {
                b[mx][my] = 'A';
                b[mx - 1][my - 1] = 'A';
                b[mx - 1][my] = 'A';
                self(self, lx, mx, ly, my, mx - 1, my-1);
                self(self, lx, mx, my, ry, mx - 1, my);
                self(self, mx, rx, ly, my, x, y);
                self(self, mx, rx, my, ry, mx, my);
            }
            else
            {
                b[mx - 1][my] = 'A';
                b[mx - 1][my - 1] = 'A';
                b[mx][my - 1] = 'A';
                self(self, lx, mx, ly, my, mx - 1, my-1);
                self(self, lx, mx, my, ry, mx - 1, my);
                self(self, mx, rx, ly, my, mx, my - 1);
                self(self, mx, rx, my, ry, x, y);
            }
        }
    };
    f(f, 0, k, 0, k, x, y);
    for (string &s : b)
    {
        cout << s << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}