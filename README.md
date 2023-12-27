<!-- PROJECT LOGO -->
<br />

<!-- ABOUT THE PROJECT -->
# Trình sinh test, so code trâu và code optimize

Một số tính năng mới:

* Tạo folder nhăm chấm các trình chấm offine như **themis**
* Random xâu 
* Có thể sử dụng cin, cout trong hàm ```sinh test```
* Format lại terminal output trực quan hơn.

Một số tính năng cũ:

* Tạo input & output
* Chấm code trâu và code tối ưu
* So sánh thời gian chạy 2 code
* Đếm số lượng test sai, test đúng.

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

```Task.cpp```

```Task_trau.cpp```

```Task.inp```

```Task.out```

```Task.ans```

* Lần lượt dán code optimize và code trâu vào các file đã tạo, chạy để lưu ra file ```.exe```
* Chạy file ```generator.cpp``` để bắt đầu chấm

<!-- Chương trình mẫu -->
## Chương trình mẫu
### Dạng 1: So sánh code trâu và code cải tiến
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
bool check(vector<int> ve)
{
    for (int i = 1; i < ve.size(); i++)
    {
        if (ve[i] < ve[i - 1])
            return false;
    }
    return true;
}
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
    int res = 0;
    vector<int> tmp;
    for (int i = 1; i < (1 << n); i++)
    {
        tmp.clear();
        for (int j = 0; j < n; j++)
            if (getbit(i, j))
                tmp.push_back(a[j + 1]);
        if (check(tmp))
            res = max(res, (int)tmp.size());
    }
    cout << res;
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

* B0: ở dòng **14** ```const int type =``` nhập 1 (mặc định là 1)
* B1: paste code trâu vào file ```Task_trau.cpp``` và đổi đuôi ```.out``` thành ```.ans```, nhấn *chạy* để tạo file ```_trau.exe```
* B2: paste code optimize (cần so sánh) vào file ```Task.cpp``` và nhấn *chạy* để tạo file ```.exe```
* B3: Tạo test mẫu (đã có các dạng input đơn giản:
  * tạo một số nguyên bất kì
  * tạo mảng một chiều bất kì có n phần tử và các phần tử trong đoạn [l..r]
  * tạo ngẫu nhiên 1 hoán vị [1..n]
  * tạo một cây có n đỉnh và m cạnh bất kì
  * tạo một đồ thị bất kì
  * tạo một chữ cái bất kì
* B4: chạy ```generator.cpp``` và uống một cốc trà xem AC☕

**Chú ý:**

  * Các dạng in ra trong phần
  ```cpp
  void SINHTEST(ofstream &cout) { //Trinh sinh test
  }
  ``` 

Hình ảnh tham khảo:

![test](https://github.com/khoidesu/CreateTestForCP/blob/42d88ec5fec3c08039c7a53402f4bcf953fd4027/github/test_type_1.gif)

### Dạng 2: Sinh test và đưa vào folder chấm themis
Việc sinh test và tạo folder nhét vô rất tốn thời gian, việc có một chương trình làm việc đó và tự động tạo test giải quyết được rất nhiều thời gian

Với ví dụ trên, ta thực hiện:

* B0: ở dòng **14** ```const int type =``` nhập 2
* B1:  B1: paste code trâu vào file ```Task_trau.cpp``` và đổi đuôi ```.out``` thành ```.ans```, nhấn *chạy* để tạo file ```_trau.exe```
* B2: đổi ```const string NAME = ``` thành tên bài của bạn (mặc định là "TASK")
* B3: tạo test như bình thường và thực hiện như trên
* B4: chạy ```generator.cpp```

Số lượng test tùy thuộc vào ```const int NTEST = 200``` như ở trên là 200 test

Folder mang tên mạng đặt sẽ nằm trong folder ```sinhtest/```

***Lưu ý:*** việc tạo test được dựa trên **code trâu** nên hãy đảm bảo code trâu bạn đúng :D

Hình ảnh tham khảo:

![test](https://github.com/khoidesu/CreateTestForCP/blob/42d88ec5fec3c08039c7a53402f4bcf953fd4027/github/test_type_2.png)


<!-- CONTRIBUTING -->
## Tài liệu tham khảo 
**VNOI**: https://vnoi.info/wiki/algo/skill/viet-trinh-cham.md


<!-- CONTACT -->
## Contact

Name - khoidesu - khoicoder1@gmail.com
