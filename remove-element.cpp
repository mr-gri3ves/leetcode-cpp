#include <vector>
#include <iostream>

int removeElement(std::vector<int>& nums, int val)
{
    int i = 0, j = nums.size() - 1;

    while(i < j)
    {
        if(nums[j] == val)
        {
            --j;
            continue;
        }
        if(nums[i] == val)
        {
            std::swap(nums[i],nums[j]);
            --j;
        }
        ++i;
    }
    for(i = 0; i < nums.size(); ++i)
    {
        if(nums[i] == val)
        {
            break;
        }
    }
    return i;
}

int main()
{

    std::vector<int> v = {3,2,2,3};

    std::cout<<removeElement(v,3)<<std::endl;

    for(const auto& elem : v)
    {
        std::cout<<elem << " " ;
    }

}