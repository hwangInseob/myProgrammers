#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int k) {
    int answer = 0;
    
    answer = (answer + 2*(k-1)) % numbers.size();

    answer = numbers[answer];

    return answer;
}

typedef struct
{
    vector<int> numbers;
    int k;
}testcase;

int main(int argc, char** argv)
{

    vector<testcase> tc;
    tc.push_back({.numbers = vector<int>{1,2,3,4}, .k = 2});
    tc.push_back({.numbers = vector<int>{1, 2, 3, 4, 5, 6}, .k = 5});

    for(auto& i : tc)
    {
        solution(i.numbers, i.k);
    }

    return 0;
}