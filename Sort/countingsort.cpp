#include "countingsort.h"
#include "../resourse/print.h"

using namespace std;

int main(){
    vector<size_t> vec2={10,8,6,1,4,3,7,5,5};

    print(vec2);
    countingSort(vec2,10);
    cout<<"after countingsort:\n";
    print(vec2);
    return 0;
}