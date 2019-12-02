#include <stdio.h>
#include <assert.h>
#include <string.h>

int IsRotation(const char *s1, const char *s2)
{
    const char  *run1, *run2;
    int count = 0, length = 0;
    
    assert (NULL != s1);
    assert (NULL != s2);
    
    if(strlen(s1) != strlen(s2))
    {
        return 0;
    }
    length = strlen(s1);
    
    run1 = s1;
    run2 = s2;
    
    while('\0' != *run2)
    {
        while ('\0' != *run1)
        {
            if(*run1 == *run2)
            {
               ++run1;
               ++run2;
               ++count;
            }
            else
            {
                ++run1;
                count = 0;
                run2 = s2;
            }
        }
        run1 = s1;
        if(0 == strncmp(run1,run2,length-count))
        {
           return 1;
        }
        else
        {
           return 0;
        }
    }
    return 1;
}

void Test(int condition, const char* msg)
{
    if(1 == condition)
    {
        printf("\033[0;32m");
        printf("Success!\n");
        printf("\033[0m");
    }
    else
    {
        printf("\033[0;31m");
        printf("Fail-%s\n", msg);
        printf("\033[0m"); 
    }

}

int main()
{
    
    Test(IsRotation("123456","456123") == 1,"");
    Test(IsRotation("456123","123445") == 0, "Not rotation");
    Test(IsRotation("","") == 1, "empty");
    Test(IsRotation("123156","156123") == 1,"");
    Test(IsRotation("123156","1561234") == 0,"not equal");
    Test(IsRotation("123","456") == 0,"Not rotation");
    Test(IsRotation("123412","121234") == 1,"");
    return 0;
}

