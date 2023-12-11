#include <iostream>
#include <memory>
#include <string>

class Image {
private:
    int* img;
    int mx;
    int my;
public:
    Image(int tmx, int tmy) :mx(tmx), my(tmy) {img = new int[mx * my]();}

    Image(const Image& v) {
        mx = v.mx;
        my = v.my;
        img = new int[mx * my]();
        for (int i = 0; i < mx * my; i++) {img[i] = (v.img)[i];}
    }

    Image operator=(const Image& v) {
        mx = v.mx;
        my = v.my;
        if (img != nullptr) {delete[] img;}
        img = new int[mx * my];
        for (int i = 0; i < mx * my; i++) { img[i] = (v.img)[i]; }
    }

    virtual ~Image() {delete[] img;}

    int get(int x, int y) {
        try {return img[y * my + x];}
        catch (const std::string& err) {std::cout << "Error occured: " << err << '\n';}
    }

    void set(int x, int y, int color) {
        try {img[y * my + x] = color;}
        catch (const std::string& err) { std::cout << "Error occured: " << err << '\n'; }
        
    }

    friend std::ostream& operator<<(std::ostream& out, const Image& d1) {
        for (int i = 0; i < d1.mx * d1.my; i++) out << d1.img[i];
        return out;
    }

    friend bool operator==(Image& arrInt, Image& arrInt2) {
        if (arrInt.mx == arrInt2.mx && arrInt.my == arrInt2.my && *(arrInt.img) == *(arrInt2.img)) return true;
        return false;
    }
};

int main(int argc, char** argv) {
    Image a{ 20, 10 };
    Image b = a;
    a.set(0, 0, 100);
    a.set(1, 0, 10);
    a.set(2, 0, 50);
    std::cout << "a colour (1, 0) = " << a.get(1, 0) << '\n';
    std::cout << a << '\n';
    std::cout << (a == b);

    return 0;
}