#include <stdio.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <unistd.h>

int main(int ac, char *av) {
        long getext = 248;
        unsigned long maj = 0, min = 0;
        char find[100] = "xsfvfhbfmin";
        if(syscall(248, find, &maj, &min) == 0) {
                printf("Found xsfvfhbfmin v%dp%d !\n", maj, min);
                }
        char find1[] = "zfh";
        if(syscall(248, find1, &maj, &min) == 0) {
                printf("Found zfh v%dp%d !\n", maj, min);
                }
        char find2[] = "zba";
        if(syscall(248, find2, &maj, &min) == 0) {
                printf("Found zba v%dp%d !\n", maj, min);
                }
        getchar();
        return 0;
}
