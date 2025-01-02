#include <iostream>
#include <cmath>
#include <complex> // สำหรับสมการกำลังสามที่มีรากเชิงซ้อน

void solveQuadraticEquation(double a, double b, double c) {
    double discriminant = b * b - 4 * a * c;
    double root1, root2;

    if (discriminant > 0) {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        std::cout << "Roots are real and different.\n";
        std::cout << "Root 1 = " << root1 << std::endl;
        std::cout << "Root 2 = " << root2 << std::endl;
    } else if (discriminant == 0) {
        root1 = -b / (2 * a);
        std::cout << "Roots are real and the same.\n";
        std::cout << "Root = " << root1 << std::endl;
    } else {
        double realPart = -b / (2 * a);
        double imaginaryPart = sqrt(-discriminant) / (2 * a);
        std::cout << "Roots are complex and different.\n";
        std::cout << "Root 1 = " << realPart << " + " << imaginaryPart << "i" << std::endl;
        std::cout << "Root 2 = " << realPart << " - " << imaginaryPart << "i" << std::endl;
    }
}

void solveCubicEquation(double a, double b, double c, double d) {
    std::complex<double> i(0, 1); // สำหรับตัวเชิงซ้อน
    std::complex<double> delta0 = b * b - 3.0 * a * c;
    std::complex<double> delta1 = 2.0 * b * b * b - 9.0 * a * b * c + 27.0 * a * a * d;
    std::complex<double> C = std::pow((delta1 + std::sqrt(delta1 * delta1 - 4.0 * delta0 * delta0 * delta0)) / 2.0, 1.0 / 3.0);

    std::complex<double> roots[3];
    std::complex<double> omega1 = -1.0 / 2.0 + std::sqrt(3.0) / 2.0 * i;
    std::complex<double> omega2 = -1.0 / 2.0 - std::sqrt(3.0) / 2.0 * i;

    roots[0] = -1.0 / (3.0 * a) * (b + C + delta0 / C);
    roots[1] = -1.0 / (3.0 * a) * (b + omega1 * C + delta0 / (omega1 * C));
    roots[2] = -1.0 / (3.0 * a) * (b + omega2 * C + delta0 / (omega2 * C));

    std::cout << "Cubic roots are:\n";
    for (int k = 0; k < 3; ++k) {
        std::cout << "Root " << k + 1 << " = " << roots[k] << std::endl;
    }
}

int main() {
    int choice;
    std::cout << "Choose the type of equation to solve:\n";
    std::cout << "1. Quadratic Equation (ax^2 + bx + c = 0)\n";
    std::cout << "2. Cubic Equation (ax^3 + bx^2 + cx + d = 0)\n";
    std::cin >> choice;

    if (choice == 1) {
        double a, b, c;
        std::cout << "Enter coefficients a, b, and c: ";
        std::cin >> a >> b >> c;

        if (a == 0) {
            std::cout << "Coefficient 'a' cannot be zero in a quadratic equation." << std::endl;
        } else {
            solveQuadraticEquation(a, b, c);
        }
    } else if (choice == 2) {
        double a, b, c, d;
        std::cout << "Enter coefficients a, b, c, and d: ";
        std::cin >> a >> b >> c >> d;

        if (a == 0) {
            std::cout << "Coefficient 'a' cannot be zero in a cubic equation." << std::endl;
        } else {
            solveCubicEquation(a, b, c, d);
        }
    } else {
        std::cout << "Invalid choice." << std::endl;
    }

    return 0;
}
