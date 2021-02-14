#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

int n = 0, arr[21][21] = {0,}, ans = INT_MAX;
bool ch[21] = {false,};

void dfs(int st){
    if(st>=n){
        int st = 0, lin = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(ch[i]&&ch[j]) st+=arr[i][j];
                else if(!ch[i]&&!ch[j]) lin+=arr[i][j];
            }
        }
        if(ans>abs(st-lin)) ans = abs(st-lin);
    }
    for(int i=st; i<=n; i++){
        if(!ch[i]){
            ch[i] = true;
            dfs(i);
            ch[i] = false;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> arr[i][j];
        }
    }
    dfs(1);
    cout << ans << "\n";
    return 0;
}
