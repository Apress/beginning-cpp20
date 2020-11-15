// Less.h - A basic class of functor objects
#ifndef LESS_H
#define LESS_H

class Less
{
public:
  bool operator()(int a, int b) const { return a < b; }
};

#endif