# eelinux

```
node0: ping -i 10  -f -c 10 -I enp3s0f0 10.10.225.255

node1: taskset -c 0 ./ixgbe 1000

# set broadcast addr
sudo ifconfig enp3s0f0 broadcast 10.10.1.255


```

## disable ipv6 (optional)
```
sudo sysctl -w net.ipv6.conf.all.disable_ipv6=1
sudo sysctl -w net.ipv6.conf.default.disable_ipv6=1
sudo sysctl -w net.ipv6.conf.lo.disable_ipv6=1
```

## Build and install Symbiote-Linux
```
sudo apt-get update -y
sudo apt install build-essential libncurses-dev bison flex libssl-dev libelf-dev fakeroot dwarves
cp -v /boot/config-$(uname -r) .config
make localmodconfig

# comment out all entries with BTF in .config
# CONFIG_DEBUG_INFO_BTF=y
# CONFIG_PAHOLE_HAS_SPLIT_BTF=y
# CONFIG_DEBUG_INFO_BTF_MODULES=y


scripts/config --disable SYSTEM_TRUSTED_KEYS
scripts/config --disable SYSTEM_REVOCATION_KEYS
scripts/config --set-str CONFIG_SYSTEM_TRUSTED_KEYS ""
scripts/config --set-str CONFIG_SYSTEM_REVOCATION_KEYS ""

fakeroot make EXTRAVERSION=-kElevate -j12
sudo make modules_install
sudo make install

# add new grub entry to 40_custom
~$ cat /etc/grub.d/40_custom
#!/bin/sh
exec tail -n +3 $0
# This file provides an easy way to add custom menu entries.  Simply type the
# menu entries you want to add after this comment.  Be careful not to change
# the 'exec tail' line above.

menuentry 'Han Linux 5.14.0-kElevate+' --class ubuntu --class gnu-linux --class gnu --class os $menuentry_id_option 'gnulinux-5.14.0-kElevate+-advanced-571337a8-0ea6-44bd-9cfc-6cb9719427c1' {
   	 recordfail
   	 load_video
   	 gfxmode $linux_gfx_mode
   	 insmod gzio
   	 if [ x$grub_platform = xxen ]; then insmod xzio; insmod lzopio; fi
   	 insmod part_gpt
   	 insmod ext2
   	 set root='hd0,gpt3'
   	 if [ x$feature_platform_search_hint = xy ]; then
   	   search --no-floppy --fs-uuid --set=root --hint-bios=hd0,gpt3 --hint-efi=hd0,gpt3 --hint-baremetal=ahci0,gpt3  571337a8-0ea6-44bd-9cfc-6cb9719427c1
   	 else
   	   search --no-floppy --fs-uuid --set=root 571337a8-0ea6-44bd-9cfc-6cb9719427c1
   	 fi
   	 echo    'Loading Linux 5.14.0-kElevate+ ...'
   	 linux    /boot/vmlinuz-5.14.0-kElevate+ root=UUID=571337a8-0ea6-44bd-9cfc-6cb9719427c1 ro console=ttyS1,115200 emulabcnet=f0:1f:af:e2:07:1e nosmap nosmep nokaslr nopti
   	 echo    'Loading initial ramdisk ...'
   	 initrd    /boot/initrd.img-5.14.0-kElevate+
    }

# force manual reboot into the kelevated kernel
~$ sudo grub-reboot Han\ Linux\ 5.14.0-kElevate+
~$ sudo reboot
```

## After rebooting
```
# check that the cmdline entries (nosmap nosmep nokaslr nopti) have been passed on
~$ cat /proc/cmdline
BOOT_IMAGE=/boot/vmlinuz-5.14.0-kElevate+ root=UUID=571337a8-0ea6-44bd-9cfc-6cb9719427c1 ro console=ttyS1,115200 emulabcnet=f0:1f:af:e2:07:1e nosmap nosmep nokaslr nopti

# ensure that the sys_elevate syscalls are available
~$ sudo cat /proc/kallsyms | grep sys_elevate
0000000000000000 T __ia32_sys_elevate
0000000000000000 T __x64_sys_elevate
0000000000000000 t __ia32_sys_elevate.cold
0000000000000000 t __x64_sys_elevate.cold
0000000000000000 d _eil_addr___ia32_sys_elevate
0000000000000000 d _eil_addr___x64_sys_elevate

~$ cd Symbi-OS/
~$ . prep_envt.sh
~$ cd Symbi-OS/Symlib/ && make
~$ cd Symbi-OS/Tools/ && make
~$ cd Symbi-OS/Tools/bin/recipes && ./mitigate_all.sh

# should see the following
~/EELinux/Symbi-OS/Tools/bin/recipes$ ./mitigate_all.sh 
ffffc9000698d000
ffffc900069c9000
ffffc900069de000
ffffc900069ed000
ffffc900069aa000
ffffc900069d1000
ffffc900069e5000
ffffc900069f5000
ffffc900069b1000
ffffc900069b9000
ffffc90006a12000
ffffc90006a21000
ffffc90006a19000
ffffc90006a29000
ffffc9000699d000
ffffc90006a55000
ffffc90006b21000
ffffc90006a65000
ffffc90006a6d000
ffffc900069c1000
ffffc90006a05000
ffffc90006b12000
ffffc90006b19000
ffffc900069fd000
ffffc90006a89000
ffffc90006a81000
ffffc90006a46000
ffffc90006a31000
ffffc90006a39000
ffffc90006a5d000
ffffc90006a4d000
ffffc90006a7a000
ffffc90006e01000
ffffc90007d7d000
ffffc90006e09000
ffffc9000703e000
ffffc90006e11000
ffffc90007d5d000
ffffc90007d6d000
ffffc90006e25000
ffffc90007d65000
ffffc90006e35000
ffffc90006e19000
ffffc90007d95000
ffffc90007da5000
ffffc90007d9d000
ffffc90007db5000
ffffc90007d75000
ffffc90007d85000
ffffc90006e2d000
ffffc90007dbd000
ffffc90007dc5000
ffffc90007dad000
ffffc90007dd5000
ffffc90007dcd000
ffffc90007d8d000
ffffc90007de5000
ffffc90007ddd000
ffffc900084fd000
ffffc90007ded000
ffffc90008505000
ffffc9000850d000
ffffc90008589000
ffffc90008899000
ffffc900088da000
ffffc900088cf000
ffffc900088d8000
ffffc900088e1000
ffffc900088e9000
mitigated core 10
ffffc900088fe000
ffffc90008a91000
ffffc90008a42000
ffffc90008a21000
ffffc90008a11000
mitigated core 20
ffffc90008a01000
ffffc90008a79000
ffffc90008a32000
ffffc90008a09000
ffffc900088f1000
ffffc90008ae6000
mitigated core 16
ffffc90008a19000
ffffc90008a40000
ffffc90008a69000
ffffc90008a49000
ffffc90008a8f000
ffffc90008aa0000
mitigated core 2
mitigated core 18
ffffc90008a8d000
mitigated core 3
ffffc90008a51000
mitigated core 7
mitigated core 21
mitigated core 8
ffffc90008a71000
mitigated core 5
ffffc90008a59000
mitigated core 15
mitigated core 23
ffffc90008c31000
mitigated core 12
mitigated core 31
mitigated core 27
mitigated core 0
mitigated core 22
mitigated core 25
mitigated core 11
mitigated core 28
mitigated core 13
mitigated core 19
mitigated core 6
ffffc90008a30000
mitigated core 30
mitigated core 14
mitigated core 1
ffffc90008a61000
mitigated core 29
mitigated core 24
mitigated core 9
ffffc90008f89000
ffffc90008fb1000
mitigated core 17
ffffc90008fb9000
mitigated core 4
mitigated core 26
mitigation finished

```
