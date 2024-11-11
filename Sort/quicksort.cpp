#include "quicksort.h"
#include "../resourse/print.h"

using namespace std;

int main(){
    vector<char> vec={'s','d','f','g','h','j','k','l'};
    vector<int> vec2={10,8,6,1,4,3,7,5,5};
    print(vec);
    quickSort(vec);
    cout<<"after quicksort:\n";
    print(vec);

    print(vec2);
    random_quickSort(vec2);
    cout<<"after random_quicksort:\n";
    print(vec2);
    return 0;
}