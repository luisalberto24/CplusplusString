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
    
    wtext = L"New wide char text.";
    ctext = "New character char text.";

    for(uint x = 0; x < ctext.get_length(); x++)
    { 
        printf("%c\n", ctext[x]);
    }

    wcout << (wchar_t_ptr)wtext << endl;
    wcout << "length: " << wtext.get_length() << endl;
    wcout << (wchar_t_ptr)wtext << endl;
    cout << ctext << endl;

    getchar();
}
