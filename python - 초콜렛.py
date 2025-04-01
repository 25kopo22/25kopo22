import numpy as np
data = np.loadtxt('chocolate_rating.csv', delimiter=',') #넘파이 배열로 로드
print('차원:', data.ndim) #배열의 차원 출력
print('모양:', data.shape) #형태의 배열 크기 출력
print('원소 수:', data.size) #데이터 개수 출력
print(data)

ratings_mean = data[:, 3].mean( ) #모든 행의 4번째 열만 서택해서 평균값 계산
print(ratings_mean)

high_level = data[data[:, 3] >= 4] #평점이 4점 이상인 초콜릿만 필터링
high_id = high_level[:, 0].astype(np.int64) #첫번째 열만 선택하고 정수형으로 변환
print('우수 초콜릿 수:', high_id.size) #개수 출력
print(high_id)

high_kakao = high_level[:, 2] #3번째열 선택
unique_values, value_counts = np.unique(high_kakao, return_counts = True) #중복 제거
print('카카오 함유량:', unique_values)
print('함유량별 빈도수:', value_counts)

max_index = np.argmax(value_counts) #가장 큰 값의 인덱스 찾기
print(unique_values[max_index]) #가장 많이 등장한 카카오 함유량 출력
print('우수 초콜릿', high_id.size, '가지 중', value_counts[max_index],\
'가지의 카카오 함유량이', unique_values[max_index] * 100, '%입니다.')
