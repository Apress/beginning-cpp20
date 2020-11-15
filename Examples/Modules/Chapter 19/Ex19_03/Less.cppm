// Less.h - A basic class of functor objects
#ifndef LESS_H
#define LESS_H

export class Less
{
public:
  bool operator()(int a, int b) const { return a < b; }
};

