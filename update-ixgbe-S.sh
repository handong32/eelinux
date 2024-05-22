#!/bin/bash

#set -x
export SYMS=${SYMS:="ksys_write ixgbe_sym_hello ixgbe_sym_napi_enable ixgbe_sym_napi_disable ixgbe_sym_poll"}

rm kernel.S
touch kernel.S

for syms in $SYMS;
do
    echo $syms
    s=$(sudo cat /proc/kallsyms | grep $syms | cut -d' ' -f1)
    if [[ -n $s ]]; then
	echo ".global ${syms}" >> kernel.S
	echo ".set ${syms}, 0x${s}" >> kernel.S
    fi
done

cat kernel.S
