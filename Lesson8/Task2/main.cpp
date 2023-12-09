#include <iostream>

class Fraction
{
public:
	int get_numerator() { return numerator_; };
	int get_denominator() { return denominator_; };
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

	Fraction operator+(const Fraction& fr) {
		int numer = numerator_ * fr.denominator_ + fr.numerator_ * denominator_;
		int denom = denominator_ * fr.denominator_;
		return { numer, denom };
	}

	Fraction operator-(const Fraction& fr) {
		int numer = numerator_ * fr.denominator_ - fr.numerator_ * denominator_;
		int denom = denominator_ * fr.denominator_;
		return { numer, denom };
	}

	Fraction operator*(const Fraction& fr) {
		return { numerator_ * fr.numerator_, denominator_ * fr.denominator_ };
	}

	Fraction operator/(const Fraction& fr) {
		return { numerator_ * fr.denominator_, denominator_ * fr.numerator_};
	}

	Fraction operator-() {
		return { -numerator_, denominator_ };
	}

	const Fraction& operator++() {
		numerator_ += denominator_;
		return *this;
	}

	const Fraction& operator++(int) {
		numerator_ += denominator_;
		return *this;
	}

	const Fraction& operator--() {
		numerator_ -= denominator_;
		return *this;
	}

	const Fraction& operator--(int) {
		numerator_ -= denominator_;
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& left, const Fraction& right);
};

std::ostream& operator<<(std::ostream& left, const Fraction& right) {
	left << right.numerator_ << "/" << right.denominator_;
	return left;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int numer = 0;
	int denom = 0;

	std::cout << "¬ведите числитель дроби 1: ";
	std::cin >> numer;
	std::cout << "¬ведите знаменатель дроби 1: ";
	std::cin >> denom;
	Fraction f1(numer, denom);
	std::cout << "¬ведите числитель дроби 2: ";
	std::cin >> numer;
	std::cout << "¬ведите знаменатель дроби 2: ";
	std::cin >> denom;
	Fraction f2(numer, denom);
	std::cout << f1 << " + " << f2 << " = " << (f1 + f2) << std::endl;
	std::cout << f1 << " - " << f2 << " = " << (f1 - f2) << std::endl;
	std::cout << f1 << " * " << f2 << " = " << (f1 * f2) << std::endl;
	std::cout << f1 << " / " << f2 << " = " << (f1 / f2) << std::endl;
	std::cout << "++" << ++f1 << " * " << f2 << " = " << (f1 * f2) << std::endl;
	return 0;
}