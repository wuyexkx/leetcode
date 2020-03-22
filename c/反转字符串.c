#include <stdio.h>
#include <string.h>

void reverse_strs(char *s)
{
    char *s1, *s2;
    if(!s || !*s) return;
    for(s1=s, s2=s + strlen(s) - 1; s1 < s2; s1++, s2--){
        *s1 ^= *s2;
        *s2 ^= *s1;
        *s1 ^= *s2;
    }
}

// int main(int argc, char **argv)
// {
//     // 有其他参数时反转
//     if(argc > 1){
//         for(int i=1; i<argc; ++i){
//             reverse_strs(argv[i]);
//             printf("%s ", argv[i]);
//         }
//     }
//     return 0;
// }