#include <string>
#include <vector>

using namespace std;

int solution(vector<int> dot) {
    int answer = 0;

    if(dot[0] > 0)
    {
        if(dot[1] > 0)
            return 1;
        else
            return 4;
    }
    else
    {
        if(dot[1] > 0)
            return 2;
        else
            return 3;
    }


    return answer;
}

int main(int argc, char** argv)
{
    vector<int> testcase = {2,4};

    solution(testcase);

    return 0;
}