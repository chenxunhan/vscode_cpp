#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5+10;
int V[maxn];
map<int, ll>S;

ll Sum(ll n)
{
    int m = (int)sqrt(n);
    int t = n / m;
    for(int i = 1;i <= m;i++)  V[i-1] = n / i;

    int cnt = 1;
    for(int i = t + m - 2;i >= m;i--)  V[i] = cnt++;


    for(int i = 0;i <= t+m-2;i++)  S[V[i]] = 1LL * V[i] * (V[i]+1) / 2 - 1;

    for(int p = 2;p <= m;p++)
    {
        if(S[p] > S[p-1])
        {
            ll sp = S[p-1];
            ll p2 = p *  p;
            for(int i = 0;i <= t+m-2;i++)
            {
                ll v = V[i];
                if(v < p2)  break;
                S[v] -= p*(S[v/p] - sp);
            }
        }
    }

    return S[n];
}

int main()
{
    printf("%lld\n", Sum(1000000000));
}
