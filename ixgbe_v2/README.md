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
hand32@node0:~/mcd$ MQPS="100000" ./run_mcd.sh runDynamic
10.10.1.2 1 100000 10.10.1.1,10.10.1.3,10.10.1.4,10.10.1.5,10.10.1.6
TARGET_QPS=100000 TBENCH_SERVER=10.10.1.2 TBENCH_AGENTS=['10.10.1.1', '10.10.1.3', '10.10.1.4', '10.10.1.5', '10.10.1.6'] GITR= GDVFS=
~/mutilate/mutilate --agentmode --threads=16
~/mutilate/mutilate --agentmode --threads=16
~/mutilate/mutilate --agentmode --threads=16
~/mutilate/mutilate --agentmode --threads=16
pkill mutilate done
taskset -c 0-14 ~/memcached/memcached -u nobody -t 15 -m 50G -c 8192 -o hashpower=20 -b 8192 -l 10.10.1.2 -B binary -L
taskset -c 0 ~/mutilate/mutilate --binary -s 10.10.1.2 --loadonly -K fb_key -V fb_value
ssh 10.10.1.1 taskset -c 0 ~/mutilate/mutilate --binary -s 10.10.1.2 --noload --agent=10.10.1.3,10.10.1.4,10.10.1.5,10.10.1.6 --threads=1 --keysize=fb_key --valuesize=fb_value --iadist=fb_ia --update=0.25 --depth=4 --measure_depth=1 --connections=16 --measure_connections=32 --measure_qps=2000 --qps=100000 --time=30
Server Output:
node5.hand32-204119.bayopsys-pg: TCPConnection.cc(418): BEV_EVENT_ERROR: No route to host

hand32@node1:~/EELinux/eelinux$ taskset -c 15 ./ixgbe_poll 1
count=1 sched_getcpu = 15 ncpus=16


[  402.864017]  **** ixgbe_sym_napi_disable ****
[  449.351711] watchdog: BUG: soft lockup - CPU#15 stuck for 22s! [ixgbe_poll:12595]
[  449.366303] Modules linked in: ixgbe(E) nfsv3 nfs_acl nfs lockd grace fscache netfs ipod(OE) sunrpc intel_rapl_msr intel_rapl_common sb_edac x86_pkg_temp_thermal intel_powerclamp coretemp kvm_intel ast kvm drm_vram_helper drm_kms_helper binfmt_misc ipmi_ssif nls_iso8859_1 syscopyarea sysfillrect crct10dif_pclmul crc32_pclmul sysimgblt ghash_clmulni_intel fb_sys_fops cec aesni_intel rc_core crypto_simd cryptd drm_ttm_helper acpi_ipmi rapl joydev ipmi_si mei_me input_leds ttm mei ipmi_devintf dcdbas intel_cstate ipmi_msghandler acpi_pad mac_hid wmi ioatdma drm sch_fq_codel ramoops reed_solomon efi_pstore ip_tables x_tables autofs4 raid10 raid456 libcrc32c async_raid6_recov async_memcpy async_pq async_xor xor async_tx mlx4_ib ib_uverbs ib_core raid6_pq raid1 raid0 multipath linear hid_generic mlx4_core igb usbhid ahci i2c_i801 i2c_algo_bit hid mdio libahci i2c_smbus lpc_ich dca [last unloaded: ixgbe]
[  449.366371] CPU: 15 PID: 12595 Comm: ixgbe_poll Tainted: G           OE     5.14.0-symbiote+ #3
[  449.366375] Hardware name: Dell Inc. PowerEdge C6220 II/09N44V, BIOS 2.3.1 01/02/2014
[  449.366377] RIP: 0010:native_queued_spin_lock_slowpath+0x143/0x230
[  449.366388] Code: 5f 5d c3 44 8d 76 01 c1 e2 10 41 c1 e6 12 41 09 d6 44 89 f0 c1 e8 10 66 87 43 02 89 c2 c1 e2 10 75 6a 31 d2 eb 02 f3 90 8b 03 <66> 85 c0 75 f7 89 c1 66 31 c9 41 39 ce 0f 84 ac 00 00 00 c6 03 01
[  449.366390] RSP: 0018:ffffc900067dce90 EFLAGS: 00000202
[  449.366392] RAX: 0000000000400101 RBX: ffff888893bdac48 RCX: 0000000000000000
[  449.366394] RDX: 0000000000000000 RSI: 000000000000000f RDI: ffff888893bdac48
[  449.366395] RBP: ffffc900067dceb8 R08: 0000000000000246 R09: 0000000000000000
[  449.366397] R10: ffffffff828060c0 R11: ffffc900067dcff8 R12: ffff88905fbee4c0
[  449.366398] R13: ffff888893bdac48 R14: 0000000000400000 R15: ffff888893bdabc0
[  449.366400] FS:  00000000014413c0(0000) GS:ffff88905fbc0000(0000) knlGS:ffff88905fbc0000
[  449.366402] CS:  0010 DS: 0000 ES: 0000 CR0: 0000000080050033
[  449.366404] CR2: 00000000004c81b0 CR3: 000000088f22a002 CR4: 00000000000706e0
[  449.366406] Call Trace:
[  449.366409]  <IRQ>
[  449.366412]  _raw_spin_lock+0x1e/0x30
[  449.366418]  tcp_tsq_handler+0x1f/0x90
[  449.366423]  tcp_tasklet_func+0xc4/0x110
[  449.366425]  tasklet_action_common.constprop.0+0xc0/0xf0
[  449.366431]  tasklet_action+0x22/0x30
[  449.366434]  __do_softirq+0xd9/0x2e3
[  449.366438]  do_softirq+0x75/0xa0
[  449.366440]  </IRQ>
[  449.366441]  __local_bh_enable_ip+0x50/0x60
[  449.366444]  ip_finish_output2+0x1b8/0x5c0
[  449.366447]  ? neigh_resolve_output+0x114/0x1b0
[  449.366454]  ? __cgroup_bpf_run_filter_skb+0x408/0x5f0
[  449.366458]  __ip_finish_output+0x98/0x130
[  449.366460]  ip_finish_output+0x2e/0xc0
[  449.366462]  ip_output+0x78/0x100
[  449.366465]  ? __ip_finish_output+0x130/0x130
[  449.366467]  ip_local_out+0x5a/0x70
[  449.366469]  __ip_queue_xmit+0x166/0x400
[  449.366472]  ip_queue_xmit+0x15/0x20
[  449.366474]  __tcp_transmit_skb+0xaae/0xc60
[  449.366477]  tcp_write_xmit+0x396/0x1440
[  449.366479]  ? sock_def_readable+0x4b/0x80
[  449.366484]  ? tcp_data_ready+0x31/0xd0
[  449.366486]  __tcp_push_pending_frames+0x37/0x100
[  449.366489]  tcp_rcv_established+0x28f/0x6c0
[  449.366491]  tcp_v4_do_rcv+0x147/0x240
[  449.366494]  tcp_v4_rcv+0xc50/0xd60
[  449.366497]  ? enqueue_entity+0x17f/0x750
[  449.366501]  ip_protocol_deliver_rcu+0x21/0x110
[  449.366507]  ? nf_hook_slow+0x44/0xb0
[  449.366510]  ip_local_deliver_finish+0x48/0x60
[  449.366513]  ip_local_deliver+0xf3/0x100
[  449.366516]  ? tcp_send_fin+0x61/0x240
[  449.366518]  ? ip_protocol_deliver_rcu+0x110/0x110
[  449.366522]  ip_rcv+0x16b/0x190
[  449.366525]  ? try_to_wake_up+0x200/0x5c0
[  449.366529]  __netif_receive_skb_one_core+0x86/0xa0
[  449.366532]  __netif_receive_skb+0x15/0x60
[  449.366534]  netif_receive_skb+0x43/0x140
[  449.366537]  ? ixgbe_process_skb_fields+0x1b3/0x260 [ixgbe]
[  449.366551]  ixgbe_poll+0x552/0x11a0 [ixgbe]
[  449.366561]  ? do_syscall_64+0x69/0xc0
[  449.366568]  ixgbe_sym_poll+0x33/0x50 [ixgbe]
[  453.347598] watchdog: BUG: soft lockup - CPU#14 stuck for 26s! [mc-worker:12645]
[  453.366211] Modules linked in: ixgbe(E) nfsv3 nfs_acl nfs lockd grace fscache netfs ipod(OE) sunrpc intel_rapl_msr intel_rapl_common sb_edac x86_pkg_temp_thermal intel_powerclamp coretemp kvm_intel ast kvm drm_vram_helper drm_kms_helper binfmt_misc ipmi_ssif nls_iso8859_1 syscopyarea sysfillrect crct10dif_pclmul crc32_pclmul sysimgblt ghash_clmulni_intel fb_sys_fops cec aesni_intel rc_core crypto_simd cryptd drm_ttm_helper acpi_ipmi rapl joydev ipmi_si mei_me input_leds ttm mei ipmi_devintf dcdbas intel_cstate ipmi_msghandler acpi_pad mac_hid wmi ioatdma drm sch_fq_codel ramoops reed_solomon efi_pstore ip_tables x_tables autofs4 raid10 raid456 libcrc32c async_raid6_recov async_memcpy async_pq async_xor xor async_tx mlx4_ib ib_uverbs ib_core raid6_pq raid1 raid0 multipath linear hid_generic mlx4_core igb usbhid ahci i2c_i801 i2c_algo_bit hid mdio libahci i2c_smbus lpc_ich dca [last unloaded: ixgbe]
[  453.366264] CPU: 14 PID: 12645 Comm: mc-worker Tainted: G           OEL    5.14.0-symbiote+ #3
[  453.366266] Hardware name: Dell Inc. PowerEdge C6220 II/09N44V, BIOS 2.3.1 01/02/2014
[  453.366268] RIP: 0010:native_queued_spin_lock_slowpath+0x73/0x230
[  453.366273] Code: 0f ba 2b 08 0f 92 c2 8b 03 0f b6 d2 c1 e2 08 30 e4 09 d0 a9 00 01 ff ff 0f 85 0d 01 00 00 85 c0 74 0e 8b 03 84 c0 74 08 f3 90 <8b> 03 84 c0 75 f8 b8 01 00 00 00 66 89 03 5b 41 5c 41 5d 41 5e 41
[  453.366276] RSP: 0018:ffffc900084c3b80 EFLAGS: 00000202
[  453.366278] RAX: 0000000000400101 RBX: ffff888893bdac48 RCX: 0000000000000040
[  453.366279] RDX: 0000000000000000 RSI: 0000000000000000 RDI: ffff888893bdac48
[  453.366281] RBP: ffffc900084c3ba8 R08: 0000000000000000 R09: ffffc900084c3c7c
[  453.366282] R10: 0000000000000002 R11: 0000000000000000 R12: ffff888893bdac48
[  453.366283] R13: 0000000000003ff3 R14: ffffc900084c3cc8 R15: 0000000000000040
[  453.366285] FS:  00007fc4ca511640(0000) GS:ffff88905fb80000(0000) knlGS:0000000000000000
[  453.366287] CS:  0010 DS: 0000 ES: 0000 CR0: 0000000080050033
[  453.366288] CR2: 00007fc4cde37738 CR3: 000000088ef72003 CR4: 00000000000706e0
[  453.366290] Call Trace:

hand32@node1:~$ cat /proc/sys/kernel/watchdog_thresh 
0
hand32@node1:~$ cat /proc/sys/kernel/watchdog
0

[  521.689928] NETDEV WATCHDOG: enp3s0f0 (ixgbe): transmit queue 1 timed out
[  521.689951] WARNING: CPU: 9 PID: 0 at net/sched/sch_generic.c:477 dev_watchdog+0x251/0x260
[  521.689961] Modules linked in: ixgbe(E) nfsv3 nfs_acl nfs lockd grace fscache netfs ipod(OE) sunrpc intel_rapl_msr intel_rapl_common sb_edac x86_pkg_temp_thermal intel_powerclamp coretemp kvm_intel kvm binfmt_misc nls_iso8859_1 ast drm_vram_helper drm_kms_helper ipmi_ssif crct10dif_pclmul syscopyarea crc32_pclmul ghash_clmulni_intel sysfillrect aesni_intel sysimgblt crypto_simd fb_sys_fops cryptd cec rapl rc_core acpi_ipmi drm_ttm_helper ttm ipmi_si intel_cstate input_leds mei_me dcdbas joydev mei ipmi_devintf ioatdma wmi ipmi_msghandler acpi_pad mac_hid sch_fq_codel drm ramoops reed_solomon efi_pstore ip_tables x_tables autofs4 raid10 raid456 libcrc32c async_raid6_recov async_memcpy async_pq async_xor xor async_tx mlx4_ib ib_uverbs ib_core raid6_pq raid1 raid0 multipath linear hid_generic igb usbhid ahci i2c_i801 i2c_algo_bit mdio hid mlx4_core i2c_smbus libahci lpc_ich dca [last unloaded: ixgbe]
[  521.690363] CPU: 9 PID: 0 Comm: swapper/9 Tainted: G           OE     5.14.0-symbiote+ #3
[  521.690369] Hardware name: Dell Inc. PowerEdge C6220 II/09N44V, BIOS 2.3.1 01/02/2014
[  521.690373] RIP: 0010:dev_watchdog+0x251/0x260
[  521.690378] Code: 35 25 fd ff eb a3 4c 89 ff c6 05 7b c3 10 01 01 e8 44 f1 f9 ff 44 89 e9 4c 89 fe 48 c7 c7 60 a7 67 82 48 89 c2 e8 33 65 16 00 <0f> 0b eb 8c e9 03 9c 1f 00 66 0f 1f 44 00 00 0f 1f 44 00 00 55 48
[  521.690381] RSP: 0018:ffffc900066a4e70 EFLAGS: 00010282
[  521.690385] RAX: 0000000000000000 RBX: 0000000000000000 RCX: 000000000000083f
[  521.690387] RDX: 0000000000000000 RSI: 00000000000000f6 RDI: 000000000000083f
[  521.690389] RBP: ffffc900066a4ea0 R08: 0000000000000003 R09: fffffffffffd6090
[  521.690392] R10: 0000000000ffff0a R11: ffffc900066a4d08 R12: ffff888115374f40
[  521.690396] R13: 0000000000000001 R14: ffff88810b454440 R15: ffff88810b454000
[  521.690399] FS:  0000000000000000(0000) GS:ffff88905fa40000(0000) knlGS:0000000000000000
[  521.690402] CS:  0010 DS: 0000 ES: 0000 CR0: 0000000080050033
[  521.690404] CR2: 00005596a44f3b08 CR3: 0000000002810002 CR4: 00000000000706e0
[  521.690408] Call Trace:
[  521.690413]  <IRQ>
[  521.690418]  ? pfifo_fast_enqueue+0x150/0x150
[  521.690422]  call_timer_fn+0x2b/0x120
[  521.690428]  __run_timers.part.0+0x1dd/0x250
[  521.690433]  ? lapic_next_deadline+0x2c/0x40
[  521.690441]  ? clockevents_program_event+0xa9/0x120
[  521.690449]  run_timer_softirq+0x2a/0x50
[  521.690453]  __do_softirq+0xd9/0x2e3
[  521.690462]  irq_exit_rcu+0xad/0xd0
[  521.690470]  sysvec_apic_timer_interrupt+0x7c/0x90
[  521.690479]  </IRQ>
[  521.690481]  asm_sysvec_apic_timer_interrupt+0x12/0x20
[  521.690486] RIP: 0010:cpuidle_enter_state+0xd9/0x620
[  521.690490] Code: 3d d4 59 61 7e e8 17 b9 6f ff 49 89 c7 0f 1f 44 00 00 31 ff e8 e8 c4 6f ff 80 7d d0 00 0f 85 5d 01 00 00 fb 66 0f 1f 44 00 00 <45> 85 f6 0f 88 69 01 00 00 4d 63 ee 49 83 fd 09 0f 87 e3 03 00 00
[  521.690493] RSP: 0018:ffffc9000640fe38 EFLAGS: 00000246
[  521.690497] RAX: ffff88905fa6d740 RBX: ffffe8ffffa40600 RCX: 0000000000000000
[  521.690499] RDX: 0000000000000000 RSI: 0000000000000002 RDI: 0000000000000000
[  521.690502] RBP: ffffc9000640fe88 R08: 0000007977243777 R09: 00000000000493e0
[  521.690506] R10: 000000786ba07378 R11: 071c71c71c71c71c R12: ffffffff82ad3220
[  521.690508] R13: 0000000000000004 R14: 0000000000000004 R15: 0000007977243777
[  521.690513]  ? cpuidle_enter_state+0xc8/0x620
[  521.690517]  cpuidle_enter+0x2e/0x40
[  521.690520]  do_idle+0x203/0x2a0
[  521.690526]  cpu_startup_entry+0x20/0x30
[  521.690531]  start_secondary+0x12a/0x180
[  521.690536]  secondary_startup_64_no_verify+0xc2/0xcb
[  521.690544] ---[ end trace 134faf2ac47ce2b7 ]---
[  521.690549] ixgbe 0000:03:00.0 enp3s0f0: initiating reset due to tx timeout
[  521.690587] ixgbe 0000:03:00.0 enp3s0f0: Reset adapter

```
