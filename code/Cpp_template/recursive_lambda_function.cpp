template<class T>
struct Func {
    T func;
    Func(const T &func):func(func) {}
    template<class... Args>
    constexpr decltype(auto) operator()(Args &&... args) {
        return func(*this, forward<Args>(args)...);
    }
};
template<class T>
Func(const T &) -> Func<T>;

/*
    Func f=[&](auto f)->int {
        return 0;
    };
*/