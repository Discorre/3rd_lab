import numpy as np

# Функция для выполнения линейной аппроксимации с использованием метода наименьших квадратов.
def linear_approximation(x, y):
    n = len(x)
    x_sum = np.sum(x)
    y_sum = np.sum(y)
    x2_sum = np.sum(np.square(x))
    xy_sum = np.sum(np.multiply(x, y))

    a = (n * xy_sum - x_sum * y_sum) / (n * x2_sum - x_sum * x_sum)
    b = (y_sum - a * x_sum) / n

    return {'a': a, 'b': b}

# Функция для расчета коэффициента корреляции и t-статистики.
def correlation(x, y):
    if len(x) != len(y) or len(x) == 0:
        raise ValueError("Векторы должны иметь одинаковый размер и не быть пустыми.")

    x_mean = np.mean(x)
    y_mean = np.mean(y)
    sum_xy = np.sum((x - x_mean) * (y - y_mean))
    sum_x2 = np.sum(np.square(x - x_mean))
    sum_y2 = np.sum(np.square(y - y_mean))

    r = sum_xy / (np.sqrt(sum_x2) * np.sqrt(sum_y2))
    t = r * np.sqrt(len(x) - 2) / np.sqrt(1 - r * r)

    return {'correlation': r, 't_value': t}

# Функция для моделирования изменения температуры кофе со временем.
def coffee_temperature(T_initial, T_room, r_rate, time_limit):
    temperatures = []
    for t in range(time_limit + 1):
        temperature = T_room + (T_initial - T_room) * np.exp(-r_rate * t)
        temperatures.append(temperature)
    return temperatures

# Начальные данные
T_initial = 90  # Начальная температура кофе
T_room = 26  # Температура комнаты
r_rate = 0.01  # Коэффициент остывания
time_limit = 60  # Временной предел в минутах

# Моделирование изменения температуры кофе.
temperatures = coffee_temperature(T_initial, T_room, r_rate, time_limit)

# Вектор временных интервалов.
times = np.arange(time_limit + 1)

# Выполнение линейной аппроксимации.
approximation_result = linear_approximation(times, temperatures)

# Вычисление коэффициента корреляции и t-статистики.
correlation_result = correlation(times, temperatures)

# Вывод результатов аппроксимации и корреляции.
print("Результат аппроксимации:")
print("a:", approximation_result['a'], ", b:", approximation_result['b'])
print("\nРезультат корреляции:")
print("Корреляция:", correlation_result['correlation'])
print("Значение t:", correlation_result['t_value'])

# Вывод данных о температуре кофе со временем.
for i in range(len(temperatures)):
    print("Время -", times[i], ":", temperatures[i], "C")
