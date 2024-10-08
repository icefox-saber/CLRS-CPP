#include "mergesort.h"
#include "../resourse/print.h"

int main(){
    std::vector<int> vec={4,5,3,6,2,7,1,8};

    print(vec);
    MergeSort(vec,0,vec.size()-1);
    cout<<"after mergesort:\n";
    print(vec);
}