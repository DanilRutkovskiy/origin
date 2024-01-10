#include <iostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}

	bool operator==(const Fraction& fr) {
		if ((numerator_/denominator_) == (fr.numerator_ / fr.denominator_)) 
			return true;
		else
			return false;
	}

	bool operator!=(const Fraction& fr) {
		return !(*this == fr);
	}

	bool operator<(const Fraction& fr) {
		return (numerator_ / denominator_) < (fr.numerator_ / fr.denominator_);
	}

	bool operator>(const Fraction& fr) {
		return (numerator_ / denominator_) > (fr.numerator_ / fr.denominator_);
	}

	bool operator<=(const Fraction& fr) {
		return (numerator_ / denominator_) <= (fr.numerator_ / fr.denominator_);
	}

	bool operator>=(const Fraction& fr) {
		return (numerator_ / denominator_) >= (fr.numerator_ / fr.denominator_);
	}
};

int main()
{
	Fraction f1(4, 3);
	Fraction f2(6, 11);

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	return 0;
}