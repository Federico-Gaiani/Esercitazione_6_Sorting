#pragma once
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

namespace SortLibrary {
template<typename T>
concept Sortable = requires(T& t) {
    {t < t} -> std::convertible_to<bool>;
};

template<Sortable T>
void BubbleSort(std::vector<T>& v)
{
	
    const unsigned int n = v.size();

	if (n == 0) return; // Gestione esplicita del caso vuoto

    for(unsigned int i = 0; i < n - 1; i++)
    {
        for(unsigned int j = i + 1; j < n; j++)
        {
            if(v[j] < v[i]){
				// swap:
				T tmp = v[i];
				v[i] = v[j];
				v[j] = tmp;
			}      
        } 
    }
}
/*
// TODO --> implementare mio heapsort
template<Sortable T>
void HeapSortPersonal(std::vector<T>& v){
	
	
}
*/

template<Sortable T>
void HeapSort(std::vector<T>& v)
{
    
	make_heap(v.begin(), v.end());
    sort_heap(v.begin(), v.end());
	
}




}


