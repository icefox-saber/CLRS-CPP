#include "insertsort.h"
#include "../resourse/print.h"

using namespace std;

int main(){
    vector<int> vec={4,5,3,6,2,7,1,8};

    print(vec);
    insertsort(vec);
    cout<<"after insertsort:\n";
    print(vec);
    insertsort_nonincrease(vec);
    cout<<"after insertsort_nonincrease:\n";
    print(vec);

    return 0;
}