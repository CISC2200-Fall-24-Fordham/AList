#ifndef __LIST_H__
#define __LIST_H__

#include <ostream>

/** List abstract class. */
template <typename Item> class List {
public:
  virtual int size() const = 0;
  virtual Item &get(int i) = 0;
  virtual const Item &get(int i) const = 0;
  virtual void insert(const Item &x, int i) = 0;
  virtual Item remove(int i) = 0;
  virtual void addFirst(const Item &x) = 0;
  virtual void addLast(const Item &x) = 0;
  virtual Item &getFirst() = 0;
  virtual Item &getLast() = 0;
  // virtual const Item &getFirst() const = 0;
  // virtual const Item &getLast() const = 0;
  virtual Item removeFirst() = 0;
  virtual Item removeLast() = 0;

  virtual void print(std::ostream &os) const {
    os << "[";
    for (int i = 0; i < size(); i += 1) {
      if (i != 0) {
        os << ",";
      }
      os << get(i);
    }
    os << "]";
  }
};

#endif // __LIST_H__
