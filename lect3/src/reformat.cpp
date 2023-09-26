#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Reformat {
    private:
    string filename_old, filename_new;
    ifstream file_old;
    ofstream file_new;

    public:
    Reformat(string filename_old, string filename_new) {
        file_old.open("../files/" + filename_old);
        file_new.open("../files/" + filename_new);
    }
    ~Reformat() {
        file_new.close();
        file_old.close();
    }

    int txt_to_gift() {
        bool bracket_open = false;
        string str = "";
        while (std::getline(file_old, str)){
            if (str.find(". ") == 1 && str.find("?") != string::npos) {
                if (bracket_open) {
                    file_new << "\n}\n" << str << " {";
                }
                else {
                    file_new << str << " {";
                    bracket_open = true;
                }
            }
            else if (str[0] == '-') {
                file_new << "\n" << str.replace(0, 1, "~");
            }
            else if (str[0] == '+') {
                file_new << "\n" << str.replace(0, 1, "=");
            }
        }
    file_new << "\n}";
    cout << "Transformation from .txt to .gift done well.";
    }
};

int main() {
    Reformat ref{"file.txt", "file.gift"};
    ref.txt_to_gift();
    return 0;
}