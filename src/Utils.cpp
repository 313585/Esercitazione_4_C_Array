#include "Utils.hpp"
#include "iostream"
#include "fstream"
#include "sstream"
#include "iomanip"

using namespace std;

bool ImportVectors(const string& inputFilePath,size_t& n,double*& w,double*& r, double& S)
{
  ifstream input(inputFilePath);
  if(input.fail())
	return false;
  string riga;
  char lettera;
  char separatore;
  
  // lettura prima riga
  getline(input, riga);
  stringstream str1(riga);
  str1>>lettera>>separatore>>S;
  
  // lettura seconda riga
  getline(input,riga);
  stringstream str2(riga);
  str2>>lettera>>separatore>>n;
  
  // salto riga: "w;r"
  string tmp;
  getline(input, tmp);
  
  w= new double[n];
  r= new double[n];
  string linea;
  
  for(unsigned int i=0; i<n; i++)
  {
	getline(input, linea);
	stringstream str3(linea);
	str3>>w[i]>>separatore>>r[i];
  }
  return true;
}

double DotProduct(const size_t& n, const double* const& w, const double* const& r)
{
		double prodotto=0.0;
		for (unsigned int i=0; i<n; i++)
			prodotto+= w[i]*r[i];
	return prodotto;
}

double ValuePortfolio(const size_t& n, const double& S, const double* const& w, const double* const& r)
{
	double V=0.0;
	for (unsigned int i=0; i<n; i++)
		V += w[i]*(1+r[i]);
	V=V*S;
	return V;
}

bool ExportResult(const string& outputFilePath, const size_t& n, const double* const& w, const double* const& r, const double& S, const double& V, const double& prodotto)
{
	ofstream output(outputFilePath);
	if(!output)
		return false;
	output<<"S: "<<setprecision(2)<<fixed<<S<<", n= "<<n<<endl;
	output<<" w=[ ";
	for (unsigned int i=0; i<n; i++)
		output<<w[i]<<" ";
	output<<" ]\n";
	output<<" r=[ ";
	for (unsigned int i=0; i<n; i++)
		output<<r[i]<<" ";
	output<<" ]\n";
	
	output<<" Rate of return of the portfolio: "<<setprecision(4)<<prodotto<<endl;
	output<<"V: "<<setprecision(2)<<V<<endl;
	output.close();
	return true;
	
}

