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

    std::vector<Elective> intervals(n);
    for (size_t i = 0; i != n; ++i)
        std::cin >> intervals[i].start >> intervals[i].finish >> intervals[i].credits;

    std::sort(intervals.begin(), intervals.end());

    std::vector<int> maxCredits(n);
    maxCredits[n-1] = intervals[n-1].credits;

    for (int i = n - 2; i >= 0; --i) {
        int current_finish = intervals[i].finish;
        auto next = std::lower_bound(intervals.begin(), intervals.end(), current_finish); // находим подходящий отрезок

        if (next == intervals.end()) { // Не нашлось
            maxCredits[i] = std::max(maxCredits[i + 1], intervals[i].credits);
        } else {
            maxCredits[i] = std::max(maxCredits[i + 1], intervals[i].credits + maxCredits[std::distance(intervals.begin(), next)]);
        }
    }
    std::cout << maxCredits[0] << std::endl;
    return 0;
}
