#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(vector<int> num_list, int n) {
    vector<vector<int>> answer(num_list.size()/n,vector<int>(n,0));

    for(int i = 0 ; i < num_list.size(); i++)
    {
        answer[i/n][i%n] = num_list[i];
        std::cout << answer[i/n][i%n] << std::endl;
    }


    return answer;


}

typedef struct{
    vector<int> arr;
    int n;
}testcase;

int main(int argc, char** argv)
{
    vector<testcase> tc = 
    {
        testcase{{1,2,3,4,5,6,7,8},2},
        testcase{{100,95,2,4,5,6,18,33,948},3}

    };

    for(auto& i : tc)
    {
        solution(i.arr, i.n);
    }
}