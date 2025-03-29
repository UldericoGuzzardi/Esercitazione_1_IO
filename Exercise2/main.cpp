#include <iostream>
#include<fstream>
#include<iomanip>

using namespace std;
double traslazione(double x)
{
	double y= x*0.75-1.75;
	return y;
}
	
	

int main()
{	ifstream file("data.txt");
	
	 if(file.fail())
    {
        cerr << "File not found" << endl;
		
        return 1;
    }
	string filename= "result.txt";
	ofstream ofs(filename);
	if (! ofs.is_open())
	{
		cerr<<"errore"<<endl;
		return 1;
	}
	
	double val;
	double sum=0;
	double w=1.0;
	double mean;
	double new_val;
	
	ofs<<"#N Mean"<<endl;
	while(file>>val) 
	{
		new_val=traslazione(val);
		sum+= new_val;
		mean= sum/w;
		w++;
		ofs<<scientific<<setprecision(16)<<mean<<endl;
		
	}
	file.close();
	
	

    return 0;
}
