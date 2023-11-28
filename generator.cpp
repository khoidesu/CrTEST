#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
const string NAME = "contest";

int correct_cnt = 0;
int wrong_cnt = 0;

const int NTEST = 10; 
const int N = 1e5 + 1;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

#define ___alisamikhailovna___ main
#define rand     rd
#define fi       first
#define se       second
#define pb       push_back
#define all(x)   x.begin(),x.end()
#define sz(x)    x.size()

typedef pair<int,int>     pii;
typedef vector<int>       vi;
typedef vector<pii>       vii;

long long Rand(long long l, long long h) {
    assert(l <= h);
    return abs((l + rd() * 1LL * rd() % (h - l + 1)));
}

bool RandAD(void) {
    long long l = 1;
    long long h = 1000;
    assert(l <= h);
    int tmp = abs((l + rd() * 1LL * rd() % (h - l + 1)));
    if (tmp > 1 && tmp < 500)
        return 0;
    return 1;
}

vi  random_array(int n,int L,int R) {   //random array of size n in range [L,R]
    vi  a(n);
    for(int i = 0 ; i < n ; ++i)
        a[i] = Rand(L,R);
    return  a;
}

vi  random_permutation(int n) {   //random permutation of size n
    vi  a(n);
    for(int i = 0 ; i < n ; ++i)
        a[i] = i + 1;
    random_shuffle(all(a));
    return  a;
}
vii random_tree(int n) {   //random tree with n vertices
    vi  x = random_permutation(n);
    vii E;
    for(int i = 2 ; i <= n ; ++i)
        E.pb(pii(i,Rand(1,i - 1)));
    for(int i = 0 ; i < n - 1 ; ++i)    {
        pii &e = E[i];
        e.fi = x[e.fi - 1];
        e.se = x[e.se - 1];
    }
    return  E;
}
vii random_graph(int n) {   //random graph with n vertices
    vii E = random_tree(n);
    map<pii,int> mp;
    for(int i = 0 ; i < n - 1 ; ++i)    {
        if(E[i].fi > E[i].se)
            swap(E[i].fi,E[i].se);
        mp[E[i]]++;
    }
    int m = min((n - 1) * (n - 2) / 2,N + N - 1 - n);
    while(m--)  {
        int x, y;
        while(1)    {
            y = Rand(1,n);
            x = Rand(1,y - 1);
            if(!mp.count(pii(x,y)))
                break;
        }
        E.pb(pii(x,y));
        mp[pii(x,y)]++;
    }
    random_shuffle(all(E));
    return  E;
}

___alisamikhailovna___()
{
    srand(time(NULL));
    for (int iTest = 1; iTest <= NTEST; iTest++)
    {
        ofstream inp((NAME + ".inp").c_str());
        /*---------------------input/*---------------------*/
        
        /*----------------------end.----------------------*/
        inp.close();

        auto TIME1 = chrono::steady_clock::now();
        system((NAME + ".exe").c_str());
        auto TIME2 = chrono::steady_clock::now();
        auto DIFF1 = TIME2 - TIME1;


        auto TIME3 = chrono::steady_clock::now();
        system((NAME + "_trau.exe").c_str());
        auto TIME4 = chrono::steady_clock::now();
        auto DIFF2 = TIME4 - TIME3;


        if (system(("fc " + NAME + ".out " + NAME + ".ans").c_str()) != 0)
        {
            cout << "Test " << iTest << ": Wrong Answer!";
            cout << "\t[normal: " << fixed << setprecision(3) << chrono::duration<double>(DIFF1).count() << "s,  ";
            cout << "trau: " << fixed << setprecision(3) << chrono::duration<double>(DIFF2).count() << "s]\n";
            wrong_cnt++;
            // return 0;
        }

        cout << "Test " << iTest << ": Accepted!";
        cout << "\t[normal: " << fixed << setprecision(3) << chrono::duration<double>(DIFF1).count() << "s,  ";
        cout << "trau: " << fixed << setprecision(3) << chrono::duration<double>(DIFF2).count() << "s]\n";
        correct_cnt++;
    }
    cout <<"----------------------\n";
    if (correct_cnt == NTEST)
        cout << "AC\n";
    else
        cout << "\nWrong Answer: " << wrong_cnt << '\n'; 
    return 0;
}