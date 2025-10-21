#include <iostream>
#include <cstdint>
#include <cmath>

class Fraction
{
private:
	uint64_t num{};
	uint64_t denum{ 1 };
	bool neg{ };
	void  Simplify();
public:
	uint64_t getNum() const
	{
		return num;
	}

	uint64_t getDenum() const
	{
		return denum;
	}

	uint64_t getNeg() const
	{
		return neg;
	}

	Fraction setNum(uint64_t num)
	{
		this->num = num;
		return *this;
	}

	Fraction setDenum(uint64_t denum)
	{
		if (denum == 0)
		{
			throw std::logic_error("error, denum is 0");
		}
		this->denum = denum;
		return *this;
	}

	Fraction setNeg(bool neg)
	{
		this->neg = neg;
		return *this;
	}
	bool operator >(const Fraction& a)
	{
		return pow(-1, this->neg) * (this->num) * a.denum > pow(-1, this->neg) * a.num * (this->denum);
	}
	bool operator <(const Fraction& a)
	{
		return pow(-1, this->neg) * (this->num) * a.denum < pow(-1, this->neg) * a.num * (this->denum);
	}
	bool operator ==(const Fraction& a)
	{
		return pow(-1, this->neg) * (this->num) * a.denum == pow(-1, a.neg) * a.num * (this->denum);
	}
	Fraction operator + (Fraction& a)
	{
		if (this->neg + a.neg == 0)
		{
			this->num = (this->num) * a.denum + a.num * (this->denum);
		}
		else if ((this->num) * a.denum > a.num * (this->denum))
		{
			this->num = (this->num) * a.denum - a.num * (this->denum);
		}
		else
		{
			this->num = (this->denum) * a.num - a.denum * (this->num);
			this->neg = a.neg;
		}
		this->denum = (this->denum) * a.denum;
		return Fraction(*this) * (-a);
	}
	Fraction operator - (const Fraction& a)
	{
		uint64_t _num{};
		uint64_t _denum{ 1 };
		bool _neg{};
		if (this->neg + a.neg == 1)
		{
			_num = (this->num) * a.denum + a.num * (this->denum);
			_neg = this->neg;
		}
		else if ((this->num) * a.denum > a.num * (this->denum))
		{
			_num = (this->num) * a.denum - a.num * (this->denum);
			_neg = this->neg;
		}
		else
		{
			_num = (this->denum) * a.num - a.denum * (this->num);
			_neg = a.neg;
		}
		_denum = (this->denum) * a.denum;

		return Fraction(_num, _denum, _neg);
	}
	Fraction operator *(const Fraction& a)
	{
		bool _neg{};
		uint64_t _num{};
		uint64_t _denum{ 1 };

		_denum = this->denum * a.denum;
		_num = this->num * a.num;
		if (this->neg + a.neg == 1)
		{
			_neg = 1;
		}

		return Fraction(_num, _denum, _neg);
	}
	Fraction operator ~()
	{
		if (this->num == 0)
		{
			throw std::logic_error("can't reverse fraction, num is 0");
		}
		std::swap(this->num, this->denum);
		return Fraction(this->num, this->denum, this->neg);
	}
	Fraction operator /(Fraction& a)
	{
		uint64_t _num{};
		uint64_t _denum{ 1 };
		bool _neg{};

		_num = this->num * a.denum;
		_denum = this->denum * a.num;
		if (this->neg + a.neg == 1)
		{
			_neg = 1;
		}

		return (*this) * (~a);
	}
	Fraction operator -()
	{
		return Fraction(this->num, this->denum, !(this->neg));
	}
	Fraction operator +(int a)
	{
		return Fraction(this->num + (a * this->denum), this->denum, this->neg);
	}
	Fraction& operator ++()
	{

		return (*this) = (*this) + 1;
	}
	Fraction& operator ++(int)
	{
		Fraction temp = *this;
		++(*this);
		return temp;
	}
	Fraction operator -(int a)
	{
		return Fraction(this->num - (a * this->denum), this->denum, this->neg);
	}
	friend Fraction operator -(int a, const Fraction& b)
	{
		uint64_t new_num = a * b.denum - b.num;
		bool new_neg = false;
		if (new_num == 0) {
			new_neg = false;
		}
		else if (a * b.denum < b.num && b.neg == false) {
			new_neg = true;
			new_num = b.num - a * b.denum;
		}
		else
		{
			new_num = b.num + a * b.denum;
		}
		return Fraction(new_num, b.denum, new_neg);
	}
	Fraction& operator --()
	{
		return (*this) = (*this) - 1;
	}
	Fraction& operator --(int)
	{
		Fraction temp = *this;
		--(*this);
		return temp;
	}
	Fraction& operator += (Fraction& right)
	{
		return (*this) = *this + right;
		/*num = num + right.num + right.num * denum;
		denum *= right.denum;*/
	}
	//Fraction operator +(int& rhs)
	//{
	//	Fraction temp = *this;
	//	return temp += rhs;
	//}
	//friend Fraction& operator = (Fraction& rhs)
	//{
	//	if (this != &rhs)
	//	{
	//		num = rhs.num;
	//		denum = rhs.denum;
	//		neg = rhs.neg;
	//	}
	//	return *this;
	//}

	friend Fraction operator+(int& a, Fraction& b)
	{
		return b + a;
	}
	friend std::ostream& operator <<(std::ostream& out, const Fraction& a)
	{
		char _neg{};
		if (pow(-1, a.neg) == -1)
		{
			_neg = '-';
		}
		if (a.num % a.denum == 0)
		{
			uint64_t num = a.num / a.denum;
			if (num == 0)
			{
				out << num << '\n';

			}
			else
			{
				out << _neg << num << '\n';
			}
		}
		else if (a.num > a.denum)
		{
			uint64_t whole = a.num / a.denum;
			uint64_t rem = a.num % a.denum;
			out << _neg << whole << '+' << rem << '/' << a.denum << '\n';
		}
		else
		{
			out << _neg << a.num << "/" << a.denum << '\n';
		}
		return out;
	}
	operator std::string() const
	{
		std::string fraction;

		return fraction;
	}

	operator double() const
	{
		return static_cast<double>(this->num) / (this->denum) * (this->neg ? -1 : 1);
	}
	explicit Fraction(const double d)
	{
		this->num = int(d * 100);
		this->denum = 100;
	}

	Fraction()
	{
		std::cout << "input num\n";
		std::cin >> this->num;
		std::cout << "input denum\n";
		std::cin >> this->denum;
		std::cout << "input neg\n";
		std::cin >> this->neg;
		if (denum == 0)
		{
			throw std::logic_error("error, denum is 0\n");
		}
		std::cout << (*this) << "=";
		Simplify();
		std::cout << (*this);
	}
	Fraction(int num, int denum, bool neg)
	{
		if (denum == 0)
		{
			throw std::logic_error("error, denum is 0\n");
		}
		this->num = num;
		this->denum = denum;
		this->neg = neg;
		Simplify();
		std::cout << (*this);
	}

};

uint64_t gcd(uint64_t a, uint64_t b)
{
	if (b == 0)
	{
		return a;
	}
	return gcd(b, a % b);
}

void Fraction::Simplify()
{
	uint64_t c{ gcd(num,denum) };
	this->num /= c;
	this->denum /= c;
}

// Д/З вывод через std::string, перегрузки сравнения, перегрузка присваивания

int main() {
    Fraction a(2, 3, 1);
    Fraction b(1, 2, 0);
	//std::cout << a.getNum() << '\n';
	//std::cout << a.getDenum() << '\n';
	//std::cout << a.getNeg() << '\n';
	//a.setNum(5);
	//a.setDenum(5);
	//a.setNeg(0);
	//std::cout << a << '\n';
	//std::cout << (double)(a) << '\n';
	double d = b;
	//std::cout << d << '\n';
	//std::cout << d / b;
	Fraction s(0.134);
	std::cout << b / d << '\n';
    //Fraction sum = a + b;
	//Fraction s = 1 - a;
	//std::cout << s << '\n';

    //Fraction diff = a - b;
    //Fraction mult = a * b;
    //Fraction div = a / b;
    return 0;
}