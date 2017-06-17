#pragma once

// RVO Example
class Rational
{
public :
	int m_numerator;
	int m_denominator;

	Rational(int numerator = 0, int denominator = 1)
	{
		m_numerator = numerator;
		m_denominator = denominator;
	}
	int numerator() const { return m_numerator;}
	int denominator() const { return m_denominator;}
};

// Rational c = *(a * b); <-- �̻�...
// & *�� ��ȯ�� ����..

/*const Rational* operator*(const Rational& lhs, const Rational& rhs)
{
...
}*/

/*const Rational& operator*(const Rational& lhs, const Rational& rhs)
{
...
}*/

// �����Ϸ��� ����ȭ�ϰ� �ϴ� ���
const Rational operator*(const Rational& lhs, const Rational& rhs)
{
	return Rational(lhs.numerator() * rhs.numerator(), lhs.denominator() * rhs.denominator());
}

// �� ���� ���
inline const Rational operator*(const Rational& lhs, const Rational& rhs)
{
	return Rational(lhs.numerator() * rhs.numerator(), lhs.denominator() * rhs.denominator());
}