#include <iostream>

class Parallelepiped {
private:
    double length;
    double width;
    double height;

public:
    // Конструктор
    Parallelepiped() {
        length = 0.0;
        width = 0.0;
        height = 0.0;
    }

    // Перевантажений конструктор з параметрами
    Parallelepiped(double l, double w, double h) {
        length = l;
        width = w;
        height = h;
    }

    // Деструктор
    ~Parallelepiped() {
        std::cout << "Об'єкт Parallelepiped був знищений." << std::endl;
    }

    // Set-методи
    void setLength(double l) {
        length = l;
    }

    void setWidth(double w) {
        width = w;
    }

    void setHeight(double h) {
        height = h;
    }

    // Get-методи
    double getLength() const {
        return length;
    }

    double getWidth() const {
        return width;
    }

    double getHeight() const {
        return height;
    }

    // Метод обчислення площі поверхні
    double calculateSurfaceArea() const {
        return 2 * (length * width + length * height + width * height);
    }

    // Метод обчислення суми довжин всіх ребер паралелепіпеда
    double calculateSumOfEdges() const {
        return 4 * (length + width + height);
    }

    // Функція для виводу інформації про об'єкт
    void printInfo() const {
        std::cout << "Довжина: " << length << " ширина: " << width << " висота: " << height << std::endl;
        std::cout << "Площа поверхні: " << calculateSurfaceArea() << std::endl;
        std::cout << "Сума довжин ребер: " << calculateSumOfEdges() << std::endl;
    }

    // Перевантаження бінарних операторів
    Parallelepiped operator+(const Parallelepiped& other) const {
        return Parallelepiped(length + other.length, width + other.width, height + other.height);
    }

    Parallelepiped operator-(const Parallelepiped& other) const {
        return Parallelepiped(length - other.length, width - other.width, height - other.height);
    }

    // Перевантаження унарних операторів
    Parallelepiped operator+() const {
        return *this;  // Повертаємо сам об'єкт без змін
    }

    Parallelepiped operator-() const {
        return Parallelepiped(-length, -width, -height);
    }
};

int main() {

    Parallelepiped parallelepiped1(6.0, 5.0, 8.0);
    Parallelepiped parallelepiped2(3.0, 2.0, 6.0);

    // Виведення інформації про об'єкти
    parallelepiped1.printInfo();
    parallelepiped2.printInfo();

    Parallelepiped sum_result = parallelepiped1 + parallelepiped2;
    std::cout << "\nРезультат додавання:" << std::endl;
    sum_result.printInfo();

    Parallelepiped diff_result = parallelepiped1 - parallelepiped2;
    std::cout << "\nРезультат віднімання:" << std::endl;
    diff_result.printInfo();

    Parallelepiped unary_plus_result = +parallelepiped1;
    std::cout << "\nРезультат унарного плюса:" << std::endl;
    unary_plus_result.printInfo();

    Parallelepiped unary_minus_result = -parallelepiped1;
    std::cout << "\nРезультат унарного мінуса:" << std::endl;
    unary_minus_result.printInfo();

    return 0;
}
