#include "Utils.hpp"
#include "iostream"
#include "fstream"
#include "sstream"
#include "iomanip"

using namespace std;

bool ImportVectors(const string& inputFilePath,size_t& n,double*& w,double*& r, unsigned int &S)
{
    ifstream input(inputFilePath);
	if(input.fail())
	  return false;
  std::string tmp; //stringa temporanea
  getline(input, tmp, ';'); // prima riga 
  input>>S;
  getline(input, tmp,';'); //seconda riga
  input>>n;
  
  w= new double[n];
  r= new double[n];
  char c;
  unsigned int i=0;
  
  getline(input, tmp);
  
  while(getline(input, tmp) && i<n)
  {
	  stringstream line3(tmp); //terza riga
	  line3>>w[i]>>c>>r[i];
	  i++;
  }
  return true;
}

double DotProduct(const size_t& n, const double* const& w, const double* const& r, const unsigned int& S, double &V)
{
	double result=0;
	for (unsigned int i=0; i<n; i++)
		result+= w[i]*r[i];
	V=(1+result)*S;
	return result;
}

bool ExportResult(const string& outputFilePath, const size_t& n, const double* const& w, const double* const& r, const unsigned int &S, const double &DP, const double &V)
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
	
	output<<" Rate of return of the portfolio: "<<setprecision(4)<<DP<<endl;
	output<<"V: "<<setprecision(2)<<V<<endl;
	return true;
	
}

