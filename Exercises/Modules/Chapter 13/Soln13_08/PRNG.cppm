export module PRNG;

export class PseudoRandomNumberGenerator
{
public:
  PseudoRandomNumberGenerator(int n = 0)
    : m_n{ n }
  {}

  // A function call operator (no parameters, return type int)
  // Unlike many function call operators, this one alters the state of the object.
  int operator()()
  {
    const int current{ m_n };
    m_n = (m_n * 41 + 7) % 100; // See chapter 12
    return current;
  }

private:
  int m_n;
};
