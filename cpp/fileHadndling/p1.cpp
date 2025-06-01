#include <iostream>
#include <fstream>
using namespace std;


int main(int argc, char const *argv[])
{

    ofstream fout;
    fout.open("file1.txt");
    fout<<"Hello world india";
    fout.operator<<("Hello world");
   
    fout.close();
    return 0;
}


