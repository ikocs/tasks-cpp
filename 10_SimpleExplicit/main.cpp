class Simple {
public:
   Simple() : a_(0), b_(0) {}
   Simple(int a) : a_(a), b_(0) {}
   Simple(int a, int b) : a_(a), b_(b) {}
private:
   int a_, b_;
};

class SimpleExplicit {
public:
   explicit SimpleExplicit() : a_(0), b_(0) {}
   explicit SimpleExplicit(int a) : a_(a), b_(0) {}
   explicit SimpleExplicit(int a, int b) : a_(a), b_(b) {}
private:
   int a_, b_;
};

template <typename S>
void someFunc(const S& s) {
}

int main(int, char**) {
   Simple s4 = {};
   someFunc<Simple>({});
   // SimpleExplicit se4 = {}; - COMPILE ERROR
   SimpleExplicit se4 = SimpleExplicit{};
   // someFunc<SimpleExplicit>({}); - COMPILE ERROR
   someFunc<SimpleExplicit>(SimpleExplicit{});

   Simple s5 = {11};
   someFunc<Simple>({11});
   // SimpleExplicit se5 = {11}; - COMPILE ERROR
   SimpleExplicit se5 = SimpleExplicit{11};
   // someFunc<SimpleExplicit>({11}); - COMPILE ERROR
   someFunc<SimpleExplicit>(SimpleExplicit{11});

   Simple s6 = {11, 22};
   someFunc<Simple>({11, 22});
   // SimpleExplicit se6 = {11, 22}; - COMPILE ERROR
   SimpleExplicit se6 = SimpleExplicit{11, 22};
   // someFunc<SimpleExplicit>({11, 22}); - COMPILE ERROR
   someFunc<SimpleExplicit>(SimpleExplicit{11, 22});

   return 0;
}