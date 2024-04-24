# NetPerf results

## Server
```
hand32@node1:~$ taskset -c 13 netserver -D -L 10.10.1.2
```

## TCP_STREAM

### Normal Linux
```
hand32@node0:~$ netperf -t TCP_STREAM -L 10.10.1.1 -H 10.10.1.2 -I 99 -- -m 1500 -R 1 
MIGRATED TCP STREAM TEST from 10.10.1.1 () port 0 AF_INET to 10.10.1.2 () port 0 AF_INET : +/-49.500% @ 99% conf.  : demo
Recv   Send    Send                          
Socket Socket  Message  Elapsed              
Size   Size    Size     Time     Throughput  
bytes  bytes   bytes    secs.    10^6bits/sec  

131072  16384   1500    10.00    9406.44   
hand32@node0:~$ netperf -t TCP_STREAM -L 10.10.1.1 -H 10.10.1.2 -l 30 -- -m 1500 -R 1
MIGRATED TCP STREAM TEST from 10.10.1.1 () port 0 AF_INET to 10.10.1.2 () port 0 AF_INET : demo
Recv   Send    Send                          
Socket Socket  Message  Elapsed              
Size   Size    Size     Time     Throughput  
bytes  bytes   bytes    secs.    10^6bits/sec  

131072  16384   1500    30.00    9412.12   
```

### Symbiosis Poll
```
hand32@node0:~$ netperf -t TCP_STREAM -L 10.10.1.1 -H 10.10.1.2 -l 10 -- -m 1500 -R 1
MIGRATED TCP STREAM TEST from 10.10.1.1 () port 0 AF_INET to 10.10.1.2 () port 0 AF_INET : demo
Recv   Send    Send                          
Socket Socket  Message  Elapsed              
Size   Size    Size     Time     Throughput  
bytes  bytes   bytes    secs.    10^6bits/sec  

131072  16384   1500    10.00    9405.64   
hand32@node0:~$ netperf -t TCP_STREAM -L 10.10.1.1 -H 10.10.1.2 -l 10 -- -m 1500 -R 1
MIGRATED TCP STREAM TEST from 10.10.1.1 () port 0 AF_INET to 10.10.1.2 () port 0 AF_INET : demo
Recv   Send    Send                          
Socket Socket  Message  Elapsed              
Size   Size    Size     Time     Throughput  
bytes  bytes   bytes    secs.    10^6bits/sec  

131072  16384   1500    10.00    9407.41   
```

## TCP_RR

### Normal Linux
```
hand32@node0:~$ netperf -t TCP_RR -L 10.10.1.1 -H 10.10.1.2 -I 99 -- -r 32,128 -R 1
MIGRATED TCP REQUEST/RESPONSE TEST from 10.10.1.1 () port 0 AF_INET to 10.10.1.2 () port 0 AF_INET : +/-49.500% @ 99% conf.  : demo : first burst 0
Local /Remote
Socket Size   Request  Resp.   Elapsed  Trans.
Send   Recv   Size     Size    Time     Rate         
bytes  Bytes  bytes    bytes   secs.    per sec   

16384  131072 32       128     10.00    22596.51   
16384  131072
hand32@node0:~$ netperf -t TCP_RR -L 10.10.1.1 -H 10.10.1.2 -I 99 -- -r 32,128 -R 1
MIGRATED TCP REQUEST/RESPONSE TEST from 10.10.1.1 () port 0 AF_INET to 10.10.1.2 () port 0 AF_INET : +/-49.500% @ 99% conf.  : demo : first burst 0
Local /Remote
Socket Size   Request  Resp.   Elapsed  Trans.
Send   Recv   Size     Size    Time     Rate         
bytes  Bytes  bytes    bytes   secs.    per sec   

16384  131072 32       128     10.00    22641.20   
16384  131072
```

### Symbiosis Poll

```
hand32@node0:~$ netperf -t TCP_RR -L 10.10.1.1 -H 10.10.1.2 -I 99 -- -r 32,128 -R 1
MIGRATED TCP REQUEST/RESPONSE TEST from 10.10.1.1 () port 0 AF_INET to 10.10.1.2 () port 0 AF_INET : +/-49.500% @ 99% conf.  : demo : first burst 0
Local /Remote
Socket Size   Request  Resp.   Elapsed  Trans.
Send   Recv   Size     Size    Time     Rate         
bytes  Bytes  bytes    bytes   secs.    per sec   

16384  131072 32       128     10.00    23498.64   
16384  131072
hand32@node0:~$ netperf -t TCP_RR -L 10.10.1.1 -H 10.10.1.2 -I 99 -- -r 32,128 -R 1
MIGRATED TCP REQUEST/RESPONSE TEST from 10.10.1.1 () port 0 AF_INET to 10.10.1.2 () port 0 AF_INET : +/-49.500% @ 99% conf.  : demo : first burst 0
Local /Remote
Socket Size   Request  Resp.   Elapsed  Trans.
Send   Recv   Size     Size    Time     Rate         
bytes  Bytes  bytes    bytes   secs.    per sec   

16384  131072 32       128     10.00    23446.50   
16384  131072
```

## Memcached

### Linux Default
```
ssh 10.10.1.1 taskset -c 0 ~/mutilate/mutilate --binary -s 10.10.1.2 --noload --agent=10.10.1.3,10.10.1.4,10.10.1.5,10.10.1.6 --threads=1 --keysize=fb_key --valuesize=fb_value --iadist=fb_ia --update=0.25 --depth=4 --measure_depth=1 --connections=16 --measure_connections=32 --measure_qps=2000 --qps=800000 --time=30
Server Output:
#type       avg     std     min     5th    10th    50th    90th    95th    99th
read       83.0    38.1    41.1    56.1    58.8    74.6   110.1   133.1   247.4
update     87.7    37.6    45.3    59.6    62.4    78.8   116.1   139.1   252.2
op_q        1.0     0.0     1.0     1.0     1.0     1.1     1.1     1.1     1.1

Total QPS = 800162.8 (24004884 / 30.0s)

#type       avg     std     min     5th    10th    50th    90th    95th    99th
read       99.0    75.6    41.1    57.0    60.6    79.6   140.5   195.0   459.2
update    104.5    76.7    45.3    61.1    64.5    85.1   148.5   200.4   464.1
op_q        1.0     0.0     1.0     1.0     1.0     1.1     1.1     1.1     1.1

Total QPS = 899559.9 (26986798 / 30.0s)

#type       avg     std     min     5th    10th    50th    90th    95th    99th
read      129.7   145.8    37.4    58.2    62.3    89.8   200.7   332.7   816.0
update    136.2   144.6    45.3    62.3    66.9    96.2   211.3   350.0   845.4
op_q        1.0     0.0     1.0     1.0     1.0     1.1     1.1     1.1     1.1

Total QPS = 999950.6 (29998520 / 30.0s)
```

### Symbiosis Poll
```

```
