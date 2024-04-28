//#include <iostream>
//#include <cmath>
//
//double function(double x) {
//    if (x <= 0) {
//        return -0.5 * x;
//    }
//    else if (0 < x && x <= 2) {
//        return -sqrt(4 - x * x) + 2;
//    }
//    else if (2 < x && x <= 4) {
//        return sqrt(4 - pow(x - 2, 2));
//    }
//    else if (4 < x && x <= 6) {
//        return -(1 / 2.0) * x + 2;
//    }
//    else {
//        return NAN; // Для значений x вне заданных интервалов нет определения функции
//    }
//}
//
//void generateTable(double start_x, double end_x, double step) {
//    std::cout << "X\t| f(X)" << std::endl;
//    std::cout << "------------------" << std::endl;
//    double x = start_x;
//    while (x <= end_x) {
//        double y = function(x);
//        if (!std::isnan(y)) {
//            printf("%.2f\t| %.2f\n", x, y);
//        }
//        x += step;
//    }
//}
//
//int main() {
//    // Задание интервала и шага
//    double start_x = -4;
//    double end_x = 6;
//    double step = 1;
//
//    // Генерация таблицы
//    generateTable(start_x, end_x, step);
//
//    return 0;
//}