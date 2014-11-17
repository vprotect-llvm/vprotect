#include <iostream>

using namespace std;

int main(){
    int a = 0;
    while(a < 5){
        cout << a++ << endl;
    }

    for(; a > 0; --a){
        cout << a << endl;
    }

    return 0;
}
