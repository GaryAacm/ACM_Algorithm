#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;
const int maxm = 1e6 + 10;
const int maxn = 3e5 + 10;

inline int read() {
    char c = getchar(); int x = 0, f = 1;
    for (; c > '9' || c < '0'; c = getchar()) if (c == '-') f = -1;
    for (; c >='0' && c <='9'; c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
    return x * f;
}

int ver[maxm], nxt[maxm], head[maxn], tot = 1;
int dfn[maxn], low[maxn], cnt_;
bool cut[maxm];

void add (int u, int v) {
    ver[++ tot] = v, nxt[tot] = head[u], head[u] = tot;
    ver[++ tot] = u, nxt[tot] = head[v], head[v] = tot;
}

void tarjan (int x, int in_edge) {
    dfn[x] = low[x] = ++ cnt_;
    for (register int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (!dfn[y]) {
            tarjan (y, i);
            low[x] = min (low[x], low[y]);
            if (low[y] > dfn[x])
                cut[i] = cut[i ^ 1] = 1;
        }
        else if (i != (in_edge ^ 1))
            low[x] = min (low[x], dfn[y]);
    }
}

int id[maxn], gg;
void dfs (int x) {
    id[x] = gg;
    for (register int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if (id[y] || cut[i]) continue;
        dfs (y);
    }
}

vector <int> h[maxn];
bool vis[maxn];
int s_, id_;

void dfs_ (int x, int s) {
    vis[x] = 1;
    if (s > s_)
        s_ = s, id_ = x;
    for (register int i = 0; i < h[x].size (); i ++)
        if (!vis[h[x][i]])
            dfs_ (h[x][i], s + 1);
}

void djj_lxy () {
    int n = read(), m = read();
    for (; m; m --)
        add (read (), read ());
    for (register int i = 1; i <= n; i ++)
        if (!dfn[i]) tarjan (i, 0);
    for (register int i = 1; i <= n; i ++)
        if (!id[i]) ++ gg, dfs (i);
    for (register int i = 1; i <= n; i ++)
        for (register int j = head[i]; j; j = nxt[j])
            if (id[i] != id[ver[j]])
                h[id[i]].push_back (id[ver[j]]);
    dfs_ (1, 1);
    memset (vis, 0, sizeof vis);
    dfs_ (id_, 1);
    printf ("%d\n", s_ - 1);
}

int main () {
    djj_lxy ();
}
