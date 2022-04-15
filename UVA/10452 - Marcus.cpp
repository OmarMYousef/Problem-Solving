/*

    UVA 10452 - Marcus
    https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1393

    Author: Omar M. Youssef
    Approach: ad-hoc

*/

#include <bits/stdc++.h>

using namespace std;
#define FIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main(){

    string allowed = "IEHOVA";

    int c; cin >> c;
    for( int i = 0; i < c; i++ ){
        string inst = "";
        int h, w;
        cin >> h >> w;
        string grid[h];

        pair<int,int> start;
        pair<int,int> end;
        pair<int,int> current;

        int checkings[3][2] = {{0,-1},{-1,0},{0,1}};
        string directions[3] = {"left","forth","right"};

        for( int hi = 0; hi < h; hi++ ){
            cin >> grid[hi];
            for( int wi = 0; wi < w; wi++ ){
                int aindex = -1;
                for( int ai = 0; ai < allowed.length(); ai++ ){
                    if( allowed[ai] == grid[hi][wi] ){
                        aindex = ai;
                        break;
                    };
                }
                if( aindex != -1 ){
                    grid[hi][wi] = 'x';
                }else{
                    if( grid[hi][wi] == '@'){
                        start.first = hi; start.second = wi;
                        current.first = hi; current.second = wi;
                    }else
                    if( grid[hi][wi] == '#'){
                        end.first = hi; end.second = wi;
                    }else{
                        grid[hi][wi] = 'o';
                    }
                }
            }
        }       

        while( true ){
            for( int ins = 0; ins < 3; ins++ ){
                int next[2] = {current.first + checkings[ins][0],current.second  + checkings[ins][1]};
                if( next[0] >= 0 && next[1] >= 0 && next[0] < h && next[1] < w && grid[next[0]][next[1]] != 'o' ){
                    grid[current.first][current.second] = 'o';
                    current.first = next[0];
                    current.second = next[1];
                    grid[current.first][current.second] = '@';
                    inst += directions[ins];
                    inst += ' ';
                    break;
                }
            }
            if( current == end ){ break; };
        };
        cout << inst << endl;
    }
    return 0;
}
