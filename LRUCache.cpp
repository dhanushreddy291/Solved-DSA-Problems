#include <bits/stdc++.h>
using namespace std;

struct List {
  int Key, Value;
  List* Prev, *Next;

  List(int key, int value)
  {
    Key = key;
    Value = value;
    Prev = Next = NULL;
  }
};

int Capacity;
map <int, List*> Map;
List* Start, *End;

class LRUCache {
  public:
    LRUCache(int capacity);
    int get(int key);
    void set(int key, int value);
};

LRUCache::LRUCache(int capacity) {
  Map.clear();
  Capacity = capacity;
  Start = NULL;
  End = NULL;
}

int LRUCache::get(int key) {

  if (Map.find(key) == Map.end())
  return -1;

  else if (Map[key] != End)
  {
    List* t = Map[key];

    if (t -> Prev) 
      t -> Prev -> Next = t -> Next;
    else 
      Start = Start -> Next;

    t -> Next -> Prev = t -> Prev;
    End -> Next = t;
    t -> Prev = End;
    End = t;
  }

  return Map[key] -> Value;

}

void LRUCache::set(int key, int value) {

  if (Map.find(key) == Map.end())
  {
    if (Map.size() == Capacity)
    {
      Map.erase(Start -> Key);
      List *t = Start -> Next;
      free(Start);

      if (t)
      {
        Start = t;
        t -> Prev = NULL;
      }
      else
        Start = End = NULL;

    }

    Map[key] = new List(key, value);

    if (End) 
    {
      End -> Next = Map[key];
      Map[key] -> Prev = End;
      End = Map[key];
    }
    
    else Start = End = Map[key];
  }

  else if (Map[key] == End) 
  {
    if (Map[key] -> Value != value)
    Map[key] -> Value = value;

    return;
  }

  else
  {
    List* t = Map[key];

    if (t -> Prev) 
      t -> Prev -> Next = t -> Next;
    else 
      Start = Start -> Next;

    t -> Next -> Prev = t -> Prev;
    End -> Next = t;
    t -> Prev = End;
    End = t;
    
    if (End -> Value != value)
    End -> Value = value;

  }

  return;
}