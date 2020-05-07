#include <iostream>
#include <vector>
#include <set>

using namespace std;

/** task 1 */
double area(double a) {
    if (a < 0) throw exception("a must be positive"); // "a must be positive";
    return 6 * a * a;
}

//double area(double a, double b) {
//    // todo: implement
//}
//
//double area(double a, double b, double c) {
//    // todo: implement
//}

/** task 2 */
int doubleFactorial(unsigned const int n) {
    if (n <= 1) return 1;
    if (n == 2) return 2;
    return doubleFactorial(n - 2) * n;
}

int doubleFactorialLoop(unsigned const int n) {
    int res = n;
//    if (n % 2 == 0) {
//        for (int i = 2; i <= n; i+=2) {
//            res *= i;
//        }
//    } else {
//        for (int i = 1; i <= n; i+=2) {
//            res *= i;
//        }
//    }
    for (int i = n % 2 + 2; i < n; i+=2) {
        res *= i;
    }

    return res;
}

/** task 3 */
double f(double x, double y) {
    return y * y + 1;
}

double solveApproximateCauchy(double (*pFunc)(double, double), int iter) {
    double h = 1.0 / iter;
    double x = 0;
    double y = 0;

    for (int i = 1; i <= iter; ++i) {
        x += h;
        y += h * pFunc(x, y);
    }

    return y;
}

/** task 4 */
vector<string> unique_names(const vector<string> &names1, const vector<string> &names2) {
    set<string> set;
    for (const auto &item : names1) {
        set.insert(item);
    }
    for (const auto &item2 : names2) {
        set.insert(item2);
    }
    vector<string> res;
    res.assign(set.begin(), set.end());
    return res;
}

int main() {
    setlocale(LC_ALL, "Russian.UTF-8");
    // task 1
    double edge = -3, edge1, edge2, edge3;
    double base, height;
    try {
        cout << "Площадь поверхности куба по ребру (" << edge << ") = " << area(edge) << endl;
    } catch (exception &ex) {
        cout << ex.what() << endl;
    }
//    cout << "Правильной четырехугольной призмы по стороне основания и высоте (" << base << ", " << height << ") = "
//         << area() << endl;
//    cout << "Прямоугольного параллелепипеда по трем ребрам (" << edge1 << ", " << edge2 << ", " << edge3 << ") = "
//         << area() << endl;
    cout << endl;

    // task 2
    cout << "0!! = " << doubleFactorial(0) << endl; //  384
    cout << "1!! = " << doubleFactorial(1) << endl; //  945
    cout << "2!! = " << doubleFactorial(2) << endl; //  945
    cout << "8!! = " << doubleFactorial(8) << endl; //  384
    cout << "9!! = " << doubleFactorial(9) << endl; //  945
    cout << endl;
    cout << "0!! = " << doubleFactorialLoop(0) << endl; //  384
    cout << "1!! = " << doubleFactorialLoop(1) << endl; //  945
    cout << "2!! = " << doubleFactorialLoop(2) << endl; //  945
    cout << "8!! = " << doubleFactorialLoop(8) << endl; //  384
    cout << "9!! = " << doubleFactorialLoop(9) << endl; //  945
    cout << endl;

    // task 3
    cout << "Решение задачи Коши для функции f(x, y) = y^2 + 1 => " << solveApproximateCauchy(f, 100) << endl;
    cout << tan(1);
    cout << endl;

    // task 4
    vector<string> names1 = {"Ava", "Emma", "Olivia"};
    vector<string> names2 = {"Olivia", "Sophia", "Emma", "Stuart"};

    vector<string> result = unique_names(names1, names2);
    for (const auto &element : result) {
        cout << element << ' '; // should print Ava Emma Olivia Sophia Stuart
    }
    cout << endl;
}