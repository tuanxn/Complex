// Student ID: 20274909

#include <string>
#include <sstream>

using namespace std;

#ifndef Complex_h
#define Complex_h

class Complex {
private:
   double _real, _imag;

public:
   static constexpr double FLOOR = 1e-10; // Threshold

   Complex(double re = 0.0, double im = 0.0) : _real(re), _imag(im) {};
   double get_real() const { return _real; }
   double get_imag() const { return _imag; }
   void set_real(double re) { _real = re; }
   void set_imag(double im) { _imag = im; }

   string to_string() const;
   double norm_squared() const { return _real * _real + _imag * _imag; }
   double norm() const { return sqrt(norm_squared()); }

   Complex reciprocal() const;
   Complex& operator= (const Complex& rhs);

   class Div_By_Zero_Exception {
   public:
      string to_string() { return "Divide by zero exception"; }
      string what() { return to_string(); } // more conventional
   };

   // operators (only the most common ones)
   Complex operator+(const Complex& that) const;
   Complex operator-(const Complex& that) const;
   Complex operator*(const Complex& that) const;
   Complex operator/(const Complex& that) const;

   bool operator==(const Complex& that) const;
   bool operator!=(const Complex& that) const { return !(*this == that); }
   bool operator<(const Complex& that) const;

   friend ostream& operator<<(ostream& os, const Complex& x);

   friend class Tests; // Don't remove this line

};


#endif