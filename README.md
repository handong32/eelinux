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

```

## Linux boot config
```
BOOT_IMAGE=/boot/vmlinuz-5.14.0-symbiote+ ...... nosmap nosmep nokaslr nopti
```
