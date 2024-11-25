#include "heapsort.h"
#include "../resourse/print.h"

int main(){
    
    CLRS::heap<char> h={'s','d','f','g','h','j','k','l'};

    CLRS::print(h);
    CLRS::build_max_heap(h);
    std::cout<<"after build_max_heap:\n";
    CLRS::print(h);
    CLRS::heapsort(h);
    std::cout<<"after heapsort:\n";
    CLRS::print(h);

    return 0;
}