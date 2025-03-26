while True:
    try:
        n = int(input("숫자를 입력하세요: "))
        if n <= 0:
            print("다시 입력해주세요.")
        else:
            a = ' * '
            for i in range(1, n + 1):
                print(a * i)
            break 
    except ValueError:
        print("다시 입력해주세요.")
