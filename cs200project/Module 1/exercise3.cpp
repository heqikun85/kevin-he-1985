#include <iostream>
#include <fstream>
using namespace std;

int main () {
//ofstream to create a file.
ofstream file;
//open file name "student.txt"
file.open ("student.txt");
//print data to file with 3 coloumns Student name , ID and Major
file << "Name \t ID \t Major\n";
file << "Siming \t 01 \t CS\n";
file << "Ray \t 02 \t Econ\n";
file << "Amy \t 03 \t Math\n";
file.close();
return 0;
}