#include <iostream>
#include <fstream>
using namespace std;


int main(){

    // ofstream fout;

    // fout.open("text.txt",ios::app);
    // fout<<" Hello bhaiya \n";
    // fout.clear();
    ifstream fin;
    fin.open("text.txt");
    if(!fin){
        cout<<"File not found";
        return 0;
    }
    char ch;
    ch = fin.get();
    while(!fin.eof()){
        cout<<ch;
        ch = fin.get();
    }
    cout<<endl;

    return 0;
}