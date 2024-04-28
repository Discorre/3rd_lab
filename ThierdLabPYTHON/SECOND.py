import random
import math

def resheto(n):
    all = [i for i in range(2, n+1)]
    i = 0
    while i < len(all):
        b = all[:i+1]
        b += [all[z] for z in range(i+1, len(all)) if all[z] % all[i] != 0]
        all = b
        i += 1
    return all

def rn(a, n):
    return random.randint(a, n)

def rn2GOST(a, b):
    randomNumber = round(random.uniform(a, b), 1)
    return randomNumber

def test_miller(n, c, t):
    n1 = n - 1
    delit = []
    for i in range(len(c)):
        if n1 == 0 or c[i] > n1:
            break
        if n1 % c[i] == 0:
            delit.append(c[i])
            while n1 % c[i] == 0 and n1 != 0:
                n1 = n1 // c[i]
    a = []
    while len(a) != t:
        ai = random.randint(2, n)
        if ai not in a:
            a.append(ai)
    for ai in a:
        res = ai % n
        for _ in range(2, n):
            res *= ai
            res = res % n
        if res != 1:
            return " - составное число", 0

    for d in delit:
        flag = True
        for ai in a:
            res = ai % n
            for _ in range(2, (n - 1) // d + 1):
                res = ai * res
                res = res % n
            if res != 1:
                flag = False
                break
        if flag:
            return " - вероятно, составное число", 0
    return " - простое число", 1

def test_pokling(n, delit, t):
    a = []
    while len(a) != t:
        ai = rn(2, n - 1)
        if ai not in a:
            a.append(ai)
    for i in range(len(a)):
        res = a[i] % n
        for j in range(2, n):
            res = (res * a[i]) % n
        if res != 1:
            return (" - составное число", 0)
    n32 = n - 1
    for j in range(len(a)):
        flag = True
        for i in range(len(delit)):
            res2 = a[j] % n
            prom = n32 / delit[i]
            for d in range(2, int(prom) + 1):
                res2 = (res2 * a[j]) % n
            if res2 == 1:
                flag = False
                break
        if flag:
            return (" - простое число", 1)
    return (" - вероятно, составное число", 0)

def build_new_from_old(q, bit):
    while True:
        zakaruchka = rn2GOST(0, 1)
        n = pow(2, bit - 1) / q + (pow(2, bit - 1) * zakaruchka) / q
        if int(n) % 2 == 1:
            n += 1
        u = 0
        while True:
            flag1 = False
            flag2 = False
            p = int((n + u) * q) + 1
            if p > pow(2, bit):
                break
            res = 2 % int(p)
            for i in range(2, int(p)):
                res *= 2
                res = res % int(p)
            if res == 1:
                flag1 = True

            res = 2 % int(p)
            for i in range(2, int(n + u + 1)):
                res *= 2
                res = res % int(p)
            if res != 1:
                flag2 = True
            if flag1 and flag2:
                return int(p)
            u += 2
def build_pokling(bit, c, t):
    max = 0
    glim = 0
    oleg = ""

    while True:
        f = True
        geted = []
        delit = []

        while f and len(geted) < 1:
            z = 1
            for i in range(len(c)):
                delitt = []
                if c[i] > pow(2, bit // 2 + 1) - 1:
                    break
                for max in range(1, c[i]):
                    if pow(c[i], max) > pow(2, bit // 2 + 1):
                        break
                max += 1
                rpow = rn(1, max - 1)
                rnum = rn(0, rpow)
                z *= pow(c[i], rnum)
                if z > pow(2, bit // 2 + 1) - 1:
                    z //= pow(c[i], rnum)
                    if z >= pow(2, bit // 2):
                        if z not in geted:
                            geted.append(z)
                        z = 1
                        f = False
                        delit = delitt
                else:
                    if rnum != 0:
                        delitt.append(c[i])

        n = rn(pow(2, bit // 2 - 1), pow(2, bit // 2) - 1)
        n = n * geted[0]
        n += 1
        resultat = test_pokling(n, delit, t)
        if resultat[1] == 0:
            result_ver = test_pokling(n, c, 1)
            if result_ver[1] == 1:
                glim += 1
        else:
            result_ver = test_pokling(n, c, 1)
            if result_ver[1] == 1:
                oleg = '+'
            else:
                oleg = '-'
        if resultat[1] == 1:
            return (oleg, n, glim)

def build_miller(bit, c, t):
    while True:
        glim = 0
        z = 1
        f = True
        geted = []
        while f and len(geted) < 1:
            z = 1
            for i in range(len(c)):
                if c[i] > pow(2, bit - 1) - 1:
                    break
                max_val = int(math.log(pow(2, bit - 1), c[i]))
                rpow = random.randint(1, max_val)
                rnum = random.randint(0, rpow)
                z *= pow(c[i], rnum)
                if z > pow(2, bit - 1) - 1:
                    z //= pow(c[i], rnum)
                    if z >= pow(2, bit - 2):
                        if z not in geted:
                            geted.append(z)
                        z = 1
                        f = False
        m = random.choice(geted)
        n = 2 * m - 1
        resultat = test_miller(n, c, t)
        oleg = ''
        if resultat[1] == 1:
            res = test_miller(n, c, 1)
            if res[1] == 0:
                oleg = '-'
            else:
                oleg = "+"
        else:
            res = test_miller(n, c, 1)
            if res[1] == 1:
                glim += 1
        if resultat[1] == 1:
            return oleg, n, glim

def main():
    bit = int(input("Введите количество бит: "))
    c = resheto(500)
    pokling_res = []
    pokling_res_p = []
    test_pokling(13, [2], 10)
    while len(pokling_res_p) != 10:
        pokling_result = build_pokling(bit, c, 10)
        p = pokling_result[1]
        if p not in pokling_res_p:
            pokling_res_p.append(p)
            pokling_res.append(pokling_result)
    print("POKLINGTON")
    print("+", end="")
    for _ in range(10):
        print("--------+", end="")
    print("\n|", end="")
    for i in range(10):
        print(f"{i + 1:8}|", end="")
    print("\n+", end="")
    for _ in range(10):
        print("--------+", end="")
    print("\n|", end="")
    for i in range(10):
        print(f"{pokling_res[i][1]:8}|", end="")
    print("\n+", end="")
    for _ in range(10):
        print("--------+", end="")
    print("\n|", end="")
    for i in range(10):
        print(f"       {pokling_res[i][0]}|", end="")
    print("\n+", end="")
    for _ in range(10):
        print("--------+", end="")
    print("\n|", end="")
    for i in range(10):
        print(f"{pokling_res[i][2]:8}|", end="")
    print("\n+", end="")
    for _ in range(10):
        print("--------+", end="")
    print("\n")

    miller_res = []
    miller_res_p = []
    while len(miller_res) != 10:
        miller_result = build_miller(bit, c, 10)
        p = miller_result[1]
        if p not in miller_res_p:
            miller_res_p.append(p)
            miller_res.append(miller_result)
    print("MILLER")
    print("+", end="")
    for _ in range(10):
        print("--------+", end="")
    print("\n|", end="")
    for i in range(10):
        print(f"{i + 1:8}|", end="")
    print("\n+", end="")
    for _ in range(10):
        print("--------+", end="")
    print("\n|", end="")
    for i in range(10):
        print(f"{miller_res[i][1]:8}|", end="")
    print("\n+", end="")
    for _ in range(10):
        print("--------+", end="")
    print("\n|", end="")
    for i in range(10):
        print(f"       {miller_res[i][0]}|", end="")
    print("\n+", end="")
    for _ in range(10):
        print("--------+", end="")
    print("\n|", end="")
    for i in range(10):
        print(f"{miller_res[i][2]:8}|", end="")
    print("\n+", end="")
    for _ in range(10):
        print("--------+", end="")
    print("\n\nGOSTR")

    print("+", end="")
    for _ in range(10):
        print("--------+", end="")
    print()

    print("|", end="")
    for i in range(10):
        print(f"{i + 1:8}|", end="")
    print()

    print("+", end="")
    for _ in range(10):
        print("--------+", end="")
    print()

    print("|", end="")
    rand = random.randint(0, (len(c) - 10) // 10) * 10
    for i in range(10):
        print(f"{build_new_from_old(c[rand + i], bit):8}|", end="")
    print()

    print("+", end="")
    for _ in range(10):
        print("--------+", end="")
    print()

if __name__ == "__main__":
    main()