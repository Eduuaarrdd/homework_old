#pragma once // NOLINT

#include <vector>
#include <istream>

typedef double (* arifmetic_func)(double, double);


namespace prep {
class Matrix {
  size_t rows;
  size_t cols;
  double* array;

 public:
  explicit Matrix(size_t rows = 0, size_t cols = 0);  //  конструктор
  explicit Matrix(std::istream& is);                  //  конструктор из потока
  Matrix(const Matrix& other);                        //  копия конструктор
  Matrix& operator=(const Matrix& other);             //  оператор присваивания
  ~Matrix();                                          //  деструктор

  size_t getRows() const;                             //  количество строк
  size_t getCols() const;                             //  количество столбцов

  double operator()(size_t i, size_t j) const;        //  доступ к элементу
  double& operator()(size_t i, size_t j);             //  ссылка на элемент

  bool operator==(const Matrix& other) const;         //  равенство матриц
  bool operator!=(const Matrix& other) const;         //  неравенство матриц

  Matrix operator+(const Matrix& sum_matrix) const;   //  сложение матриц
  Matrix operator-(const Matrix& sub_matrix) const;   //  вычитание матриц
  Matrix operator*(const Matrix& mul_matrix) const;   //  умножение матриц

  Matrix operator*(double val) const;                 //  умножение матрицы на число

  friend
  Matrix operator*(double val, const Matrix& matrix);  // и на число и на матрицу
  friend
  std::ostream& operator<<(std::ostream& os, const Matrix& matrix);  // вывод матрицы

  Matrix transp() const;
  double det() const;
  Matrix adj() const;
  Matrix inv() const;

 private:
  bool isSameDemention(const Matrix& other) const;
  bool isSquare() const;
  double Minor(size_t x, size_t y) const;
  double AlgCompl(size_t x, size_t y) const;
  Matrix arifmetic(const Matrix& matrix, arifmetic_func fn) const;
};

Matrix operator*(double val, const Matrix& matrix);
std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
}  // namespace prep
