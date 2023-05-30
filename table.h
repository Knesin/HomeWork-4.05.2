#pragma once
template <class T>
class table
{
public:
	table(int row, int col);
	~table();
	table& operator=(const table& t);
	table(const table& t);
	T* operator[](int row);
	T* operator[](int row) const;
	int Size() const;
private:
	int col_;
	int row_;
	T** data_;
};

template <class T>
table<T>::table(int row, int col) : row_(row), col_(col) {
	if (row_ < 0 || col_ < 0) throw "Размер таблицы меньше 0";
	data_ = new T * [row_];
	for (int i = 0; i < row_; ++i) {
		data_[i] = new T[col_];
	}
};

template <class T>
table<T>::~table() {
	for (int i = 0; i < row_; ++i) {
		delete[] data_[i];
		data_[i] = nullptr;
	}
	delete data_;
	data_ = nullptr;
};

template <class T>
T* table<T>::operator[](int row) {
	if (row < 0 || row > row_) throw "Индекс вне диапозона";
	return data_[row];
}

template <class T>
T* table<T>::operator[](int row) const {
	if (row < 0 || row > row_) throw "Индекс вне диапозона";
	return data_[row];
}

template <class T>
table<T>& table<T>::operator=(const table& rt) {
	for (int i = 0; i < row_; ++i) {
		delete[] data_[i];
	}
	delete data_;
	row_ = rt.row_;
	col_ = rt.col_;
	data_ = new T * [row_];
	for (int i = 0; i < row_; ++i) {
		data_[i] = new T[col_];
		for (int j = 0; j < col_; ++j) {
			data_[i][j] = rt.data_[i][j];
		}
	}
	return *this;
}

template <class T>
int table<T>::Size() const {
	return row_ * col_;
}

template <class T>
table<T>::table(const table& t)
	:table<T> (t.row_, t.col_)
{
	for (int i = 0; i < row_; ++i) {
		for (int j = 0; j < col_; ++j) {
			data_[i][j] = t.data_[i][j];
		}
	}
}