#include <iostream>

class Hist {
private:
	int len;
	int* values;
public:
	Hist(int p_len) : len(p_len) {
		values = new int[len]();
	}
	Hist(const Hist& h) {
		len = h.len;
		for (int i = 0; i < len; i++) { values[i] = h.values[i]; }
	}
	Hist operator= (const Hist& h) {
		len = h.len;
		if (values != nullptr) { delete[] values; }
		int* values = new int[len];
		for (int i = 0; i < len; i++) { values[i] = h.values[i]; }
	}
	virtual ~Hist() {delete[] values;}

	friend std::ostream& operator<< (std::ostream& out, const Hist& h) {
		for (int i = 0; i < h.len; i++) { out << h.values[i]; }
		return out;
	}

	friend bool operator== (const Hist& h1, const Hist& h2) {
		if (h1.len == h2.len && (*h1.values) == (*h2.values)) return true;
		return false;
	}

	int get(int index) {return values[index];}

	void set(int index, int value) { values[index] = value; }
};

int main(int argc, char** argv) {

	return 0;
}