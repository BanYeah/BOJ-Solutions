## 벡터 사용법
```cpp
#include <vector>

vector<int> A;
vector<int> B(10, 0); // 10의 요소를 가지며, 0으로 초기화
vector<vector<int>> C(3, vector<int>(4, 0)); // 3 X 4 벡터를 0으로 초기화

// 삽입 연산
A.push_back(1);
A.insert(A.begin, 1);
A.insert(A.begin + 1, 1);

// 삭제 연산
A.pop_back();
A.erase(A.begin);
A.clear();

// 정보
A.size();
A.at(0);

// 정렬
#include <algorithm>
std::vector<int> v = {5, 2, 9, 1, 5, 6};
std::sort(v.begin(), v.end(), std::greater<int>()); // 내림차순 정렬


bool customCompare(int a, int b) {
    return a > b; // 내림차순 정렬
}
std::sort(v.begin(), v.end(), customCompare); // 비교 함수 이용
```