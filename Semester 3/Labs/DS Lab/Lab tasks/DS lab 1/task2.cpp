#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(int argc, char **argv)
{
    fstream fp;
    fp.open("Myfile.txt",ios::out);
    for (int i = 0; i < argc; i++)
    {
        fp<<argv[i]<<" ";
    }
    fp.close();
    fp.open("Myfile.txt",ios::in);
    if (!fp)
    {
        cout<<"File not found"<<endl;
    }
    else
    {
        string temp;
        getline(fp,temp);
        cout<<temp;
    }
}
    
 