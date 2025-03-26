while True:
    try:
        n = int(input("1부터 9 사이의 숫자를 입력하세요: "))
        if n < 1 or n > 9:
            print("1부터 9 사이의 숫자를 입력해주세요.")
        else:
            count = 0
            star_distribution = [1, 3, 5]

            for i in range(3):
                stars = ''
                for j in range(star_distribution[i]):
                    if count < n:
                        stars += '*'
                        count += 1
                    else:
                        stars += ' '
                print(stars.center(5))
            break
    except ValueError:
        print("정수를 입력해주세요.")
