#include <iostream>
#include <map>
#include <string>
#include <vector>

#include <fmt/format.h>
#include <range/v3/algorithm/sort.hpp>
using namespace std;
auto main() -> int
{
    auto bands = map<string, vector<string>>{};

    bands["The Beatles"] = {
        "Paul McCartney",
        "John Lennon",
        "Ringo Starr",
        "George Harrison"};
    bands["Pink Floyd"] = {
        "Nick Mason",
        "Syd Barrett",
        "Roger Waters",
        "Richard Wright",
        "David Gilmour",
        "Bob Klose"};
    bands["Arctic Monkeys"] = {
        "Alex Turner",
        "Matt Helders",
        "Jamie Cook",
        "Nick O'Malley",
        "Andy Nicholson",
        "Glyn Jones"};
    fmt::print("Search a pop/rock band: ");
    auto band_to_search = std::string{};
    std::getline(std::cin, band_to_search);
    if (auto it = bands.find(band_to_search); it != bands.end())
    {
        fmt::print("{:_^30}\n", band_to_search);
        auto &members = it->second;
        ranges::sort(members);
        for (auto const &mb : members)
            fmt::print("{:^30}\n", mb);
    }
    else
    {
        fmt::print("Sorry, '{}' is not on the list", band_to_search);
    }
}
