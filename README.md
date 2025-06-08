# BOJ-Solutions
## About
> Do it! 알고리즘 코딩 테스트 C++ 편

[![Solved.ac프로필](http://mazassumnida.wtf/api/v2/generate_badge?boj=04smailing)](https://solved.ac/04smailing)  
<br>
<br>

## Solving Memo
```cpp
// 화면 출력 속도 향상
ios::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
```

```cpp
// 문자열 형 변환
#include <string>
string snum = "1234";
string snum_d = "1234.56";
int inum = stoi(snum);
long lnum = stol(snum);
double dnum = stod(snum_d);
float fnum = stof(snum_d);

inum = 1234;
lnum = 1234;
dnum = 1234.56;
fnum = 1234.56f;
string sint = to_string(inum);
string slong = to_string(lnum);
string sdouble = to_string(dnum);
string sfloat = to_string(lnum);
```

```cpp
// 소수점 아래 출력
#include <iomanip>

double num = 3.141592;
cout << fixed << setprecision(3) << num << endl;
```

```cpp
// 자료형 최대값
#include <climits>
int num = INT_MAX;
```

### Search Algorithms
**DFS**
* **재귀함수**\스택으로 구현
* 사이클 탐색
<br>
<br>

**BFS**
* **큐**로 구현
* 최단 경로 탐색 보장 (간선에 가중치가 없을 때)
* 이분그래프 확인
<br>
<br>

### Graph
**Union-find**
* **배열**의 값을 각 인덱스 값으로 초기화 후 진행
<br>
<br>
* Union 연산: 두 노드를 동일한 대표 노드로 연결
* Find 연산: 해당 노드의 대표 노드 탐색 (재귀적으로 대표 노드의 값으로 변경)
<br>
<br>

**Topology Sort**
* 배열에 각 정점의 **진입 차수**(in-degree) 저장
* 진입 차수가 0인 정점부터 차례로 제거 (연결된 정점의 진입 차수 감소)
<br>
<br>

**Dijkstra**
* 그래프에서 시작 노드부터의 **최단 거리** 탐색
* 간선의 가중치가 모두 **양수**여야 가능
* 시간복잡도: O(ElogV)
<br>
<br>
1. 우선순위 큐(Min-heap)로 시작 노드로부터의 거리가 작은 순으로 정렬
2. 방문되지 않은 노드와의 거리를 최솟값으로 업데이트 후 큐에 삽입
<br>
<br>

**Bellman-ford-moore**
* 그래프에서 시작 노드부터의 **최단 거리** 탐색
* 간선의 가중치가 음수여도 가능
* 음수 사이클의 존재 여부 확인 가능
* 시간복잡도: O(VE)
<br>
<br>
1. 시작 노드를 제외하고 최단 거리를 최댓값(INT_MAX)으로 초기화
2. 모든 간선을 V-1번 확인하면서 최단 거리 업데이트
3. V-1번 이후 업데이트가 발생 시, 음수 사이클이 존재
<br>
<br>

**Floyd-warshall**
* 그래프에서 시작 노드부터의 **최단 거리** 탐색
* 간선의 가중치가 음수여도 가능
* 시간복잡도: O($V^3$)
<br>
<br>
1. 인접행렬 초기화 (자기 자신은 0으로, 그외는 최댓값으로)
2. 경유지 K에 대해 D[i][j] < D[i][k] + D[k][j]이면 최단 거리 업데이트
3. 자기자신이 0이 아닌 경우, 사이클 존재
<br>
<br>

**Minimum Spanning Tree**
* 그래프의 모든 노드를 연결하는 간선들의 가중치의 합을 최소화
<br>
<br>
1. 우선순위 큐(Min-heap)로 간선을 가중치가 작은 순으로 정렬
2. 유니온파인드를 이용해 간선의 두 정점이 같은 집합이 아닐 때만 연결
<br>
<br>

### Tree
**Segment Tree**
* 주어진 데이터의 구간 합/최소/최대 계산과 **데이터 업데이트**를 빠르게 수행
<br>
<br>

**Lowest Common Ancestor**
* 트리에서 임의의 두 노드가 부모 노드를 탐색할 때 처음 공통으로 만나는 부모 노드
* $2^K$씩 단계를 올라가면서 탐색
* P[K][N] = P[K-1][P[K-1][N]]의 점화식 이용  
<br>
<br>
