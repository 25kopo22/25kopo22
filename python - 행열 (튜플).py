while True:
    try:
        m = int(input('행을 입력하세요: '))
        n = int(input('열을 입력하세요: '))
        if m <= 0 or n <= 0:
            print("양의 정수를 입력하세요.")
            continue
        break
    except ValueError:
        print("정수를 입력하세요.")

for i in range(m):
    row = tuple(i + j + 1 for j in range(n))
    for num in row:
        print(num, end="")
    print()
