#include <algorithm>
#include <iostream>
#include <vector>

class Elective {
public:
    Elective () {}

    bool operator<(Elective b) {
        return start < b.start;
    }
    bool operator<(int b) {
        return start < b;
    }

    int start;
    int finish;
    int credits;

};

int main(int argc, const char *argv[])
{
    int n;
    std::cin >> n;
    if (n == 0) {
        std::cout << 0 << std::endl;
        return 0;
    }

    std::vector<Elective> electives(n);
    for (size_t i = 0; i != n; ++i)
        std::cin >> electives[i].start >> electives[i].finish >> electives[i].credits;

    std::sort(electives.begin(), electives.end());

    std::vector<int> maxCredits(n);
    maxCredits[n-1] = electives[n-1].credits;

    for (int i = n - 2; i >= 0; --i) {
        int current_finish = electives[i].finish;
        auto next = std::lower_bound(electives.begin(), electives.end(), current_finish); // находим подходящий отрезок

        if (next == electives.end()) { // Не нашлось
            maxCredits[i] = std::max(maxCredits[i + 1], electives[i].credits);
        } else {
            maxCredits[i] = std::max(maxCredits[i + 1], electives[i].credits + maxCredits[std::distance(electives.begin(), next)]);
        }
    }
    std::cout << maxCredits[0] << std::endl;
    return 0;
}

