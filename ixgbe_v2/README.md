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
