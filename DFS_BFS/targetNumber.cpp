#include <string>
#include <vector>
#include <iostream>

using namespace std;

int ans = 0;

typedef struct
{
    std::vector<int> numbers;
    int target;
}testcase;

void make_target_number(vector<int>& numbers, int count, int num, int target)
{
    
    count++;
    int plus_num = num + numbers[count-1];
    int minus_num = num - numbers[count-1];

    if(count == numbers.size())
    {
        if(plus_num == target)
        {
            ans++;
        }
        
        if(minus_num == target)
        {
            ans++;
        }
    }
    else
    {
        make_target_number(numbers, count, plus_num, target);
        make_target_number(numbers, count, minus_num, target);
    }
        


}

int solution(vector<int> numbers, int target) {
    int answer = 0;

    make_target_number(numbers,0,0,target);

    answer = ans;
    
    std::cout << "answer : " << answer << std::endl;

    return answer;
}


void make_testcase(std::vector<testcase>& src)
{
    src.push_back(testcase{{1,1,1,1,1}, 3});
    src.push_back(testcase{{4,1,2,1}, 4});
}

int main(int argc, char** argv)
{
    std::vector<testcase> tc;

    make_testcase(tc);

    for(auto& i : tc)
    {
        solution(i.numbers,i.target);
        ans = 0;
    }


    return 0;
}