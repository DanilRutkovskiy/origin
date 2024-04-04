#include <iostream>
#include <string>

class BigNumber {
public:
    BigNumber(std::string num);
    BigNumber(BigNumber&& num) noexcept;

public:
    BigNumber operator=(BigNumber&& num) noexcept;
    BigNumber operator+(const BigNumber& num);
    friend BigNumber operator*(int n1, const BigNumber& num);

private:
    std::string m_data;
};

BigNumber operator*(int n1, const BigNumber& num) {
    std::string ret;
    int ind = num.m_data.length() - 1;
    int to_add = 0;
    while (ind >= 0) {
        int res = static_cast<int>(num.m_data[ind] - '0');
        res = res * n1 + to_add;
        to_add = res / 10;

        ret.insert(ret.begin(), std::to_string(res % 10)[0]);
        --ind;
    }

    if(to_add > 0)
        ret.insert(ret.begin(), std::to_string(to_add)[0]);

    return { ret };
}

BigNumber operator*(const BigNumber& num, int n1) {
    return n1 * num;
}

int main()
{
    BigNumber n1{ "99999" };
    BigNumber n2{ "1" };
    BigNumber n3 = n1 + n2;

    n1 = n3 * 5;

    return 0;
}

BigNumber::BigNumber(std::string num) : m_data(num)
{
}

BigNumber::BigNumber(BigNumber&& num) noexcept
{
    this->m_data = std::move(num.m_data);
}

BigNumber BigNumber::operator=(BigNumber&& num) noexcept
{
    return std::move(num);
}

BigNumber BigNumber::operator+(const BigNumber& num)
{
    std::string str;
    int left_ind = this->m_data.length() - 1;
    int right_ind = num.m_data.length() - 1;
    bool plus = false;
    int left = 0; int right = 0;
    while (left_ind >= 0 || right_ind >= 0) {
        left = left_ind >= 0 ? static_cast<int>(this->m_data[left_ind] - '0') : 0;
        right = right_ind >= 0 ? static_cast<int>(num.m_data[right_ind] - '0') : 0;

        int res = left + right + (plus ? 1 : 0); plus = res >= 10;
        res = res % 10;
        str.insert(str.begin(), std::to_string(res)[0]);
        --left_ind; --right_ind;
    }

    if (plus)
        str.insert(str.begin(), '1');

    return { str };
}
