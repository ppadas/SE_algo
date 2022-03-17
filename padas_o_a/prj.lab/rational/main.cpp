// file.cpp: определяет точку входа для консольного приложения.
#include <fstream>
using namespace std;
 
int main(int argc, char* argv[])
{
    ofstream fout("out_test.txt"); // создаём объект класса ofstream для записи и связываем его с файлом cppstudio.txt
    fout << "Работа с файлами в С++\n"; // запись строки в файл
    fout.close(); // закрываем файл
    return 0;
}