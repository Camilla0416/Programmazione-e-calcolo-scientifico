#pragma once
#include <numeric> /* serve per Euclide */
#include <concepts>
#include <iostream>

template<typename I> requires std::integral<I>
class rational
{
	I num_;
	I den_;
	
	/* Semplifico le frazioni */
	void simplify() {
		if (den_==0)
			return;
		/* nel caso den<0 voglio den>0 e diventa num<0 */
		if (den_<0) {
			num_ = -num_;
			den_ = -den_;
		}
		/* Algoritmo di Euclide: gcd(a,b)=gcd(b,a%b) finchè resto==0 */
		I g=std::gcd(num_,den_);
		/* escludo se ho num e/o den uguali a zero --> Inf e NaN */
		if (g!=0) {
			num_=num_/g;
			den_=den_/g;
		}
	}	
public:
	/* Costruttore di default */
	rational()
		: num_(I{0}), den_(I{1})
	{}
	
	/* Costruttore user-defined */
	rational(const I& pnum, const I& pden)
		:num_(pnum), den_(pden) {
		/* Casi in cui devo semplificare */
		if (den_!=0) {
			simplify();
		}
	}
	
	/* Casi: NaN,+Inf,-Inf,0 */
	/* 0/0=NaN */
	bool is_nan() const {
		if (den_==0) {
			if (num_==0) {
				return true;
			} else {
				return false;
			}
		} else {
			return false;
		}
	}
	/* +num/0=+Inf */
	bool is_pos_inf() const {
		if (den_==0) {
			if (num_>0) {
				return true;
			} else {
				return false;
			}
		} else {
			return false;
		}
	}
	/* -num/0=-Inf */
	bool is_neg_inf() const {
		if (den_==0) {
			if (num_<0) {
				return true;
			} else {
				return false;
			}
		} else {
			return false;
		}
	}
	/* 0/den=0 */
	bool is_zero() const {
		if (den_!=0) {
			if (num_==0) {
				return true;
			} else {
				return false;
			}
		} else {
			return false;
		}
	}
	
	/* Restituisco i valori num e den */
	I num() const { return num_; }
	I den() const { return den_; }
	
	/* Implementazione canonica dell'incremento */
	rational& operator+=(const rational& other) {
		/* Caso NaN+razionale=NaN (o viceversa) */
		if (is_nan() or other.is_nan()) {
			num_=0;
			den_=0;
			return *this;
		}
		/* Caso +Inf-Inf=NaN o -Inf+Inf=NaN */
		if ((is_pos_inf() and other.is_neg_inf()) or (is_neg_inf() and other.is_pos_inf())) {
			num_=0;
			den_=0;
			return *this;
		}
		/* Caso +Inf+razionale=+Inf (o viceversa) */
		if (is_pos_inf() or other.is_pos_inf()) {
			num_=1;
			den_=0;
			return *this;
		}
		/* Caso -Inf+razionale=-Inf (o viceversa) */
		if (is_neg_inf() or other.is_neg_inf()) {
			num_=-1;
			den_=0;
			return *this;
		}
		num_=other.den_*num_+den_*other.num_;
		den_=den_*other.den_;
		simplify();
		return *this;
	}
	
	/* Implementazione canonica della somma */
	rational operator+(const rational& other) const{
		rational ret=*this;
		ret+=other;
		return ret;
	}
	
	/* Implementazione canonica del decremento */
	rational& operator-=(const rational& other) {
		/* Caso NaN-razionale=NaN (o viceversa) */
		if (is_nan() or other.is_nan()) {
			num_=0;
			den_=0;
			return *this;
		}
		/* Caso +Inf-(+Inf)=NaN o -Inf-(-Inf)=NaN */
		if ((is_pos_inf() and other.is_pos_inf()) or (is_neg_inf() and other.is_neg_inf())) {
			num_=0;
			den_=0;
			return *this;
		}
		/* Caso (+-)Inf-razionale=(+-)Inf */
		if (is_pos_inf() or is_neg_inf()) {
			return *this;
		}
		/* Caso razionale-Inf=-Inf */
		if (other.is_pos_inf()) {
			num_=-1;
			den_=0;
			return *this;
		}
		/* Caso razionale-(-Inf)=+Inf */
		if (other.is_neg_inf()) {
			num_=1;
			den_=0;
			return *this;
		}
		num_=other.den_*num_-den_*other.num_;
		den_=den_*other.den_;
		simplify();
		return *this;
	}
	
	/* Implementazione canonica della differenza */
	rational operator-(const rational& other) const{
		rational ret=*this;
		ret-=other;
		return ret;
	}
	
	/* Implementazione canonica della moltiplicazione */
	rational& operator*=(const rational& other) {
		/* Caso NaN*razionale=NaN (o viceversa) */
		if (is_nan() or other.is_nan()) {
			num_=0;
			den_=0;
			return *this;
		}
		/* Caso 0*+Inf=NaN (o viceversa) */
		if ((is_zero() and other.is_pos_inf()) or (is_pos_inf() and other.is_zero())) {
			num_=0;
			den_=0;
			return *this;
		}
		/* Caso 0*-Inf=NaN (o viceversa) */
		if ((is_zero() and other.is_neg_inf()) or (is_neg_inf() and other.is_zero())) {
			num_=0;
			den_=0;
			return *this;
		}
		/* Caso +Inf*+Inf=+Inf (o viceversa) */
		if ((is_pos_inf() and other.is_pos_inf()) or (is_neg_inf() and other.is_neg_inf())) {
			num_=1;
			den_=0;
			return *this;
		}
		/* Caso +Inf*-Inf=-Inf (o viceversa) */
		if ((is_pos_inf() and other.is_neg_inf()) or (is_neg_inf() and other.is_pos_inf())) {
			num_=-1;
			den_=0;
			return *this;
		}
		num_=other.num_*num_;
		den_=den_*other.den_;
		simplify();
		return *this;
	}
	
	/* Implementazione canonica del prodotto */
	rational operator*(const rational& other) const{
		rational ret=*this;
		ret*=other;
		return ret;
	}
	
	/* Implementazione canonica della divisione */
	rational& operator/=(const rational& other) {
		/* Caso NaN/razionale=NaN (o viceversa) */
		if (is_nan() or other.is_nan()) {
			num_=0;
			den_=0;
			return *this;
		}
		/* Caso 0/0=NaN */
		if (is_zero() and other.is_zero()) {
			num_=0;
			den_=0;
			return *this;
		}
		/* Caso (+-)Inf/(+-)Inf=NaN */
		if ((is_pos_inf() or is_neg_inf()) and (other.is_pos_inf() or other.is_neg_inf())) {
			num_=0;
			den_=0;
			return *this;
		}
		/* Caso razionale/0=+Inf */
		if (other.is_zero() and num_>0) {
			num_=1;
			den_=0;
			return *this;
		}
		/* Caso -razionale/0=-Inf */
		if (other.is_zero() and num_<0) {
			num_=-1;
			den_=0;
			return *this;
		}
		/* Caso razionale/(+-)Inf=0 */
		if (other.is_pos_inf() or other.is_neg_inf()) {
			num_=0;
			den_=1;
			return *this;
		}
		num_=num_*other.den_;
		den_=den_*other.num_;
		simplify();
		return *this;
	}
	
	/* Implementazione canonica della divisione */
	rational operator/(const rational& other) const{
		rational ret=*this;
		ret/=other;
		return ret;
	}
};

/* Implementazione dell'output */
template<typename I>
std::ostream&
operator<<(std::ostream& os, const rational<I>& v)
{
	/* Eccezioni: NaN,+Inf,-Inf,0 */
	if (v.den()==0) {
		if (v.num()==0)
			os << "NaN";
		else if (v.num()>0)
			os << "+Inf";
		else
			os << "-Inf";
	} else if (v.num()==0) {
        os << "0";
	} else {
		/* Stampo la frazione */
		os << v.num() << "/" << v.den();
	}
	return os;
}