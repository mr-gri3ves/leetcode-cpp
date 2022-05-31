#include <string>
#include <stack>


constexpr bool isOpeningBracket(char c)
{
    return c == '(' || c == '{' || c == '[';
}

constexpr bool isClosingBracket(char c)
{
    return c == ')' || c == '}' || c == ']';
}

constexpr bool isSameTypeBracket(char op, char cl)
{
    return op == '(' ? cl == ')' : op == '{' ? cl == '}' : cl == ']';
}

bool isValid(const std::string& s)
{
    std::stack<char> stack;

    for(const auto& c : s)
    {
        if (isOpeningBracket(c))
        {
            stack.push(c);
            continue;
        }
        if(isClosingBracket(c))
        {
            if(stack.empty())
            {
                return false;
            }
            char op = stack.top();
            if(!isSameTypeBracket(op,c))
            {
                return false;
            }
            stack.pop();
        }
    }
    return stack.empty();
}

int main()
{

}