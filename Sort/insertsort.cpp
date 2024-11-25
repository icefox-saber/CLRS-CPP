#include "insertsort.h"
#include "../resourse/print.h"


int main(){
    std::vector<int> vec={4,5,3,6,2,7,1,8};

    CLRS::print(vec);
    CLRS::insertsort(vec);
    std::cout<<"after insertsort:\n";
    CLRS::print(vec);
    CLRS::insertsort_nonincrease(vec);
    std::cout<<"after insertsort_nonincrease:\n";
    CLRS::print(vec);

    return 0;
}