#include<bits/stdc++.h>


#define vocuc 1e18
#define ll long long
using namespace std;

typedef pair<ll,int> ii;
// m?ng n�y l� danh s�ch k?
vector<ii> arr[100005];
int n,m;
// m?ng n�y n�y l� gi� tr? g�n l�c d?u l� v�  c?c khi chua x�t d?nh
ll d[100005];

ll duongdi[100005];
void solve(int cnt)
{
    if(cnt!=1)
    solve(duongdi[cnt]);
    cout<< cnt << " ";
}
void dijstra()
{
    // d�ng priority
    // th?ng n�y n� ho?t d?ng nhu stack . m?c d� l� queue nhung n� k c� front m� ch? c� top
    // d�ng greater n� m?c d?nh ph?n t? top lu�n m� min c�n k d�ng th� l� max
    priority_queue<ii , vector<ii > ,greater<ii > > pq;
    ll v,uv;
    // kh?i t?o v� c?c c?a m?ng d
    for(int i=1;i<=n;i++)
    d[i] =vocuc;
    // d?nh b?t d?u th� gi� tr? c?a d[0] l� 0
    d[1] = 0;

    pq.push(ii(1,0));
    int dinhke,dinhdangxet,trongso;
    while(pq.size())
    {

        dinhdangxet = pq.top().first;
        trongso = pq.top().second;
        pq.pop();


        if (trongso!=d[dinhdangxet]) continue;

        for (int i=0; dinhke=arr[dinhdangxet][i].first; i++)
        {
            //cout<< u<< " ";
            //cout<< arr[u][i].first << " "<< arr[u][i].second << " " << i<< endl;
            // arr[u][i].first l� tr?ng s? c?a d?nh
            //int dinhke=arr[dinhdangxet][i].first;
            //int temp2=arr[dinhdangxet][i].second;
            int trongsodangxet = arr[dinhdangxet][i].second;
            if (d[dinhke]>trongso+trongsodangxet) {
                d[dinhke]=trongso+trongsodangxet;
                pq.push(ii(dinhke,d[dinhke]));
            //cout<< dinhke<< " "<< dinhdangxet<< endl;
                duongdi[dinhke]=dinhdangxet;

            }

        }



    }

}

int main()
{

    int p, q,  w;
    scanf("%d%d", &n, &m);
    while (m--){
        scanf("%d%d%d", &p, &q, &w);
        arr[p].push_back(ii(q, w));
        arr[q].push_back(ii(p, w));
    }
    for (int i=1; i<=n; i++) arr[i].push_back(ii(0,0));

    dijstra();
//    for(int i=1;i<=n;i++)
//    cout<< d[i]<< " ";
    if(d[n]==vocuc)
        cout<< -1;
    else
        {
            solve(n);

        }



}
