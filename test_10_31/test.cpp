#define _CRT_SECURE_NO_WARNINGS 1


                                高精度加法
#include<iostream>
#include<vector>
using namespace std;
vector<int> add(vector<int>& A, vector<int>& B)
{
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size() || i < B.size(); i++)
    {
        if (i < A.size())
            t += A[i];
        if (i < B.size())
            t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    if (t) C.push_back(1);
    return C;
}
int main()
{
    string a, b;
    vector<int> A, B;
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        A.push_back(a[i] - '0');
    }
    for (int i = b.size() - 1; i >= 0; i--)
    {
        B.push_back(b[i] - '0');
    }
    auto C = add(A, B);
    for (int i = C.size() - 1; i >= 0; i--)
    {
        cout << C[i];
    }
    return 0;
}

                                高精度减法


#include<iostream>
#include<vector>
using namespace std;
int cmp(vector<int>&A,vector<int>&B)
{
    if(A.size()>B.size())
    return 1;
    else if(A.size()<B.size())
    return 0;
    else
    {
        for(int i = A.size()-1;i>= 0;i--)
        {
            if(A[i] > B[i])
            return 1;
            if(A[i] < B[i])
            return 0;
        }
    }
    return 1;
}
vector<int> sub(vector<int>&A,vector<int>&B)
{
    vector<int>C;
    int t = 0;
    for(int i = 0;i < A.size();i++)
    {
        t = A[i] - t;
        if(i < B.size())
        t -= B[i];
        C.push_back((t+10)%10);
        if(t<0)
        t = 1;
        else
        t = 0;
    }
    while(C.size()>1&&C.back() == 0)
    C.pop_back();
    return C;
}
int main()
{
    string a,b;
    cin>>a>>b;
    vector<int>A,B;
    for(int i = a.size()-1;i>=0;i--)
    {
        A.push_back(a[i] - '0');
    }
    for(int i = b.size()-1;i>=0;i--)
    {
        B.push_back(b[i] - '0');
    }

    if(cmp(A,B))
    {
        auto C = sub(A,B);
        for(int i = C.size()-1;i>=0;i--)
        {
            cout<<C[i];
        }
    }
    else
    {
        auto C = sub(B,A);
        cout<<'-';
        for(int i = C.size()-1;i>=0;i--)
        {
            cout<<C[i];
        }
    }

    return 0;
}


                               高精度乘法
#include<iostream>
#include<vector>
using namespace std;
vector<int> mul(vector<int>& A,int b)
{
    vector<int>C;
    int t = 0;
    for(int i = 0; i < A.size();i++)
    {
        t += A[i]*b;
        C.push_back(t%10);
        t /= 10;
    }
    if(t)
    C.push_back(t);
    while(C.size()>1&&C.back()== 0)
    C.pop_back();
    return C;
}
int main()
{
    string a;
    int b;
    vector<int>A;
    cin>>a>>b;
    for(int i = a.size()-1;i>=0;i--)
    {
        A.push_back(a[i] - '0');
    }
    auto C = mul(A,b);
    for(int i = C.size()-1;i>=0;i--)
    {
        cout<<C[i];
    }
    return 0;
}


                                高精度除法

                                        #include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> div(vector<int> &A,int b,int& r)
{
    vector<int> C;
    int t= 0;
    for(int i = A.size()-1;i>=0;i--)
    {
        t = t*10+A[i];
        C.push_back(t / b);
        t %= b;
    }
    r = t;
    reverse(C.begin(),C.end());
    while(C.size()>1 && C.back() == 0)
    C.pop_back();
    return C;
}
int main()
{
    string a;
    int b;
    vector<int>A;
    cin>>a>>b;
    for(int i = a.size()-1;i>=0;i--)
    {
        A.push_back(a[i] - '0');
    }
    int r;
    auto C = div(A,b,r);
    for(int i = C.size()-1;i>=0;i--)
    {
        cout<<C[i];
    }
    cout<<endl<<r<<endl;
    return 0;
}