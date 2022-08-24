#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    while(n--){
        priority_queue <int> pq;
        for(int i=0;i<5;i++){
            int tmp;
            cin >> tmp;
            pq.push(tmp);
        }
        int sum=0,count=0;
        int array[5]={42, 26, 16, 10, 6};
        while(!pq.empty()){
            sum+=pq.top()*array[count];
            count++;
            pq.pop();
        }
        cout << sum << endl;
    }
    return 0;
}