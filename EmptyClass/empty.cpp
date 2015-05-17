#include <iostream>
using namespace std;

class ClassA {
  char d;
};
class ClassB {
 //private:
  int b;
  int c;
  int d;
};
class ClassC : public ClassA {

};
class ClassD : public ClassB {

};
class ClassE {
 public:
  int GetReturnValue() {
    return 0;
  }
};
struct StructA {

};

int main() {
  cout << "ClassA " << sizeof(ClassA) << endl;
  cout << "ClassB " << sizeof(ClassB) << endl;
  cout << "ClassC " << sizeof(ClassC) << endl;
  cout << "ClassD " << sizeof(ClassD) << endl;
  cout << "ClassE " << sizeof(ClassE) << endl;
  cout << "StructA " << sizeof(StructA) << endl;
}
