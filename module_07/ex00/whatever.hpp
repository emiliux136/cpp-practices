#pragma once //Prevent multiple inclusion of a header

template <typename E> //defines a parameter called E

//The function wants to modify the originals, so it must receive references. If not it would act with copies.
void swap(E &a, E &b)
{
    E temp = b;
    b = a;
    a = temp;
}

template <typename M> 

M &min(M &a, M &b)
{
    if(a < b)
        return a;
    return b;
}

template <typename I> 

I &max(I &a, I &b)
{
    if(a > b)
        return a;
    return b;
}
