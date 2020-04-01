class A
{
  public:
    void f() {}
};

int main()
{
  {
    A a;
    a.f(); // works fine
  }

  {
    A *a = new A();
    a->f(); // this doesn't
  }
}