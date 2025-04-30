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

//My_MakeHeap rende il sottoalbero radicato nel nodo i un heap valido, 
// assumendo che i suoi figli siano già heap. Per questo la chiamata a 
// My_MakeHeap nel primo for della funzione di sorting parte dai nodi immediatamente
// sopra le foglie (n/2 -1) per poi ordinare l'albero "salendo".
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
	//creo l'albero
	for (int i=n/2 -1; i>=0;i--){
		My_MakeHeap(v, n, i);
	}
	
	//man mano estraggo i nodi con valore maggiore e ristabilisco la struttura di albero 
	// sul pezzo di vettore rimasto.
	for (int i=n-1;i>0;i--){
		T tmp = v[i];
		v[i] = v[0];
		v[0] = tmp;
		
		My_MakeHeap(v, i, 0);
	}
	
}


// includendo <algorithm> 
template<Sortable T>
void HeapSort(std::vector<T>& v)
{
    
	make_heap(v.begin(), v.end()); // https://en.cppreference.com/w/cpp/algorithm/make_heap
    sort_heap(v.begin(), v.end()); // https://en.cppreference.com/w/cpp/algorithm/sort_heap
	
}




}


