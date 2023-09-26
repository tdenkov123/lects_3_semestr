#include <iostream>
#include <string>

using namespace std;

class FooString {
    private:
        string str;
    public:
        FooString(string p_str) : str(p_str) {};
        ~FooString() {};
        
        string getString() {return str;}
        int getLen() {return str.length();}
        void print() {cout << str << endl;}
};

int main() {
    FooString mystr {"Halllllloooo"};
    cout << mystr.getLen() << endl;
    mystr.print();

    return 0;
}