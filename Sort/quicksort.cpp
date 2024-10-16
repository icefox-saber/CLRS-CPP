#include "quicksort.h"
#include "../resourse/print.h"

using namespace std;

int main(){
    vector<char> vec={'s','d','f','g','h','j','k','l'};

    print(vec);
    quickSort(vec);
    cout<<"after quicksort:\n";
    print(vec);

    return 0;
}