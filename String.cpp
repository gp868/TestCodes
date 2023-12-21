#include <cstring>
using namespace std;

class String{
public:
    // 默认构造函数
    String(){
        m_data = new char[1];
        m_data[0] = '/0';
        count = 1;
    }

    // 构造函数
    String(const char* str){
        int n = strlen(str);
        m_data = new char[n + 1];
        strcpy(m_data, str);
        count = 1;
    }

    // 拷贝构造函数
    String(String& str){
        int n = strlen(str.m_data);
        m_data = new char[n + 1];
        strcpy(m_data, str.m_data);
        count = 1;
    }

    ~String(){
        count--;
        if(count == 0){
            delete[] m_data;
        }
    }

    String& operator=(String& str){
        if(this != &str){
            String tmp(other);
            swap(m_data, tmp.m_data);
            swap(count, tmp.count);
        }
        return *this;
    }


private:
    char* m_data;
    int count;
};