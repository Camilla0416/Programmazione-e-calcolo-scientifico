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
	const int m=100; /* numero test per ogni dimensione */
	for (int n=2; n<=80; n+=1) { /* dimensioni */
		/* preallocazione vettori */
		std::vector<std::vector<int>> data(m,std::vector<int>(n)); /* data è una matrice con m vettori ciascuno di dim n: data=[v1,v2,...,vm] */
		for (auto &v : data) {
			rf.fill(v,-1000,1000); /* ho m vettori indipendenti tutti con valori random diversi */
		}
		std::cout << "n = " << n << "\n";
		
		/* Bubble */
		auto d1=data; /* copio dati originali altrimenti gli altri vettori lavorerebbero su dati già ordinati */
		tc.tic();
		for (auto &v : d1) {
			bubble_sort(v); /* ordino tutti i vettori dentro alla copia */
		}
		double t_bubble=tc.toc()/m; /* faccio la media */
		std::cout << "Bubble: " << t_bubble << "\n";
		
		/* Insertion */
		auto d2=data; /* copio dati originali */
		tc.tic();
		for (auto &v : d2) {
			insertion_sort(v); /* ordino tutti i vettori dentro alla copia */
		}
		double t_insertion=tc.toc()/m; /* faccio la media */
		std::cout << "Insertion: " << t_insertion << "\n";
		
		/* Selection */
		auto d3=data; /* copio dati originali */
		tc.tic();
		for (auto &v : d3) {
			selection_sort(v); /* ordino tutti i vettori dentro alla copia */
		}
		double t_selection=tc.toc()/m; /* faccio la media */
		std::cout << "Selection: " << t_selection << "\n";
		
		/* Merge */
		auto d4=data; /* copio dati originali */
		tc.tic();
		for (auto &v : d4) {
			if (!v.empty()) {
				merge_sort(v,0,v.size()-1); /* ordino tutti i vettori dentro alla copia */
			}
		}
		double t_merge=tc.toc()/m; /* faccio la media */
		std::cout << "Merge: " << t_merge << "\n";
		
		/* Quick */
		auto d5=data; /* copio dati originali */
		tc.tic();
		for (auto &v : d5) {
			if (!v.empty()) {
				quick_sort(v,0,v.size()-1); /* ordino tutti i vettori dentro alla copia */
			}
		}
		double t_quick=tc.toc()/m; /* faccio la media */
		std::cout << "Quick: " << t_quick << "\n";
		
		/* std::sort */
		auto d6=data; /* copio dati originali */
		tc.tic();
		for (auto &v : d6) {
			std::sort(v.begin(),v.end()); /* ordino tutti i vettori dentro alla copia */
		}
		double t_std=tc.toc()/m; /* faccio la media */
		std::cout << "std::sort: " << t_std << "\n";
		
		std::cout << "\n";
	}
	return 0;
}