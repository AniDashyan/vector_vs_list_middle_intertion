#include <iostream>
#include <vector>
#include <list>
#include <chrono>
#include <iomanip>

using namespace std::chrono;
const int n = 10000;

auto middle_insertions_vector(std::vector<int>& cont) {
    auto start = steady_clock::now();
    for (int i = 0; i < n; i++) {
        cont.insert(cont.begin() + cont.size() / 2, i);
    }
    auto end = steady_clock::now();
    return (duration_cast<milliseconds>(end - start).count());
}


auto middle_insertions_list(std::list<int>& cont) {
    auto start = steady_clock::now();
    for (int i = 0; i < n; i++) {
        auto it = cont.begin();
        std::advance(it, cont.size() / 2);
        cont.insert(it, i);
    }
    auto end = steady_clock::now();
    return (duration_cast<milliseconds>(end - start).count());
}

int main() {
    std::vector<int> vec;
    std::list<int> list;
    std::vector<int> pre_vec;
    pre_vec.reserve(n);

    auto vec_time = middle_insertions_vector(vec);
    auto list_time = middle_insertions_list(list);
    auto pre_vec_time = middle_insertions_vector(vec);


    std::cout << "Vector time: " << vec_time << "ms\n";
    std::cout << "List time: " << list_time << "ms\n";
    std::cout << "Preallocated Vector time: " << pre_vec_time << "ms\n";
    return (0);
}