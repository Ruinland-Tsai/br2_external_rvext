#include <stdio.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <dlfcn.h>
#include <string.h>

int main(int ac, char *av) {
        unsigned long maj = 0, min = 0;
        void *handle;
        int (*getext)(char *, unsigned long *, unsigned long *);
        char *error;

        handle = dlopen("linux-vdso.so.1", RTLD_LAZY);
        if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
        }
        *(void **) (&getext) = dlsym(handle, "__vdso_riscv_check_extension");

           if ((error = dlerror()) != NULL)  {
                fprintf(stderr, "%s\n", error);
                exit(EXIT_FAILURE);
            }

        char find[100] = "xsfvfhbfmin";
        if((*getext)(find, &maj, &min) == 0) {
                printf("Found xsfvfhbfmin v%dp%d !\n", maj, min);
                }
        char find1[] = "zfh";
        if((*getext)(find1, &maj, &min) == 0) {
                printf("Found zfh v%dp%d !\n", maj, min);
                }
        char find2[] = "zba";
        if((*getext)(find2, &maj, &min) == 0) {
                printf("Found zba v%dp%d !\n", maj, min);
                }
        getchar();
        return 0;
        }
