#define RFACTOR 2

/** Similar to the IntArray class in Lab 1, which is a wrapper around the
 * built-in array */
class AList {
private:
  /** Used to hold the items */
  //   int items[100] = {}; // initialize all values to 0
  int *items;
  int maxCnt;
  int count;

  void resize(int capacity) {
    maxCnt = capacity;
    int *a = new int[maxCnt];
    for (int i = 0; i < count; i++) {
      a[i] = items[i];
    }
    delete[] items;
    items = a;
  }

public:
  AList(int initialSize = 100) {
    count = 0;
    maxCnt = initialSize;
    items = new int[maxCnt];
  }

  ~AList() { delete[] items; }

  /** Append the list with x */
  void addLast(int x) {
    // before:[0, 1, 2, 3, 4] count = 5
    // after :[0, 1, 2, 3, 4, 5] count = 6
    if (count == maxCnt) {
      // resize
      resize(maxCnt * RFACTOR);
    }
    items[count] = x;
    count++;
  }

  /** Return the last item in list */
  int &getLast() { return items[count - 1]; }

  /** Return the i-th item */
  int &get(int i) { return items[i]; }

  int size() { return count; }

  /** Remove and return the last item */
  int removeLast() {
    // before:[0, 1, 2, 3, 4] count = 5
    // after :[0, 1, 2, 3] count = 4
    int lastItem = items[count - 1];
    count--;
    return lastItem;
  }
};
