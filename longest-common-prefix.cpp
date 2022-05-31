#include <string>
#include <vector>
#include <algorithm>

std::string longestCommonPrefix(const std::vector<std::string>& strs)
{
    std::string smallestStr = strs[0];

    for(const auto& str : strs)
    {
        if(str.size() < smallestStr.size())
        {
            smallestStr = str;
        }
    }

    for(int i = 0; i < smallestStr.size(); ++i)
    {
        std::string subStr = smallestStr.substr(0,smallestStr.size() - i);

        if(std::all_of(strs.begin(),strs.end(),[&](const auto& str)
        {
            return str.find(subStr) == 0;
        })){
            return subStr;
        }
    }
    return "";
}