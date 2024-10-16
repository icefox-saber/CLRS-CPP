#include "heapsort.h"
#include "../resourse/print.h"

int main(){
    heap<char> h={'s','d','f','g','h','j','k','l'};

    print(h);
    build_max_heap(h);
    cout<<"after build_max_heap:\n";
    print(h);
    heapsort(h);
    cout<<"after heapsort:\n";
    print(h);

    return 0;
}