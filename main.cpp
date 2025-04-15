#include <iostream>
#include "Utils.hpp"

using namespace std;


int main()
{
    string inputFilePath="data.txt";
	string outputFilePath="result.txt";
	size_t n;
	double *w=nullptr;
	double *r=nullptr;
	double S=0;
	
	ImportVectors(inputFilePath, n, w, r, S);
	
	double prodotto= DotProduct(n,w,r);
	double V=ValuePortfolio(n,S,w,r);
	
	ExportResult(outputFilePath,n,w,r,S,V,prodotto);
	
	delete[] w;
	delete[] r;
		
	return 0;
}

