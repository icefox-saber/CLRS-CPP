#include "./selectionsort.h"
#include "../resourse/print.h"

using namespace std;

int main(){
    vector<int> vec={4,5,3,6,2,7,1,8};

    print(vec);
    selectionsort(vec);
    cout<<"after selectionsort:\n";
    print(vec);

}