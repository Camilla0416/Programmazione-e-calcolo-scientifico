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
		std::vector<int> v(size);
		rf.fill(v,-1000,1000);
		selection_sort(v);
		if (!is_sorted(v)) {
			return EXIT_FAILURE;
		}
	}
	/* stringhe */
	std::vector<std::string> s={"macchina","piatto","cellulare","profumo","divano","lampada","tavolo","penna","foglio","specchio"};
	selection_sort(s);
	if (!is_sorted(s)) {
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}