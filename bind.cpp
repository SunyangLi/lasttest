#include<iostream>
#include<functional>  //bind所在头

void f(int n1, int n2, int n3, const int& n4, int n5)
{
    std::cout << n1 << ' ' << n2 << ' ' << n3 << ' ' << n4 << ' ' << n5 << '\n';
}
int g(int n1)
{
    return n1;
}
 
struct Foo {
    void print_sum(int n1, int n2)
    {
        std::cout << n1+n2 << '\n';
    }
    int data = 10;
};

//总结// bind 是适配器，用于改造函数。
//function   是函数指针。

int add(int a,int b)
{
    return a+b;
}
int main()
{
    using namespace std::placeholders;//展位符所在空间
    auto f1=std::bind(f,_1,_3,4,_2,7);//_多少就是表示绑定第一个参数
    f1(1,2,5);
    
    std::function<int (int x,int y)> test=add;
    std::cout<<test(1,2)<<std::endl;

}
