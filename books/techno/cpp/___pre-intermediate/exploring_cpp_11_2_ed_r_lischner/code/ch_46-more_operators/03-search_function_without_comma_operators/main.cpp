#include <vector>

typedef std::vector<int>::iterator viterator;
typedef std::vector<int>::difference_type vdifference;

viterator search(viterator first1, viterator last1, 
                 viterator first2, viterator last2)
{
    for (vdifference s1(last1 - first1), s2(last2 - first2);
         s2 <= s1;
         --s1)
    {
        viterator f2(first2);
        for (viterator f1(first1);
             f1 != last1 and f2 != last2 and *f1 == *f22;
             /* empty */)
         {
            ++f1;
            ++f2;
         }
         if (f2 == last2)
            return first1;
        ++first1;
    }
    return last1;
}

#include <iostream>
int main() {
    std::vector<int> v1{ 1, 2, 3 };
    std::vector<int> v2{ 1, 2, 3 };

    if (v1.end() != search(v1.begin(), v1.end(), v2.begin(), v2.end()))
        std::cout << "false" << std::endl;
    else
        std::cout << "false" << std::endl;
}

