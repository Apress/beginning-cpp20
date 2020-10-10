export module math;

export auto square(const auto& x) { return x * x; }  // An abbreviated function template

export const double lambda = 1.303577269034296391257;        // Conway's constant

export enum class Oddity { Even, Odd };
bool isOdd(int x) { return x % 2 != 0; }  // Module-local function (not exported)
export auto getOddity(int x) { return isOdd(x) ? Oddity::Odd : Oddity::Even; }
