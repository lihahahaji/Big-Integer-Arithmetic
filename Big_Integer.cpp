#include <iostream>
#include <string>
using namespace std;

// 加
string Addition(string a, string b)
{
    int m = a.size();
    int n = b.size();
    int carry = 0; // 进位
    string result = "";

    // 从低位到高位逐位相加
    for (int i = m - 1, j = n - 1; i >= 0 || j >= 0 || carry > 0; i--, j--)
    {
        int x = (i >= 0) ? (a[i] - '0') : 0;
        int y = (j >= 0) ? (b[j] - '0') : 0;
        int sum = x + y + carry;
        carry = sum / 10;
        result = to_string(sum % 10) + result;
    }

    return result;
}

// 减
string Subtraction(string a, string b)
{
    int m = a.size();
    int n = b.size();
    int borrow = 0; // 借位
    string result = "";

    // 从低位到高位逐位相减
    for (int i = m - 1, j = n - 1; i >= 0 || j >= 0; i--, j--)
    {
        int x = (i >= 0) ? (a[i] - '0') : 0;
        int y = (j >= 0) ? (b[j] - '0') : 0;
        int diff = x - y - borrow;
        if (diff < 0)
        {
            diff += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }
        result = to_string(diff) + result;
    }

    // 去掉结果中前导零
    int i = 0;
    while (i < result.size() && result[i] == '0')
    {
        i++;
    }
    return (i == result.size()) ? "0" : result.substr(i);
}

// 乘
string Multiplication(string a, string b)
{
    int m = a.size();
    int n = b.size();
    vector<int> result(m + n, 0);

    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            int mul = (a[i] - '0') * (b[j] - '0');
            int p1 = i + j;
            int p2 = i + j + 1;
            int sum = mul + result[p2];
            result[p1] += sum / 10;
            result[p2] = sum % 10;
        }
    }

    // 去掉结果中前导零
    int i = 0;
    while (i < m + n && result[i] == 0)
    {
        i++;
    }

    string res = "";
    for (; i < m + n; i++)
    {
        res.push_back(result[i] + '0');
    }

    return res.empty() ? "0" : res;
}

int main()
{
    string a = "12";
    string b = "13";
    cout << Addition(a, b) << endl;
    cout << Subtraction(a, b) << endl;
    cout << Multiplication(a, b) << endl;
}