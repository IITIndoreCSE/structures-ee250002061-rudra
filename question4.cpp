#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

struct TaylorTerm {
    int order;
    double coeff;
    double value;
};

void print_taylor_term(int index, int order, double coeff, double value) {
    std::cout << "Term[" << index << "]: "
              << "order=" << order << ", "
              << "coeff=" << coeff << ", "
              << "value=" << value << "\n";
}

void print_taylor_result(const char* function_name, double x, int terms, double approximation) {
    std::cout << "Approximation of " << function_name
              << "(x) at x=" << x
              << " with " << terms << " terms: "
              << approximation << "\n";
}

double factorial(int n) {
    double result = 1.0;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    std::ifstream input("input.txt");
    if (!input) {
        std::cerr << "Error opening input file\n";
        return 1;
    }

    double x;
    int N;
    input >> x >> N;
    input.close();

    std::vector<TaylorTerm> terms(N);
    double approximation = 0.0;

    for (int n = 0; n < N; ++n) {
        int order = 2 * n + 1;
        double coeff = std::pow(-1, n) / factorial(order);
        double value = coeff * std::pow(x, order);

        terms[n] = {order, coeff, value};
        approximation += value;

        print_taylor_term(n, terms[n].order, terms[n].coeff, terms[n].value);
    }

    print_taylor_result("sin", x, N, approximation);

    return 0;
}
