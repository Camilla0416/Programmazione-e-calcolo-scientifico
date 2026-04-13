#include "sort.hpp"
#include "timecounter.h" /* calcolo tempo */
#include "randfiller.h" /* numeri random */
#include <vector>
#include <algorithm> /* serve per sort */
#include <iostream>

int main()
{
	randfiller rf; /* funzione randomica */
	timecounter tc; /* funzione tempo */
	std::vector<int> sizes={4,8,16,32,64,128,256,512,1024,2048,4096,8192}; /* dimensioni fisse */
	for (int n:sizes) {
		std::vector<int> v(n);
		rf.fill(v,-1000,1000); /*numeri random */
		/* copie per ogni algoritmo */
		auto v1=v;
		auto v2=v;
		auto v3=v;
		auto v4=v;
		
		std::cout << "n = " << n << "\n";
		
		/* bubble_sort */
		tc.tic(); /* inizio */
		bubble_sort(v1);
		std::cout << "Bubble: " << tc.toc() << "\n"; /*finisco */
		
		/* insertion_sort */
		tc.tic(); /* inizio */
		insertion_sort(v2);
		std::cout << "Insertion: " << tc.toc() << "\n"; /*finisco */
		
		/* selection_sort */
		tc.tic(); /* inizio */
		selection_sort(v3);
		std::cout << "Selection: " << tc.toc() << "\n"; /*finisco */
		
		/* std::sort */
		tc.tic(); /* inizio */
		std::sort(v4.begin(),v4.end());
		std::cout << "std::sort: " << tc.toc() << "\n"; /*finisco */
		
		std::cout << "\n";
	}
	return 0;
}