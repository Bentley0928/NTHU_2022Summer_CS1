#include <bits/stdc++.h>

using namespace std ;


int max= INT_MAX;
void generation(int N, bool is_used[], int log[], int index){
    if( index >= N ){
        for(int i=0 ; i<N ; i++){
            if(i)
                cout << " " ;
            cout << log[i] ;
        }
        cout << endl ;
        return ;
    }

    for(int i=1 ; i<=N ; i++ ){
        if( is_used[i] )
            continue ;

        log[index] = i ;

        is_used[i] = true ;
        generation(N, is_used, log, index+1) ;
        is_used[i] = false ;
    }
}


int main(void){
    int N ;
    cin >> N ;

    int log[32] ;
    bool is_used[32] ;

    for( int i=1 ; i<=N ; i++ )
        is_used[i] = false ;
    generation(N, is_used, log, 0) ;
    return 0 ;
}
