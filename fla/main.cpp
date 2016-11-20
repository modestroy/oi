#include <iostream>

using namespace std;

struct trap{
    int min,max,pos;
};

int main() {
	ios_base::sync_with_stdio(0);
    int x=0, y=0, clicks=0;
    int i_Traps, i_Length;
    bool err=0;
    cin >> i_Traps >> i_Length;
    trap * pulapki = new trap[i_Traps];
    for(int i=0; i<i_Traps; i++){
        cin >> pulapki[i].pos >> pulapki[i].min >> pulapki[i].max;
    }
    for(int i=0; i<i_Traps; i++){
        int pos=pulapki[i].pos-x;
        int min=pulapki[i].min-y;
        if(i==0){
            pos++;
            x--;
            y++;
        }
        int max=pulapki[i].max-y;
        int pom=y-pos;
        while(pom<=pulapki[i].min){
            pom+=2;
            clicks++;
        }
        x+=pos;
        y=pom;
        if(pom>=pulapki[i].max){
            err=1;
            break;
        }
    }
    if(err)cout<<"NIE";
    else cout << clicks;
    delete [] pulapki;
    return 0;
}