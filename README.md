<!-- PROJECT LOGO -->
<br />

<!-- ABOUT THE PROJECT -->
# Trình sinh test, so code trâu và code optimize

Một số tính năng 

* Tạo input & output
* Chấm code trâu và code tối ưu
* So sánh thời gian chạy 2 code
* Đếm số lượng test sai, test đúng

### Built With

* CPP

<!-- USAGE EXAMPLES -->
## Cách sử dụng
Tải file: [generator.cpp](https://github.com/khoidesu/CreateTestForCP/blob/9229f9b628e26570cf84a33c278f584eb5efc152/generator.cpp)

Tạo thư mục sinh test

```
sinhtest/
```


copy ```generator.cpp``` và tạo ra *5 file*:
```
Task.cpp
Task_trau.cpp
Task.inp
Task.out
Task.ans
```

* Lần lượt dán code optimize và code trâu vào các file đã tạo, chạy để lưu ra file ```.exe```
* Chạy file ```generator.cpp``` để bắt đầu chấm

<!-- Chương trình mẫu -->
## Chương trình mẫu
Example: Cho đề bài đơn giản là tìm LIS của mảng a

Code trâu:
```cpp
#include <bits/stdc++.h>
#define name "Task"
#define int long long
using namespace std;
const int maxn = 1e5;
int a[maxn];
int getbit(int x, int k)
{
    return ((x >> k) & 1);
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen(name ".inp", "r", stdin);
    freopen(name ".out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
            cout << getbit(i, j);
        cout << endl;
    }
    return 0;
}
```
Code bằng dp:
```cpp
#include <bits/stdc++.h>
#define name "Task"
#define int long long
using namespace std;
const int maxn = 1e5;
int a[maxn], f[maxn];
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen(name ".inp", "r", stdin);
    freopen(name ".out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        f[i] = 1;
        for (int j = 1; j < i; j++)
            if (a[j] <= a[i])
                f[i] = max(f[i], f[j] + 1);
    }
    cout << *max_element(f + 1, f + n + 1);
    return 0;
}
```

* B1: paste code trâu vào file ```Task_trau.cpp``` và đổi đuôi ```.out``` thành ```.ans```, nhấn *chạy* để tạo file ```_trau.exe```
* B2: paste code optimize (cần so sánh) vào file ```Task.cpp``` và nhấn *chạy* để tạo file ```.exe```
* B3: Tạo test mẫu (đã có các dạng input đơn giản:
  * tạo một số nguyên bất kì
  * tạo mảng một chiều bất kì có n phần tử và các phần tử trong đoạn [l..r]
  * tạo ngẫu nhiên 1 hoán vị [1..n]
  * tạo một cây có n đỉnh và m cạnh bất kì
  * tạo một đồ thị bất kì
* B4: chạy ```generator.cpp``` và uống một cốc trà xem AC☕
**Chú ý: **
  * Các dạng in ra trong phần
  ```
  /*---------------------input-----------------------*/
  
  /*----------------------end.----------------------*/
  ``` 
  đều phải viết dạng ```inp <<``` không được ghi dạng ```cout <<``` vì cout sẽ chạy trong terminal
  * Có thể thay đổi số lượng test trong ```const int NTEST = ```*soluongtest*```;```

Hình ảnh tham khảo:

![test](https://github.com/khoidesu/CreateTestForCP/blob/main/screenshot_test.png?raw=true)

<!-- CONTRIBUTING -->
## Tài liệu tham khảo 
**VNOI**: https://vnoi.info/wiki/algo/skill/viet-trinh-cham.md


<!-- CONTACT -->
## Contact

Name - khoidesu - khoicoder1@gmail.com
