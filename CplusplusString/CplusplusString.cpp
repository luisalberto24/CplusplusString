// CplusplusString.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "base_string.h"
#include <iostream>

using namespace std;

int main()
{
    w_string wtext = L"Hola pepe";
    c_string ctext = "Hola pepe";

    CREATE_WSTRING_POINTER(pwtext);
    *pwtext = L"Tenant!!!!";
    wcout << "text: " << pwtext->get_value() << endl;
    wcout << "length: " << pwtext->get_length() << endl;
    DELETE_WSTRING_POINTER(pwtext);

    cout << w_string::get_length(L"") << endl;
    wtext = L"Funciona bastante bien!!!";
    ctext = "Funciona bastante bien 222!!!";

    wcout << (wchar_t_ptr)wtext << endl;
    wcout << wtext.get_length() << endl;
    wcout << (wchar_t_ptr)wtext << endl;
    cout << ctext << endl;

    std::cout << "Hello World!\n";
}
