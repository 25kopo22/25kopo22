while True:
  try:
    print('음료목록 1.오렌지주스(100원), 2.커피(200원), 3.콜라(300원)')

    coin = int(input('동전을 넣으세요.'))

    if coin <= 0:
      print('유효하지 않은 동전입니다.')
      continue

    drink = int(input('음료를 고르세요.\n'))

    tuple_1 = 1, 2, 3
    tuple_2 = 100, 200, 300

    if drink == tuple_1[0]:
    #오렌지주스 100원
      if coin >= tuple_2[0]:
          remain = coin - tuple_2[0]
          print('오렌지주스가 곧 제공됩니다.')
          print('거스름돈은 {}원입니다.'.format(remain))
      else:
          print('잔액이 부족합니다.')

    elif drink == tuple_1[1]:
    #커피 200원
      if coin >= tuple_2[1]:
        remain = coin - tuple_2[1]
        print('커피가 곧 제공됩니다.')
        print('거스름돈은 {}원입니다.'.format(remain))
      else:
        print('잔액이 부족합니다.')

    elif drink == tuple_1[2]:
    #콜라 300원
      if coin >= tuple_2[2]:
        remain = coin - tuple_2[2]
        print('콜라가 곧 제공됩니다.')
        print('거스름돈은 {}원입니다.'.format(remain))
      else:
        print('잔액이 부족합니다.')

    else:
    #없는 번호
     print('없는 메뉴입니다. 다시 입력해 주세요.')

  except ValueError:
        print("다시 입력해주세요.")
