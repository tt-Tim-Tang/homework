//2453805 唐先泽 大数据
#include <iostream>
#include <string>
using namespace std;

template<typename T, int ROW, int COL>
class matrix {
private:
	T value[ROW][COL];
public:
	matrix() {
		for (int i = 0; i < ROW; i++) {
			for (int j = 0; j < COL; j++) {
				value[i][j] = T();
			}
		}
	}
	matrix<T,ROW,COL> operator+(const matrix& m) const {
		matrix temp;
		for (int i = 0; i < ROW; i++) {
			for (int j = 0; j < COL; j++) {
				temp.value[i][j] = this->value[i][j] + m.value[i][j];
			}
		}
		return temp;
	}

	friend ostream& operator << (ostream& out, const matrix& a) {
		for (int i = 0; i < ROW; i++) {
			for (int j = 0; j < COL; j++) {
				out << a.value[i][j] << " ";
			}
			out << endl;
		}
		return out;
	}
	friend istream& operator >> (istream& in, matrix& a) {
		for (int i = 0; i < ROW; i++) {
			for (int j = 0; j < COL; j++) {
				in >> a.value[i][j];
			}
		}
		return in;
	}
};




