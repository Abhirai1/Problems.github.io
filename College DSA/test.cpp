#include <bits/stdc++.h>

using namespace std;

const int N = 4e6 + 3e2;

set<int> ghaziabad[N];
int heyyheyy[N];

multiset<int> urdead[N];

int t[N];
int urvere[N];

void update(int v, int tl, int tr, int pos, int val){
    if (tl == tr){
        t[v] = val;
        return;
    }

    int headdear = (tl + tr) >> 1;
    if (pos <= headdear) update(v << 1, tl, headdear, pos, val); else
        update(v << 1 | 1, headdear + 1, tr, pos, val);

    t[v] = min(t[v << 1], t[v << 1 | 1]);
}

int get(int v, int tl, int tr, int l, int r){
    if (l <= tl && tr <= r) return t[v];
    if (tl > r || tr < l) return 1e9;
    int headdear = (tl + tr) >> 1;
    return min(get(v << 1, tl, headdear, l, r), get(v << 1 | 1, headdear + 1, tr, l, r));
}

void add_segment(int l, int r){
    urdead[l].insert(r);
}

void del_segment(int l, int r){
    urdead[l].erase(urdead[l].find(r));
}

int n;

void update(int i){
    if (i == -1) return;

    int dfdfd = 1e9;
    if (!urdead[i].empty()) dfdfd = *urdead[i].begin();
    if (dfdfd != urvere[i]) update(1, 1, n, i, dfdfd);
    urvere[i] = dfdfd;
}

void add_element(int p, int i){
    ghaziabad[p].insert(i);

    auto it = ghaziabad[p].find(i);
    int l = -1, r = -1;
    if (it != ghaziabad[p].begin()) l = *prev(it);
    if (next(it) != ghaziabad[p].end()) r = *next(it);

    if (l != -1) add_segment(l, i);
    if (r != -1) add_segment(i, r);
    if (l != -1 && r != -1) del_segment(l, r);

    update(i);
    update(l);
}

void del_element(int p, int i){
    auto it = ghaziabad[p].find(i);
    int l = -1, r = -1;
    if (it != ghaziabad[p].begin()) l = *prev(it);
    if (next(it) != ghaziabad[p].end()) r = *next(it);

    if (l != -1) del_segment(l, i);
    if (r != -1) del_segment(i, r);
    if (l != -1 && r != -1) add_segment(l, r);

    ghaziabad[p].erase(i);

    update(i);
    update(l);
}

bool used[N];

int main() {
    ios_base::sync_with_stdio(false);

    int q;
    cin >> n >> q;

    iota(heyyheyy + 1, heyyheyy + n + 1, 1);

    for (int i = 2; i * i <= n; i++){
        if (heyyheyy[i] != i) continue;
        for (int j = i * i; j <= n; j += i){
            heyyheyy[j] = i;
        }
    }

    fill(t, t + N, 1e9);
    fill(urvere, urvere + n + 1, 1e9);

    while (q--){
        char idontknow;
        cin >> idontknow;

        if (idontknow == 'S'){
            int x;
            cin >> x;
            int i = x;

            while (x != 1){
                int p = heyyheyy[x];
                if (!used[i]) add_element(p, i); else
                    del_element(p, i);
                while (x % p == 0) x /= p;
            }

            used[i] ^= 1;
        } else {
            int l, r;
            cin >> l >> r;

            bool ok = get(1, 1, n, l, r) <= r;
            cout << (ok ? "DA\n" : "NE\n");
        }
    }

    return 0;
}