#!/bin/bash

# disable HyperThreads
echo off | sudo tee /sys/devices/system/cpu/smt/control

# disable TurboBoost
echo "1" | sudo tee /sys/devices/system/cpu/intel_pstate/no_turbo

# disable irq rebalance
sudo killall irqbalance

# set irq affinity - make sure receive/transmit queues are mapped to the same core
export IETH=$(ifconfig | grep -B1 10.10.1 | grep -o "^\w*")

sudo ./intel_set_irq_affinity.sh -x all ${IETH}


