#ifndef __ALIST_H__
#define __ALIST_H__

#include "List.h"

#define DEFAULT_SIZE 100

/** Array-based list. */
template <typename ItemType> class AList : public List<ItemType> {

private:
  /** The underlying array. */
  ItemType *items;

  /** Stores the current size of the list. */
  size_t count;

  /** Max number of items allowed. */
  size_t maxCnt;

  /** Resize the underlying array to the target capacity. */
  void resize(size_t capacity) {
    maxCnt = capacity;
    ItemType *a = new ItemType[maxCnt];
    for (size_t i = 0; i < count; i++) {
      a[i] = items[i];
    }
    delete[] items;
    items = a;
  }

public:
  /**
   * Construct a new AList object.
   *
   * @param initSize initial size of the underlying array; default 100
   */
  AList(size_t initSize = DEFAULT_SIZE) {
    count = 0;
    maxCnt = initSize;
    items = new ItemType[maxCnt];
  }

  /** Destroy the AList object. */
  ~AList() { delete[] items; }

  /** Return the number of elements in list. */
  int size() const override { return count; }

  /** Return the i-th item in list .*/
  ItemType &get(int i) override {
    if (i < 0)
      return get(i + count);
    return items[i];
  }
  const ItemType &get(int i) const override {
    if (i < 0)
      return get(i + count);
    return items[i];
  }

  /** Append `x` to the end of list. */
  void addLast(const ItemType &x) override {
    if (count == maxCnt) {
      resize(count * 2); // use factor 2
    }
    items[count] = x;
    count += 1;
  }

  /** Return the last item in list. */
  ItemType &getLast() override { return items[count - 1]; }

  /** Delete and return the last item. */
  ItemType removeLast() override {
    ItemType returnItem = getLast();
    count -= 1;
    return returnItem;
  }

  AList(const AList<ItemType> &other) {
    count = other.count;
    maxCnt = other.maxCnt;
    items = new ItemType[maxCnt];
    for (size_t i = 0; i < count; i++) {
      items[i] = other.items[i];
    }
  }

  void addFirst(const ItemType &x) override {
    if (count == maxCnt) {
      resize(count * 2); // use factor 2
    }
    for (size_t i = count; i > 0; i--) {
      items[i] = items[i - 1];
    }
    items[0] = x;
    count += 1;
  }

  ItemType &getFirst() override { return items[0]; }

  ItemType removeFirst() override {
    ItemType f = items[0];
    for (size_t i = 0; i < count - 1; i++) {
      items[i] = items[i + 1];
    }
    count -= 1;
    return f;
  }

  void insert(const ItemType &x, int pos) override {
    if (count == maxCnt) {
      resize(count * 2); // use factor 2
    }
    for (int j = count; j > pos; j--) {
      items[j] = items[j - 1];
    }
    items[pos] = x;
    count += 1;
  }
  ItemType remove(int pos) override {
    ItemType f = items[pos];
    for (size_t i = pos; i < count - 1; i++) {
      items[i] = items[i + 1];
    }
    count -= 1;
    return f;
  }
};

#endif // __ALIST_H__
