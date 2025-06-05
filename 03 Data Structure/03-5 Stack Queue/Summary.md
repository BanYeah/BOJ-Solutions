스택(Stack)은 삽입과 삭제 연산이 후입선출(LIFO)로 이루어지는 자료구조.  
큐(Queue)는 삽입과 삭제 연산이 선입선출(FIFO)로 이루어지는 자료구조.  

스택은 ```<stack>```으로, 큐는 ```<queue>``` STL을 이용할 수 있다.
<br>
<br>

## 우선 순위 큐 사용법
```cpp
#include <queue>

priority_queue<int> pq; // 기본적으로 Max-heap
priority_queue<int, vector<int>, greater<int>> min_pq; // Min-heap
```
<br>

사용자 정의 구조체/클래스와 함께 사용하는 법
```cpp
class Point {
    public:
        int value;
        int index;

        bool operator<(const Point& other) const {
            return value < other.value; // x가 클수록 우선순위를 높게(Max-heap)
        }
};

priority_queue<Point> pq;
```

```cpp
class Point {
    public:
        int value; 
        int index;
};

class Compare {
    public:
        bool operator()(const Point& a, const Point& b) {
            return a.x > b.x;  // x가 작을수록 우선순위를 낮게 (min-heap)
        }
};

priority_queue<Point, vector<Point>, Compare> pq;
```