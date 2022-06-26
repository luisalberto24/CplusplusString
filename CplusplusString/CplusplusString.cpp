#include "base_string.h"
#include <iostream>

using namespace std;

int main()
{
    w_string wtext = L"Hello world";
    c_string ctext = "Hello world";

    CREATE_WSTRING_POINTER(pwtext);
    *pwtext = L"This is a hello world string!";
    wcout << "text: " << pwtext->get_value() << endl;
    wcout << "length: " << pwtext->get_length() << endl;
    DELETE_WSTRING_POINTER(pwtext);
    
    wtext = L"New wide chart text.";
    ctext = "New character chart text.";

    wcout << (wchar_t_ptr)wtext << endl;
    wcout << "length: " << wtext.get_length() << endl;
    wcout << (wchar_t_ptr)wtext << endl;
    cout << ctext << endl;

    getchar();
}
