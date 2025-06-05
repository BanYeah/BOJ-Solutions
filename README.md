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