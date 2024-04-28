import math

def generate_table(start_x, end_x, step):
    print("X\t\t| f(X)")
    print("------------------")
    x = start_x
    while x <= end_x:
        y = function(x)
        if not math.isnan(y):
            print("{:.2f}\t| {:.2f}".format(x, y))
        x += step

def function(x):
    if x <= 0:
        return -0.5 * x
    elif 0 < x <= 2:
        return -math.sqrt(4 - x * x) + 2
    elif 2 < x <= 4:
        return math.sqrt(4 - (x - 2) ** 2)
    elif 4 < x <= 6:
        return -(1 / 2.0) * x + 2
    else:
        return float("nan")

if __name__ == "__main__":
    start_x = -4
    end_x = 6
    step = 1
    generate_table(start_x, end_x, step)
