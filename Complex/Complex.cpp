// Student ID: 20274909

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>
#include "Complex.h"

using namespace std;

//int main()
//{
//   Complex c = Complex(0.71785581797, 0.4131147882);
//   cout << c.to_string();
//}

bool Complex::operator==(const Complex& that) const {
   if (this->get_real() == that.get_real() && this->get_imag() == that.get_imag()) {
      return true;
   }
   return false;
}

Complex& Complex::operator=(const Complex& rhs) {
   this->set_real(rhs.get_real());
   this->set_imag(rhs.get_imag());
   return *this;
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
   temp.set_real((this->get_real() * that.get_real()) - (this->get_imag() * that.get_imag()));
   temp.set_imag((this->get_real() * that.get_imag()) + (this->get_imag() * that.get_real()));
   return temp;
}

Complex Complex::reciprocal() const {

   //try {

      if (this->norm_squared() <= Complex::FLOOR)
         throw Div_By_Zero_Exception();

      Complex temp;
      temp.set_real(this->get_real() / this->norm_squared());
      temp.set_imag((-(this->get_imag())) / this->norm_squared());
      return temp;
   //}
   //catch (Complex::Div_By_Zero_Exception e) {
   //   cerr << e.what() << endl;
   //   exit(-1);
   //}

}

Complex Complex::operator/(const Complex& that) const {

      Complex recip_that = that.reciprocal();
      Complex temp = *this * recip_that;
      return temp;

}

string Complex::to_string() const {
   char buf[50];
   //sprintf(buf, "%f", _real);
   snprintf(buf, sizeof(buf), "(%.11g,%.11g)", _real, _imag);
   return string(buf);
}

ostream& operator<<(ostream& os, const Complex& x) {
   os << x.to_string();
   return os;
}