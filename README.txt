```
git clone https://github.com/buildroot/buildroot
git clone https://github.com/Ruinland-Tsai/br2_external_rvext
cd buildroot
make BR2_EXTERNAL=../br2_external_rvext qemu_riscv64_virt_rvext_defconfig
make BR2_EXTERNAL=../br2_external_rvext testprograms-rebuild
make BR2_EXTERNAL=../br2_external_rvext rootfs-ext2
qemu-system-riscv64  -M virt -cpu rv64,x-b=true,Zfh=true, -bios output/images/fw_jump.elf -kernel output/images/Image -append "rootwait root=/dev/vda ro" -drive file=output/images/rootfs.ext2,format=raw,id=hd0 -device virtio-blk-device,drive=hd0 -netdev user,id=net0 -device virtio-net-device,netdev=net0 -nographic
```

# In the qemu console, test commands are :
hwcap2_traverse
rv_check_ext_syscall
rv_check_ext_vdso
