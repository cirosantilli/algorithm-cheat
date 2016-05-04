/*
http://stackoverflow.com/questions/15057010/comparing-version-numbers-in-c/15059401#15059401
*/

#include <assert.h>
#include <stdlib.h>

int versionCmp( char *pc1, char *pc2)
{
    int result = 0;
    /* loop through each level of the version string */
    while (result == 0) {
        /* extract leading version numbers */
        char* tail1;
        char* tail2;
        unsigned long ver1 = strtoul( pc1, &tail1, 10 );
        unsigned long ver2 = strtoul( pc2, &tail2, 10 );
        /* if numbers differ, then set the result */
        if (ver1 < ver2)
            result = -1;
        else if (ver1 > ver2)
            result = +1;
        else {
            /* if numbers are the same, go to next level */
            pc1 = tail1;
            pc2 = tail2;
            /* if we reach the end of both, then they are identical */
            if (*pc1 == '\0' && *pc2 == '\0')
                break;
            /* if we reach the end of one only, it is the smaller */
            else if (*pc1 == '\0')
                result = -1;
            else if (*pc2 == '\0')
                result = +1;
            /*  not at end ... so far they match so keep going */
            else {
                pc1++;
                pc2++;
            }
        }
    }
    return result;
}

int main( void )
{
    assert(versionCmp("1.2.3" , "1.2.3" ) == 0);
    assert(versionCmp("1.2.3" , "1.2.4" )  < 0);
    assert(versionCmp("1.2.4" , "1.2.3" )  > 0);
    assert(versionCmp("10.2.4", "9.2.3" )  > 0);
    assert(versionCmp("9.2.4",  "10.2.3")  < 0);
    /* Trailing 0 ignored. */
    assert(versionCmp("01", "1") == 0);
    /* Any single space delimiter is OK. */
    assert(versionCmp("1a2", "1b2") == 0);
    return EXIT_SUCCESS;
}
