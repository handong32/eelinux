## dmesg log when

```
Server:
hand32@node1:~/EELinux/eelinux/linux$ taskset -c 13 socat - TCP-LISTEN:8889
sdasd
asdas
asdasd
```

```
Client:
hand32@node0:~$ socat -  TCP:10.10.1.2:8889
sdasd
asdas
asdasd
```

## on core 13
```
249216.898765] ixgbe: ixgbe_poll v_idx=13 budget=64
[249216.898770] ixgbe: ixgbe_get_rx_buffer
[249216.898772] ixgbe: ixgbe_run_xdp
[249216.898774] ixgbe: ixgbe_build_skb
[249216.898777] ixgbe: ixgbe_put_rx_buffer
[249216.898779] ixgbe: ixgbe_can_reuse_rx_page
[249216.898782] ixgbe: ixgbe_reuse_rx_page
[249216.898784] ixgbe: ixgbe_is_non_eop
[249216.898786] ixgbe: ixgbe_cleanup_headers
[249216.898788] ixgbe: ixgbe_process_skb_fields
[249216.898790] ixgbe: ixgbe_update_rsc_stats
[249216.898792] ixgbe: ixgbe_rx_hash
[249216.898794] ixgbe: ixgbe_rx_checksum
[249216.898797] ixgbe: ixgbe_rx_skb
[249216.898819] ixgbe: ixgbe_features_check
[249216.898823] ixgbe: ixgbe_xmit_frame
[249216.898825] ixgbe: __ixgbe_xmit_frame
[249216.898828] ixgbe: ixgbe_xmit_frame_ring
[249216.898829] ixgbe: ixgbe_maybe_stop_tx
[249216.898831] ixgbe: ixgbe_tso
[249216.898833] ixgbe: ixgbe_tx_csum
[249216.898836] ixgbe: ixgbe_atr
[249216.898838] ixgbe: ixgbe_tx_cmd_type
[249216.898840] ixgbe: ixgbe_tx_map
[249216.898842] ixgbe: ixgbe_tx_olinfo_status
[249216.898845] ixgbe: ixgbe_maybe_stop_tx
[249216.898850] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[249216.898860] ixgbe: ixgbe_msix_clean_rings
[249216.898863] ixgbe: ixgbe_poll v_idx=13 budget=64
[249216.898867] ixgbe: ixgbe_write_eitr
[249216.898869] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[249216.898898] ixgbe: ixgbe_msix_clean_rings
[249216.898903] ixgbe: ixgbe_poll v_idx=13 budget=64
[249216.898907] ixgbe: ixgbe_get_rx_buffer
[249216.898909] ixgbe: ixgbe_run_xdp
[249216.898911] ixgbe: ixgbe_build_skb
[249216.898914] ixgbe: ixgbe_put_rx_buffer
[249216.898916] ixgbe: ixgbe_can_reuse_rx_page
[249216.898919] ixgbe: ixgbe_reuse_rx_page
[249216.898921] ixgbe: ixgbe_is_non_eop
[249216.898922] ixgbe: ixgbe_cleanup_headers
[249216.898925] ixgbe: ixgbe_process_skb_fields
[249216.898927] ixgbe: ixgbe_update_rsc_stats
[249216.898929] ixgbe: ixgbe_rx_hash
[249216.898932] ixgbe: ixgbe_rx_checksum
[249216.898934] ixgbe: ixgbe_rx_skb
[249216.898952] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[249218.089724] ixgbe: ixgbe_msix_clean_rings
[249218.089742] ixgbe: ixgbe_poll v_idx=13 budget=64
[249218.089745] ixgbe: ixgbe_get_rx_buffer
[249218.089748] ixgbe: ixgbe_run_xdp
[249218.089750] ixgbe: ixgbe_build_skb
[249218.089752] ixgbe: ixgbe_put_rx_buffer
[249218.089754] ixgbe: ixgbe_can_reuse_rx_page
[249218.089756] ixgbe: ixgbe_reuse_rx_page
[249218.089758] ixgbe: ixgbe_is_non_eop
[249218.089759] ixgbe: ixgbe_cleanup_headers
[249218.089762] ixgbe: ixgbe_process_skb_fields
[249218.089764] ixgbe: ixgbe_update_rsc_stats
[249218.089766] ixgbe: ixgbe_rx_hash
[249218.089768] ixgbe: ixgbe_rx_checksum
[249218.089770] ixgbe: ixgbe_rx_skb
[249218.089789] ixgbe: ixgbe_features_check
[249218.089793] ixgbe: ixgbe_xmit_frame
[249218.089795] ixgbe: __ixgbe_xmit_frame
[249218.089797] ixgbe: ixgbe_xmit_frame_ring
[249218.089799] ixgbe: ixgbe_maybe_stop_tx
[249218.089801] ixgbe: ixgbe_tso
[249218.089803] ixgbe: ixgbe_tx_csum
[249218.089805] ixgbe: ixgbe_atr
[249218.089807] ixgbe: ixgbe_tx_cmd_type
[249218.089809] ixgbe: ixgbe_tx_map
[249218.089810] ixgbe: ixgbe_tx_olinfo_status
[249218.089813] ixgbe: ixgbe_maybe_stop_tx
[249218.089816] ixgbe: ixgbe_write_eitr
[249218.089819] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[249218.089827] ixgbe: ixgbe_msix_clean_rings
[249218.089830] ixgbe: ixgbe_poll v_idx=13 budget=64
[249218.089835] ixgbe: ixgbe_write_eitr
[249218.089837] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[249218.178718] ixgbe: ixgbe_service_timer
[249218.178735] ixgbe: ixgbe_service_event_schedule
[249218.178772] ixgbe: ixgbe_service_task
[249218.178776] ixgbe: ixgbe_check_fw_error
[249218.178779] ixgbe: ixgbe_reset_subtask
[249218.178780] ixgbe: ixgbe_phy_interrupt_subtask
[249218.178781] ixgbe: ixgbe_sfp_detection_subtask
[249218.178783] ixgbe: ixgbe_sfp_link_config_subtask
[249218.178784] ixgbe: ixgbe_check_overtemp_subtask
[249218.178785] ixgbe: ixgbe_watchdog_subtask
[249218.178787] ixgbe: ixgbe_watchdog_update_link
[249218.178788] ixgbe: ixgbe_watchdog_link_is_up
[249218.178789] ixgbe: ixgbe_check_for_bad_vf
[249218.178791] ixgbe: ixgbe_spoof_check
[249218.178792] ixgbe: ixgbe_update_stats
[249218.178860] ixgbe: ixgbe_update_xoff_received
[249218.178861] ixgbe: ixgbe_update_xoff_rx_lfc
[249218.178887] ixgbe: ixgbe_watchdog_flush_tx
[249218.178889] ixgbe: ixgbe_fdir_reinit_subtask
[249218.178890] ixgbe: ixgbe_check_hang_subtask
[249218.178892] ixgbe: ixgbe_irq_rearm_queues
[249218.178893] ixgbe: ixgbe_service_event_complete
[249218.178899] ixgbe: ixgbe_msix_clean_rings
[249218.178900] ixgbe: ixgbe_msix_clean_rings
[249218.178899] ixgbe: ixgbe_msix_clean_rings
[249218.178900] ixgbe: ixgbe_msix_clean_rings
[249218.178900] ixgbe: ixgbe_msix_clean_rings
[249218.178901] ixgbe: ixgbe_msix_clean_rings
[249218.178900] ixgbe: ixgbe_msix_clean_rings
[249218.178904] ixgbe: ixgbe_msix_clean_rings
[249218.178902] ixgbe: ixgbe_poll v_idx=17 budget=64
[249218.178906] ixgbe: ixgbe_poll v_idx=15 budget=64
[249218.178901] ixgbe: ixgbe_msix_clean_rings
[249218.178909] ixgbe: ixgbe_poll v_idx=19 budget=64
[249218.178913] ixgbe: ixgbe_poll v_idx=8 budget=64
[249218.178916] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[249218.178916] ixgbe: ixgbe_poll v_idx=4 budget=64
[249218.178918] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[249218.178920] ixgbe: ixgbe_poll v_idx=7 budget=64
[249218.178920] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[249218.178923] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[249218.178924] ixgbe: ixgbe_poll v_idx=14 budget=64
[249218.178926] ixgbe: ixgbe_msix_clean_rings
[249218.178928] ixgbe: ixgbe_poll v_idx=12 budget=64
[249218.178928] ixgbe: ixgbe_msix_clean_rings
[249218.178927] ixgbe: ixgbe_msix_clean_rings
[249218.178929] ixgbe: ixgbe_msix_clean_rings
[249218.178933] ixgbe: ixgbe_msix_clean_rings
[249218.178932] ixgbe: ixgbe_msix_clean_rings
[249218.178929] ixgbe: ixgbe_msix_clean_rings
[249218.178928] ixgbe: ixgbe_msix_clean_rings
[249218.178934] ixgbe: ixgbe_msix_clean_rings
[249218.178944] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[249218.178931] ixgbe: ixgbe_msix_clean_rings
[249218.178945] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[249218.178943] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[249218.178930] ixgbe: ixgbe_msix_clean_rings
[249218.178934] ixgbe: ixgbe_poll v_idx=11 budget=64
[249218.178951] ixgbe: ixgbe_poll v_idx=13 budget=64
[249218.178930] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[249218.178959] ixgbe: ixgbe_poll v_idx=5 budget=64
[249218.178962] ixgbe: ixgbe_poll v_idx=1 budget=64
[249218.178969] ixgbe: ixgbe_poll v_idx=16 budget=64
[249218.178972] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[249218.178968] ixgbe: ixgbe_poll v_idx=6 budget=64
[249218.178984] ixgbe: ixgbe_poll v_idx=2 budget=64
[249218.178984] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[249218.178989] ixgbe: ixgbe_poll v_idx=3 budget=64
[249218.178986] ixgbe: ixgbe_write_eitr
[249218.178993] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[249218.178992] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[249218.178994] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[249218.178991] ixgbe: ixgbe_poll v_idx=9 budget=64
[249218.179000] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[249218.179000] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[249218.179005] ixgbe: ixgbe_poll v_idx=18 budget=64
[249218.179007] ixgbe: ixgbe_poll v_idx=0 budget=64
[249218.179019] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[249218.179026] ixgbe: ixgbe_poll v_idx=10 budget=64
[249218.179029] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[249218.179032] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[249218.179034] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[249218.179033] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[249218.947347] ixgbe: ixgbe_msix_clean_rings
[249218.947363] ixgbe: ixgbe_poll v_idx=13 budget=64
[249218.947367] ixgbe: ixgbe_get_rx_buffer
[249218.947369] ixgbe: ixgbe_run_xdp
[249218.947371] ixgbe: ixgbe_build_skb
[249218.947374] ixgbe: ixgbe_put_rx_buffer
[249218.947376] ixgbe: ixgbe_can_reuse_rx_page
[249218.947378] ixgbe: ixgbe_reuse_rx_page
[249218.947380] ixgbe: ixgbe_is_non_eop
[249218.947382] ixgbe: ixgbe_cleanup_headers
[249218.947384] ixgbe: ixgbe_process_skb_fields
[249218.947386] ixgbe: ixgbe_update_rsc_stats
[249218.947388] ixgbe: ixgbe_rx_hash
[249218.947389] ixgbe: ixgbe_rx_checksum
[249218.947391] ixgbe: ixgbe_rx_skb
[249218.947406] ixgbe: ixgbe_features_check
[249218.947410] ixgbe: ixgbe_xmit_frame
[249218.947412] ixgbe: __ixgbe_xmit_frame
[249218.947415] ixgbe: ixgbe_xmit_frame_ring
[249218.947417] ixgbe: ixgbe_maybe_stop_tx
[249218.947419] ixgbe: ixgbe_tso
[249218.947421] ixgbe: ixgbe_tx_csum
[249218.947423] ixgbe: ixgbe_atr
[249218.947425] ixgbe: ixgbe_tx_cmd_type
[249218.947427] ixgbe: ixgbe_tx_map
[249218.947429] ixgbe: ixgbe_tx_olinfo_status
[249218.947431] ixgbe: ixgbe_maybe_stop_tx
[249218.947436] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[249218.947444] ixgbe: ixgbe_msix_clean_rings
[249218.947447] ixgbe: ixgbe_poll v_idx=13 budget=64
[249218.947451] ixgbe: ixgbe_write_eitr
[249218.947454] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[249220.194672] ixgbe: ixgbe_service_timer
[249220.194690] ixgbe: ixgbe_service_event_schedule
[249220.194725] ixgbe: ixgbe_service_task
[249220.194730] ixgbe: ixgbe_check_fw_error
[249220.194733] ixgbe: ixgbe_reset_subtask
[249220.194734] ixgbe: ixgbe_phy_interrupt_subtask
[249220.194735] ixgbe: ixgbe_sfp_detection_subtask
[249220.194736] ixgbe: ixgbe_sfp_link_config_subtask
[249220.194737] ixgbe: ixgbe_check_overtemp_subtask
[249220.194739] ixgbe: ixgbe_watchdog_subtask
[249220.194739] ixgbe: ixgbe_watchdog_update_link
[249220.194740] ixgbe: ixgbe_watchdog_link_is_up
[249220.194741] ixgbe: ixgbe_check_for_bad_vf
[249220.194743] ixgbe: ixgbe_spoof_check
[249220.194744] ixgbe: ixgbe_update_stats
[249220.194811] ixgbe: ixgbe_update_xoff_received
[249220.194813] ixgbe: ixgbe_update_xoff_rx_lfc
[249220.194839] ixgbe: ixgbe_watchdog_flush_tx
[249220.194840] ixgbe: ixgbe_fdir_reinit_subtask
[249220.194842] ixgbe: ixgbe_check_hang_subtask
[249220.194844] ixgbe: ixgbe_irq_rearm_queues
[249220.194845] ixgbe: ixgbe_service_event_complete
[249220.194851] ixgbe: ixgbe_msix_clean_rings
[249220.194851] ixgbe: ixgbe_msix_clean_rings
[249220.194852] ixgbe: ixgbe_msix_clean_rings
[249220.194853] ixgbe: ixgbe_msix_clean_rings
[249220.194853] ixgbe: ixgbe_msix_clean_rings
[249220.194852] ixgbe: ixgbe_msix_clean_rings
[249220.194854] ixgbe: ixgbe_poll v_idx=19 budget=64
[249220.194855] ixgbe: ixgbe_poll v_idx=17 budget=64
[249220.194853] ixgbe: ixgbe_msix_clean_rings
[249220.194854] ixgbe: ixgbe_msix_clean_rings
[249220.194852] ixgbe: ixgbe_msix_clean_rings
[249220.194853] ixgbe: ixgbe_msix_clean_rings
[249220.194865] ixgbe: ixgbe_poll v_idx=7 budget=64
[249220.194867] ixgbe: ixgbe_poll v_idx=8 budget=64
[249220.194870] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[249220.194869] ixgbe: ixgbe_poll v_idx=15 budget=64
[249220.194872] ixgbe: ixgbe_poll v_idx=0 budget=64
[249220.194876] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[249220.194879] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[249220.194880] ixgbe: ixgbe_poll v_idx=14 budget=64
[249220.194877] ixgbe: ixgbe_msix_clean_rings
[249220.194883] ixgbe: ixgbe_msix_clean_rings
[249220.194879] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[249220.194883] ixgbe: ixgbe_msix_clean_rings
[249220.194879] ixgbe: ixgbe_poll v_idx=11 budget=64
[249220.194885] ixgbe: ixgbe_msix_clean_rings
[249220.194881] ixgbe: ixgbe_msix_clean_rings
[249220.194878] ixgbe: ixgbe_msix_clean_rings
[249220.194886] ixgbe: ixgbe_msix_clean_rings
[249220.194886] ixgbe: ixgbe_poll v_idx=16 budget=64
[249220.194881] ixgbe: ixgbe_msix_clean_rings
[249220.194886] ixgbe: ixgbe_msix_clean_rings
[249220.194899] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[249220.194904] ixgbe: ixgbe_poll v_idx=4 budget=64
[249220.194896] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[249220.194902] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[249220.194909] ixgbe: ixgbe_poll v_idx=13 budget=64
[249220.194914] ixgbe: ixgbe_poll v_idx=5 budget=64
[249220.194920] ixgbe: ixgbe_poll v_idx=3 budget=64
[249220.194923] ixgbe: ixgbe_poll v_idx=6 budget=64
[249220.194912] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[249220.194927] ixgbe: ixgbe_poll v_idx=2 budget=64
[249220.194926] ixgbe: ixgbe_poll v_idx=9 budget=64
[249220.194928] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[249220.194916] ixgbe: ixgbe_poll v_idx=10 budget=64
[249220.194932] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[249220.194930] ixgbe: ixgbe_poll v_idx=1 budget=64
[249220.194880] ixgbe: ixgbe_msix_clean_rings
[249220.194938] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[249220.194951] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[249220.194953] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[249220.194952] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[249220.194960] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[249220.194958] ixgbe: ixgbe_poll v_idx=12 budget=64
[249220.194965] ixgbe: ixgbe_poll v_idx=18 budget=64
[249220.194967] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[249220.194973] ixgbe: ixgbe_write_eitr
[249220.194975] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[249220.194979] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[249220.194980] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[249220.194983] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[249220.610887] ixgbe: ixgbe_features_check
[249220.610892] ixgbe: ixgbe_xmit_frame
[249220.610893] ixgbe: __ixgbe_xmit_frame
[249220.610895] ixgbe: ixgbe_xmit_frame_ring
[249220.610896] ixgbe: ixgbe_maybe_stop_tx
[249220.610897] ixgbe: ixgbe_tso
[249220.610898] ixgbe: ixgbe_tx_csum
[249220.610899] ixgbe: ixgbe_atr
[249220.610900] ixgbe: ixgbe_tx_cmd_type
[249220.610901] ixgbe: ixgbe_tx_map
[249220.610902] ixgbe: ixgbe_tx_olinfo_status
[249220.610903] ixgbe: ixgbe_maybe_stop_tx
[249220.610911] ixgbe: ixgbe_msix_clean_rings
[249220.610913] ixgbe: ixgbe_poll v_idx=3 budget=64
[249220.610917] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[249220.611037] ixgbe: ixgbe_msix_clean_rings
[249220.611053] ixgbe: ixgbe_poll v_idx=13 budget=64
[249220.611057] ixgbe: ixgbe_get_rx_buffer
[249220.611060] ixgbe: ixgbe_run_xdp
[249220.611062] ixgbe: ixgbe_build_skb
[249220.611065] ixgbe: ixgbe_put_rx_buffer
[249220.611067] ixgbe: ixgbe_can_reuse_rx_page
[249220.611070] ixgbe: ixgbe_reuse_rx_page
[249220.611072] ixgbe: ixgbe_is_non_eop
[249220.611074] ixgbe: ixgbe_cleanup_headers
[249220.611077] ixgbe: ixgbe_process_skb_fields
[249220.611080] ixgbe: ixgbe_update_rsc_stats
[249220.611082] ixgbe: ixgbe_rx_hash
[249220.611084] ixgbe: ixgbe_rx_checksum
[249220.611087] ixgbe: ixgbe_rx_skb
[249220.611100] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues

```

## After NAPI is disable, possible issues where packet receive might not work anymore
```
ixgbe_rx_skb calls napi_gro_receive -> does this call happen? ixgbe_rx_skb is the function that passes receive buffers up the stack

At the end of ixgbe_poll, calls to ixgbe_set_itr and ixgbe_irq_enable_queues after checking napi_complete_done, now these calls won't happen

```