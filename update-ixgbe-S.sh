#!/bin/bash

#set -x
SYMS="ksys_write han_ixgbe_test han_ixgbe_poll han_napi_disable han_napi_enable"
rm kernel.S
touch kernel.S

for syms in $SYMS;
do
    s=$(sudo cat /proc/kallsyms | grep $syms | cut -d' ' -f1)
    if [[ -n $s ]]; then
	echo ".global ${syms}" >> kernel.S
	echo ".set ${syms}, 0x${s}" >> kernel.S
    fi
done

cat kernel.S
