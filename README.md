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