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
	// visto a lezione con il professor Vicini
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

// TODO --> implementare mio heapsort
template<Sortable T>

void My_MakeHeap(std::vector<T>& v, unsigned int n, unsigned int i){
	
	unsigned int max_nodo = i;
	
	while (true){
		unsigned int sx = 2*i+1;
		unsigned int dx = 2*i+2;

        if (sx < n && v[sx] > v[max_nodo])
            max_nodo = sx;

        if (dx < n && v[dx] > v[max_nodo])
            max_nodo = dx;

        if (max_nodo != i){
            T tmp = v[i];
			v[i] = v[max_nodo];
			v[max_nodo] = tmp;
			
            i = max_nodo;
        }
        else{
            break;
        }
    }
}

template<Sortable T>

void My_HeapSort(std::vector<T>& v){
	unsigned int n = v.size();
	
	for (int i=n/2 -1; i>=0;i--){
		My_MakeHeap(v, n, i);
	}
	
	for (int i=n-1;i>0;i--){
		T tmp = v[i];
		v[i] = v[0];
		v[0] = tmp;
		
		My_MakeHeap(v, i, 0);
	}
	
}


template<Sortable T>
void HeapSort(std::vector<T>& v)
{
    
	make_heap(v.begin(), v.end());
    sort_heap(v.begin(), v.end());
	
}




}


