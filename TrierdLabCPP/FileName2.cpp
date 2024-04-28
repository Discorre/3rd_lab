//#include <iostream>
//#include <vector>
//#include <unordered_map>
//#include <cmath>
//#include <cstdlib>
//#include <ctime>
//#include <string>
//#include <iomanip>
//
//using namespace std;
//
//// Функция для проверки простоты числа методом Поклингтона
//bool lehmann_pocklington(int p, int R, int F, int t = 1) {
//    for (int i = 0; i < t; ++i) {
//        int a = rand() % (p - 2) + 2;
//        if ((a ^ ((p - 1) / 2) % p) != (R ^ ((p - 1) / 2) % p))
//            return false;
//        if ((a ^ (p - 1) % p) != 1)
//            return false;
//        int b = a^((p - 1) / 2) % p;
//        if (b != 1 && b != p - 1)
//            return false;
//        if ((F ^ ((p - 1) / 2) % p) != 1)
//            return false;
//    }
//    return true;
//}
//
//// Генерация таблицы для теста Поклингтона
//vector<vector<int>> lehmann_pocklington_table(const vector<int>& numbers, const vector<int>& R_values, const vector<int>& F_values, int t = 100) {
//    srand(time(nullptr));
//    vector<vector<int>> results;
//    for (int p : numbers) {
//        int errors = 0;
//        for (int i = 0; i < t; ++i) {
//            int R = R_values[rand() % R_values.size()];
//            int F = F_values[rand() % F_values.size()];
//            if (!lehmann_pocklington(p, R, F))
//                errors++;
//        }
//        int error_probability = static_cast<double>(errors) / t;
//        vector<int> row = { p, R_values[rand() % R_values.size()], error_probability };
//        results.push_back(row);
//    }
//    return results;
//}
//
//// Функция для разложения числа на простые множители с подсчетом повторяющихся множителей
//unordered_map<int, int> prime_factors(int n) {
//    unordered_map<int, int> factors_count;
//    while (n % 2 == 0) {
//        factors_count[2]++;
//        n /= 2;
//    }
//    for (int i = 3; i <= sqrt(n); i += 2) {
//        while (n % i == 0) {
//            factors_count[i]++;
//            n /= i;
//        }
//    }
//    if (n > 2)
//        factors_count[n]++;
//    return factors_count;
//}
//
//// Преобразование словаря множителей в строку
//string factors_to_string(const unordered_map<int, int>& factors) {
//    string factors_str;
//    for (const auto& factor : factors) {
//        if (factor.second > 1)
//            factors_str += to_string(factor.first) + "^" + to_string(factor.second) + " * ";
//        else
//            factors_str += to_string(factor.first) + " * ";
//    }
//    return factors_str.substr(0, factors_str.length() - 3);
//}
//
//int main() {
//    vector<int> pocklington_numbers = { 13, 29, 61, 97, 157, 173, 179, 353, 419, 461, 617, 821, 1069, 5953, 6121, 6197, 6373 };
//    vector<int> R_values = { 4, 7, 15, 12, 13, 43, 89, 22, 209, 23, 77, 41, 89, 93, 85, 1549, 177 };
//    vector<int> F_values = { 3, 4, 4, 8, 8, 4, 2, 16, 2, 20, 8, 20, 8, 20, 12, 64, 72, 4, 36 };
//    int iterations = 100;
//    auto pocklington_table = lehmann_pocklington_table(pocklington_numbers, R_values, F_values, iterations);
//    cout << "Lehmann-Pocklington Test Results:" << endl;
//    cout << "---------------------------------------------------------------------" << endl;
//    cout << setw(15) << left << "Простое число p" << setw(20) << left << "Разложение F" << setw(10) << left << "R" << setw(25) << left << "Вероятность ошибки" << endl;
//    cout << "---------------------------------------------------------------------" << endl;
//    for (const auto& row : pocklington_table) {
//        auto factors = prime_factors(row[0] - 1);
//        string factors_str = factors_to_string(factors);
//        cout << setw(15) << left << row[0] << setw(20) << left << factors_str << setw(10) << left << row[1] << setw(25) << left << row[2] << endl;
//    }
//    cout << "---------------------------------------------------------------------" << endl;
//    return 0;
//}
