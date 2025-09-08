#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <iomanip>

struct TaylorTerm {
    int order;      // The power of x (2n+1)
    double coeff;   // The coefficient: (-1)^n / (2n+1)!
    double value;   // The value of the term: coeff * x^(order)
};

void print_taylor_term(int index, int order, double coeff, double value) {
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Term[" << index << "]: "
              << "order=" << order << ", "
              << "coeff=" << coeff << ", "
              << "value=" << value << "\n";
}

void print_taylor_result(const char* function_name, double x,
                         int terms, double approximation) {
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Approximation of " << function_name
              << "(x) at x=" << x
              << " with " << terms << " terms: "
              << approximation << "\n";
}

// Helper function to compute factorial (for small numbers)
double factorial(int n) {
    double fact = 1.0;
    for (int i = 2; i <= n; ++i) {
        fact *= i;
    }
    return fact;
}

int main() {
    std::ifstream infile("taylor_input.txt");
    if (!infile) {
        std::cerr << "Error opening file.\n";
        return 1;
    }

    double x;
    int N;
    infile >> x >> N;

    std::vector<TaylorTerm> terms;
    double approximation = 0.0;

    for (int n = 0; n < N; ++n) {
        int order = 2 * n + 1;
        double coeff = pow(-1, n) / factorial(order);
        double value = coeff * pow(x, order);

        terms.push_back({order, coeff, value});
        approximation += value;

        print_taylor_term(n, order, coeff, value);
    }

    print_taylor_result("sin", x, N, approximation);

    return 0;
}

}
