#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+5;

int n, m;
int p[maxn];
int se = 0;
int ans = 0;

struct edge
{
    int x, y;
    int v;
}   t[maxn];

int findp(int x)
{
    if (p[x] == -1) return x; // kiểm tra có phải cây khung khác nhau hay không nếu tìm thấy gốc trả về -1
    else return findp(p[x]); // nếu không tiếp tục tìm cha của đỉnh đó
}

bool cmp(edge a, edge b)
{
    return a.v < b.v; // sắp xếp theo trọng số.
}

int main()
{
    cin >> n >> m;
    int u, v, w;
    for (int i=1; i<=n; i++) p[i] = -1;
    for (int i=1; i<=m; i++)
        cin >> t[i].x >> t[i].y >> t[i].v;
    sort (t+1, t+m+1, cmp);
    int  i = 1;
    while (se < n-1)
    {
        while (findp(t[i].x) == findp(t[i].y)) // bằng nhau tức là cha chung của 2 đỉnh.
            i++; // xét thứ tự lần lượt của các cạnh theo chiều tăng dần của trọng số
        ans += t[i].v; // cộng các trọng số của cạnh đang xét.
        p[findp(t[i].x)] = findp(t[i].y); // nối 2 cây khung khác nhau tạo thành một cây khung mới không tạo chu trình
        se++; // đếm số cạnh vừa kết nối của cây khung.
    }
    cout << ans;
}
