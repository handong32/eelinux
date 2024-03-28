## Debugging napi ixgbe

Added `pr_info("%s\n", __FUNCTION__);` to every function call in ixgbe device driver

```
dmesg.1 is output - getting "/dev/kmsg buffer overrun, some messages lost." messages.
Seeing a lot of calls to ixgbe_alloc_mapped_page and ixgbe_read_reg, which are basic calls to alloc memory and reading device registers. Also calls to ixgbe_get_ring_stats64, which is part of some statistic bookkeeping.
-> Removing them and seeing what calls actually matter

dmesg.2 - cleaned up a lot of redundant comments causing overflow. I see ixgbe_update_itr getting called by ixgbe_poll pretty frequently, so took that out. Also ixgbe_update_dca which is Direct Cache Access mechanism; a mostly hardware mechanism that I'll comment out too.

dmesg.3 -
	Remove ixgbe_rx_frame_truesize, its doing page aligning work
	Remove ixgbe_get_tx_completed, ixgbe_get_tx_pending, and ixgbe_check_tx_hang as they are called by ixgbe_clean_tx_irq, which is invoked by ixgbe_poll

dmesg.4 -
        Getting spammed with ixgbe_clean_tx_irq and ixgbe_clean_rx_irq, which are basic functions that reap memory pages from transmitted packets and ingest received packets -> Removing them for now	
```


## Disabling NAPI

After NAPI is disabled, 
```

```