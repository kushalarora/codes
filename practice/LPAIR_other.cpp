//Program: lpair
//Author: gary
//Date: 16/02/2014
#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ( (int) (x).size() )
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef pair<int, int> i2;
typedef long long ll;
const int INF = 1e9;
const int MAX_N = 1e5 +10;
int N;
i2 P[MAX_N];
int F[MAX_N];
int T[MAX_N];
ll mergesort(int l, int r){
  if(l >= r)
    return 0;
  int mid = (l + r) / 2;
  ll res = 0;
  res += mergesort(l, mid);
  res += mergesort(mid + 1, r);
  int s = 0;
  int i = l, j = mid + 1;
  while(i <= mid || j <= r){
    if(i <= mid && j <= r){
      if(F[i] < F[j]){
	T[s++] = F[i++];
      } else {
	res += (mid - i + 1);
	T[s++] = F[j++];
      }
    } else if(i <= mid) {
      T[s++] = F[i++];
    } else {
      T[s++] = F[j++];
    }
  }
  for(int k = l; k <= r; k++) {
    F[k] = T[k - l];
    //    cout << F[k] << ' ';
  }
  //  cout << endl;
  return res;
}

int main(){
  ios::sync_with_stdio(0);
  while(cin >> N){
    for(int i = 0; i < N; i++)
      cin >> P[i].fi >> P[i].se;
    sort(P, P + N);
    for(int i = 0; i < N; i++)
      F[i] = P[i].se;
    cout << mergesort(0, N - 1) << endl;
  }
  return 0;
}

