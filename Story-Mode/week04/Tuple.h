#pragma once
class Tuple
{
public:
	Tuple();
	Tuple(const Tuple&);
	Tuple &operator=(const Tuple&);
	~Tuple();
	Tuple(int, int);
	const int getA() const;
	const int getB() const;
	void setA(const int);
	void setB(const int);
	void print() const;
	long sum() const;
	double average() const;
	void incrementBy(const Tuple &);
	void multiplyBy(const Tuple &);
	void operator+=(const Tuple&);
	void operator*=(const Tuple&);
	void operator*=(int);
private:
	int a;
	int b;
};