#include <iostream>
#include <cmath>

int main()
{
	static const int N=10;
	double arr[N]={1.3,2.1,3.8,6.2,4.8,5.9,1.1,4.6,9.5,0.6};
	double minimo=arr[0];
	double massimo=arr[0];
	double somma=0.0;
	double varianza=0.0;
	double sigma=0.0;
	for (int i=0; i<N; i++) {
		minimo=std::min(arr[i],minimo);
		massimo=std::max(arr[i],massimo);
		somma=somma+arr[i];
	}
	double media=somma/N;
	for (int i=0; i<N; i++) {
		varianza=varianza+(arr[i]-media)*(arr[i]-media);
	}
	varianza=varianza/N;
	sigma=std::sqrt(varianza);
	
	std::cout << "Il minimo è: " << minimo << "\n";
	std::cout << "Il massimo è: " << massimo << "\n";
	std::cout << "La media è: " << media << "\n";
	std::cout << "La deviazione standard è: " << sigma << "\n";
	
	return 0;
}