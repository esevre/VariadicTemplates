#include <iostream>
#include <string>


template <class ...Args>
void super_printer(Args ... args) {
    auto p = [](auto x){ std::cout << x << ", "; };
    ((void) p(args), ...);
}

template <class ...Args>
int super_sum(Args ... args) {
    return (args+ ...);
}


template <class T>
T v_sum(T a, T b)
{
    return a + b;
}

template <class T, class ... Args>
T v_sum(T a, T b, const Args ... args)
{
    T sum = a + b;
    sum = v_sum(sum, args...);
    return sum;
}

void printer() {
    std::cout << "\n";
}

template <class T, class ... Args>
void printer(const T arg0, const Args ... args)
{
    std::cout << arg0 << ", ";
    printer(args...);
}

struct Thing {
    int t = 0;

    friend std::ostream& operator<<(std::ostream& os, const Thing& thing)
    {
        os << "thing: " << thing.t;
        return os;
    }
};

int main()
{

    int i = 3;
    double d = 1.234;
    std::string s = "real string";
    Thing t{4};

    printer("hello world", i, d, s);

    printer( i, d, s, "hello world");
    printer( i, d, "hello world", s, t);
    printer( d,"hello world", i, s);

    super_printer( d,"hello world", i, s);


    std::cout << "\n\nvariadic sum: " << v_sum(1,2,3,4,5,6,7,8) << "\n";

    std::cout << "super sum: " << super_sum<int>(1,2,3,4,5,6,7) << "\n";
}