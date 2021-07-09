#pragma once

using namespace std;

template <typename T, typename U>
struct return_t {
  vector<T> d;
  vector<U> p;
  return_t(vector<T> &d, vector<U> &p) : d(d), p(p) {}
  ~return_t() = default;
};