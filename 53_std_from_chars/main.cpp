/// URL ref: https://www.cppstories.com/2018/12/fromchars/

#include <charconv> // from_char, to_char
#include <string>
#include <iostream>
#include <optional>
#include <string_view>

constexpr std::optional<int> to_int(std::string_view sv)
{
    int value {};
    const auto ret = std::from_chars(sv.begin(), sv.end(), value);
    if (ret.ec == std::errc{})
        return value;

    return {};
}

std::optional<double> to_double(std::string_view sv)
{
    double value {};
    const auto ret = std::from_chars(sv.begin(), sv.end(), value);
    if (ret.ec == std::errc{})
        return value;

    return {};
}

int main()
{
    static_assert(to_int("hello") == std::nullopt);
    static_assert(to_int("10") == 10);
    std::cout << to_double("1.123").value() << "\n";
}
