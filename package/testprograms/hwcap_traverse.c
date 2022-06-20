#include <sys/auxv.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

struct arch_vdso_data {
    uint64_t mvendor;
    uint64_t march;
    uint64_t mimpl;
    struct list_head extension_head;
    char buffer[];
} __attribute__((packed));

struct rvext {
    uint64_t  spec_maj;
    uint64_t  spec_min;
    char ext_name[100];
    struct list_head exts;
    };

#define container_of(ptr, type, member) ({                      \
        const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
        (type *)( (char *)__mptr - offsetof(type,member) );})

int main(int ac, char *av) {
        unsigned long hwcap2_address = getauxval(AT_HWCAP2);
        struct arch_vdso_data* cur;
        struct list_head* iter;
        struct rvext* ext_ptr;

        printf("hwcap2 points to %lx \n", hwcap2_address);
        cur = (struct arch_vdso_data*) hwcap2_address;
        printf("HWCAP2 info :\nmvendor %x, march %x, mimpl %x\n", cur->mvendor, cur->march, cur->mimpl);
        iter = &(cur->extension_head);
        for(ext_ptr = (struct rvext*) cur->buffer; iter != NULL; ext_ptr++) {
                printf("ext name : %s, maj : %d, min : %d\n", ext_ptr->ext_name, ext_ptr->spec_maj, ext_ptr->spec_min);
                iter = ext_ptr->exts.next;
                }

        return 0;
        }
