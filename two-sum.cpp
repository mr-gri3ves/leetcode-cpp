#include <vector>
#include <iostream>
#include <unordered_map>

std::vector<int> twoSum(const std::vector<int>& nums, int target)
{
    std::unordered_map<int,int> records;
    for(int i = 0; i < nums.size(); ++i)
    {
        if(records.find(nums[i]) != records.end() && 2 * nums[i] == target)
        {
            return {records[nums[i]],i};
        }
        records[nums[i]] = i;
    }

    for(int i = 0; i < nums.size(); ++i)
    {
        int elem = nums[i];
        int complement = target - elem;
        records.erase(elem);
        if(records.find(complement) != records.end())
        {
            return {i,records[complement]};
        }
    }

    // Not possible
    return {-1,-1};
}

int main()
{
    for(const auto& elem : twoSum({3,2,4},6))
    {
        std::cout<<elem << " ";
    }   

}