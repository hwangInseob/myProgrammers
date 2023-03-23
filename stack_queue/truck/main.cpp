#include <iostream>
#include <vector>

// 1 <= bridge_length   <= 10000            ....다리길이
// 1 <= weight          <= 10000            ....다리가 견딜 수 있는 무기
// 1 <= truck_weights.length()  <= 10000    ....트럭의 수
// 1 <= truck_weights[n]    <= weight       ....각 트럭의 무게



typedef struct
{
    short bridge_length;
    short weight;
    std::vector<int> truck_weights;
}testcase;

static std::vector<testcase> tc= 
{
    {2, 10, {7,4,5,6}},
    {100, 100, {10}},
    {100, 100, {10, 10, 10, 10, 10, 10, 10, 10, 10, 10}},
    {5,5,{2,2,2,2,1,1,1,1,1}}
};

typedef struct
{
    short weight;
    short position_on_bridge;
    bool is_on_the_road;
    bool is_passed;
}truck;


typedef struct 
{
    uint32_t length;
    uint32_t weight;
    uint32_t left_weight;
    uint32_t left_space;
}bridge;



/*
    (1)     이번에 도착하는 트럭이 있는지
        (1-1)   있다면, 현재 다리에 올라간 모든 트럭 중량에서 제외

    (2)     0 < (weight - (다음 트럭의 무게 + 현재 올라간 모든 트럭의 무게))

    (3)     (2)이 성립하면 다음 트럭 올라감


*/

void init_bridge(int bridge_length, int weight, bridge& src)
{
    src.length = bridge_length;
    src.weight = weight;
    src.left_space = bridge_length;
    src.left_weight = weight;
}

void init_trucks(std::vector<int> truck_weights, std::vector<truck>& truck_src)
{
    for(int i = 0 ; i < truck_weights.size(); i++)
    {
        truck tmp;
        tmp.weight = truck_weights[i];
        tmp.position_on_bridge = 0;
        tmp.is_on_the_road = false;
        tmp.is_passed = false;

        truck_src.push_back(tmp);
    }
}

int solution(int bridge_length, int weight, std::vector<int> truck_weights)
{
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "-------------------------- START -------------------------" << std::endl;

    int result = 0;

    bridge bridge_src;
    std::vector<truck> truck_src;
    int passed_truck_count = 0;

    std::cout << "bridge init START" << std::endl;
    init_bridge(bridge_length, weight, bridge_src);
    std::cout << "bridge init END" << std::endl;

    std::cout << "truck init START" << std::endl;
    init_trucks(truck_weights, truck_src);
    std::cout << "truck init END" << std::endl;

    while(true)
    {
        result++;   // 총 걸리는 시간 1씩 증가, 시간당 1칸씩 흐름
        std::cout << "time[" << result << "]" << std::endl;
        for(int i = 0 ; i < truck_src.size(); i++)
        {
            //일단 다리 위에 있는 트럭들 모두 한칸씩 전진, 
            //다 지나간 트럭에 대한 처리
            if(truck_src[i].is_on_the_road &&       //트럭이 다리 위에 있고
                truck_src[i].is_passed == false)    //아직 도착하지 않았으면
            {
                truck_src[i].position_on_bridge++;
                
                if(truck_src[i].position_on_bridge >= bridge_src.length)
                {
                    truck_src[i].is_on_the_road = false;
                    truck_src[i].is_passed = true;
                    bridge_src.left_weight = bridge_src.left_weight + truck_src[i].weight;
                    bridge_src.left_space++;
                    passed_truck_count++;

                    std::cout << "truck["<< i << "] passed" << std::endl;
                    std::cout << "current pass truck count = " << passed_truck_count << std::endl;

                }
            }

            if(truck_src[i].is_on_the_road == false &&      // 아직 올라가지 않았고
                truck_src[i].is_passed == false)            // 도착하지도 않았고
            {           
                if(bridge_src.left_weight - truck_src[i].weight <= bridge_src.weight &&    // 다리에 무게가 충분하고
                    bridge_src.left_space > 0)                                              // 공간도 충분하면
                {
                    truck_src[i].is_on_the_road = true;
                    
                    bridge_src.left_space--;
                    bridge_src.left_weight = bridge_src.left_weight - truck_src[i].weight;
                    std::cout << "truck ["<< i <<"] is start." << std::endl;
                }

                break;
            }

        }

        if( passed_truck_count == truck_src.size())
        {
            break;
        }

    }
    
    std::cout << "-------------------------- END -------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    return result;
}



/*
================================================================
=                                                              =
=                                                              =
=                     M a i n                                  =
=                                                              =
=                                                              =
================================================================
*/
int main(int argc, char** argv)
{

    for(int i = 0 ; i < tc.size(); i++)
    {
        std::cout << solution(tc[i].bridge_length, tc[i].weight, tc[i].truck_weights) << std::endl;
    }
    
    return 0;
}