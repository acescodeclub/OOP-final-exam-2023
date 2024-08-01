//7106721
#include <iostream>
using namespace std;

class Fraction {
protected:
    int numerator, denominator, whole_number;

public:
    // Constructor for fractions without whole number
    Fraction(int num, int deno) {
        numerator = num;
        denominator = deno;
        whole_number = 0;
    }

    // Constructor for mixed fractions
    Fraction(int whole, int num, int deno) {
        whole_number = whole;
        numerator = num;
        denominator = deno;
    }

    // Overloaded addition operator
    Fraction operator+(const Fraction& fraction_2) const {
        int fraction_upper = (numerator * fraction_2.denominator) + (fraction_2.numerator * denominator);
        int fraction_bottom = denominator * fraction_2.denominator;
        return Fraction(fraction_upper, fraction_bottom);
    }

    // Overloaded multiplication operator
    Fraction operator*(const Fraction& fraction_3) const {
        int fraction_top = numerator * fraction_3.numerator;
        int fraction_down = denominator * fraction_3.denominator;
        return Fraction(fraction_top, fraction_down);
    }

    // Convert fraction to decimal
    float toDecimal() const {
        return static_cast<float>(numerator) / denominator;
    }

    // Display fraction
    void showFraction() const {
        if (whole_number != 0) {
            cout << whole_number << " " << numerator << "/" << denominator << endl;
        } else {
            cout << numerator << "/" << denominator << endl;
        }
    }
};

class ProperFraction : public Fraction {

};

class ImproperFraction : public Fraction {
private:
    bool mixed;

public:
    // Constructor with mixed fraction indicator
    ImproperFraction(int num, int deno, bool mix) : Fraction(num, deno), mixed(mix) {}

    // Accessor for mixed attribute
    bool isMixed() const {
        return mixed;
    }

    // Mutator for mixed attribute
    void setMixed(bool mix) {
        mixed = mix;
    }

    // Simplify the fraction
    void simplify() {
        int gcd = calculateGCD(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }

    // Helper function to find greatest common divisor
    int calculateGCD(int a, int b) const {
        if (b == 0)
            return a;
        return calculateGCD(b, a % b);
    }
};

int main() {
    // Create instances of Fraction
    Fraction alpha(1, 2);
    Fraction beta(2, 3, 4);
    Fraction gamma(5, 3);
    Fraction delta(2, 3, 4);

    // Calculation x: (1/2) + (1/2)
    Fraction x_result = alpha + alpha;
    cout << "a: ";
    x_result.showFraction();

    // Calculation y: (2 whole number, 3/4) + (5/3)
    Fraction y_result = beta + gamma;
    cout << "b: ";
    y_result.showFraction();

    // Calculation z: (5/3) + (1/2)
    Fraction z_result = gamma + alpha;
    cout << "c: ";
    z_result.showFraction();

    // Calculation w: (2 whole number 3/4) * 5/3
    Fraction w_result = delta * gamma;
    cout << "d: ";
    w_result.showFraction();

    // Calculation p: Convert (1/2) to decimal
    float p_result = alpha.toDecimal();
    cout << "e: " << p_result << endl;

    // Calculation q: Convert 5/3 to decimal
    float q_result = gamma.toDecimal();
    cout << "f: " << q_result << endl;

    // Convert 2 whole number, 3/4 to decimal
    float r_result = delta.toDecimal();
    cout << "g: " << r_result << endl;

    // Extend functionalities for ImproperFraction
    ImproperFraction impFraction(7, 10, true);

    // Check if the fraction is mixed
    cout << "Is mixed: " << (impFraction.isMixed() ? "Yes" : "No") << endl;

    // Set the fraction as not mixed
    impFraction.setMixed(false);

    // Simplify the fraction
    impFraction.simplify();
    cout << "Simplified improper fraction: ";
    impFraction.showFraction();

    return 0;
}
