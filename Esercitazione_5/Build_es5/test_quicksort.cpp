#include "is_sorted.hpp"
#include "sort.hpp"
#include "randfiller.h" /* numeri random */
#include <vector>
#include <string>

int main()
{
	randfiller rf; /* funzione randomica */
	/* genero 100 dimensioni casuali tra 1 e 100 */
	std::vector<int> sizes(100);
	rf.fill(sizes,1,100); /* applico la funzione random */
	/* test su 100 vettori di dimensione random */
	for (int size:sizes) {
		std::vector<int> A(size);
		rf.fill(A,-1000,1000);
		/* non ho bisogno di controllare se A non è vuoto perchè ho p<r nel sort che è già il caso vettore vuoto/1 elemento */
		quick_sort(A,0,A.size()-1);
		if (!is_sorted(A)) {
			return EXIT_FAILURE;
		}
	}
	/* stringhe */
	std::vector<std::string> s={"macchina","piatto","cellulare","profumo","divano","lampada","tavolo","penna","foglio","specchio"};
	quick_sort(s,0,s.size()-1);
	if (!is_sorted(s)) {
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}