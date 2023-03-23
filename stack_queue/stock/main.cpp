#include <iostream>
#include <vector>

#define LOG() \
        std::cout << "[ " << __func__ << " :: " << __LINE__ << " ] \t\t"

static std::vector<std::vector<int>> testcase = {{1, 2, 3, 2, 3}};

void print_result(const std::vector<int>& result)
{
    for(int i = 0 ; i < result.size() ; i++)
    {
        if(result.size() == 1)
        {
            LOG() << "[ " << result[i] << " ]" << std::endl;
        }
        else
        {
            if(i == 0 )
                LOG() << "[ " << result[i] << ", ";
            else if( i == result.size() - 1)
                std::cout << result[i] << " ]" << std::endl;
            else
                std::cout << result[i] << ", ";
        }
    }
}



std::vector<int> solution(std::vector<int> prices)
{
    LOG() << ":::::::::::::::::::::::: solution start ::::::::::::::::::::::::" << std::endl;
    std::vector<int> result;

    for(int i = 0 ; i < prices.size() ; i++)    
    {
        int tmp = 0;

        for(int j = i + 1 ; j < prices.size() ; j++)
        {
            tmp++;
            if(prices[i] > prices[j])
            {
                break;
            }
        }

        LOG() << "i : " << tmp << std::endl;
        result.push_back(tmp);
    }

    print_result(result);
    LOG() << ":::::::::::::::::::::::: solution end ::::::::::::::::::::::::" << std::endl;
    return result;
}


int main(int argc, char** argv)
{
    for(int i = 0 ; i < testcase.size(); i++)
    {
        solution(testcase[i]);
    }
}

