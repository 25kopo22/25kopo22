n = int(input())
a = ' * '
if n <= 0:
  print('다시 입력해주세요.')
else:
  for i in range(1, n+1):
    print(a * i)
