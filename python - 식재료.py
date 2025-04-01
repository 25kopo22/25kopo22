def check_prime_num(x):
    try:
        if x == 1:
            return False
        if x == 2:
            return True

        if x < 1:
            raise ValueError

        for i in range(2, x):
            if x % i == 0:
                return False

        return True

    except Exception:
        return None

try:
    number = int(input('판별할 자연수를 입력하세요: '))
    result = check_prime_num(number)

    if result is None:
        print("잘못된 입력입니다.")
    else:
        print(result)

except ValueError:
    print("잘못된 입력입니다.")
