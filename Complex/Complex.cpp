// Student ID: 20274909

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Complex.h"

using namespace std;

int main()
{
   Complex c = 3.14;
   Complex d = (3.14);
   Complex zero = Complex();
   Complex both = Complex(1.1, 2.2);
}

bool Complex::operator==(const Complex& that) const {
   if (this->get_real() == that.get_real() && this->get_imag() == that.get_imag()) {
      return true;
   }
   return false;
}

Complex& Complex::operator= (const Complex& rhs) {
   *this = Complex(rhs.get_real(), rhs.get_imag());
}

bool Complex::operator<(const Complex& that) const {
   if ((this->norm() - that.norm()) < 0) {
      return true;
   }
   return false;
}

Complex Complex::operator+(const Complex& that) const {
   Complex temp;
   temp.set_real(this->get_real() + that.get_real());
   temp.set_imag(this->get_imag() + that.get_imag());
   return temp;
}

Complex Complex::operator-(const Complex& that) const {
   Complex temp;
   temp.set_real(this->get_real() - that.get_real());
   temp.set_imag(this->get_imag() - that.get_imag());
   return temp;
}

Complex Complex::operator*(const Complex& that) const {
   Complex temp;
   temp.set_real((this->get_real() * that.get_real()) - (this->get_imag() - that.get_imag()));
   temp.set_imag((this->get_real() * that.get_imag()) - (this->get_imag() - that.get_real()));
   return temp;
}

Complex Complex::reciprocal() const {
   Complex temp;
   temp.set_real(this->get_real() / this->norm_squared());
   temp.set_imag((-(this->get_imag())) / this->norm_squared());
   return temp;
}

Complex Complex::operator/(const Complex& that) const {
   
   Complex recip_that = that.reciprocal();
   Complex temp = *this * recip_that;
   return temp;
}