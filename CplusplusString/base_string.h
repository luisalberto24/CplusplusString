#pragma once

typedef unsigned int uint;

template<typename T>
class base_string
{
    private:

        T* data;
        uint length;

    public:

        base_string()
        {
            this->init();
        }

        base_string(const T* value)
        {
            load_data(value);
        }

        ~base_string()
        {
            this->free();
        }

    private:

        void load_data(const T* value)
        {
            load_data(value, base_string::get_length(value));
        }

        void load_data(const T* value, uint length)
        {
            this->init();
            this->new_base_string(value, length);            
        }

        void new_base_string(const T* value, uint length)
        {
            if (length > 0)
            {
                this->length = length;
                this->data = new T[length + 1];
                this->data[length] = 0;
                for (uint i = 0; i < length; i++)
                {
                    this->data[i] = value[i];
                }
            }
        }

        void init()
        {
            this->data = 0;
            this->length = 0;
        }

        void free()
        {
            if (length > 0)
            {
                delete this->data;
            }
            this->init();
        }

    public:

        static uint get_length(const T* value)
        {
            if (value)
            {
                uint i = 0;
                while (value[i]) i++;
                return i;
            }

            return 0;
        }

        uint get_length()
        {
            return this->length;
        }

        T* const get_value()
        {
            return this->data;
        }

    public:

        base_string& operator = (const T* value)
        {
            this->free();
            this->load_data(value);

            return *this;
        }

        char operator [](int i)
        {
            return (i > -1 && i < (int)length) ? this->data[i] : '\x0';
        }

        operator T* const()
        {
            return this->data;
        }
};

typedef wchar_t* wchar_t_ptr;
typedef char* char_ptr;

typedef base_string<wchar_t> w_string;
typedef base_string<char> c_string;

typedef w_string* w_string_ptr;
typedef c_string* c_string_ptr;

#define CREATE_WSTRING_POINTER(x) w_string_ptr x = new w_string();
#define DELETE_WSTRING_POINTER(x) delete x;

#define CREATE_CSTRING_POINTER(x) c_string_ptr x = new c_string();
#define DELETE_CSTRING_POINTER(x) delete x;



