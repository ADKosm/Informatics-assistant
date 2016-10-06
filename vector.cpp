#include <iostream>

class LVector {
public: // публичная секция - тут лежат функции, которые могут быть вызваны у объекта
	LVector() { // конструктор - функция вызывается при создании объекта
		size = 0; // задать начальные параметры
		dataSize = 0;
		delta = 4;
	}

	~LVector() { // деструктор - вызывается при уничтожении объекта (например конец программы)
		delete[] data; // очистить память
	}

	void push_back(int elem) { // добавить элемент в конец
		if(dataSize == size) {
			reallocate();
		}
		data[size] = elem;
		size += 1;
	}

	int at(int index) { // взять элемент под номером (аналог [])
		if(index >= 0 and index < size) {
			return data[index];
		} else {
			return 0;
		}
	}

	int getSize() { // узнать размер массива
		return size;
	}

private: // приватная зона - данные +  фукнции, которые нельзя вызывать извне
	void reallocate() { // выделяем новое местро для хранения
		dataSize = size+delta;
		int * newdata = new int[dataSize];
		for(int i = 0; i < size; i++) {
			newdata[i] = data[i];
		}
		delete[] data;
		data = newdata;
	}

	// данные объекта
	int * data; // указатель на данные
	int size; // количество элементов
	int dataSize; // количество выделенных ячеек
	int delta; // количество выделяемых новых ячеек
};

int main() {
	LVector h;
	h.push_back(3);
	h.push_back(6);
	h.push_back(9);
	h.push_back(12);
	h.push_back(51);
	h.push_back(21);

	for(int i = 0; i < h.getSize(); i++) {
		std::cout << h.at(i) << std::endl;
	}

	return 0;
}
