# BOJ-Solutions

<br>

## About

[![Solved.ac프로필](http://mazassumnida.wtf/api/v2/generate_badge?boj=04smailing)](https://solved.ac/04smailing)  
<br>
<br>

## Solving Memo

### 반올림

```cpp
#include <iomanip>
#include <cmath>

/* 중략 */

double ratio = 3.14;

// 소수점 아래 두자리 수에서 반올림
round(ratio * 10) / 10;
cout << << std::fixed << std::setprecision(1) << ratio << "%" << endl;
```
