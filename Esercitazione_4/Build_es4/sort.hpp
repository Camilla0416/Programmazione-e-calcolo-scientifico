/* ordino i vettori che non sono già ordinati */

#pragma once
#include <vector>

template<typename T>
void bubble_sort(std::vector<T>& vec)
{
	for (int i=0; i<vec.size()-1; i+=1) {
		for (int j=vec.size()-1; j>i; j-=1) {
			if (vec[j]<vec[j-1]) {
				std::swap(vec[j],vec[j-1]);
			}
		}
	}
}

template<typename T>
void insertion_sort(std::vector<T>& vec)
{
	for (int j=1; j<vec.size(); j+=1) {
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
	for (int i=0; i<vec.size()-1; i+=1) {
		int min=i;
		for (int j=i+1; j<vec.size(); j+=1) {
			if (vec[j]<vec[min]) {
				min=j;
			}
		}
		std::swap(vec[i],vec[min]);
	}
}