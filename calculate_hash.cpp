#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include "md5.h"        //included header file of md5
using namespace std;
int i;
char const *files[100];

void CreateFile(string,string);
string CalculateHash(string);

class Hash
{
    public:

    void CreateFile(string name ,string data )
{
    ofstream fp(name);        
    fp<<data;     //append content to file
    fp.close();
}

string CalculateHash(string filename)
{
    MD5 md5;
    ifstream fp(filename);
    string hash_value;
    string path="/home/amisha/amisha/";
    path.append(filename);
    char const * c = path.data();
    files[i]=c;
    hash_value =md5.digestFile((char*)c);     //hash stored in string
    return hash_value;
}
    
};
int main()
{   
    Hash hash_obj;
    string name,data;
    int n;
    i=0;
    cout<<"enter the number of files\n";
    cin>>n;
    string arr_value[n];
    for(i=0;i<n;i++)
    {
        cout<<"enter filename"<<n<<"\n";
        cin>>name;
        getchar();
        cout<<"enter the data\n";
        std::getline (std::cin, data);
        hash_obj.CreateFile(name,data);
        arr_value[i]=hash_obj.CalculateHash(name);
        cout<<"hash of file"<<n<<"  "<<arr_value[i]<<"\n";     //displayed on screen 
    }
    return 0;
}



