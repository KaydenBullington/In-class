
//Fraction Definition
class Fraction {
	int num;
	int den;
public:
	Fraction() :num(1), den(1) {}//default const
	Fraction(int, int);//overloaded
	void setNum(int);
	void setDen(int);
	int getNum(void);
	int getDen(void);
	void setNumDen(int, int);
	friend std::ostream& operator <<(std::ostream& banana,const Fraction& f) {
		return banana << "[" << f.num << "/" << f.den << "]";
		
	}
};

//Fraction Implementation


Fraction::Fraction(int n, int d) {
	num = n;
	den = d;
}


void Fraction::setNumDen(int n, int d) {
	num = n;
	den = d;
}
void Fraction::setNum(int n) {
	num = n;
}

void Fraction::setDen(int d) {
	den = d;
}

int Fraction::getNum() {
	return num;
}

int Fraction::getDen() {
	return den;
}

