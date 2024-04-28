//#include <iostream> // Подключение библиотеки для ввода/вывода через консоль.
//#include <vector> // Подключение библиотеки для использования векторов.
//#include <numeric> // Подключение библиотеки для выполнения численных операций с последовательностями.
//#include <cmath> // Подключение библиотеки для математических операций.
//#include <stdexcept> // Подключение библиотеки для обработки исключений.
//
//using namespace std;// Использование стандартного пространства имен.
//
//// Структура для хранения коэффициентов линейной аппроксимации.
//struct ApproximationResult {
//    double a; // Коэффициент наклона прямой.
//    double b; // Свободный член уравнения прямой.
//};
//
//// Структура для хранения коэффициентов корреляции.
//struct CorrelationResult {
//    double correlation; // Коэффициент корреляции.
//    double t_value; // Значение t-статистики.
//};
//
//// Функция для выполнения линейной аппроксимации по методу наименьших квадратов.
//ApproximationResult aproks(const vector<double>& x, const vector<double>& y);
//
//// Функция для расчета коэффициента корреляции и t-статистики.
//CorrelationResult korrel(const vector<double>& x, const vector<double>& y);
//
//// Функция для моделирования изменения температуры кофе со временем.
//vector<double> coffee(double T, double Ts, double r, int time);
//
//// Функция для вывода данных о температуре кофе со временем.
//void printCoffee(vector<double> temperatures, vector<double>times);
//
//// Функции для вывода результатов аппроксимации и корреляции.
//void printApproximationResult(ApproximationResult result);
//void printCorrelationResult(CorrelationResult result);
//
//int main() {
//    double T = 88; // Начальная температура кофе
//    double Ts = 26; // Температура комнаты
//    double r = 0.1; // Коэффициент остывания
//    int time = 60; // Временной предел в минутах
//
//    vector<double> temperatures = coffee(T, Ts, r, time); // Моделирование изменения температуры кофе.
//
//    vector<double> times(time + 1);// Вектор временных интервалов.
//    iota(times.begin(), times.end(), 0);// Заполнение временных интервалов от 0 до time.
//
//    ApproximationResult approx_result = aproks(times, temperatures);// Выполнение линейной аппроксимации.
//    CorrelationResult corr_result = korrel(times, temperatures);// Вычисление коэффициента корреляции и t-статистики.
//
//    printApproximationResult(approx_result);// Вывод результатов аппроксимации.
//    printCorrelationResult(corr_result);// Вывод результатов корреляции.
//    printCoffee(temperatures, times);// Вывод данных о температуре кофе со временем.
//
//    return 0;
//}
//
//// Реализация функции для выполнения линейной аппроксимации по методу наименьших квадратов.
//ApproximationResult aproks(const vector<double>& x, const vector<double>& y) {
//    double x_sum = accumulate(x.begin(), x.end(), 0.0);// Сумма значений из вектора x.
//    double y_sum = accumulate(y.begin(), y.end(), 0.0);// Сумма значений из вектора y.
//    double x2_sum = inner_product(x.begin(), x.end(), x.begin(), 0.0);// Сумма квадратов значений из вектора x.
//    double xy_sum = inner_product(x.begin(), x.end(), y.begin(), 0.0);// Сумма произведений значений из векторов x и y.
//    size_t n = x.size();// Количество элементов в векторе x.
//
//    double a = (n * xy_sum - x_sum * y_sum) / (n * x2_sum - x_sum * x_sum);// Вычисление коэффициента наклона прямой.
//    double b = (y_sum - a * x_sum) / n;// Вычисление свободного члена уравнения прямой.
//
//    return { a, b };// Возвращение результатов аппроксимации.
//}
//
//// Функция для вычисления среднего значения элементов вектора.
//// Принимает вектор вещественных чисел в качестве аргумента.
//// Возвращает среднее значение элементов вектора.
//double mean(const vector<double>& vec) {
//    // Используется стандартный алгоритм accumulate для суммирования всех элементов вектора.
//    // Начальное значение суммы задано как 0.0.
//    // Результат функции accumulate - сумма всех элементов вектора.
//    // Затем результат делится на количество элементов вектора (его размер) для получения среднего значения.
//    return accumulate(vec.begin(), vec.end(), 0.0) / vec.size();
//}
//
//// Реализация функции для расчета коэффициента корреляции и t-статистики.
//CorrelationResult korrel(const vector<double>& x, const vector<double>& y) {
//    if (x.size() != y.size() || x.empty()) {// Проверка на одинаковый размер и непустоту векторов.
//        throw invalid_argument("Vectors must be of the same size and not empty.");// Выброс исключения, если условие не выполняется.
//    }
//
//    double x_mean = mean(x); // Вычисление среднего значения вектора x.
//    double y_mean = mean(y);// Вычисление среднего значения вектора y.
//    double sum_xy = 0.0;// Инициализация переменной для суммы произведений (x_i - x_mean) * (y_i - y_mean).
//    double sum_x2 = 0.0;// Инициализация переменной для суммы квадратов (x_i - x_mean).
//    double sum_y2 = 0.0;// Инициализация переменной для суммы квадратов (y_i - y_mean).
//    size_t n = x.size();// Количество элементов в векторе x
//
//    for (size_t i = 0; i < n; ++i) {// Цикл по всем элементам векторов x и y.
//        sum_xy += (x[i] - x_mean) * (y[i] - y_mean);// Приращение суммы произведений.
//        sum_x2 += (x[i] - x_mean) * (x[i] - x_mean); // Приращение суммы квадратов для x.
//        sum_y2 += (y[i] - y_mean) * (y[i] - y_mean); // Приращение суммы квадратов для y.
//    }
//
//    double r = sum_xy / (sqrt(sum_x2) * sqrt(sum_y2));// Вычисление коэффициента корреляции.
//    double t = r * sqrt(n - 2) / sqrt(1 - r * r);// Вычисление коэффициента корреляции.
//
//    return { r, t };// Возвращение результатов корреляции.
//}
//// Реализация функции для моделирования изменения температуры кофе со временем.
//vector<double> coffee(double T, double Ts, double r, int time) {
//    vector<double> temperatures;// Инициализация вектора для хранения температур.
//
//    for (int t = 0; t <= time; t++) {// Цикл по всем временным интервалам от 0 до time.
//        double temperature = Ts + (T - Ts) * exp(-r * t);// Вычисление температуры кофе в момент времени t.
//        temperatures.push_back(temperature);// Добавление температуры в вектор.
//    }
//
//    return temperatures;// Возвращение вектора температур.
//}
//
//// Реализация функции для вывода данных о температуре кофе со временем.
//void printApproximationResult(ApproximationResult result) {
//    cout << "Approximation Result:" << endl;// Цикл по всем элементам вектора температур.
//    cout << "a: " << result.a << ", b = " << result.b << endl; // Вывод времени и температуры кофе.
//}
//
//void printCorrelationResult(CorrelationResult result) {
//    cout << "Correlation Result:" << endl;
//    cout << "Correlation: " << result.correlation << endl;
//    cout << "T-value: " << result.t_value << endl;
//}
//
//void printCoffee(vector<double> temperatures, vector<double>times) {
//    for (int i = 0; i < temperatures.size(); i++) {
//        cout << "Time - " << times[i] << ":  " << temperatures[i] << " C" << endl;
//    }
//}
