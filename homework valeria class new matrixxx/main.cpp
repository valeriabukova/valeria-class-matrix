//
//  main.cpp
//  homework valeria class new matrixxx
//
//  Created by Valeria  Bukova on 16.10.2024.
//

#include <iostream>

template <typename T>
class Matrix {
private:
    T** data;
    int rows, cols;

    void allocateMemory() {
        data = new T*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new T[cols];
        }
    }

    void freeMemory() {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }

public:
    
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        allocateMemory();
    }

    
    ~Matrix() {
        freeMemory();
    }

    
    void fillFromInput() {
        std::cout << "Enter elements of the matrix:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                std::cin >> data[i][j];
            }
        }
    }

   
    void fillWithRandom() {
        int value = 1;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                data[i][j] = value++;
            }
        }
    }

    
    void display() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

   
    Matrix operator+(const Matrix& other) {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator-(const Matrix& other) {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator*(const Matrix& other) {
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                result.data[i][j] = 0;
                for (int k = 0; k < cols; k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

   
    T findMax() const {
        T maxElem = data[0][0];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (data[i][j] > maxElem) {
                    maxElem = data[i][j];
                }
            }
        }
        return maxElem;
    }

   
    T findMin() const {
        T minElem = data[0][0];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (data[i][j] < minElem) {
                    minElem = data[i][j];
                }
            }
        }
        return minElem;
    }
};

// Custom class A
class A {
private:
    int value;

public:
    A(int v = 0) : value(v) {}

    A operator+(const A& other) const {
        return A(this->value + other.value);
    }

    A operator-(const A& other) const {
        return A(this->value - other.value);
    }

    A operator*(const A& other) const {
        return A(this->value * other.value);
    }

    bool operator>(const A& other) const {
        return this->value > other.value;
    }

    bool operator<(const A& other) const {
        return this->value < other.value;
    }

    friend std::ostream& operator<<(std::ostream& os, const A& a) {
        os << a.value;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, A& a) {
        is >> a.value;
        return is;
    }
};

int main() {
    Matrix<int> m1(3, 3);
    m1.fillWithRandom();
    m1.display();

    Matrix<A> m2(2, 2);
    m2.fillFromInput();

    m2.display();

    return 0;
}
