all: hwcap_traverse rv_check_ext_syscall  rv_check_ext_vdso

hwcap_traverse: hwcap_traverse
		$(CC) -o hwcap_traverse hwcap_traverse.c

rv_check_ext_syscall: rv_check_ext_syscall
		$(CC) -o rv_check_ext_syscall rv_check_ext_syscall.c

rv_check_ext_vdso: rv_check_ext_vdso
		$(CC) -o rv_check_ext_vdso rv_check_ext_vdso.c

clean:
		rm -rf hwcap_traverse  rv_check_ext_syscall  rv_check_ext_vdso
install:
		$(INSTALL) -D -m 0755 rv_check_ext_vdso $(TARGET_DIR)/bin
		$(INSTALL) -D -m 0755 rv_check_ext_syscall $(TARGET_DIR)/bin
		$(INSTALL) -D -m 0755 hwcap_traverse $(TARGET_DIR)/bin
.PHONY: all clean
