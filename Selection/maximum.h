#ifndef maximum_h
#define maximum_h

#include <vector>

template <class T>
T max(const std::vector<T> & vec)
{
    T m = vec[0];
    std::size_t size = (int) vec.size();
    for (std::size_t i = 1; i < size - 1; i++)
    {
        if (m<vec[i])
        {
            m = vec[i];
        }
        
    }
    
    return  m;
}

#endif
