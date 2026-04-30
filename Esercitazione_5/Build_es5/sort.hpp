/* ordino i vettori che non sono già ordinati */

#pragma once
#include <vector>
#include <cmath>

template<typename T>
void merge(std::vector<T>& A, int p, int q, int r)
{
	int n1=q-p+1;
	int n2=r-q;
	std::vector<T> L(n1);
	std::vector<T> R(n2);
	for (int i=0; i<n1; i++) {
		L[i]=A[p+i];
	}
	for (int j=0; j<n2; j++) {
		R[j]=A[q+1+j];
	}
	/* uso infinito alla fine degli array */
	int i=0;
	int j=0;
	int k=p;
	while (i<n1 && j<n2) { /* vado avanti fino a quando entrambi L e R hanno ancora elementi */
		/* prendo la componente minore tra i 2 array */
		if (L[i]<=R[j]) {
			A[k]=L[i];
			i=i+1;
		}
		else {
			A[k]=R[j];
			j=j+1;
		}
		k=k+1;
	}
	/* quando uno è finito, copio il resto dell'altro */
	while (i<n1) {
		A[k]=L[i];
		i=i+1;
		k=k+1;
	}
	while (j<n2) {
		A[k]=R[j];
		j=j+1;
		k=k+1;
	}
}

template<typename T>
void merge_sort(std::vector<T>& A, int p, int r)
{
	if (p<r) {
		int q=std::floor((p+r)/2);
		merge_sort(A,p,q);
		merge_sort(A,q+1,r);
		merge(A,p,q,r);
	}
}

template<typename T>
int partition(std::vector<T>& A, int p, int r)
{
	T x=A[r];
	int i=p-1;
	for (int j=p; j<r; j++) {
		if (A[j]<=x) {
			i=i+1;
			std::swap(A[i],A[j]);
		}
	}
	std::swap(A[i+1],A[r]);
	return i+1;
}

template<typename T>
void quick_sort(std::vector<T>& A, int p, int r)
{
	if (p<r) {
		int q=partition(A,p,r);
		quick_sort(A,p,q-1);
		quick_sort(A,q+1,r);
	}
}

template<typename T>
void bubble_sort(std::vector<T>& vec)
{
	for (size_t i=0; i<vec.size()-1; i+=1) {
		for (size_t j=vec.size()-1; j>i; j-=1) {
			if (vec[j]<vec[j-1]) {
				std::swap(vec[j],vec[j-1]);
			}
		}
	}
}

template<typename T>
void insertion_sort(std::vector<T>& vec)
{
	for (size_t j=1; j<vec.size(); j+=1) {
		T key=vec[j];
		int i=j-1;
		while (i>=0 && vec[i]>key) {
			vec[i+1]=vec[i];
			i=i-1;
		}
		vec[i+1]=key;
	}
}

template<typename T>
void selection_sort(std::vector<T>& vec)
{
	for (size_t i=0; i<vec.size()-1; i+=1) {
		int min=i;
		for (size_t j=i+1; j<vec.size(); j+=1) {
			if (vec[j]<vec[min]) {
				min=j;
			}
		}
		std::swap(vec[i],vec[min]);
	}
}