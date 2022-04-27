#include "matrix.h"
#include "exceptions.h"


#include <limits>
#include <cmath>
#include <iomanip>



namespace prep {


//  Конструктор

Matrix::Matrix(size_t rows, size_t cols) {
    this->cols = cols;
    this->rows = rows;
    this->array = new double[rows * cols];

    for (size_t i = 0; i < rows * cols; i++)
        array[i] = 0;
}


//  Контруктор из потока

Matrix::Matrix(std::istream& is) {
    is >> rows;
    is >> cols;

    if (this->cols == 0 || this->rows == 0 || is.fail()) {
        this->array = nullptr;
        throw InvalidMatrixStream();
    }
    this->array = new double[rows * cols];

    for (size_t i = 0; i < cols * rows; i++) {
        is >> this->array[i];

        if (is.fail()) {
            this->~Matrix();
            throw InvalidMatrixStream();
        }
    }
}

//  Конструктор копирования

Matrix::Matrix(const Matrix& other) {
    this->rows = other.rows;
    this->cols = other.cols;
    this->array = new double[cols * rows];

    for (size_t i = 0; i < cols * rows; i++)
        this->array[i] = other.array[i];
}

//  Деструктор

Matrix::~Matrix() {
    if (array != nullptr) {
        delete[] this->array;
        array = nullptr;
    }
}

//  Вернуть кол-во строк

size_t Matrix::getRows() const {
    return rows;
}

//  Вернуть кол-во столбцов

size_t Matrix::getCols() const {
    return cols;
}

//  Вернуть значение элемента

double Matrix::operator()(size_t i, size_t j) const {
    if (i >= rows || j >= cols) throw OutOfRange(i, j, *this);
    return array[i * cols + j];
}

//  Вернуть  ссылку на элемент

double& Matrix::operator()(size_t i, size_t j) {
    if (i >= rows || j >= cols) throw OutOfRange(i, j, *this);
    return array[i * cols +j];
}

//  Оператор присвоения

Matrix& Matrix::operator=(const Matrix& other) {
    if (&other == this) return *this;
    delete[] array;
    rows = other.rows;
    cols = other.cols;

    array = new double[rows * cols];

    for (size_t i = 0; i < cols * rows; i++)
        array[i] = other.array[i];

    return *this;
}

// Сравнение с точностью Эпсилон

bool isEqual(double x, double y, double epsilon) {
    return fabs(x - y) > epsilon;
}

//  Оператор сравнения

bool Matrix::operator==(const Matrix& other) const {
    bool result = true;
    if (other.cols != cols || other.rows != rows)
        return false;
    for (size_t i = 0; i < rows * cols; i++) {
        if (isEqual(array[i], other.array[i], std::numeric_limits<float>::epsilon()))
            result = false;
    }
    return result;
}


//  Оператор неравно

bool Matrix::operator!=(const Matrix& other) const {
    return !(this == &other);
}

//  Оператор вывода в поток

std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
    os << matrix.rows << ' ' << matrix.cols << std::endl;

    for (size_t i = 0; i < matrix.rows; i++) {
        for (size_t j = 0; j < matrix.cols; j++) {
            os << std::fixed << std::setprecision(std::numeric_limits<float>::max_digits10)
               << matrix.array[i*matrix.cols+j];
            if (j != matrix.cols - 1) {
                os << ' ';
            }
        }
        os << std::endl;
    }
    return os;
}

//  Операция арифметическая матрицы

Matrix Matrix::arifmetic(const Matrix& matrix, arifmetic_func fn) const {
    if (!isSameDemention(matrix))
        throw DimensionMismatch(matrix, *this);
    Matrix result(rows, cols);
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            result.array[i * cols + j] = fn(array[i * cols + j], matrix.array[i * cols + j]);
        }
    }
    return result;
}

//  сумма

double summary(double x, double y) {
    return x + y;
}

//  разность

double subtract(double x, double y) {
    return x - y;
}

// Оператор сложения

Matrix Matrix::operator+(const Matrix& sum_matrix) const {
    return arifmetic(sum_matrix, summary);
}

//  Оператор вычитания

Matrix Matrix::operator-(const Matrix& sub_matrix) const {
    return arifmetic(sub_matrix, subtract);
}

//  Оператор умножения матриц

Matrix Matrix::operator*(const Matrix& mul_matrix) const {
    if ((cols != mul_matrix.rows)) throw DimensionMismatch(mul_matrix, *this);

    Matrix multiply(rows, mul_matrix.cols);

    size_t mid = cols;
    size_t n = multiply.rows;
    size_t m = multiply.cols;

    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            double buffer = 0;

            for (size_t k = 0; k< mid; k++) {
                buffer += array[i * mid + k] * mul_matrix.array[k * m + j];
            }
        multiply.array[i * m + j] = buffer;
        }
    }
    return multiply;
}



//  Операторация транспонирования

Matrix Matrix::transp() const {
    Matrix transp_matrix(cols, rows);

    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            transp_matrix.array[j * rows + i] = array[i * cols + j];
        }
    }
    return transp_matrix;
}

//  Оператор умножения  на скаляр

Matrix Matrix::operator*(double val) const {
    Matrix matrix(rows, cols);

    for (size_t i = 0; i < rows * cols; i++) {
        matrix.array[i] = val * array[i];
    }
    return matrix;
}

//  Оператор умножения на скаляр слева

Matrix operator*(double val, const Matrix& matrix) {
    Matrix mul_matrix(matrix.rows, matrix.cols);

    for (size_t i = 0; i < matrix.rows * matrix.cols; i++) {
        mul_matrix.array[i] = val * matrix.array[i];
    }
    return mul_matrix;
}


//  Сравнение размерностей

bool Matrix::isSameDemention(const Matrix& other) const {
    return (cols == other.cols) && (rows == other.rows);
}

//  Определение детерминанта

double Matrix::det() const {
    if (!isSquare()) throw DimensionMismatch(*this);

    size_t n = rows;
    if (n == 1) {
        return array[0];
    }
    if (n == 2) {
        return array[0] * array[3] - array[2] * array[1];
    }
    double determinant = 0;

    for (size_t i = 0; i < n; i++) {
        determinant += array[i] * this->AlgCompl(0, i);
    }
    return determinant;
}

//  Дополнительная матрица

Matrix Matrix::adj() const {
    if (!isSquare()) throw DimensionMismatch(*this);

    size_t size = rows;
    Matrix adjoint(size, size);

    if (size == 1) {
        adjoint.array[0] = 1;
        return adjoint;
    }
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            adjoint.array[i * cols + j] = this->AlgCompl(j, i);
        }
    }
    return adjoint;
}

//  Присоединительная матрица

Matrix Matrix::inv() const {
    if (!isSquare()) throw DimensionMismatch(*this);

    if (fabs(this -> det()) < std::numeric_limits<double>::epsilon()) throw SingularMatrix();

    Matrix inval(cols, rows);

    double number = 1 / det();
    inval = number * adj();
    adj().~Matrix();
    return inval;
}


double Matrix::AlgCompl(size_t x, size_t y) const {
    if (rows == cols && x <= rows && y <= cols) {
        return (((x+y) % 2 == 0) ? 1: -1) * this->Minor(x, y);
    }
    return 0;
}

double Matrix::Minor(size_t x, size_t y) const {
    Matrix minor_matrix(rows - 1, cols - 1);
    size_t n = rows;
    int pointer = 0;

    for (size_t i = 0; i < n; i++) {
        if (i != x) {
            for (size_t j = 0; j < n; j++) {
                if (j != y) {
                    minor_matrix.array[pointer] = array[i * n + j];
                    pointer++;
                }
            }
        }
    }

    double minor_det = minor_matrix.det();
    minor_matrix.~Matrix();
    return minor_det;
}

//  Крадратная?

bool Matrix::isSquare() const {
    return rows == cols;
}


}  // namespace prep
