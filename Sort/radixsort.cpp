#include "radixsort.h"
#include "../resourse/print.h"

using namespace std;

int main(){
    vector<int> vec2={10,8,6,1,4,3,7,5,5,20};

    print(vec2);
    radixSort(vec2,2);
    cout<<"after radixsort:\n";
    print(vec2);
    return 0;
}