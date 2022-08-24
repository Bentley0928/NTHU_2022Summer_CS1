#include <bits/stdc++.h>

using namespace std ;


struct people{
    string name;
    int year,mon,day,group;
} ;



int N ;


bool comp(people a, people b){
    if( a.group != b.group )
        return a.group < b.group ;

    else if( a.year != b.year )
        return a.year > b.year ;

    else if(a.mon!=b.mon)
        return a.mon > b.mon;
    else if(a.day != b.day)
        return a.day > b.day;
    else return a.name < b.name;

}


int main(){
    cin >> N ;
    string ss;
    people peo[100000];
    for(int i=0 ; i<N ; i++){
        cin >> peo[i].name >> ss ;
        peo[i].year=0;
        peo[i].mon=0;
        peo[i].day=0;
        int cnt=3;
        int sum=0;
        for(int j=0;j<10;j++){
            sum+=int(ss[j]);
        }
        peo[i].group=sum%10;
        for(int j=0;j<=3;j++){
            peo[i].year+=int(ss[j]-'0')*pow(10,cnt);
            cnt--;
        }
        cnt=2;
        peo[i].mon+=10*int(ss[5]-'0')+int(ss[6]-'0');
        peo[i].day+=10*int(ss[8]-'0')+int(ss[9]-'0');
    }
    sort(peo, peo+N, comp) ;
    
    for( int i=0 ; i<N ; i++ ){
        cout << peo[i].group << " ";
        if(peo[i].mon<10) cout << "0" << peo[i].mon << "/";
        else cout << peo[i].mon << "/";
        if(peo[i].day<10) cout << "0" << peo[i].day << "/";
        else cout << peo[i].day << "/";
        if((peo[i].year%100)<10) cout << "0" << peo[i].year%100 << " ";
        else cout << peo[i].year%100 << " ";
        cout << peo[i].name << endl;
    }
    return 0 ;
}
//<< peo[i].day << "/" << peo[i].mon  << "/" << peo[i].year%100 << " " << peo[i].name << endl ;