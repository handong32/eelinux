## Basic ixgbe_napi_disable to see what happens -> basically interrupts coming in but we are not handling anything

```
hand32@node1:~/EELinux/eelinux$ sudo dmesg -W
[250637.613984] ixgbe: ixgbe_service_timer
[250637.614003] ixgbe: ixgbe_service_event_schedule
[250637.614041] ixgbe: ixgbe_service_task
[250637.614047] ixgbe: ixgbe_check_fw_error
[250637.614049] ixgbe: ixgbe_reset_subtask
[250637.614050] ixgbe: ixgbe_phy_interrupt_subtask
[250637.614051] ixgbe: ixgbe_sfp_detection_subtask
[250637.614053] ixgbe: ixgbe_sfp_link_config_subtask
[250637.614053] ixgbe: ixgbe_check_overtemp_subtask
[250637.614054] ixgbe: ixgbe_watchdog_subtask
[250637.614055] ixgbe: ixgbe_watchdog_update_link
[250637.614056] ixgbe: ixgbe_watchdog_link_is_up
[250637.614057] ixgbe: ixgbe_check_for_bad_vf
[250637.614058] ixgbe: ixgbe_spoof_check
[250637.614059] ixgbe: ixgbe_update_stats
[250637.614126] ixgbe: ixgbe_update_xoff_received
[250637.614128] ixgbe: ixgbe_update_xoff_rx_lfc
[250637.614154] ixgbe: ixgbe_watchdog_flush_tx
[250637.614155] ixgbe: ixgbe_fdir_reinit_subtask
[250637.614156] ixgbe: ixgbe_check_hang_subtask
[250637.614158] ixgbe: ixgbe_irq_rearm_queues
[250637.614160] ixgbe: ixgbe_service_event_complete
[250637.614166] ixgbe: ixgbe_msix_clean_rings
[250637.614167] ixgbe: ixgbe_msix_clean_rings
[250637.614167] ixgbe: ixgbe_msix_clean_rings
[250637.614168] ixgbe: ixgbe_msix_clean_rings
[250637.614170] ixgbe: ixgbe_msix_clean_rings
[250637.614168] ixgbe: ixgbe_msix_clean_rings
[250637.614167] ixgbe: ixgbe_msix_clean_rings
[250637.614169] ixgbe: ixgbe_msix_clean_rings
[250637.614171] ixgbe: ixgbe_msix_clean_rings
[250637.614177] ixgbe: ixgbe_poll v_idx=14 budget=64
[250637.614180] ixgbe: ixgbe_poll v_idx=8 budget=64
[250637.614182] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250637.614181] ixgbe: ixgbe_poll v_idx=19 budget=64
[250637.614180] ixgbe: ixgbe_poll v_idx=5 budget=64
[250637.614182] ixgbe: ixgbe_poll v_idx=3 budget=64
[250637.614187] ixgbe: ixgbe_poll v_idx=10 budget=64
[250637.614191] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250637.614191] ixgbe: ixgbe_poll v_idx=0 budget=64
[250637.614191] ixgbe: ixgbe_poll v_idx=7 budget=64
[250637.614195] ixgbe: ixgbe_msix_clean_rings
[250637.614195] ixgbe: ixgbe_msix_clean_rings
[250637.614194] ixgbe: ixgbe_msix_clean_rings
[250637.614194] ixgbe: ixgbe_msix_clean_rings
[250637.614200] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250637.614198] ixgbe: ixgbe_msix_clean_rings
[250637.614198] ixgbe: ixgbe_msix_clean_rings
[250637.614190] ixgbe: ixgbe_poll v_idx=9 budget=64
[250637.614197] ixgbe: ixgbe_msix_clean_rings
[250637.614195] ixgbe: ixgbe_msix_clean_rings
[250637.614206] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250637.614196] ixgbe: ixgbe_msix_clean_rings
[250637.614193] ixgbe: ixgbe_msix_clean_rings
[250637.614197] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250637.614200] ixgbe: ixgbe_msix_clean_rings
[250637.614221] ixgbe: ixgbe_poll v_idx=16 budget=64
[250637.614222] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250637.614216] ixgbe: ixgbe_poll v_idx=12 budget=64
[250637.614225] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250637.614201] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250637.614226] ixgbe: ixgbe_poll v_idx=17 budget=64
[250637.614237] ixgbe: ixgbe_poll v_idx=1 budget=64
[250637.614238] ixgbe: ixgbe_poll v_idx=2 budget=64
[250637.614244] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250637.614249] ixgbe: ixgbe_poll v_idx=6 budget=64
[250637.614256] ixgbe: ixgbe_poll v_idx=4 budget=64
[250637.614259] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250637.614262] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250637.614254] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250637.614267] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250637.614271] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250637.614268] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250637.614270] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250637.614277] ixgbe: ixgbe_poll v_idx=11 budget=64
[250637.614285] ixgbe: ixgbe_poll v_idx=18 budget=64
[250637.614287] ixgbe: ixgbe_poll v_idx=15 budget=64
[250637.614299] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250637.614301] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250637.614304] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250637.614308] ixgbe: ixgbe_poll v_idx=13 budget=64
[250637.614318] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250639.324134]  **** han_napi_DISABLE  ****
[250639.324139] ixgbe: ixgbe_irq_disable
[250639.324151] ixgbe: ixgbe_napi_disable_all
[250639.324155] ixgbe: ixgbe_irq_disable
[250639.629954] ixgbe: ixgbe_service_timer
[250639.629972] ixgbe: ixgbe_service_event_schedule
[250639.630011] ixgbe: ixgbe_service_task
[250639.630017] ixgbe: ixgbe_check_fw_error
[250639.630019] ixgbe: ixgbe_reset_subtask
[250639.630021] ixgbe: ixgbe_phy_interrupt_subtask
[250639.630022] ixgbe: ixgbe_sfp_detection_subtask
[250639.630023] ixgbe: ixgbe_sfp_link_config_subtask
[250639.630024] ixgbe: ixgbe_check_overtemp_subtask
[250639.630025] ixgbe: ixgbe_watchdog_subtask
[250639.630026] ixgbe: ixgbe_watchdog_update_link
[250639.630027] ixgbe: ixgbe_watchdog_link_is_up
[250639.630028] ixgbe: ixgbe_check_for_bad_vf
[250639.630030] ixgbe: ixgbe_spoof_check
[250639.630031] ixgbe: ixgbe_update_stats
[250639.630099] ixgbe: ixgbe_update_xoff_received
[250639.630101] ixgbe: ixgbe_update_xoff_rx_lfc
[250639.630126] ixgbe: ixgbe_watchdog_flush_tx
[250639.630128] ixgbe: ixgbe_fdir_reinit_subtask
[250639.630129] ixgbe: ixgbe_check_hang_subtask
[250639.630132] ixgbe: ixgbe_irq_rearm_queues
[250639.630133] ixgbe: ixgbe_service_event_complete
[250639.630139] ixgbe: ixgbe_msix_clean_rings
[250639.630139] ixgbe: ixgbe_msix_clean_rings
[250639.630141] ixgbe: ixgbe_msix_clean_rings
[250639.630140] ixgbe: ixgbe_msix_clean_rings
[250639.630141] ixgbe: ixgbe_msix_clean_rings
[250639.630141] ixgbe: ixgbe_msix_clean_rings
[250639.630142] ixgbe: ixgbe_msix_clean_rings
[250639.630143] ixgbe: ixgbe_msix_clean_rings
[250639.630141] ixgbe: ixgbe_msix_clean_rings
[250639.630167] ixgbe: ixgbe_msix_clean_rings
[250639.630167] ixgbe: ixgbe_msix_clean_rings
[250639.630168] ixgbe: ixgbe_msix_clean_rings
[250639.630169] ixgbe: ixgbe_msix_clean_rings
[250639.630168] ixgbe: ixgbe_msix_clean_rings
[250639.630169] ixgbe: ixgbe_msix_clean_rings
[250639.630171] ixgbe: ixgbe_msix_clean_rings
[250639.630170] ixgbe: ixgbe_msix_clean_rings
[250639.630172] ixgbe: ixgbe_msix_clean_rings
[250639.630171] ixgbe: ixgbe_msix_clean_rings
[250639.630174] ixgbe: ixgbe_msix_clean_rings
[250641.645882] ixgbe: ixgbe_service_timer
[250641.645900] ixgbe: ixgbe_service_event_schedule
[250641.645936] ixgbe: ixgbe_service_task
[250641.645942] ixgbe: ixgbe_check_fw_error
[250641.645944] ixgbe: ixgbe_reset_subtask
[250641.645945] ixgbe: ixgbe_phy_interrupt_subtask
[250641.645946] ixgbe: ixgbe_sfp_detection_subtask
[250641.645947] ixgbe: ixgbe_sfp_link_config_subtask
[250641.645947] ixgbe: ixgbe_check_overtemp_subtask
[250641.645948] ixgbe: ixgbe_watchdog_subtask
[250641.645949] ixgbe: ixgbe_watchdog_update_link
[250641.645950] ixgbe: ixgbe_watchdog_link_is_up
[250641.645951] ixgbe: ixgbe_check_for_bad_vf
[250641.645953] ixgbe: ixgbe_spoof_check
[250641.645954] ixgbe: ixgbe_update_stats
[250641.646022] ixgbe: ixgbe_update_xoff_received
[250641.646023] ixgbe: ixgbe_update_xoff_rx_lfc
[250641.646049] ixgbe: ixgbe_watchdog_flush_tx
[250641.646051] ixgbe: ixgbe_fdir_reinit_subtask
[250641.646052] ixgbe: ixgbe_check_hang_subtask
[250641.646053] ixgbe: ixgbe_irq_rearm_queues
[250641.646055] ixgbe: ixgbe_service_event_complete
[250641.646062] ixgbe: ixgbe_msix_clean_rings
[250641.646062] ixgbe: ixgbe_msix_clean_rings
[250641.646063] ixgbe: ixgbe_msix_clean_rings
[250641.646063] ixgbe: ixgbe_msix_clean_rings
[250641.646064] ixgbe: ixgbe_msix_clean_rings
[250641.646065] ixgbe: ixgbe_msix_clean_rings
[250641.646065] ixgbe: ixgbe_msix_clean_rings
[250641.646064] ixgbe: ixgbe_msix_clean_rings
[250641.646065] ixgbe: ixgbe_msix_clean_rings
[250641.646089] ixgbe: ixgbe_msix_clean_rings
[250641.646090] ixgbe: ixgbe_msix_clean_rings
[250641.646091] ixgbe: ixgbe_msix_clean_rings
[250641.646090] ixgbe: ixgbe_msix_clean_rings
[250641.646091] ixgbe: ixgbe_msix_clean_rings
[250641.646093] ixgbe: ixgbe_msix_clean_rings
[250641.646092] ixgbe: ixgbe_msix_clean_rings
[250641.646095] ixgbe: ixgbe_msix_clean_rings
[250641.646094] ixgbe: ixgbe_msix_clean_rings
[250641.646093] ixgbe: ixgbe_msix_clean_rings
[250641.646092] ixgbe: ixgbe_msix_clean_rings
[250643.661898] ixgbe: ixgbe_service_timer
[250643.661916] ixgbe: ixgbe_service_event_schedule
[250643.661961] ixgbe: ixgbe_service_task
[250643.661966] ixgbe: ixgbe_check_fw_error
[250643.661969] ixgbe: ixgbe_reset_subtask
[250643.661970] ixgbe: ixgbe_phy_interrupt_subtask
[250643.661972] ixgbe: ixgbe_sfp_detection_subtask
[250643.661973] ixgbe: ixgbe_sfp_link_config_subtask
[250643.661974] ixgbe: ixgbe_check_overtemp_subtask
[250643.661975] ixgbe: ixgbe_watchdog_subtask
[250643.661977] ixgbe: ixgbe_watchdog_update_link
[250643.661978] ixgbe: ixgbe_watchdog_link_is_up
[250643.661979] ixgbe: ixgbe_check_for_bad_vf
[250643.661981] ixgbe: ixgbe_spoof_check
[250643.661982] ixgbe: ixgbe_update_stats
[250643.662050] ixgbe: ixgbe_update_xoff_received
[250643.662052] ixgbe: ixgbe_update_xoff_rx_lfc
[250643.662078] ixgbe: ixgbe_watchdog_flush_tx
[250643.662079] ixgbe: ixgbe_fdir_reinit_subtask
[250643.662081] ixgbe: ixgbe_check_hang_subtask
[250643.662083] ixgbe: ixgbe_irq_rearm_queues
[250643.662085] ixgbe: ixgbe_service_event_complete
[250643.662091] ixgbe: ixgbe_msix_clean_rings
[250643.662092] ixgbe: ixgbe_msix_clean_rings
[250643.662092] ixgbe: ixgbe_msix_clean_rings
[250643.662093] ixgbe: ixgbe_msix_clean_rings
[250643.662094] ixgbe: ixgbe_msix_clean_rings
[250643.662092] ixgbe: ixgbe_msix_clean_rings
[250643.662092] ixgbe: ixgbe_msix_clean_rings
[250643.662095] ixgbe: ixgbe_msix_clean_rings
[250643.662094] ixgbe: ixgbe_msix_clean_rings
[250643.662119] ixgbe: ixgbe_msix_clean_rings
[250643.662119] ixgbe: ixgbe_msix_clean_rings
[250643.662120] ixgbe: ixgbe_msix_clean_rings
[250643.662120] ixgbe: ixgbe_msix_clean_rings
[250643.662123] ixgbe: ixgbe_msix_clean_rings
[250643.662122] ixgbe: ixgbe_msix_clean_rings
[250643.662121] ixgbe: ixgbe_msix_clean_rings
[250643.662121] ixgbe: ixgbe_msix_clean_rings
[250643.662122] ixgbe: ixgbe_msix_clean_rings
[250643.662125] ixgbe: ixgbe_msix_clean_rings
[250643.662124] ixgbe: ixgbe_msix_clean_rings
[250645.677873] ixgbe: ixgbe_service_timer
[250645.677891] ixgbe: ixgbe_service_event_schedule
[250645.677939] ixgbe: ixgbe_service_task
[250645.677944] ixgbe: ixgbe_check_fw_error
[250645.677947] ixgbe: ixgbe_reset_subtask
[250645.677948] ixgbe: ixgbe_phy_interrupt_subtask
[250645.677949] ixgbe: ixgbe_sfp_detection_subtask
[250645.677950] ixgbe: ixgbe_sfp_link_config_subtask
[250645.677951] ixgbe: ixgbe_check_overtemp_subtask
[250645.677953] ixgbe: ixgbe_watchdog_subtask
[250645.677954] ixgbe: ixgbe_watchdog_update_link
[250645.677955] ixgbe: ixgbe_watchdog_link_is_up
[250645.677957] ixgbe: ixgbe_check_for_bad_vf
[250645.677958] ixgbe: ixgbe_spoof_check
[250645.677959] ixgbe: ixgbe_update_stats
[250645.678027] ixgbe: ixgbe_update_xoff_received
[250645.678028] ixgbe: ixgbe_update_xoff_rx_lfc
[250645.678054] ixgbe: ixgbe_watchdog_flush_tx
[250645.678056] ixgbe: ixgbe_fdir_reinit_subtask
[250645.678057] ixgbe: ixgbe_check_hang_subtask
[250645.678059] ixgbe: ixgbe_irq_rearm_queues
[250645.678060] ixgbe: ixgbe_service_event_complete
[250645.678067] ixgbe: ixgbe_msix_clean_rings
[250645.678067] ixgbe: ixgbe_msix_clean_rings
[250645.678068] ixgbe: ixgbe_msix_clean_rings
[250645.678068] ixgbe: ixgbe_msix_clean_rings
[250645.678068] ixgbe: ixgbe_msix_clean_rings
[250645.678069] ixgbe: ixgbe_msix_clean_rings
[250645.678070] ixgbe: ixgbe_msix_clean_rings
[250645.678072] ixgbe: ixgbe_msix_clean_rings
[250645.678072] ixgbe: ixgbe_msix_clean_rings
[250645.678094] ixgbe: ixgbe_msix_clean_rings
[250645.678095] ixgbe: ixgbe_msix_clean_rings
[250645.678095] ixgbe: ixgbe_msix_clean_rings
[250645.678096] ixgbe: ixgbe_msix_clean_rings
[250645.678097] ixgbe: ixgbe_msix_clean_rings
[250645.678096] ixgbe: ixgbe_msix_clean_rings
[250645.678099] ixgbe: ixgbe_msix_clean_rings
[250645.678098] ixgbe: ixgbe_msix_clean_rings
[250645.678098] ixgbe: ixgbe_msix_clean_rings
[250645.678097] ixgbe: ixgbe_msix_clean_rings
[250645.678100] ixgbe: ixgbe_msix_clean_rings
[250647.693840] ixgbe: ixgbe_service_timer
[250647.693859] ixgbe: ixgbe_service_event_schedule
[250647.693905] ixgbe: ixgbe_service_task
[250647.693911] ixgbe: ixgbe_check_fw_error
[250647.693914] ixgbe: ixgbe_reset_subtask
[250647.693915] ixgbe: ixgbe_phy_interrupt_subtask
[250647.693916] ixgbe: ixgbe_sfp_detection_subtask
[250647.693917] ixgbe: ixgbe_sfp_link_config_subtask
[250647.693919] ixgbe: ixgbe_check_overtemp_subtask
[250647.693920] ixgbe: ixgbe_watchdog_subtask
[250647.693921] ixgbe: ixgbe_watchdog_update_link
[250647.693922] ixgbe: ixgbe_watchdog_link_is_up
[250647.693924] ixgbe: ixgbe_check_for_bad_vf
[250647.693925] ixgbe: ixgbe_spoof_check
[250647.693926] ixgbe: ixgbe_update_stats
[250647.693994] ixgbe: ixgbe_update_xoff_received
[250647.693995] ixgbe: ixgbe_update_xoff_rx_lfc
[250647.694021] ixgbe: ixgbe_watchdog_flush_tx
[250647.694023] ixgbe: ixgbe_fdir_reinit_subtask
[250647.694024] ixgbe: ixgbe_check_hang_subtask
[250647.694026] ixgbe: ixgbe_irq_rearm_queues
[250647.694028] ixgbe: ixgbe_service_event_complete
[250647.694034] ixgbe: ixgbe_msix_clean_rings
[250647.694036] ixgbe: ixgbe_msix_clean_rings
[250647.694036] ixgbe: ixgbe_msix_clean_rings
[250647.694037] ixgbe: ixgbe_msix_clean_rings
[250647.694038] ixgbe: ixgbe_msix_clean_rings
[250647.694038] ixgbe: ixgbe_msix_clean_rings
[250647.694037] ixgbe: ixgbe_msix_clean_rings
[250647.694040] ixgbe: ixgbe_msix_clean_rings
[250647.694046] ixgbe: ixgbe_msix_clean_rings
[250647.694056] ixgbe: ixgbe_msix_clean_rings
[250647.694063] ixgbe: ixgbe_msix_clean_rings
[250647.694064] ixgbe: ixgbe_msix_clean_rings
[250647.694065] ixgbe: ixgbe_msix_clean_rings
[250647.694066] ixgbe: ixgbe_msix_clean_rings
[250647.694067] ixgbe: ixgbe_msix_clean_rings
[250647.694068] ixgbe: ixgbe_msix_clean_rings
[250647.694069] ixgbe: ixgbe_msix_clean_rings
[250647.694070] ixgbe: ixgbe_msix_clean_rings
[250647.694071] ixgbe: ixgbe_msix_clean_rings
[250647.694072] ixgbe: ixgbe_msix_clean_rings
[250649.709818] ixgbe: ixgbe_service_timer
[250649.709835] ixgbe: ixgbe_service_event_schedule
[250649.709875] ixgbe: ixgbe_service_task
[250649.709880] ixgbe: ixgbe_check_fw_error
[250649.709882] ixgbe: ixgbe_reset_subtask
[250649.709884] ixgbe: ixgbe_phy_interrupt_subtask
[250649.709886] ixgbe: ixgbe_sfp_detection_subtask
[250649.709887] ixgbe: ixgbe_sfp_link_config_subtask
[250649.709889] ixgbe: ixgbe_check_overtemp_subtask
[250649.709890] ixgbe: ixgbe_watchdog_subtask
[250649.709891] ixgbe: ixgbe_watchdog_update_link
[250649.709892] ixgbe: ixgbe_watchdog_link_is_up
[250649.709893] ixgbe: ixgbe_check_for_bad_vf
[250649.709895] ixgbe: ixgbe_spoof_check
[250649.709896] ixgbe: ixgbe_update_stats
[250649.709968] ixgbe: ixgbe_update_xoff_received
[250649.709970] ixgbe: ixgbe_update_xoff_rx_lfc
[250649.709996] ixgbe: ixgbe_watchdog_flush_tx
[250649.709997] ixgbe: ixgbe_fdir_reinit_subtask
[250649.709998] ixgbe: ixgbe_check_hang_subtask
[250649.710001] ixgbe: ixgbe_irq_rearm_queues
[250649.710002] ixgbe: ixgbe_service_event_complete
[250649.710008] ixgbe: ixgbe_msix_clean_rings
[250649.710008] ixgbe: ixgbe_msix_clean_rings
[250649.710008] ixgbe: ixgbe_msix_clean_rings
[250649.710008] ixgbe: ixgbe_msix_clean_rings
[250649.710009] ixgbe: ixgbe_msix_clean_rings
[250649.710010] ixgbe: ixgbe_msix_clean_rings
[250649.710010] ixgbe: ixgbe_msix_clean_rings
[250649.710009] ixgbe: ixgbe_msix_clean_rings
[250649.710010] ixgbe: ixgbe_msix_clean_rings
[250649.710011] ixgbe: ixgbe_msix_clean_rings
[250649.710012] ixgbe: ixgbe_msix_clean_rings
[250649.710009] ixgbe: ixgbe_msix_clean_rings
[250649.710012] ixgbe: ixgbe_msix_clean_rings
[250649.710031] ixgbe: ixgbe_msix_clean_rings
[250649.710034] ixgbe: ixgbe_msix_clean_rings
[250649.710035] ixgbe: ixgbe_msix_clean_rings
[250649.710036] ixgbe: ixgbe_msix_clean_rings
[250649.710044] ixgbe: ixgbe_msix_clean_rings
[250649.710045] ixgbe: ixgbe_msix_clean_rings
[250649.710046] ixgbe: ixgbe_msix_clean_rings
[250651.725777] ixgbe: ixgbe_service_timer
[250651.725795] ixgbe: ixgbe_service_event_schedule
[250651.725831] ixgbe: ixgbe_service_task
[250651.725836] ixgbe: ixgbe_check_fw_error
[250651.725838] ixgbe: ixgbe_reset_subtask
[250651.725839] ixgbe: ixgbe_phy_interrupt_subtask
[250651.725841] ixgbe: ixgbe_sfp_detection_subtask
[250651.725842] ixgbe: ixgbe_sfp_link_config_subtask
[250651.725847] ixgbe: ixgbe_check_overtemp_subtask
[250651.725848] ixgbe: ixgbe_watchdog_subtask
[250651.725850] ixgbe: ixgbe_watchdog_update_link
[250651.725851] ixgbe: ixgbe_watchdog_link_is_up
[250651.725853] ixgbe: ixgbe_check_for_bad_vf
[250651.725855] ixgbe: ixgbe_spoof_check
[250651.725856] ixgbe: ixgbe_update_stats
[250651.725924] ixgbe: ixgbe_update_xoff_received
[250651.725925] ixgbe: ixgbe_update_xoff_rx_lfc
[250651.725952] ixgbe: ixgbe_watchdog_flush_tx
[250651.725953] ixgbe: ixgbe_fdir_reinit_subtask
[250651.725954] ixgbe: ixgbe_check_hang_subtask
[250651.725956] ixgbe: ixgbe_irq_rearm_queues
[250651.725958] ixgbe: ixgbe_service_event_complete
[250651.725963] ixgbe: ixgbe_msix_clean_rings
[250651.725964] ixgbe: ixgbe_msix_clean_rings
[250651.725963] ixgbe: ixgbe_msix_clean_rings
[250651.725964] ixgbe: ixgbe_msix_clean_rings
[250651.725965] ixgbe: ixgbe_msix_clean_rings
[250651.725965] ixgbe: ixgbe_msix_clean_rings
[250651.725967] ixgbe: ixgbe_msix_clean_rings
[250651.725967] ixgbe: ixgbe_msix_clean_rings
[250651.725964] ixgbe: ixgbe_msix_clean_rings
[250651.725967] ixgbe: ixgbe_msix_clean_rings
[250651.725964] ixgbe: ixgbe_msix_clean_rings
[250651.725970] ixgbe: ixgbe_msix_clean_rings
[250651.725967] ixgbe: ixgbe_msix_clean_rings
[250651.725985] ixgbe: ixgbe_msix_clean_rings
[250651.725992] ixgbe: ixgbe_msix_clean_rings
[250651.725993] ixgbe: ixgbe_msix_clean_rings
[250651.725993] ixgbe: ixgbe_msix_clean_rings
[250651.725995] ixgbe: ixgbe_msix_clean_rings
[250651.725997] ixgbe: ixgbe_msix_clean_rings
[250651.725999] ixgbe: ixgbe_msix_clean_rings
[250652.831368]  **** han_napi_ENABLE ****
[250652.831372] ixgbe: ixgbe_napi_enable_all
[250652.831375] ixgbe: ixgbe_irq_enable
[250652.831376] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250653.741751] ixgbe: ixgbe_service_timer
[250653.741769] ixgbe: ixgbe_service_event_schedule
[250653.741808] ixgbe: ixgbe_service_task
[250653.741813] ixgbe: ixgbe_check_fw_error
[250653.741816] ixgbe: ixgbe_reset_subtask
[250653.741817] ixgbe: ixgbe_phy_interrupt_subtask
[250653.741818] ixgbe: ixgbe_sfp_detection_subtask
[250653.741819] ixgbe: ixgbe_sfp_link_config_subtask
[250653.741821] ixgbe: ixgbe_check_overtemp_subtask
[250653.741822] ixgbe: ixgbe_watchdog_subtask
[250653.741824] ixgbe: ixgbe_watchdog_update_link
[250653.741825] ixgbe: ixgbe_watchdog_link_is_up
[250653.741826] ixgbe: ixgbe_check_for_bad_vf
[250653.741828] ixgbe: ixgbe_spoof_check
[250653.741829] ixgbe: ixgbe_update_stats
[250653.741898] ixgbe: ixgbe_update_xoff_received
[250653.741899] ixgbe: ixgbe_update_xoff_rx_lfc
[250653.741925] ixgbe: ixgbe_watchdog_flush_tx
[250653.741927] ixgbe: ixgbe_fdir_reinit_subtask
[250653.741928] ixgbe: ixgbe_check_hang_subtask
[250653.741930] ixgbe: ixgbe_irq_rearm_queues
[250653.741933] ixgbe: ixgbe_service_event_complete
[250653.741939] ixgbe: ixgbe_msix_clean_rings
[250653.741939] ixgbe: ixgbe_msix_clean_rings
[250653.741940] ixgbe: ixgbe_msix_clean_rings
[250653.741940] ixgbe: ixgbe_msix_clean_rings
[250653.741940] ixgbe: ixgbe_msix_clean_rings
[250653.741941] ixgbe: ixgbe_poll v_idx=15 budget=64
[250653.741941] ixgbe: ixgbe_msix_clean_rings
[250653.741940] ixgbe: ixgbe_msix_clean_rings
[250653.741942] ixgbe: ixgbe_msix_clean_rings
[250653.741942] ixgbe: ixgbe_msix_clean_rings
[250653.741942] ixgbe: ixgbe_msix_clean_rings
[250653.741949] ixgbe: ixgbe_poll v_idx=5 budget=64
[250653.741954] ixgbe: ixgbe_poll v_idx=15 budget=64
[250653.741955] ixgbe: ixgbe_poll v_idx=5 budget=64
[250653.741957] ixgbe: ixgbe_poll v_idx=19 budget=64
[250653.741959] ixgbe: ixgbe_poll v_idx=8 budget=64
[250653.741963] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250653.741962] ixgbe: ixgbe_poll v_idx=16 budget=64
[250653.741962] ixgbe: ixgbe_poll v_idx=6 budget=64
[250653.741966] ixgbe: ixgbe_msix_clean_rings
[250653.741967] ixgbe: ixgbe_msix_clean_rings
[250653.741969] ixgbe: ixgbe_msix_clean_rings
[250653.741968] ixgbe: ixgbe_msix_clean_rings
[250653.741970] ixgbe: ixgbe_msix_clean_rings
[250653.741968] ixgbe: ixgbe_msix_clean_rings
[250653.741967] ixgbe: ixgbe_msix_clean_rings
[250653.741969] ixgbe: ixgbe_msix_clean_rings
[250653.741978] ixgbe: ixgbe_poll v_idx=7 budget=64
[250653.741980] ixgbe: ixgbe_poll v_idx=6 budget=64
[250653.741973] ixgbe: ixgbe_poll v_idx=19 budget=64
[250653.741974] ixgbe: ixgbe_poll v_idx=11 budget=64
[250653.741984] ixgbe: ixgbe_poll v_idx=8 budget=64
[250653.741966] ixgbe: ixgbe_msix_clean_rings
[250653.741971] ixgbe: ixgbe_msix_clean_rings
[250653.741998] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250653.741993] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250653.741988] ixgbe: ixgbe_poll v_idx=0 budget=64
[250653.742009] ixgbe: ixgbe_poll v_idx=14 budget=64
[250653.742003] ixgbe: ixgbe_poll v_idx=1 budget=64
[250653.742012] ixgbe: ixgbe_poll v_idx=12 budget=64
[250653.742017] ixgbe: ixgbe_poll v_idx=17 budget=64
[250653.742016] ixgbe: ixgbe_poll v_idx=10 budget=64
[250653.742018] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250653.742031] ixgbe: ixgbe_poll v_idx=3 budget=64
[250653.742032] ixgbe: ixgbe_poll v_idx=14 budget=64
[250653.742039] ixgbe: ixgbe_poll v_idx=0 budget=64
[250653.742042] ixgbe: ixgbe_poll v_idx=17 budget=64
[250653.742037] ixgbe: ixgbe_poll v_idx=16 budget=64
[250653.742039] ixgbe: ixgbe_poll v_idx=18 budget=64
[250653.742048] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250653.742046] ixgbe: ixgbe_poll v_idx=13 budget=64
[250653.742049] ixgbe: ixgbe_poll v_idx=12 budget=64
[250653.742029] ixgbe: ixgbe_poll v_idx=9 budget=64
[250653.742060] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250653.742058] ixgbe: ixgbe_poll v_idx=11 budget=64
[250653.742066] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250653.742071] ixgbe: ixgbe_get_rx_buffer
[250653.742064] ixgbe: ixgbe_poll v_idx=18 budget=64
[250653.742067] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250653.742081] ixgbe: ixgbe_poll v_idx=10 budget=64
[250653.742086] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250653.742089] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250653.742094] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250653.742099] ixgbe: ixgbe_poll v_idx=9 budget=64
[250653.742100] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250653.742099] ixgbe: ixgbe_poll v_idx=13 budget=64
[250653.742104] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250653.742091] ixgbe: ixgbe_run_xdp
[250653.742114] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250653.742119] ixgbe: ixgbe_build_skb
[250653.742127] ixgbe: ixgbe_put_rx_buffer
[250653.742129] ixgbe: ixgbe_poll v_idx=7 budget=64
[250653.742131] ixgbe: ixgbe_poll v_idx=4 budget=64
[250653.742133] ixgbe: ixgbe_can_reuse_rx_page
[250653.742135] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250653.742136] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250653.742135] ixgbe: ixgbe_poll v_idx=2 budget=64
[250653.742136] ixgbe: ixgbe_reuse_rx_page
[250653.742138] ixgbe: ixgbe_poll v_idx=4 budget=64
[250653.742139] ixgbe: ixgbe_is_non_eop
[250653.742141] ixgbe: ixgbe_cleanup_headers
[250653.742141] ixgbe: ixgbe_poll v_idx=2 budget=64
[250653.742142] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250653.742142] ixgbe: ixgbe_process_skb_fields
[250653.742144] ixgbe: ixgbe_update_rsc_stats
[250653.742146] ixgbe: ixgbe_rx_hash
[250653.742146] ixgbe: ixgbe_poll v_idx=3 budget=64
[250653.742147] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250653.742148] ixgbe: ixgbe_rx_checksum
[250653.742150] ixgbe: ixgbe_rx_skb
[250653.742150] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250653.742152] ixgbe: ixgbe_get_rx_buffer
[250653.742153] ixgbe: ixgbe_run_xdp
[250653.742154] ixgbe: ixgbe_build_skb
[250653.742155] ixgbe: ixgbe_put_rx_buffer
[250653.742156] ixgbe: ixgbe_can_reuse_rx_page
[250653.742157] ixgbe: ixgbe_reuse_rx_page
[250653.742158] ixgbe: ixgbe_is_non_eop
[250653.742159] ixgbe: ixgbe_cleanup_headers
[250653.742160] ixgbe: ixgbe_process_skb_fields
[250653.742161] ixgbe: ixgbe_update_rsc_stats
[250653.742162] ixgbe: ixgbe_rx_hash
[250653.742162] ixgbe: ixgbe_rx_checksum
[250653.742163] ixgbe: ixgbe_rx_skb
[250653.742164] ixgbe: ixgbe_get_rx_buffer
[250653.742165] ixgbe: ixgbe_run_xdp
[250653.742166] ixgbe: ixgbe_build_skb
[250653.742167] ixgbe: ixgbe_put_rx_buffer
[250653.742168] ixgbe: ixgbe_can_reuse_rx_page
[250653.742169] ixgbe: ixgbe_reuse_rx_page
[250653.742170] ixgbe: ixgbe_is_non_eop
[250653.742171] ixgbe: ixgbe_cleanup_headers
[250653.742171] ixgbe: ixgbe_process_skb_fields
[250653.742172] ixgbe: ixgbe_update_rsc_stats
[250653.742173] ixgbe: ixgbe_rx_hash
[250653.742174] ixgbe: ixgbe_rx_checksum
[250653.742175] ixgbe: ixgbe_rx_skb
[250653.742175] ixgbe: ixgbe_get_rx_buffer
[250653.742176] ixgbe: ixgbe_run_xdp
[250653.742177] ixgbe: ixgbe_build_skb
[250653.742179] ixgbe: ixgbe_put_rx_buffer
[250653.742179] ixgbe: ixgbe_can_reuse_rx_page
[250653.742180] ixgbe: ixgbe_reuse_rx_page
[250653.742181] ixgbe: ixgbe_is_non_eop
[250653.742182] ixgbe: ixgbe_cleanup_headers
[250653.742183] ixgbe: ixgbe_process_skb_fields
[250653.742183] ixgbe: ixgbe_update_rsc_stats
[250653.742184] ixgbe: ixgbe_rx_hash
[250653.742185] ixgbe: ixgbe_rx_checksum
[250653.742186] ixgbe: ixgbe_rx_skb
[250653.742187] ixgbe: ixgbe_get_rx_buffer
[250653.742188] ixgbe: ixgbe_run_xdp
[250653.742189] ixgbe: ixgbe_build_skb
[250653.742190] ixgbe: ixgbe_put_rx_buffer
[250653.742191] ixgbe: ixgbe_can_reuse_rx_page
[250653.742192] ixgbe: ixgbe_reuse_rx_page
[250653.742193] ixgbe: ixgbe_is_non_eop
[250653.742193] ixgbe: ixgbe_cleanup_headers
[250653.742194] ixgbe: ixgbe_process_skb_fields
[250653.742195] ixgbe: ixgbe_update_rsc_stats
[250653.742196] ixgbe: ixgbe_rx_hash
[250653.742197] ixgbe: ixgbe_rx_checksum
[250653.742197] ixgbe: ixgbe_rx_skb
[250653.742198] ixgbe: ixgbe_get_rx_buffer
[250653.742199] ixgbe: ixgbe_run_xdp
[250653.742200] ixgbe: ixgbe_build_skb
[250653.742201] ixgbe: ixgbe_put_rx_buffer
[250653.742202] ixgbe: ixgbe_can_reuse_rx_page
[250653.742203] ixgbe: ixgbe_reuse_rx_page
[250653.742203] ixgbe: ixgbe_is_non_eop
[250653.742204] ixgbe: ixgbe_cleanup_headers
[250653.742205] ixgbe: ixgbe_process_skb_fields
[250653.742206] ixgbe: ixgbe_update_rsc_stats
[250653.742206] ixgbe: ixgbe_rx_hash
[250653.742207] ixgbe: ixgbe_rx_checksum
[250653.742208] ixgbe: ixgbe_rx_skb
[250653.742209] ixgbe: ixgbe_get_rx_buffer
[250653.742210] ixgbe: ixgbe_run_xdp
[250653.742210] ixgbe: ixgbe_build_skb
[250653.742211] ixgbe: ixgbe_put_rx_buffer
[250653.742212] ixgbe: ixgbe_can_reuse_rx_page
[250653.742213] ixgbe: ixgbe_reuse_rx_page
[250653.742214] ixgbe: ixgbe_is_non_eop
[250653.742215] ixgbe: ixgbe_cleanup_headers
[250653.742216] ixgbe: ixgbe_process_skb_fields
[250653.742216] ixgbe: ixgbe_update_rsc_stats
[250653.742217] ixgbe: ixgbe_rx_hash
[250653.742218] ixgbe: ixgbe_rx_checksum
[250653.742219] ixgbe: ixgbe_rx_skb
[250653.742235] ixgbe: ixgbe_features_check
[250653.742237] ixgbe: ixgbe_xmit_frame
[250653.742238] ixgbe: __ixgbe_xmit_frame
[250653.742239] ixgbe: ixgbe_xmit_frame_ring
[250653.742240] ixgbe: ixgbe_maybe_stop_tx
[250653.742241] ixgbe: ixgbe_tso
[250653.742241] ixgbe: ixgbe_tx_csum
[250653.742243] ixgbe: ixgbe_atr
[250653.742244] ixgbe: ixgbe_tx_cmd_type
[250653.742245] ixgbe: ixgbe_tx_map
[250653.742245] ixgbe: ixgbe_tx_olinfo_status
[250653.742247] ixgbe: ixgbe_maybe_stop_tx
[250653.742259] ixgbe: ixgbe_features_check
[250653.742261] ixgbe: ixgbe_xmit_frame
[250653.742263] ixgbe: __ixgbe_xmit_frame
[250653.742264] ixgbe: ixgbe_xmit_frame_ring
[250653.742266] ixgbe: ixgbe_maybe_stop_tx
[250653.742267] ixgbe: ixgbe_tso
[250653.742268] ixgbe: ixgbe_tx_csum
[250653.742270] ixgbe: ixgbe_atr
[250653.742271] ixgbe: ixgbe_tx_cmd_type
[250653.742273] ixgbe: ixgbe_tx_map
[250653.742275] ixgbe: ixgbe_tx_olinfo_status
[250653.742276] ixgbe: ixgbe_maybe_stop_tx
[250653.742281] ixgbe: ixgbe_poll v_idx=1 budget=64
[250653.742286] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250653.742290] ixgbe: ixgbe_features_check
[250653.742293] ixgbe: ixgbe_msix_clean_rings
[250653.742294] ixgbe: ixgbe_xmit_frame
[250653.742295] ixgbe: ixgbe_poll v_idx=1 budget=64
[250653.742296] ixgbe: __ixgbe_xmit_frame
[250653.742299] ixgbe: ixgbe_xmit_frame_ring
[250653.742300] ixgbe: ixgbe_write_eitr
[250653.742301] ixgbe: ixgbe_maybe_stop_tx
[250653.742303] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250653.742303] ixgbe: ixgbe_tso
[250653.742305] ixgbe: ixgbe_tx_csum
[250653.742307] ixgbe: ixgbe_atr
[250653.742309] ixgbe: ixgbe_tx_cmd_type
[250653.742311] ixgbe: ixgbe_tx_map
[250653.742313] ixgbe: ixgbe_tx_olinfo_status
[250653.742315] ixgbe: ixgbe_maybe_stop_tx
[250653.742320] ixgbe: ixgbe_features_check
[250653.742323] ixgbe: ixgbe_msix_clean_rings
[250653.742326] ixgbe: ixgbe_poll v_idx=3 budget=64
[250653.742331] ixgbe: ixgbe_write_eitr
[250653.742332] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250653.742334] ixgbe: ixgbe_xmit_frame
[250653.742336] ixgbe: __ixgbe_xmit_frame
[250653.742337] ixgbe: ixgbe_xmit_frame_ring
[250653.742339] ixgbe: ixgbe_maybe_stop_tx
[250653.742340] ixgbe: ixgbe_tso
[250653.742341] ixgbe: ixgbe_tx_csum
[250653.742343] ixgbe: ixgbe_atr
[250653.742345] ixgbe: ixgbe_tx_cmd_type
[250653.742346] ixgbe: ixgbe_tx_map
[250653.742348] ixgbe: ixgbe_tx_olinfo_status
[250653.742350] ixgbe: ixgbe_maybe_stop_tx
[250653.742355] ixgbe: ixgbe_features_check
[250653.742357] ixgbe: ixgbe_xmit_frame
[250653.742359] ixgbe: ixgbe_msix_clean_rings
[250653.742361] ixgbe: __ixgbe_xmit_frame
[250653.742363] ixgbe: ixgbe_xmit_frame_ring
[250653.742364] ixgbe: ixgbe_maybe_stop_tx
[250653.742366] ixgbe: ixgbe_tso
[250653.742368] ixgbe: ixgbe_tx_csum
[250653.742370] ixgbe: ixgbe_atr
[250653.742371] ixgbe: ixgbe_tx_cmd_type
[250653.742372] ixgbe: ixgbe_tx_map
[250653.742374] ixgbe: ixgbe_tx_olinfo_status
[250653.742376] ixgbe: ixgbe_maybe_stop_tx
[250653.742378] ixgbe: ixgbe_poll v_idx=3 budget=64
[250653.742381] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250653.742385] ixgbe: ixgbe_features_check
[250653.742387] ixgbe: ixgbe_xmit_frame
[250653.742388] ixgbe: ixgbe_msix_clean_rings
[250653.742389] ixgbe: __ixgbe_xmit_frame
[250653.742390] ixgbe: ixgbe_xmit_frame_ring
[250653.742391] ixgbe: ixgbe_maybe_stop_tx
[250653.742392] ixgbe: ixgbe_tso
[250653.742392] ixgbe: ixgbe_tx_csum
[250653.742393] ixgbe: ixgbe_atr
[250653.742394] ixgbe: ixgbe_tx_cmd_type
[250653.742395] ixgbe: ixgbe_tx_map
[250653.742396] ixgbe: ixgbe_tx_olinfo_status
[250653.742397] ixgbe: ixgbe_maybe_stop_tx
[250653.742398] ixgbe: ixgbe_poll v_idx=3 budget=64
[250653.742399] ixgbe: ixgbe_write_eitr
[250653.742400] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250653.742404] ixgbe: ixgbe_features_check
[250653.742405] ixgbe: ixgbe_xmit_frame
[250653.742406] ixgbe: ixgbe_msix_clean_rings
[250653.742408] ixgbe: __ixgbe_xmit_frame
[250653.742409] ixgbe: ixgbe_xmit_frame_ring
[250653.742410] ixgbe: ixgbe_maybe_stop_tx
[250653.742411] ixgbe: ixgbe_tso
[250653.742411] ixgbe: ixgbe_tx_csum
[250653.742412] ixgbe: ixgbe_atr
[250653.742413] ixgbe: ixgbe_tx_cmd_type
[250653.742414] ixgbe: ixgbe_tx_map
[250653.742415] ixgbe: ixgbe_tx_olinfo_status
[250653.742416] ixgbe: ixgbe_maybe_stop_tx
[250653.742418] ixgbe: ixgbe_poll v_idx=3 budget=64
[250653.742420] ixgbe: ixgbe_write_eitr
[250653.742421] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250653.742427] ixgbe: ixgbe_msix_clean_rings
[250653.742428] ixgbe: ixgbe_poll v_idx=3 budget=64
[250653.742429] ixgbe: ixgbe_write_eitr
[250653.742430] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues

```

## Add elevated ixgbe_poll call
```
[250756.166596]  **** han_napi_DISABLE  ****
[250756.166601] ixgbe: ixgbe_irq_disable
[250756.166613] ixgbe: ixgbe_napi_disable_all
[250756.166619] ixgbe: ixgbe_irq_disable
[250756.556249] ixgbe: ixgbe_service_timer
[250756.556266] ixgbe: ixgbe_service_event_schedule
[250756.556306] ixgbe: ixgbe_service_task
[250756.556312] ixgbe: ixgbe_check_fw_error
[250756.556314] ixgbe: ixgbe_reset_subtask
[250756.556315] ixgbe: ixgbe_phy_interrupt_subtask
[250756.556316] ixgbe: ixgbe_sfp_detection_subtask
[250756.556317] ixgbe: ixgbe_sfp_link_config_subtask
[250756.556318] ixgbe: ixgbe_check_overtemp_subtask
[250756.556319] ixgbe: ixgbe_watchdog_subtask
[250756.556320] ixgbe: ixgbe_watchdog_update_link
[250756.556321] ixgbe: ixgbe_watchdog_link_is_up
[250756.556322] ixgbe: ixgbe_check_for_bad_vf
[250756.556324] ixgbe: ixgbe_spoof_check
[250756.556325] ixgbe: ixgbe_update_stats
[250756.556386] ixgbe: ixgbe_update_xoff_received
[250756.556388] ixgbe: ixgbe_update_xoff_rx_lfc
[250756.556411] ixgbe: ixgbe_watchdog_flush_tx
[250756.556412] ixgbe: ixgbe_fdir_reinit_subtask
[250756.556413] ixgbe: ixgbe_check_hang_subtask
[250756.556416] ixgbe: ixgbe_irq_rearm_queues
[250756.556417] ixgbe: ixgbe_service_event_complete
[250756.556424] ixgbe: ixgbe_msix_clean_rings
[250756.556423] ixgbe: ixgbe_msix_clean_rings
[250756.556424] ixgbe: ixgbe_msix_clean_rings
[250756.556426] ixgbe: ixgbe_msix_clean_rings
[250756.556425] ixgbe: ixgbe_msix_clean_rings
[250756.556426] ixgbe: ixgbe_msix_clean_rings
[250756.556425] ixgbe: ixgbe_msix_clean_rings
[250756.556429] ixgbe: ixgbe_msix_clean_rings
[250756.556429] ixgbe: ixgbe_msix_clean_rings
[250756.556430] ixgbe: ixgbe_msix_clean_rings
[250756.556451] ixgbe: ixgbe_msix_clean_rings
[250756.556452] ixgbe: ixgbe_msix_clean_rings
[250756.556452] ixgbe: ixgbe_msix_clean_rings
[250756.556453] ixgbe: ixgbe_msix_clean_rings
[250756.556453] ixgbe: ixgbe_msix_clean_rings
[250756.556454] ixgbe: ixgbe_msix_clean_rings
[250756.556456] ixgbe: ixgbe_msix_clean_rings
[250756.556454] ixgbe: ixgbe_msix_clean_rings
[250756.556457] ixgbe: ixgbe_msix_clean_rings
[250756.556453] ixgbe: ixgbe_msix_clean_rings
[250758.572220] ixgbe: ixgbe_service_timer
[250758.572238] ixgbe: ixgbe_service_event_schedule
[250758.572280] ixgbe: ixgbe_service_task
[250758.572286] ixgbe: ixgbe_check_fw_error
[250758.572288] ixgbe: ixgbe_reset_subtask
[250758.572289] ixgbe: ixgbe_phy_interrupt_subtask
[250758.572290] ixgbe: ixgbe_sfp_detection_subtask
[250758.572291] ixgbe: ixgbe_sfp_link_config_subtask
[250758.572291] ixgbe: ixgbe_check_overtemp_subtask
[250758.572292] ixgbe: ixgbe_watchdog_subtask
[250758.572293] ixgbe: ixgbe_watchdog_update_link
[250758.572294] ixgbe: ixgbe_watchdog_link_is_up
[250758.572295] ixgbe: ixgbe_check_for_bad_vf
[250758.572297] ixgbe: ixgbe_spoof_check
[250758.572297] ixgbe: ixgbe_update_stats
[250758.572358] ixgbe: ixgbe_update_xoff_received
[250758.572360] ixgbe: ixgbe_update_xoff_rx_lfc
[250758.572383] ixgbe: ixgbe_watchdog_flush_tx
[250758.572384] ixgbe: ixgbe_fdir_reinit_subtask
[250758.572385] ixgbe: ixgbe_check_hang_subtask
[250758.572387] ixgbe: ixgbe_irq_rearm_queues
[250758.572388] ixgbe: ixgbe_service_event_complete
[250758.572394] ixgbe: ixgbe_msix_clean_rings
[250758.572396] ixgbe: ixgbe_msix_clean_rings
[250758.572396] ixgbe: ixgbe_msix_clean_rings
[250758.572395] ixgbe: ixgbe_msix_clean_rings
[250758.572398] ixgbe: ixgbe_msix_clean_rings
[250758.572397] ixgbe: ixgbe_msix_clean_rings
[250758.572397] ixgbe: ixgbe_msix_clean_rings
[250758.572397] ixgbe: ixgbe_msix_clean_rings
[250758.572401] ixgbe: ixgbe_msix_clean_rings
[250758.572403] ixgbe: ixgbe_msix_clean_rings
[250758.572419] ixgbe: ixgbe_msix_clean_rings
[250758.572420] ixgbe: ixgbe_msix_clean_rings
[250758.572421] ixgbe: ixgbe_msix_clean_rings
[250758.572423] ixgbe: ixgbe_msix_clean_rings
[250758.572423] ixgbe: ixgbe_msix_clean_rings
[250758.572424] ixgbe: ixgbe_msix_clean_rings
[250758.572426] ixgbe: ixgbe_msix_clean_rings
[250758.572426] ixgbe: ixgbe_msix_clean_rings
[250758.572428] ixgbe: ixgbe_msix_clean_rings
[250758.572428] ixgbe: ixgbe_msix_clean_rings
[250760.588205] ixgbe: ixgbe_service_timer
[250760.588223] ixgbe: ixgbe_service_event_schedule
[250760.588257] ixgbe: ixgbe_service_task
[250760.588262] ixgbe: ixgbe_check_fw_error
[250760.588266] ixgbe: ixgbe_reset_subtask
[250760.588268] ixgbe: ixgbe_phy_interrupt_subtask
[250760.588269] ixgbe: ixgbe_sfp_detection_subtask
[250760.588270] ixgbe: ixgbe_sfp_link_config_subtask
[250760.588271] ixgbe: ixgbe_check_overtemp_subtask
[250760.588272] ixgbe: ixgbe_watchdog_subtask
[250760.588273] ixgbe: ixgbe_watchdog_update_link
[250760.588274] ixgbe: ixgbe_watchdog_link_is_up
[250760.588275] ixgbe: ixgbe_check_for_bad_vf
[250760.588276] ixgbe: ixgbe_spoof_check
[250760.588277] ixgbe: ixgbe_update_stats
[250760.588337] ixgbe: ixgbe_update_xoff_received
[250760.588340] ixgbe: ixgbe_update_xoff_rx_lfc
[250760.588363] ixgbe: ixgbe_watchdog_flush_tx
[250760.588364] ixgbe: ixgbe_fdir_reinit_subtask
[250760.588365] ixgbe: ixgbe_check_hang_subtask
[250760.588367] ixgbe: ixgbe_irq_rearm_queues
[250760.588368] ixgbe: ixgbe_service_event_complete
[250760.588374] ixgbe: ixgbe_msix_clean_rings
[250760.588376] ixgbe: ixgbe_msix_clean_rings
[250760.588377] ixgbe: ixgbe_msix_clean_rings
[250760.588379] ixgbe: ixgbe_msix_clean_rings
[250760.588379] ixgbe: ixgbe_msix_clean_rings
[250760.588382] ixgbe: ixgbe_msix_clean_rings
[250760.588382] ixgbe: ixgbe_msix_clean_rings
[250760.588386] ixgbe: ixgbe_msix_clean_rings
[250760.588403] ixgbe: ixgbe_msix_clean_rings
[250760.588403] ixgbe: ixgbe_msix_clean_rings
[250760.588404] ixgbe: ixgbe_msix_clean_rings
[250760.588404] ixgbe: ixgbe_msix_clean_rings
[250760.588406] ixgbe: ixgbe_msix_clean_rings
[250760.588406] ixgbe: ixgbe_msix_clean_rings
[250760.588407] ixgbe: ixgbe_msix_clean_rings
[250760.588408] ixgbe: ixgbe_msix_clean_rings
[250760.588409] ixgbe: ixgbe_msix_clean_rings
[250760.588410] ixgbe: ixgbe_msix_clean_rings
[250760.588411] ixgbe: ixgbe_msix_clean_rings
[250760.588412] ixgbe: ixgbe_msix_clean_rings
[250762.604174] ixgbe: ixgbe_service_timer
[250762.604191] ixgbe: ixgbe_service_event_schedule
[250762.604230] ixgbe: ixgbe_service_task
[250762.604235] ixgbe: ixgbe_check_fw_error
[250762.604237] ixgbe: ixgbe_reset_subtask
[250762.604238] ixgbe: ixgbe_phy_interrupt_subtask
[250762.604239] ixgbe: ixgbe_sfp_detection_subtask
[250762.604240] ixgbe: ixgbe_sfp_link_config_subtask
[250762.604241] ixgbe: ixgbe_check_overtemp_subtask
[250762.604242] ixgbe: ixgbe_watchdog_subtask
[250762.604243] ixgbe: ixgbe_watchdog_update_link
[250762.604244] ixgbe: ixgbe_watchdog_link_is_up
[250762.604245] ixgbe: ixgbe_check_for_bad_vf
[250762.604247] ixgbe: ixgbe_spoof_check
[250762.604248] ixgbe: ixgbe_update_stats
[250762.604308] ixgbe: ixgbe_update_xoff_received
[250762.604310] ixgbe: ixgbe_update_xoff_rx_lfc
[250762.604333] ixgbe: ixgbe_watchdog_flush_tx
[250762.604334] ixgbe: ixgbe_fdir_reinit_subtask
[250762.604336] ixgbe: ixgbe_check_hang_subtask
[250762.604337] ixgbe: ixgbe_irq_rearm_queues
[250762.604339] ixgbe: ixgbe_service_event_complete
[250762.604345] ixgbe: ixgbe_msix_clean_rings
[250762.604347] ixgbe: ixgbe_msix_clean_rings
[250762.604346] ixgbe: ixgbe_msix_clean_rings
[250762.604349] ixgbe: ixgbe_msix_clean_rings
[250762.604347] ixgbe: ixgbe_msix_clean_rings
[250762.604347] ixgbe: ixgbe_msix_clean_rings
[250762.604348] ixgbe: ixgbe_msix_clean_rings
[250762.604349] ixgbe: ixgbe_msix_clean_rings
[250762.604365] ixgbe: ixgbe_msix_clean_rings
[250762.604372] ixgbe: ixgbe_msix_clean_rings
[250762.604374] ixgbe: ixgbe_msix_clean_rings
[250762.604375] ixgbe: ixgbe_msix_clean_rings
[250762.604379] ixgbe: ixgbe_msix_clean_rings
[250762.604381] ixgbe: ixgbe_msix_clean_rings
[250762.604381] ixgbe: ixgbe_msix_clean_rings
[250762.604383] ixgbe: ixgbe_msix_clean_rings
[250762.604383] ixgbe: ixgbe_msix_clean_rings
[250762.604384] ixgbe: ixgbe_msix_clean_rings
[250762.604386] ixgbe: ixgbe_msix_clean_rings
[250762.604386] ixgbe: ixgbe_msix_clean_rings
[250764.620143] ixgbe: ixgbe_service_timer
[250764.620161] ixgbe: ixgbe_service_event_schedule
[250764.620200] ixgbe: ixgbe_service_task
[250764.620206] ixgbe: ixgbe_check_fw_error
[250764.620208] ixgbe: ixgbe_reset_subtask
[250764.620209] ixgbe: ixgbe_phy_interrupt_subtask
[250764.620210] ixgbe: ixgbe_sfp_detection_subtask
[250764.620211] ixgbe: ixgbe_sfp_link_config_subtask
[250764.620212] ixgbe: ixgbe_check_overtemp_subtask
[250764.620213] ixgbe: ixgbe_watchdog_subtask
[250764.620214] ixgbe: ixgbe_watchdog_update_link
[250764.620215] ixgbe: ixgbe_watchdog_link_is_up
[250764.620216] ixgbe: ixgbe_check_for_bad_vf
[250764.620217] ixgbe: ixgbe_spoof_check
[250764.620219] ixgbe: ixgbe_update_stats
[250764.620279] ixgbe: ixgbe_update_xoff_received
[250764.620281] ixgbe: ixgbe_update_xoff_rx_lfc
[250764.620304] ixgbe: ixgbe_watchdog_flush_tx
[250764.620305] ixgbe: ixgbe_fdir_reinit_subtask
[250764.620306] ixgbe: ixgbe_check_hang_subtask
[250764.620308] ixgbe: ixgbe_irq_rearm_queues
[250764.620309] ixgbe: ixgbe_service_event_complete
[250764.620315] ixgbe: ixgbe_msix_clean_rings
[250764.620316] ixgbe: ixgbe_msix_clean_rings
[250764.620316] ixgbe: ixgbe_msix_clean_rings
[250764.620317] ixgbe: ixgbe_msix_clean_rings
[250764.620316] ixgbe: ixgbe_msix_clean_rings
[250764.620318] ixgbe: ixgbe_msix_clean_rings
[250764.620316] ixgbe: ixgbe_msix_clean_rings
[250764.620318] ixgbe: ixgbe_msix_clean_rings
[250764.620319] ixgbe: ixgbe_msix_clean_rings
[250764.620334] ixgbe: ixgbe_msix_clean_rings
[250764.620343] ixgbe: ixgbe_msix_clean_rings
[250764.620344] ixgbe: ixgbe_msix_clean_rings
[250764.620345] ixgbe: ixgbe_msix_clean_rings
[250764.620348] ixgbe: ixgbe_msix_clean_rings
[250764.620349] ixgbe: ixgbe_msix_clean_rings
[250764.620350] ixgbe: ixgbe_msix_clean_rings
[250764.620351] ixgbe: ixgbe_msix_clean_rings
[250764.620352] ixgbe: ixgbe_msix_clean_rings
[250764.620353] ixgbe: ixgbe_msix_clean_rings
[250764.620354] ixgbe: ixgbe_msix_clean_rings
[250766.636113] ixgbe: ixgbe_service_timer
[250766.636133] ixgbe: ixgbe_service_event_schedule
[250766.636171] ixgbe: ixgbe_service_task
[250766.636177] ixgbe: ixgbe_check_fw_error
[250766.636178] ixgbe: ixgbe_reset_subtask
[250766.636180] ixgbe: ixgbe_phy_interrupt_subtask
[250766.636181] ixgbe: ixgbe_sfp_detection_subtask
[250766.636182] ixgbe: ixgbe_sfp_link_config_subtask
[250766.636183] ixgbe: ixgbe_check_overtemp_subtask
[250766.636184] ixgbe: ixgbe_watchdog_subtask
[250766.636185] ixgbe: ixgbe_watchdog_update_link
[250766.636186] ixgbe: ixgbe_watchdog_link_is_up
[250766.636187] ixgbe: ixgbe_check_for_bad_vf
[250766.636190] ixgbe: ixgbe_spoof_check
[250766.636191] ixgbe: ixgbe_update_stats
[250766.636253] ixgbe: ixgbe_update_xoff_received
[250766.636255] ixgbe: ixgbe_update_xoff_rx_lfc
[250766.636278] ixgbe: ixgbe_watchdog_flush_tx
[250766.636279] ixgbe: ixgbe_fdir_reinit_subtask
[250766.636280] ixgbe: ixgbe_check_hang_subtask
[250766.636282] ixgbe: ixgbe_irq_rearm_queues
[250766.636284] ixgbe: ixgbe_service_event_complete
[250766.636289] ixgbe: ixgbe_msix_clean_rings
[250766.636291] ixgbe: ixgbe_msix_clean_rings
[250766.636291] ixgbe: ixgbe_msix_clean_rings
[250766.636291] ixgbe: ixgbe_msix_clean_rings
[250766.636292] ixgbe: ixgbe_msix_clean_rings
[250766.636295] ixgbe: ixgbe_msix_clean_rings
[250766.636291] ixgbe: ixgbe_msix_clean_rings
[250766.636293] ixgbe: ixgbe_msix_clean_rings
[250766.636293] ixgbe: ixgbe_msix_clean_rings
[250766.636293] ixgbe: ixgbe_msix_clean_rings
[250766.636304] ixgbe: ixgbe_msix_clean_rings
[250766.636308] ixgbe: ixgbe_msix_clean_rings
[250766.636318] ixgbe: ixgbe_msix_clean_rings
[250766.636319] ixgbe: ixgbe_msix_clean_rings
[250766.636320] ixgbe: ixgbe_msix_clean_rings
[250766.636321] ixgbe: ixgbe_msix_clean_rings
[250766.636322] ixgbe: ixgbe_msix_clean_rings
[250766.636323] ixgbe: ixgbe_msix_clean_rings
[250766.636322] ixgbe: ixgbe_msix_clean_rings
[250766.636323] ixgbe: ixgbe_msix_clean_rings
[250768.652084] ixgbe: ixgbe_service_timer
[250768.652102] ixgbe: ixgbe_service_event_schedule
[250768.652141] ixgbe: ixgbe_service_task
[250768.652147] ixgbe: ixgbe_check_fw_error
[250768.652149] ixgbe: ixgbe_reset_subtask
[250768.652151] ixgbe: ixgbe_phy_interrupt_subtask
[250768.652152] ixgbe: ixgbe_sfp_detection_subtask
[250768.652153] ixgbe: ixgbe_sfp_link_config_subtask
[250768.652154] ixgbe: ixgbe_check_overtemp_subtask
[250768.652155] ixgbe: ixgbe_watchdog_subtask
[250768.652156] ixgbe: ixgbe_watchdog_update_link
[250768.652157] ixgbe: ixgbe_watchdog_link_is_up
[250768.652158] ixgbe: ixgbe_check_for_bad_vf
[250768.652159] ixgbe: ixgbe_spoof_check
[250768.652160] ixgbe: ixgbe_update_stats
[250768.652220] ixgbe: ixgbe_update_xoff_received
[250768.652222] ixgbe: ixgbe_update_xoff_rx_lfc
[250768.652246] ixgbe: ixgbe_watchdog_flush_tx
[250768.652247] ixgbe: ixgbe_fdir_reinit_subtask
[250768.652248] ixgbe: ixgbe_check_hang_subtask
[250768.652250] ixgbe: ixgbe_irq_rearm_queues
[250768.652251] ixgbe: ixgbe_service_event_complete
[250768.652259] ixgbe: ixgbe_msix_clean_rings
[250768.652259] ixgbe: ixgbe_msix_clean_rings
[250768.652260] ixgbe: ixgbe_msix_clean_rings
[250768.652261] ixgbe: ixgbe_msix_clean_rings
[250768.652260] ixgbe: ixgbe_msix_clean_rings
[250768.652260] ixgbe: ixgbe_msix_clean_rings
[250768.652262] ixgbe: ixgbe_msix_clean_rings
[250768.652260] ixgbe: ixgbe_msix_clean_rings
[250768.652267] ixgbe: ixgbe_msix_clean_rings
[250768.652285] ixgbe: ixgbe_msix_clean_rings
[250768.652285] ixgbe: ixgbe_msix_clean_rings
[250768.652287] ixgbe: ixgbe_msix_clean_rings
[250768.652286] ixgbe: ixgbe_msix_clean_rings
[250768.652288] ixgbe: ixgbe_msix_clean_rings
[250768.652289] ixgbe: ixgbe_msix_clean_rings
[250768.652287] ixgbe: ixgbe_msix_clean_rings
[250768.652290] ixgbe: ixgbe_msix_clean_rings
[250768.652291] ixgbe: ixgbe_msix_clean_rings
[250768.652292] ixgbe: ixgbe_msix_clean_rings
[250768.652293] ixgbe: ixgbe_msix_clean_rings
[250770.313700] ixgbe: ixgbe_poll v_idx=0 budget=1
[250770.313709] ixgbe: ixgbe_poll v_idx=1 budget=1
[250770.313712] ixgbe: ixgbe_poll v_idx=2 budget=1
[250770.313714] ixgbe: ixgbe_poll v_idx=3 budget=1
[250770.313717] ixgbe: ixgbe_poll v_idx=4 budget=1
[250770.313719] ixgbe: ixgbe_poll v_idx=5 budget=1
[250770.313721] ixgbe: ixgbe_poll v_idx=6 budget=1
[250770.313723] ixgbe: ixgbe_poll v_idx=7 budget=1
[250770.313725] ixgbe: ixgbe_poll v_idx=8 budget=1
[250770.313728] ixgbe: ixgbe_poll v_idx=9 budget=1
[250770.313730] ixgbe: ixgbe_poll v_idx=10 budget=1
[250770.313732] ixgbe: ixgbe_poll v_idx=11 budget=1
[250770.313734] ixgbe: ixgbe_poll v_idx=12 budget=1
[250770.313737] ixgbe: ixgbe_poll v_idx=13 budget=1
[250770.313739] ixgbe: ixgbe_poll v_idx=14 budget=1
[250770.313741] ixgbe: ixgbe_poll v_idx=15 budget=1
[250770.313744] ixgbe: ixgbe_poll v_idx=16 budget=1
[250770.313746] ixgbe: ixgbe_poll v_idx=17 budget=1
[250770.313748] ixgbe: ixgbe_poll v_idx=18 budget=1
[250770.313750] ixgbe: ixgbe_poll v_idx=19 budget=1
[250770.668045] ixgbe: ixgbe_service_timer
[250770.668063] ixgbe: ixgbe_service_event_schedule
[250770.668100] ixgbe: ixgbe_service_task
[250770.668105] ixgbe: ixgbe_check_fw_error
[250770.668108] ixgbe: ixgbe_reset_subtask
[250770.668109] ixgbe: ixgbe_phy_interrupt_subtask
[250770.668111] ixgbe: ixgbe_sfp_detection_subtask
[250770.668114] ixgbe: ixgbe_sfp_link_config_subtask
[250770.668116] ixgbe: ixgbe_check_overtemp_subtask
[250770.668117] ixgbe: ixgbe_watchdog_subtask
[250770.668118] ixgbe: ixgbe_watchdog_update_link
[250770.668119] ixgbe: ixgbe_watchdog_link_is_up
[250770.668120] ixgbe: ixgbe_check_for_bad_vf
[250770.668121] ixgbe: ixgbe_spoof_check
[250770.668122] ixgbe: ixgbe_update_stats
[250770.668183] ixgbe: ixgbe_update_xoff_received
[250770.668185] ixgbe: ixgbe_update_xoff_rx_lfc
[250770.668208] ixgbe: ixgbe_watchdog_flush_tx
[250770.668210] ixgbe: ixgbe_fdir_reinit_subtask
[250770.668211] ixgbe: ixgbe_check_hang_subtask
[250770.668213] ixgbe: ixgbe_irq_rearm_queues
[250770.668215] ixgbe: ixgbe_service_event_complete
[250770.668222] ixgbe: ixgbe_msix_clean_rings
[250770.668222] ixgbe: ixgbe_msix_clean_rings
[250770.668222] ixgbe: ixgbe_msix_clean_rings
[250770.668223] ixgbe: ixgbe_msix_clean_rings
[250770.668225] ixgbe: ixgbe_msix_clean_rings
[250770.668223] ixgbe: ixgbe_msix_clean_rings
[250770.668222] ixgbe: ixgbe_msix_clean_rings
[250770.668223] ixgbe: ixgbe_msix_clean_rings
[250770.668223] ixgbe: ixgbe_msix_clean_rings
[250770.668248] ixgbe: ixgbe_msix_clean_rings
[250770.668249] ixgbe: ixgbe_msix_clean_rings
[250770.668249] ixgbe: ixgbe_msix_clean_rings
[250770.668250] ixgbe: ixgbe_msix_clean_rings
[250770.668250] ixgbe: ixgbe_msix_clean_rings
[250770.668253] ixgbe: ixgbe_msix_clean_rings
[250770.668252] ixgbe: ixgbe_msix_clean_rings
[250770.668256] ixgbe: ixgbe_msix_clean_rings
[250770.668251] ixgbe: ixgbe_msix_clean_rings
[250770.668254] ixgbe: ixgbe_msix_clean_rings
[250770.668255] ixgbe: ixgbe_msix_clean_rings
[250771.313856] ixgbe: ixgbe_poll v_idx=0 budget=1
[250771.313863] ixgbe: ixgbe_poll v_idx=1 budget=1
[250771.313865] ixgbe: ixgbe_poll v_idx=2 budget=1
[250771.313867] ixgbe: ixgbe_poll v_idx=3 budget=1
[250771.313869] ixgbe: ixgbe_poll v_idx=4 budget=1
[250771.313871] ixgbe: ixgbe_poll v_idx=5 budget=1
[250771.313873] ixgbe: ixgbe_poll v_idx=6 budget=1
[250771.313874] ixgbe: ixgbe_poll v_idx=7 budget=1
[250771.313876] ixgbe: ixgbe_poll v_idx=8 budget=1
[250771.313878] ixgbe: ixgbe_poll v_idx=9 budget=1
[250771.313879] ixgbe: ixgbe_poll v_idx=10 budget=1
[250771.313881] ixgbe: ixgbe_poll v_idx=11 budget=1
[250771.313883] ixgbe: ixgbe_poll v_idx=12 budget=1
[250771.313885] ixgbe: ixgbe_poll v_idx=13 budget=1
[250771.313887] ixgbe: ixgbe_poll v_idx=14 budget=1
[250771.313889] ixgbe: ixgbe_poll v_idx=15 budget=1
[250771.313891] ixgbe: ixgbe_poll v_idx=16 budget=1
[250771.313892] ixgbe: ixgbe_poll v_idx=17 budget=1
[250771.313894] ixgbe: ixgbe_poll v_idx=18 budget=1
[250771.313896] ixgbe: ixgbe_poll v_idx=19 budget=1
[250772.314011] ixgbe: ixgbe_poll v_idx=0 budget=1
[250772.314017] ixgbe: ixgbe_poll v_idx=1 budget=1
[250772.314019] ixgbe: ixgbe_poll v_idx=2 budget=1
[250772.314021] ixgbe: ixgbe_poll v_idx=3 budget=1
[250772.314022] ixgbe: ixgbe_poll v_idx=4 budget=1
[250772.314023] ixgbe: ixgbe_poll v_idx=5 budget=1
[250772.314025] ixgbe: ixgbe_poll v_idx=6 budget=1
[250772.314026] ixgbe: ixgbe_poll v_idx=7 budget=1
[250772.314028] ixgbe: ixgbe_poll v_idx=8 budget=1
[250772.314029] ixgbe: ixgbe_poll v_idx=9 budget=1
[250772.314031] ixgbe: ixgbe_poll v_idx=10 budget=1
[250772.314032] ixgbe: ixgbe_poll v_idx=11 budget=1
[250772.314034] ixgbe: ixgbe_poll v_idx=12 budget=1
[250772.314036] ixgbe: ixgbe_poll v_idx=13 budget=1
[250772.314037] ixgbe: ixgbe_poll v_idx=14 budget=1
[250772.314039] ixgbe: ixgbe_poll v_idx=15 budget=1
[250772.314040] ixgbe: ixgbe_poll v_idx=16 budget=1
[250772.314041] ixgbe: ixgbe_poll v_idx=17 budget=1
[250772.314043] ixgbe: ixgbe_poll v_idx=18 budget=1
[250772.314044] ixgbe: ixgbe_poll v_idx=19 budget=1
[250772.684018] ixgbe: ixgbe_service_timer
[250772.684035] ixgbe: ixgbe_service_event_schedule
[250772.684074] ixgbe: ixgbe_service_task
[250772.684080] ixgbe: ixgbe_check_fw_error
[250772.684083] ixgbe: ixgbe_reset_subtask
[250772.684084] ixgbe: ixgbe_phy_interrupt_subtask
[250772.684085] ixgbe: ixgbe_sfp_detection_subtask
[250772.684086] ixgbe: ixgbe_sfp_link_config_subtask
[250772.684087] ixgbe: ixgbe_check_overtemp_subtask
[250772.684088] ixgbe: ixgbe_watchdog_subtask
[250772.684089] ixgbe: ixgbe_watchdog_update_link
[250772.684090] ixgbe: ixgbe_watchdog_link_is_up
[250772.684091] ixgbe: ixgbe_check_for_bad_vf
[250772.684092] ixgbe: ixgbe_spoof_check
[250772.684093] ixgbe: ixgbe_update_stats
[250772.684154] ixgbe: ixgbe_update_xoff_received
[250772.684156] ixgbe: ixgbe_update_xoff_rx_lfc
[250772.684179] ixgbe: ixgbe_watchdog_flush_tx
[250772.684180] ixgbe: ixgbe_fdir_reinit_subtask
[250772.684181] ixgbe: ixgbe_check_hang_subtask
[250772.684184] ixgbe: ixgbe_irq_rearm_queues
[250772.684185] ixgbe: ixgbe_service_event_complete
[250772.684194] ixgbe: ixgbe_msix_clean_rings
[250772.684194] ixgbe: ixgbe_msix_clean_rings
[250772.684196] ixgbe: ixgbe_msix_clean_rings
[250772.684194] ixgbe: ixgbe_msix_clean_rings
[250772.684195] ixgbe: ixgbe_msix_clean_rings
[250772.684196] ixgbe: ixgbe_msix_clean_rings
[250772.684195] ixgbe: ixgbe_msix_clean_rings
[250772.684195] ixgbe: ixgbe_msix_clean_rings
[250772.684203] ixgbe: ixgbe_msix_clean_rings
[250772.684220] ixgbe: ixgbe_msix_clean_rings
[250772.684221] ixgbe: ixgbe_msix_clean_rings
[250772.684221] ixgbe: ixgbe_msix_clean_rings
[250772.684222] ixgbe: ixgbe_msix_clean_rings
[250772.684222] ixgbe: ixgbe_msix_clean_rings
[250772.684223] ixgbe: ixgbe_msix_clean_rings
[250772.684223] ixgbe: ixgbe_msix_clean_rings
[250772.684224] ixgbe: ixgbe_msix_clean_rings
[250772.684225] ixgbe: ixgbe_msix_clean_rings
[250772.684226] ixgbe: ixgbe_msix_clean_rings
[250772.684227] ixgbe: ixgbe_msix_clean_rings
[250773.314160] ixgbe: ixgbe_poll v_idx=0 budget=1
[250773.314167] ixgbe: ixgbe_poll v_idx=1 budget=1
[250773.314169] ixgbe: ixgbe_poll v_idx=2 budget=1
[250773.314172] ixgbe: ixgbe_poll v_idx=3 budget=1
[250773.314174] ixgbe: ixgbe_poll v_idx=4 budget=1
[250773.314176] ixgbe: ixgbe_poll v_idx=5 budget=1
[250773.314177] ixgbe: ixgbe_poll v_idx=6 budget=1
[250773.314179] ixgbe: ixgbe_poll v_idx=7 budget=1
[250773.314181] ixgbe: ixgbe_poll v_idx=8 budget=1
[250773.314182] ixgbe: ixgbe_poll v_idx=9 budget=1
[250773.314184] ixgbe: ixgbe_poll v_idx=10 budget=1
[250773.314186] ixgbe: ixgbe_poll v_idx=11 budget=1
[250773.314188] ixgbe: ixgbe_poll v_idx=12 budget=1
[250773.314189] ixgbe: ixgbe_poll v_idx=13 budget=1
[250773.314191] ixgbe: ixgbe_poll v_idx=14 budget=1
[250773.314193] ixgbe: ixgbe_poll v_idx=15 budget=1
[250773.314194] ixgbe: ixgbe_poll v_idx=16 budget=1
[250773.314196] ixgbe: ixgbe_poll v_idx=17 budget=1
[250773.314198] ixgbe: ixgbe_poll v_idx=18 budget=1
[250773.314200] ixgbe: ixgbe_poll v_idx=19 budget=1
[250774.314316] ixgbe: ixgbe_poll v_idx=0 budget=1
[250774.314322] ixgbe: ixgbe_poll v_idx=1 budget=1
[250774.314324] ixgbe: ixgbe_poll v_idx=2 budget=1
[250774.314326] ixgbe: ixgbe_poll v_idx=3 budget=1
[250774.314327] ixgbe: ixgbe_poll v_idx=4 budget=1
[250774.314328] ixgbe: ixgbe_poll v_idx=5 budget=1
[250774.314329] ixgbe: ixgbe_poll v_idx=6 budget=1
[250774.314331] ixgbe: ixgbe_poll v_idx=7 budget=1
[250774.314332] ixgbe: ixgbe_poll v_idx=8 budget=1
[250774.314333] ixgbe: ixgbe_poll v_idx=9 budget=1
[250774.314335] ixgbe: ixgbe_poll v_idx=10 budget=1
[250774.314337] ixgbe: ixgbe_poll v_idx=11 budget=1
[250774.314338] ixgbe: ixgbe_poll v_idx=12 budget=1
[250774.314340] ixgbe: ixgbe_poll v_idx=13 budget=1
[250774.314341] ixgbe: ixgbe_poll v_idx=14 budget=1
[250774.314342] ixgbe: ixgbe_poll v_idx=15 budget=1
[250774.314344] ixgbe: ixgbe_poll v_idx=16 budget=1
[250774.314345] ixgbe: ixgbe_poll v_idx=17 budget=1
[250774.314347] ixgbe: ixgbe_poll v_idx=18 budget=1
[250774.314348] ixgbe: ixgbe_poll v_idx=19 budget=1
[250774.699986] ixgbe: ixgbe_service_timer
[250774.700003] ixgbe: ixgbe_service_event_schedule
[250774.700043] ixgbe: ixgbe_service_task
[250774.700048] ixgbe: ixgbe_check_fw_error
[250774.700051] ixgbe: ixgbe_reset_subtask
[250774.700052] ixgbe: ixgbe_phy_interrupt_subtask
[250774.700053] ixgbe: ixgbe_sfp_detection_subtask
[250774.700054] ixgbe: ixgbe_sfp_link_config_subtask
[250774.700056] ixgbe: ixgbe_check_overtemp_subtask
[250774.700057] ixgbe: ixgbe_watchdog_subtask
[250774.700058] ixgbe: ixgbe_watchdog_update_link
[250774.700059] ixgbe: ixgbe_watchdog_link_is_up
[250774.700060] ixgbe: ixgbe_check_for_bad_vf
[250774.700061] ixgbe: ixgbe_spoof_check
[250774.700062] ixgbe: ixgbe_update_stats
[250774.700123] ixgbe: ixgbe_update_xoff_received
[250774.700125] ixgbe: ixgbe_update_xoff_rx_lfc
[250774.700148] ixgbe: ixgbe_watchdog_flush_tx
[250774.700149] ixgbe: ixgbe_fdir_reinit_subtask
[250774.700151] ixgbe: ixgbe_check_hang_subtask
[250774.700154] ixgbe: ixgbe_irq_rearm_queues
[250774.700155] ixgbe: ixgbe_service_event_complete
[250774.700163] ixgbe: ixgbe_msix_clean_rings
[250774.700163] ixgbe: ixgbe_msix_clean_rings
[250774.700162] ixgbe: ixgbe_msix_clean_rings
[250774.700165] ixgbe: ixgbe_msix_clean_rings
[250774.700163] ixgbe: ixgbe_msix_clean_rings
[250774.700164] ixgbe: ixgbe_msix_clean_rings
[250774.700164] ixgbe: ixgbe_msix_clean_rings
[250774.700163] ixgbe: ixgbe_msix_clean_rings
[250774.700176] ixgbe: ixgbe_msix_clean_rings
[250774.700187] ixgbe: ixgbe_msix_clean_rings
[250774.700188] ixgbe: ixgbe_msix_clean_rings
[250774.700189] ixgbe: ixgbe_msix_clean_rings
[250774.700191] ixgbe: ixgbe_msix_clean_rings
[250774.700191] ixgbe: ixgbe_msix_clean_rings
[250774.700192] ixgbe: ixgbe_msix_clean_rings
[250774.700193] ixgbe: ixgbe_msix_clean_rings
[250774.700194] ixgbe: ixgbe_msix_clean_rings
[250774.700195] ixgbe: ixgbe_msix_clean_rings
[250774.700196] ixgbe: ixgbe_msix_clean_rings
[250774.700198] ixgbe: ixgbe_msix_clean_rings
[250775.314455] ixgbe: ixgbe_poll v_idx=0 budget=1
[250775.314461] ixgbe: ixgbe_poll v_idx=1 budget=1
[250775.314464] ixgbe: ixgbe_get_rx_buffer
[250775.314466] ixgbe: ixgbe_run_xdp
[250775.314467] ixgbe: ixgbe_build_skb
[250775.314470] ixgbe: ixgbe_put_rx_buffer
[250775.314471] ixgbe: ixgbe_can_reuse_rx_page
[250775.314472] ixgbe: ixgbe_is_non_eop
[250775.314474] ixgbe: ixgbe_cleanup_headers
[250775.314475] ixgbe: ixgbe_process_skb_fields
[250775.314477] ixgbe: ixgbe_update_rsc_stats
[250775.314478] ixgbe: ixgbe_rx_hash
[250775.314479] ixgbe: ixgbe_rx_checksum
[250775.314481] ixgbe: ixgbe_rx_skb
[250775.314483] ixgbe: ixgbe_poll v_idx=2 budget=1
[250775.314485] ixgbe: ixgbe_poll v_idx=3 budget=1
[250775.314486] ixgbe: ixgbe_poll v_idx=4 budget=1
[250775.314488] ixgbe: ixgbe_poll v_idx=5 budget=1
[250775.314490] ixgbe: ixgbe_poll v_idx=6 budget=1
[250775.314492] ixgbe: ixgbe_poll v_idx=7 budget=1
[250775.314493] ixgbe: ixgbe_poll v_idx=8 budget=1
[250775.314495] ixgbe: ixgbe_poll v_idx=9 budget=1
[250775.314497] ixgbe: ixgbe_poll v_idx=10 budget=1
[250775.314499] ixgbe: ixgbe_poll v_idx=11 budget=1
[250775.314500] ixgbe: ixgbe_poll v_idx=12 budget=1
[250775.314502] ixgbe: ixgbe_poll v_idx=13 budget=1
[250775.314504] ixgbe: ixgbe_poll v_idx=14 budget=1
[250775.314505] ixgbe: ixgbe_poll v_idx=15 budget=1
[250775.314507] ixgbe: ixgbe_poll v_idx=16 budget=1
[250775.314509] ixgbe: ixgbe_poll v_idx=17 budget=1
[250775.314510] ixgbe: ixgbe_poll v_idx=18 budget=1
[250775.314512] ixgbe: ixgbe_poll v_idx=19 budget=1
[250776.314588] ixgbe: ixgbe_poll v_idx=0 budget=1
[250776.314595] ixgbe: ixgbe_poll v_idx=1 budget=1
[250776.314597] ixgbe: ixgbe_poll v_idx=2 budget=1
[250776.314598] ixgbe: ixgbe_poll v_idx=3 budget=1
[250776.314599] ixgbe: ixgbe_poll v_idx=4 budget=1
[250776.314601] ixgbe: ixgbe_poll v_idx=5 budget=1
[250776.314602] ixgbe: ixgbe_poll v_idx=6 budget=1
[250776.314603] ixgbe: ixgbe_poll v_idx=7 budget=1
[250776.314605] ixgbe: ixgbe_poll v_idx=8 budget=1
[250776.314607] ixgbe: ixgbe_poll v_idx=9 budget=1
[250776.314608] ixgbe: ixgbe_poll v_idx=10 budget=1
[250776.314610] ixgbe: ixgbe_poll v_idx=11 budget=1
[250776.314612] ixgbe: ixgbe_poll v_idx=12 budget=1
[250776.314614] ixgbe: ixgbe_poll v_idx=13 budget=1
[250776.314615] ixgbe: ixgbe_poll v_idx=14 budget=1
[250776.314616] ixgbe: ixgbe_poll v_idx=15 budget=1
[250776.314618] ixgbe: ixgbe_poll v_idx=16 budget=1
[250776.314619] ixgbe: ixgbe_poll v_idx=17 budget=1
[250776.314620] ixgbe: ixgbe_poll v_idx=18 budget=1
[250776.314622] ixgbe: ixgbe_poll v_idx=19 budget=1
[250776.715958] ixgbe: ixgbe_service_timer
[250776.715975] ixgbe: ixgbe_service_event_schedule
[250776.716014] ixgbe: ixgbe_service_task
[250776.716019] ixgbe: ixgbe_check_fw_error
[250776.716022] ixgbe: ixgbe_reset_subtask
[250776.716023] ixgbe: ixgbe_phy_interrupt_subtask
[250776.716026] ixgbe: ixgbe_sfp_detection_subtask
[250776.716028] ixgbe: ixgbe_sfp_link_config_subtask
[250776.716029] ixgbe: ixgbe_check_overtemp_subtask
[250776.716031] ixgbe: ixgbe_watchdog_subtask
[250776.716032] ixgbe: ixgbe_watchdog_update_link
[250776.716033] ixgbe: ixgbe_watchdog_link_is_up
[250776.716034] ixgbe: ixgbe_check_for_bad_vf
[250776.716035] ixgbe: ixgbe_spoof_check
[250776.716036] ixgbe: ixgbe_update_stats
[250776.716097] ixgbe: ixgbe_update_xoff_received
[250776.716098] ixgbe: ixgbe_update_xoff_rx_lfc
[250776.716122] ixgbe: ixgbe_watchdog_flush_tx
[250776.716123] ixgbe: ixgbe_fdir_reinit_subtask
[250776.716124] ixgbe: ixgbe_check_hang_subtask
[250776.716127] ixgbe: ixgbe_irq_rearm_queues
[250776.716129] ixgbe: ixgbe_service_event_complete
[250776.716136] ixgbe: ixgbe_msix_clean_rings
[250776.716136] ixgbe: ixgbe_msix_clean_rings
[250776.716136] ixgbe: ixgbe_msix_clean_rings
[250776.716138] ixgbe: ixgbe_msix_clean_rings
[250776.716137] ixgbe: ixgbe_msix_clean_rings
[250776.716137] ixgbe: ixgbe_msix_clean_rings
[250776.716137] ixgbe: ixgbe_msix_clean_rings
[250776.716139] ixgbe: ixgbe_msix_clean_rings
[250776.716137] ixgbe: ixgbe_msix_clean_rings
[250776.716163] ixgbe: ixgbe_msix_clean_rings
[250776.716164] ixgbe: ixgbe_msix_clean_rings
[250776.716163] ixgbe: ixgbe_msix_clean_rings
[250776.716164] ixgbe: ixgbe_msix_clean_rings
[250776.716166] ixgbe: ixgbe_msix_clean_rings
[250776.716165] ixgbe: ixgbe_msix_clean_rings
[250776.716165] ixgbe: ixgbe_msix_clean_rings
[250776.716168] ixgbe: ixgbe_msix_clean_rings
[250776.716167] ixgbe: ixgbe_msix_clean_rings
[250776.716170] ixgbe: ixgbe_msix_clean_rings
[250776.716169] ixgbe: ixgbe_msix_clean_rings
[250777.314737] ixgbe: ixgbe_poll v_idx=0 budget=1
[250777.314744] ixgbe: ixgbe_poll v_idx=1 budget=1
[250777.314746] ixgbe: ixgbe_get_rx_buffer
[250777.314747] ixgbe: ixgbe_run_xdp
[250777.314748] ixgbe: ixgbe_build_skb
[250777.314751] ixgbe: ixgbe_put_rx_buffer
[250777.314751] ixgbe: ixgbe_can_reuse_rx_page
[250777.314753] ixgbe: ixgbe_is_non_eop
[250777.314754] ixgbe: ixgbe_cleanup_headers
[250777.314756] ixgbe: ixgbe_process_skb_fields
[250777.314757] ixgbe: ixgbe_update_rsc_stats
[250777.314757] ixgbe: ixgbe_rx_hash
[250777.314759] ixgbe: ixgbe_rx_checksum
[250777.314760] ixgbe: ixgbe_rx_skb
[250777.314762] ixgbe: ixgbe_poll v_idx=2 budget=1
[250777.314764] ixgbe: ixgbe_poll v_idx=3 budget=1
[250777.314766] ixgbe: ixgbe_poll v_idx=4 budget=1
[250777.314768] ixgbe: ixgbe_poll v_idx=5 budget=1
[250777.314769] ixgbe: ixgbe_poll v_idx=6 budget=1
[250777.314771] ixgbe: ixgbe_poll v_idx=7 budget=1
[250777.314772] ixgbe: ixgbe_poll v_idx=8 budget=1
[250777.314774] ixgbe: ixgbe_poll v_idx=9 budget=1
[250777.314776] ixgbe: ixgbe_poll v_idx=10 budget=1
[250777.314778] ixgbe: ixgbe_poll v_idx=11 budget=1
[250777.314780] ixgbe: ixgbe_poll v_idx=12 budget=1
[250777.314781] ixgbe: ixgbe_poll v_idx=13 budget=1
[250777.314783] ixgbe: ixgbe_poll v_idx=14 budget=1
[250777.314785] ixgbe: ixgbe_poll v_idx=15 budget=1
[250777.314787] ixgbe: ixgbe_poll v_idx=16 budget=1
[250777.314788] ixgbe: ixgbe_poll v_idx=17 budget=1
[250777.314790] ixgbe: ixgbe_poll v_idx=18 budget=1
[250777.314792] ixgbe: ixgbe_poll v_idx=19 budget=1
[250778.314903] ixgbe: ixgbe_poll v_idx=0 budget=1
[250778.314909] ixgbe: ixgbe_poll v_idx=1 budget=1
[250778.314911] ixgbe: ixgbe_poll v_idx=2 budget=1
[250778.314913] ixgbe: ixgbe_poll v_idx=3 budget=1
[250778.314914] ixgbe: ixgbe_poll v_idx=4 budget=1
[250778.314916] ixgbe: ixgbe_poll v_idx=5 budget=1
[250778.314917] ixgbe: ixgbe_poll v_idx=6 budget=1
[250778.314918] ixgbe: ixgbe_poll v_idx=7 budget=1
[250778.314920] ixgbe: ixgbe_poll v_idx=8 budget=1
[250778.314921] ixgbe: ixgbe_poll v_idx=9 budget=1
[250778.314922] ixgbe: ixgbe_poll v_idx=10 budget=1
[250778.314924] ixgbe: ixgbe_poll v_idx=11 budget=1
[250778.314925] ixgbe: ixgbe_poll v_idx=12 budget=1
[250778.314927] ixgbe: ixgbe_poll v_idx=13 budget=1
[250778.314928] ixgbe: ixgbe_poll v_idx=14 budget=1
[250778.314930] ixgbe: ixgbe_poll v_idx=15 budget=1
[250778.314931] ixgbe: ixgbe_poll v_idx=16 budget=1
[250778.314932] ixgbe: ixgbe_poll v_idx=17 budget=1
[250778.314934] ixgbe: ixgbe_poll v_idx=18 budget=1
[250778.314935] ixgbe: ixgbe_poll v_idx=19 budget=1
[250778.731901] ixgbe: ixgbe_service_timer
[250778.731916] ixgbe: ixgbe_service_event_schedule
[250778.731956] ixgbe: ixgbe_service_task
[250778.731962] ixgbe: ixgbe_check_fw_error
[250778.731964] ixgbe: ixgbe_reset_subtask
[250778.731965] ixgbe: ixgbe_phy_interrupt_subtask
[250778.731966] ixgbe: ixgbe_sfp_detection_subtask
[250778.731967] ixgbe: ixgbe_sfp_link_config_subtask
[250778.731968] ixgbe: ixgbe_check_overtemp_subtask
[250778.731969] ixgbe: ixgbe_watchdog_subtask
[250778.731970] ixgbe: ixgbe_watchdog_update_link
[250778.731971] ixgbe: ixgbe_watchdog_link_is_up
[250778.731972] ixgbe: ixgbe_check_for_bad_vf
[250778.731974] ixgbe: ixgbe_spoof_check
[250778.731974] ixgbe: ixgbe_update_stats
[250778.732035] ixgbe: ixgbe_update_xoff_received
[250778.732037] ixgbe: ixgbe_update_xoff_rx_lfc
[250778.732060] ixgbe: ixgbe_watchdog_flush_tx
[250778.732062] ixgbe: ixgbe_fdir_reinit_subtask
[250778.732063] ixgbe: ixgbe_check_hang_subtask
[250778.732066] ixgbe: ixgbe_irq_rearm_queues
[250778.732067] ixgbe: ixgbe_service_event_complete
[250778.732073] ixgbe: ixgbe_msix_clean_rings
[250778.732075] ixgbe: ixgbe_msix_clean_rings
[250778.732075] ixgbe: ixgbe_msix_clean_rings
[250778.732075] ixgbe: ixgbe_msix_clean_rings
[250778.732078] ixgbe: ixgbe_msix_clean_rings
[250778.732075] ixgbe: ixgbe_msix_clean_rings
[250778.732075] ixgbe: ixgbe_msix_clean_rings
[250778.732078] ixgbe: ixgbe_msix_clean_rings
[250778.732075] ixgbe: ixgbe_msix_clean_rings
[250778.732100] ixgbe: ixgbe_msix_clean_rings
[250778.732101] ixgbe: ixgbe_msix_clean_rings
[250778.732101] ixgbe: ixgbe_msix_clean_rings
[250778.732103] ixgbe: ixgbe_msix_clean_rings
[250778.732103] ixgbe: ixgbe_msix_clean_rings
[250778.732105] ixgbe: ixgbe_msix_clean_rings
[250778.732102] ixgbe: ixgbe_msix_clean_rings
[250778.732104] ixgbe: ixgbe_msix_clean_rings
[250778.732106] ixgbe: ixgbe_msix_clean_rings
[250778.732107] ixgbe: ixgbe_msix_clean_rings
[250778.732102] ixgbe: ixgbe_msix_clean_rings
[250779.315044] ixgbe: ixgbe_poll v_idx=0 budget=1
[250779.315051] ixgbe: ixgbe_poll v_idx=1 budget=1
[250779.315054] ixgbe: ixgbe_poll v_idx=2 budget=1
[250779.315056] ixgbe: ixgbe_poll v_idx=3 budget=1
[250779.315058] ixgbe: ixgbe_poll v_idx=4 budget=1
[250779.315060] ixgbe: ixgbe_poll v_idx=5 budget=1
[250779.315062] ixgbe: ixgbe_poll v_idx=6 budget=1
[250779.315065] ixgbe: ixgbe_poll v_idx=7 budget=1
[250779.315067] ixgbe: ixgbe_poll v_idx=8 budget=1
[250779.315069] ixgbe: ixgbe_poll v_idx=9 budget=1
[250779.315070] ixgbe: ixgbe_poll v_idx=10 budget=1
[250779.315072] ixgbe: ixgbe_poll v_idx=11 budget=1
[250779.315074] ixgbe: ixgbe_poll v_idx=12 budget=1
[250779.315076] ixgbe: ixgbe_poll v_idx=13 budget=1
[250779.315078] ixgbe: ixgbe_poll v_idx=14 budget=1
[250779.315079] ixgbe: ixgbe_poll v_idx=15 budget=1
[250779.315081] ixgbe: ixgbe_poll v_idx=16 budget=1
[250779.315083] ixgbe: ixgbe_poll v_idx=17 budget=1
[250779.315085] ixgbe: ixgbe_poll v_idx=18 budget=1
[250779.315087] ixgbe: ixgbe_poll v_idx=19 budget=1
[250780.747911] ixgbe: ixgbe_service_timer
[250780.747929] ixgbe: ixgbe_service_event_schedule
[250780.747969] ixgbe: ixgbe_service_task
[250780.747974] ixgbe: ixgbe_check_fw_error
[250780.747977] ixgbe: ixgbe_reset_subtask
[250780.747980] ixgbe: ixgbe_phy_interrupt_subtask
[250780.747981] ixgbe: ixgbe_sfp_detection_subtask
[250780.747983] ixgbe: ixgbe_sfp_link_config_subtask
[250780.747984] ixgbe: ixgbe_check_overtemp_subtask
[250780.747985] ixgbe: ixgbe_watchdog_subtask
[250780.747986] ixgbe: ixgbe_watchdog_update_link
[250780.747987] ixgbe: ixgbe_watchdog_link_is_up
[250780.747988] ixgbe: ixgbe_check_for_bad_vf
[250780.747990] ixgbe: ixgbe_spoof_check
[250780.747991] ixgbe: ixgbe_update_stats
[250780.748051] ixgbe: ixgbe_update_xoff_received
[250780.748053] ixgbe: ixgbe_update_xoff_rx_lfc
[250780.748077] ixgbe: ixgbe_watchdog_flush_tx
[250780.748078] ixgbe: ixgbe_fdir_reinit_subtask
[250780.748079] ixgbe: ixgbe_check_hang_subtask
[250780.748082] ixgbe: ixgbe_irq_rearm_queues
[250780.748083] ixgbe: ixgbe_service_event_complete
[250780.748090] ixgbe: ixgbe_msix_clean_rings
[250780.748089] ixgbe: ixgbe_msix_clean_rings
[250780.748091] ixgbe: ixgbe_msix_clean_rings
[250780.748091] ixgbe: ixgbe_msix_clean_rings
[250780.748093] ixgbe: ixgbe_msix_clean_rings
[250780.748091] ixgbe: ixgbe_msix_clean_rings
[250780.748091] ixgbe: ixgbe_msix_clean_rings
[250780.748090] ixgbe: ixgbe_msix_clean_rings
[250780.748092] ixgbe: ixgbe_msix_clean_rings
[250780.748098] ixgbe: ixgbe_msix_clean_rings
[250780.748099] ixgbe: ixgbe_msix_clean_rings
[250780.748116] ixgbe: ixgbe_msix_clean_rings
[250780.748116] ixgbe: ixgbe_msix_clean_rings
[250780.748118] ixgbe: ixgbe_msix_clean_rings
[250780.748118] ixgbe: ixgbe_msix_clean_rings
[250780.748120] ixgbe: ixgbe_msix_clean_rings
[250780.748119] ixgbe: ixgbe_msix_clean_rings
[250780.748122] ixgbe: ixgbe_msix_clean_rings
[250780.748122] ixgbe: ixgbe_msix_clean_rings
[250780.748123] ixgbe: ixgbe_msix_clean_rings
[250782.763868] ixgbe: ixgbe_service_timer
[250782.763886] ixgbe: ixgbe_service_event_schedule
[250782.763925] ixgbe: ixgbe_service_task
[250782.763930] ixgbe: ixgbe_check_fw_error
[250782.763932] ixgbe: ixgbe_reset_subtask
[250782.763933] ixgbe: ixgbe_phy_interrupt_subtask
[250782.763935] ixgbe: ixgbe_sfp_detection_subtask
[250782.763936] ixgbe: ixgbe_sfp_link_config_subtask
[250782.763937] ixgbe: ixgbe_check_overtemp_subtask
[250782.763938] ixgbe: ixgbe_watchdog_subtask
[250782.763939] ixgbe: ixgbe_watchdog_update_link
[250782.763940] ixgbe: ixgbe_watchdog_link_is_up
[250782.763941] ixgbe: ixgbe_check_for_bad_vf
[250782.763942] ixgbe: ixgbe_spoof_check
[250782.763944] ixgbe: ixgbe_update_stats
[250782.764005] ixgbe: ixgbe_update_xoff_received
[250782.764007] ixgbe: ixgbe_update_xoff_rx_lfc
[250782.764030] ixgbe: ixgbe_watchdog_flush_tx
[250782.764031] ixgbe: ixgbe_fdir_reinit_subtask
[250782.764033] ixgbe: ixgbe_check_hang_subtask
[250782.764034] ixgbe: ixgbe_irq_rearm_queues
[250782.764036] ixgbe: ixgbe_service_event_complete
[250782.764042] ixgbe: ixgbe_msix_clean_rings
[250782.764044] ixgbe: ixgbe_msix_clean_rings
[250782.764044] ixgbe: ixgbe_msix_clean_rings
[250782.764045] ixgbe: ixgbe_msix_clean_rings
[250782.764044] ixgbe: ixgbe_msix_clean_rings
[250782.764046] ixgbe: ixgbe_msix_clean_rings
[250782.764045] ixgbe: ixgbe_msix_clean_rings
[250782.764045] ixgbe: ixgbe_msix_clean_rings
[250782.764044] ixgbe: ixgbe_msix_clean_rings
[250782.764058] ixgbe: ixgbe_msix_clean_rings
[250782.764071] ixgbe: ixgbe_msix_clean_rings
[250782.764072] ixgbe: ixgbe_msix_clean_rings
[250782.764072] ixgbe: ixgbe_msix_clean_rings
[250782.764072] ixgbe: ixgbe_msix_clean_rings
[250782.764074] ixgbe: ixgbe_msix_clean_rings
[250782.764073] ixgbe: ixgbe_msix_clean_rings
[250782.764076] ixgbe: ixgbe_msix_clean_rings
[250782.764077] ixgbe: ixgbe_msix_clean_rings
```

### At this point, if we send a packet from node0 while the elevated ixgbe_poll is running, the packet doesn't seem to make it across even though it seems we are calling the correct functions

### After calling ixgbe_napi_enable again
```
[250792.701205]  **** han_napi_ENABLE ****
[250792.701210] ixgbe: ixgbe_napi_enable_all
[250792.701213] ixgbe: ixgbe_irq_enable
[250792.701215] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250792.843737] ixgbe: ixgbe_service_timer
[250792.843752] ixgbe: ixgbe_service_event_schedule
[250792.843768] ixgbe: ixgbe_service_task
[250792.843770] ixgbe: ixgbe_check_fw_error
[250792.843772] ixgbe: ixgbe_reset_subtask
[250792.843772] ixgbe: ixgbe_phy_interrupt_subtask
[250792.843774] ixgbe: ixgbe_sfp_detection_subtask
[250792.843775] ixgbe: ixgbe_sfp_link_config_subtask
[250792.843775] ixgbe: ixgbe_check_overtemp_subtask
[250792.843776] ixgbe: ixgbe_watchdog_subtask
[250792.843777] ixgbe: ixgbe_watchdog_update_link
[250792.843778] ixgbe: ixgbe_watchdog_link_is_up
[250792.843779] ixgbe: ixgbe_check_for_bad_vf
[250792.843781] ixgbe: ixgbe_spoof_check
[250792.843782] ixgbe: ixgbe_update_stats
[250792.843842] ixgbe: ixgbe_update_xoff_received
[250792.843844] ixgbe: ixgbe_update_xoff_rx_lfc
[250792.843867] ixgbe: ixgbe_watchdog_flush_tx
[250792.843869] ixgbe: ixgbe_fdir_reinit_subtask
[250792.843870] ixgbe: ixgbe_check_hang_subtask
[250792.843871] ixgbe: ixgbe_irq_rearm_queues
[250792.843873] ixgbe: ixgbe_service_event_complete
[250792.843880] ixgbe: ixgbe_msix_clean_rings
[250792.843881] ixgbe: ixgbe_msix_clean_rings
[250792.843882] ixgbe: ixgbe_msix_clean_rings
[250792.843883] ixgbe: ixgbe_msix_clean_rings
[250792.843889] ixgbe: ixgbe_poll v_idx=9 budget=64
[250792.843889] ixgbe: ixgbe_poll v_idx=5 budget=64
[250792.843890] ixgbe: ixgbe_poll v_idx=0 budget=64
[250792.843894] ixgbe: ixgbe_poll v_idx=11 budget=64
[250792.843898] ixgbe: ixgbe_get_rx_buffer
[250792.843898] ixgbe: ixgbe_poll v_idx=5 budget=64
[250792.843899] ixgbe: ixgbe_poll v_idx=9 budget=64
[250792.843900] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250792.843901] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250792.843902] ixgbe: ixgbe_run_xdp
[250792.843904] ixgbe: ixgbe_build_skb
[250792.843906] ixgbe: ixgbe_put_rx_buffer
[250792.843907] ixgbe: ixgbe_can_reuse_rx_page
[250792.843907] ixgbe: ixgbe_poll v_idx=11 budget=64
[250792.843907] ixgbe: ixgbe_msix_clean_rings
[250792.843908] ixgbe: ixgbe_msix_clean_rings
[250792.843908] ixgbe: ixgbe_msix_clean_rings
[250792.843909] ixgbe: ixgbe_msix_clean_rings
[250792.843912] ixgbe: ixgbe_msix_clean_rings
[250792.843910] ixgbe: ixgbe_msix_clean_rings
[250792.843911] ixgbe: ixgbe_msix_clean_rings
[250792.843909] ixgbe: ixgbe_reuse_rx_page
[250792.843914] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250792.843909] ixgbe: ixgbe_msix_clean_rings
[250792.843912] ixgbe: ixgbe_msix_clean_rings
[250792.843916] ixgbe: ixgbe_msix_clean_rings
[250792.843910] ixgbe: ixgbe_msix_clean_rings
[250792.843913] ixgbe: ixgbe_msix_clean_rings
[250792.843912] ixgbe: ixgbe_msix_clean_rings
[250792.843913] ixgbe: ixgbe_msix_clean_rings
[250792.843921] ixgbe: ixgbe_poll v_idx=10 budget=64
[250792.843914] ixgbe: ixgbe_msix_clean_rings
[250792.843933] ixgbe: ixgbe_poll v_idx=4 budget=64
[250792.843931] ixgbe: ixgbe_poll v_idx=7 budget=64
[250792.843939] ixgbe: ixgbe_poll v_idx=3 budget=64
[250792.843930] ixgbe: ixgbe_poll v_idx=1 budget=64
[250792.843944] ixgbe: ixgbe_poll v_idx=6 budget=64
[250792.843946] ixgbe: ixgbe_poll v_idx=16 budget=64
[250792.843920] ixgbe: ixgbe_is_non_eop
[250792.843916] ixgbe: ixgbe_msix_clean_rings
[250792.843954] ixgbe: ixgbe_poll v_idx=14 budget=64
[250792.843953] ixgbe: ixgbe_poll v_idx=15 budget=64
[250792.843962] ixgbe: ixgbe_cleanup_headers
[250792.843959] ixgbe: ixgbe_poll v_idx=3 budget=64
[250792.843962] ixgbe: ixgbe_poll v_idx=16 budget=64
[250792.843949] ixgbe: ixgbe_poll v_idx=13 budget=64
[250792.843964] ixgbe: ixgbe_poll v_idx=7 budget=64
[250792.843936] ixgbe: ixgbe_poll v_idx=12 budget=64
[250792.843975] ixgbe: ixgbe_poll v_idx=14 budget=64
[250792.843978] ixgbe: ixgbe_poll v_idx=19 budget=64
[250792.843981] ixgbe: ixgbe_poll v_idx=6 budget=64
[250792.843976] ixgbe: ixgbe_poll v_idx=2 budget=64
[250792.843988] ixgbe: ixgbe_poll v_idx=4 budget=64
[250792.843993] ixgbe: ixgbe_poll v_idx=15 budget=64
[250792.843990] ixgbe: ixgbe_features_check
[250792.843997] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250792.843992] ixgbe: ixgbe_poll v_idx=8 budget=64
[250792.843999] ixgbe: ixgbe_poll v_idx=12 budget=64
[250792.844002] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250792.844010] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250792.844009] ixgbe: ixgbe_poll v_idx=18 budget=64
[250792.844022] ixgbe: ixgbe_xmit_frame
[250792.844021] ixgbe: ixgbe_poll v_idx=13 budget=64
[250792.844015] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250792.844025] ixgbe: ixgbe_poll v_idx=17 budget=64
[250792.844027] ixgbe: ixgbe_process_skb_fields
[250792.844037] ixgbe: __ixgbe_xmit_frame
[250792.844039] ixgbe: ixgbe_poll v_idx=18 budget=64
[250792.844029] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250792.844031] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250792.844046] ixgbe: ixgbe_update_rsc_stats
[250792.844046] ixgbe: ixgbe_poll v_idx=17 budget=64
[250792.844055] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250792.844042] ixgbe: ixgbe_poll v_idx=19 budget=64
[250792.844051] ixgbe: ixgbe_poll v_idx=8 budget=64
[250792.844058] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250792.844061] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250792.844052] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250792.844065] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250792.844069] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250792.844075] ixgbe: ixgbe_poll v_idx=2 budget=64
[250792.844074] ixgbe: ixgbe_rx_hash
[250792.844074] ixgbe: ixgbe_xmit_frame_ring
[250792.844088] ixgbe: ixgbe_rx_checksum
[250792.844087] ixgbe: ixgbe_poll v_idx=10 budget=64
[250792.844091] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250792.844102] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250792.844106] ixgbe: ixgbe_maybe_stop_tx
[250792.844115] ixgbe: ixgbe_rx_skb
[250792.844113] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250792.844116] ixgbe: ixgbe_tso
[250792.844121] ixgbe: ixgbe_get_rx_buffer
[250792.844124] ixgbe: ixgbe_run_xdp
[250792.844125] ixgbe: ixgbe_tx_csum
[250792.844126] ixgbe: ixgbe_build_skb
[250792.844128] ixgbe: ixgbe_put_rx_buffer
[250792.844128] ixgbe: ixgbe_atr
[250792.844129] ixgbe: ixgbe_can_reuse_rx_page
[250792.844130] ixgbe: ixgbe_reuse_rx_page
[250792.844131] ixgbe: ixgbe_tx_cmd_type
[250792.844132] ixgbe: ixgbe_is_non_eop
[250792.844133] ixgbe: ixgbe_tx_map
[250792.844133] ixgbe: ixgbe_cleanup_headers
[250792.844135] ixgbe: ixgbe_process_skb_fields
[250792.844136] ixgbe: ixgbe_update_rsc_stats
[250792.844136] ixgbe: ixgbe_tx_olinfo_status
[250792.844137] ixgbe: ixgbe_rx_hash
[250792.844139] ixgbe: ixgbe_rx_checksum
[250792.844140] ixgbe: ixgbe_rx_skb
[250792.844140] ixgbe: ixgbe_maybe_stop_tx
[250792.844141] ixgbe: ixgbe_get_rx_buffer
[250792.844143] ixgbe: ixgbe_run_xdp
[250792.844143] ixgbe: ixgbe_build_skb
[250792.844145] ixgbe: ixgbe_put_rx_buffer
[250792.844146] ixgbe: ixgbe_can_reuse_rx_page
[250792.844147] ixgbe: ixgbe_reuse_rx_page
[250792.844147] ixgbe: ixgbe_is_non_eop
[250792.844148] ixgbe: ixgbe_cleanup_headers
[250792.844149] ixgbe: ixgbe_process_skb_fields
[250792.844150] ixgbe: ixgbe_update_rsc_stats
[250792.844151] ixgbe: ixgbe_rx_hash
[250792.844152] ixgbe: ixgbe_rx_checksum
[250792.844153] ixgbe: ixgbe_rx_skb
[250792.844153] ixgbe: ixgbe_get_rx_buffer
[250792.844154] ixgbe: ixgbe_run_xdp
[250792.844155] ixgbe: ixgbe_build_skb
[250792.844157] ixgbe: ixgbe_put_rx_buffer
[250792.844158] ixgbe: ixgbe_can_reuse_rx_page
[250792.844158] ixgbe: ixgbe_features_check
[250792.844159] ixgbe: ixgbe_reuse_rx_page
[250792.844160] ixgbe: ixgbe_is_non_eop
[250792.844161] ixgbe: ixgbe_cleanup_headers
[250792.844161] ixgbe: ixgbe_xmit_frame
[250792.844162] ixgbe: ixgbe_process_skb_fields
[250792.844164] ixgbe: ixgbe_update_rsc_stats
[250792.844164] ixgbe: __ixgbe_xmit_frame
[250792.844165] ixgbe: ixgbe_rx_hash
[250792.844166] ixgbe: ixgbe_rx_checksum
[250792.844167] ixgbe: ixgbe_xmit_frame_ring
[250792.844167] ixgbe: ixgbe_rx_skb
[250792.844169] ixgbe: ixgbe_get_rx_buffer
[250792.844169] ixgbe: ixgbe_maybe_stop_tx
[250792.844170] ixgbe: ixgbe_run_xdp
[250792.844171] ixgbe: ixgbe_build_skb
[250792.844172] ixgbe: ixgbe_tso
[250792.844173] ixgbe: ixgbe_put_rx_buffer
[250792.844174] ixgbe: ixgbe_can_reuse_rx_page
[250792.844174] ixgbe: ixgbe_tx_csum
[250792.844175] ixgbe: ixgbe_reuse_rx_page
[250792.844177] ixgbe: ixgbe_is_non_eop
[250792.844177] ixgbe: ixgbe_atr
[250792.844178] ixgbe: ixgbe_cleanup_headers
[250792.844179] ixgbe: ixgbe_process_skb_fields
[250792.844180] ixgbe: ixgbe_tx_cmd_type
[250792.844181] ixgbe: ixgbe_update_rsc_stats
[250792.844182] ixgbe: ixgbe_rx_hash
[250792.844183] ixgbe: ixgbe_tx_map
[250792.844183] ixgbe: ixgbe_rx_checksum
[250792.844185] ixgbe: ixgbe_rx_skb
[250792.844185] ixgbe: ixgbe_tx_olinfo_status
[250792.844186] ixgbe: ixgbe_get_rx_buffer
[250792.844187] ixgbe: ixgbe_run_xdp
[250792.844188] ixgbe: ixgbe_maybe_stop_tx
[250792.844189] ixgbe: ixgbe_build_skb
[250792.844191] ixgbe: ixgbe_put_rx_buffer
[250792.844192] ixgbe: ixgbe_can_reuse_rx_page
[250792.844192] ixgbe: ixgbe_reuse_rx_page
[250792.844192] ixgbe: ixgbe_poll v_idx=1 budget=64
[250792.844194] ixgbe: ixgbe_is_non_eop
[250792.844195] ixgbe: ixgbe_cleanup_headers
[250792.844196] ixgbe: ixgbe_process_skb_fields
[250792.844197] ixgbe: ixgbe_update_rsc_stats
[250792.844198] ixgbe: ixgbe_rx_hash
[250792.844198] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250792.844199] ixgbe: ixgbe_rx_checksum
[250792.844201] ixgbe: ixgbe_rx_skb
[250792.844207] ixgbe: ixgbe_msix_clean_rings
[250792.844210] ixgbe: ixgbe_poll v_idx=1 budget=64
[250792.844211] ixgbe: ixgbe_features_check
[250792.844213] ixgbe: ixgbe_xmit_frame
[250792.844214] ixgbe: ixgbe_write_eitr
[250792.844215] ixgbe: __ixgbe_xmit_frame
[250792.844216] ixgbe: ixgbe_xmit_frame_ring
[250792.844216] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250792.844217] ixgbe: ixgbe_maybe_stop_tx
[250792.844219] ixgbe: ixgbe_tso
[250792.844220] ixgbe: ixgbe_tx_csum
[250792.844220] ixgbe: ixgbe_atr
[250792.844221] ixgbe: ixgbe_tx_cmd_type
[250792.844222] ixgbe: ixgbe_tx_map
[250792.844223] ixgbe: ixgbe_tx_olinfo_status
[250792.844224] ixgbe: ixgbe_maybe_stop_tx
[250792.844228] ixgbe: ixgbe_features_check
[250792.844229] ixgbe: ixgbe_xmit_frame
[250792.844230] ixgbe: __ixgbe_xmit_frame
[250792.844231] ixgbe: ixgbe_xmit_frame_ring
[250792.844232] ixgbe: ixgbe_maybe_stop_tx
[250792.844233] ixgbe: ixgbe_tso
[250792.844233] ixgbe: ixgbe_tx_csum
[250792.844234] ixgbe: ixgbe_atr
[250792.844235] ixgbe: ixgbe_tx_cmd_type
[250792.844236] ixgbe: ixgbe_tx_map
[250792.844237] ixgbe: ixgbe_tx_olinfo_status
[250792.844238] ixgbe: ixgbe_maybe_stop_tx
[250792.844241] ixgbe: ixgbe_features_check
[250792.844248] ixgbe: ixgbe_poll v_idx=0 budget=64
[250792.844252] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250792.844253] ixgbe: ixgbe_xmit_frame
[250792.844254] ixgbe: __ixgbe_xmit_frame
[250792.844255] ixgbe: ixgbe_xmit_frame_ring
[250792.844255] ixgbe: ixgbe_maybe_stop_tx
[250792.844256] ixgbe: ixgbe_tso
[250792.844257] ixgbe: ixgbe_msix_clean_rings
[250792.844259] ixgbe: ixgbe_tx_csum
[250792.844260] ixgbe: ixgbe_atr
[250792.844261] ixgbe: ixgbe_tx_cmd_type
[250792.844262] ixgbe: ixgbe_tx_map
[250792.844262] ixgbe: ixgbe_tx_olinfo_status
[250792.844263] ixgbe: ixgbe_maybe_stop_tx
[250792.844265] ixgbe: ixgbe_features_check
[250792.844266] ixgbe: ixgbe_features_check
[250792.844267] ixgbe: ixgbe_xmit_frame
[250792.844268] ixgbe: __ixgbe_xmit_frame
[250792.844269] ixgbe: ixgbe_xmit_frame_ring
[250792.844270] ixgbe: ixgbe_maybe_stop_tx
[250792.844271] ixgbe: ixgbe_tso
[250792.844272] ixgbe: ixgbe_tx_csum
[250792.844272] ixgbe: ixgbe_atr
[250792.844273] ixgbe: ixgbe_tx_cmd_type
[250792.844274] ixgbe: ixgbe_tx_map
[250792.844275] ixgbe: ixgbe_tx_olinfo_status
[250792.844276] ixgbe: ixgbe_maybe_stop_tx
[250792.844277] ixgbe: ixgbe_xmit_frame
[250792.844278] ixgbe: __ixgbe_xmit_frame
[250792.844278] ixgbe: ixgbe_xmit_frame_ring
[250792.844279] ixgbe: ixgbe_maybe_stop_tx
[250792.844280] ixgbe: ixgbe_tso
[250792.844281] ixgbe: ixgbe_tx_csum
[250792.844282] ixgbe: ixgbe_atr
[250792.844283] ixgbe: ixgbe_tx_cmd_type
[250792.844284] ixgbe: ixgbe_tx_map
[250792.844284] ixgbe: ixgbe_tx_olinfo_status
[250792.844285] ixgbe: ixgbe_maybe_stop_tx
[250792.844286] ixgbe: ixgbe_features_check
[250792.844287] ixgbe: ixgbe_xmit_frame
[250792.844288] ixgbe: __ixgbe_xmit_frame
[250792.844289] ixgbe: ixgbe_xmit_frame_ring
[250792.844290] ixgbe: ixgbe_maybe_stop_tx
[250792.844291] ixgbe: ixgbe_tso
[250792.844292] ixgbe: ixgbe_tx_csum
[250792.844293] ixgbe: ixgbe_atr
[250792.844293] ixgbe: ixgbe_tx_cmd_type
[250792.844294] ixgbe: ixgbe_tx_map
[250792.844295] ixgbe: ixgbe_tx_olinfo_status
[250792.844296] ixgbe: ixgbe_maybe_stop_tx
[250792.844297] ixgbe: ixgbe_poll v_idx=0 budget=64
[250792.844299] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250792.844304] ixgbe: ixgbe_msix_clean_rings
[250792.844306] ixgbe: ixgbe_poll v_idx=0 budget=64
[250792.844307] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250794.859699] ixgbe: ixgbe_service_timer
[250794.859715] ixgbe: ixgbe_service_event_schedule
[250794.859734] ixgbe: ixgbe_service_task
[250794.859736] ixgbe: ixgbe_check_fw_error
[250794.859738] ixgbe: ixgbe_reset_subtask
[250794.859739] ixgbe: ixgbe_phy_interrupt_subtask
[250794.859740] ixgbe: ixgbe_sfp_detection_subtask
[250794.859741] ixgbe: ixgbe_sfp_link_config_subtask
[250794.859742] ixgbe: ixgbe_check_overtemp_subtask
[250794.859743] ixgbe: ixgbe_watchdog_subtask
[250794.859744] ixgbe: ixgbe_watchdog_update_link
[250794.859745] ixgbe: ixgbe_watchdog_link_is_up
[250794.859746] ixgbe: ixgbe_check_for_bad_vf
[250794.859748] ixgbe: ixgbe_spoof_check
[250794.859749] ixgbe: ixgbe_update_stats
[250794.859809] ixgbe: ixgbe_update_xoff_received
[250794.859811] ixgbe: ixgbe_update_xoff_rx_lfc
[250794.859834] ixgbe: ixgbe_watchdog_flush_tx
[250794.859835] ixgbe: ixgbe_fdir_reinit_subtask
[250794.859836] ixgbe: ixgbe_check_hang_subtask
[250794.859839] ixgbe: ixgbe_irq_rearm_queues
[250794.859840] ixgbe: ixgbe_service_event_complete
[250794.859848] ixgbe: ixgbe_msix_clean_rings
[250794.859847] ixgbe: ixgbe_msix_clean_rings
[250794.859848] ixgbe: ixgbe_msix_clean_rings
[250794.859850] ixgbe: ixgbe_msix_clean_rings
[250794.859854] ixgbe: ixgbe_poll v_idx=5 budget=64
[250794.859856] ixgbe: ixgbe_poll v_idx=9 budget=64
[250794.859857] ixgbe: ixgbe_poll v_idx=0 budget=64
[250794.859859] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250794.859860] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250794.859862] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250794.859862] ixgbe: ixgbe_poll v_idx=11 budget=64
[250794.859869] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250794.859874] ixgbe: ixgbe_msix_clean_rings
[250794.859875] ixgbe: ixgbe_msix_clean_rings
[250794.859876] ixgbe: ixgbe_msix_clean_rings
[250794.859877] ixgbe: ixgbe_msix_clean_rings
[250794.859877] ixgbe: ixgbe_msix_clean_rings
[250794.859877] ixgbe: ixgbe_msix_clean_rings
[250794.859878] ixgbe: ixgbe_msix_clean_rings
[250794.859878] ixgbe: ixgbe_msix_clean_rings
[250794.859880] ixgbe: ixgbe_msix_clean_rings
[250794.859879] ixgbe: ixgbe_msix_clean_rings
[250794.859881] ixgbe: ixgbe_msix_clean_rings
[250794.859882] ixgbe: ixgbe_msix_clean_rings
[250794.859882] ixgbe: ixgbe_msix_clean_rings
[250794.859889] ixgbe: ixgbe_poll v_idx=14 budget=64
[250794.859884] ixgbe: ixgbe_poll v_idx=12 budget=64
[250794.859886] ixgbe: ixgbe_poll v_idx=10 budget=64
[250794.859882] ixgbe: ixgbe_msix_clean_rings
[250794.859882] ixgbe: ixgbe_msix_clean_rings
[250794.859894] ixgbe: ixgbe_poll v_idx=13 budget=64
[250794.859880] ixgbe: ixgbe_msix_clean_rings
[250794.859897] ixgbe: ixgbe_poll v_idx=15 budget=64
[250794.859905] ixgbe: ixgbe_poll v_idx=4 budget=64
[250794.859904] ixgbe: ixgbe_poll v_idx=3 budget=64
[250794.859914] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250794.859906] ixgbe: ixgbe_poll v_idx=16 budget=64
[250794.859912] ixgbe: ixgbe_poll v_idx=1 budget=64
[250794.859915] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250794.859919] ixgbe: ixgbe_poll v_idx=19 budget=64
[250794.859921] ixgbe: ixgbe_poll v_idx=8 budget=64
[250794.859920] ixgbe: ixgbe_poll v_idx=18 budget=64
[250794.859931] ixgbe: ixgbe_write_eitr
[250794.859929] ixgbe: ixgbe_poll v_idx=6 budget=64
[250794.859937] ixgbe: ixgbe_poll v_idx=7 budget=64
[250794.859944] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250794.859944] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250794.859940] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250794.859952] ixgbe: ixgbe_poll v_idx=17 budget=64
[250794.859957] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250794.859948] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250794.859960] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250794.859958] ixgbe: ixgbe_poll v_idx=2 budget=64
[250794.859965] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250794.859968] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250794.859964] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250794.859971] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250794.859977] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250794.859980] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250794.859976] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250794.860005] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250796.875680] ixgbe: ixgbe_service_timer
[250796.875694] ixgbe: ixgbe_service_event_schedule
[250796.875716] ixgbe: ixgbe_service_task
[250796.875718] ixgbe: ixgbe_check_fw_error
[250796.875720] ixgbe: ixgbe_reset_subtask
[250796.875721] ixgbe: ixgbe_phy_interrupt_subtask
[250796.875722] ixgbe: ixgbe_sfp_detection_subtask
[250796.875723] ixgbe: ixgbe_sfp_link_config_subtask
[250796.875724] ixgbe: ixgbe_check_overtemp_subtask
[250796.875725] ixgbe: ixgbe_watchdog_subtask
[250796.875726] ixgbe: ixgbe_watchdog_update_link
[250796.875727] ixgbe: ixgbe_watchdog_link_is_up
[250796.875728] ixgbe: ixgbe_check_for_bad_vf
[250796.875730] ixgbe: ixgbe_spoof_check
[250796.875731] ixgbe: ixgbe_update_stats
[250796.875791] ixgbe: ixgbe_update_xoff_received
[250796.875793] ixgbe: ixgbe_update_xoff_rx_lfc
[250796.875817] ixgbe: ixgbe_watchdog_flush_tx
[250796.875818] ixgbe: ixgbe_fdir_reinit_subtask
[250796.875819] ixgbe: ixgbe_check_hang_subtask
[250796.875822] ixgbe: ixgbe_irq_rearm_queues
[250796.875823] ixgbe: ixgbe_service_event_complete
[250796.875830] ixgbe: ixgbe_msix_clean_rings
[250796.875831] ixgbe: ixgbe_msix_clean_rings
[250796.875832] ixgbe: ixgbe_msix_clean_rings
[250796.875833] ixgbe: ixgbe_msix_clean_rings
[250796.875839] ixgbe: ixgbe_poll v_idx=5 budget=64
[250796.875839] ixgbe: ixgbe_poll v_idx=0 budget=64
[250796.875841] ixgbe: ixgbe_poll v_idx=9 budget=64
[250796.875843] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250796.875844] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250796.875845] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250796.875843] ixgbe: ixgbe_poll v_idx=11 budget=64
[250796.875853] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250796.875857] ixgbe: ixgbe_msix_clean_rings
[250796.875857] ixgbe: ixgbe_msix_clean_rings
[250796.875858] ixgbe: ixgbe_msix_clean_rings
[250796.875860] ixgbe: ixgbe_msix_clean_rings
[250796.875860] ixgbe: ixgbe_msix_clean_rings
[250796.875861] ixgbe: ixgbe_msix_clean_rings
[250796.875859] ixgbe: ixgbe_msix_clean_rings
[250796.875858] ixgbe: ixgbe_msix_clean_rings
[250796.875865] ixgbe: ixgbe_msix_clean_rings
[250796.875862] ixgbe: ixgbe_msix_clean_rings
[250796.875862] ixgbe: ixgbe_msix_clean_rings
[250796.875863] ixgbe: ixgbe_msix_clean_rings
[250796.875863] ixgbe: ixgbe_msix_clean_rings
[250796.875864] ixgbe: ixgbe_msix_clean_rings
[250796.875859] ixgbe: ixgbe_msix_clean_rings
[250796.875874] ixgbe: ixgbe_poll v_idx=2 budget=64
[250796.875872] ixgbe: ixgbe_poll v_idx=4 budget=64
[250796.875861] ixgbe: ixgbe_msix_clean_rings
[250796.875882] ixgbe: ixgbe_poll v_idx=6 budget=64
[250796.875870] ixgbe: ixgbe_poll v_idx=1 budget=64
[250796.875887] ixgbe: ixgbe_poll v_idx=7 budget=64
[250796.875889] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250796.875889] ixgbe: ixgbe_poll v_idx=3 budget=64
[250796.875891] ixgbe: ixgbe_poll v_idx=8 budget=64
[250796.875891] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250796.875884] ixgbe: ixgbe_poll v_idx=10 budget=64
[250796.875901] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250796.875900] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250796.875898] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250796.875913] ixgbe: ixgbe_poll v_idx=14 budget=64
[250796.875912] ixgbe: ixgbe_poll v_idx=13 budget=64
[250796.875917] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250796.875916] ixgbe: ixgbe_poll v_idx=15 budget=64
[250796.875924] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250796.875929] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250796.875930] ixgbe: ixgbe_poll v_idx=18 budget=64
[250796.875923] ixgbe: ixgbe_poll v_idx=12 budget=64
[250796.875953] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250796.875955] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250796.875955] ixgbe: ixgbe_poll v_idx=17 budget=64
[250796.875957] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250796.875957] ixgbe: ixgbe_poll v_idx=16 budget=64
[250796.875958] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250796.875958] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250796.875960] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250796.875962] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250796.875966] ixgbe: ixgbe_poll v_idx=19 budget=64
[250796.875971] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250797.931650] ixgbe: ixgbe_features_check
[250797.931656] ixgbe: ixgbe_features_check
[250797.931664] ixgbe: ixgbe_xmit_frame
[250797.931665] ixgbe: ixgbe_xmit_frame
[250797.931668] ixgbe: __ixgbe_xmit_frame
[250797.931668] ixgbe: __ixgbe_xmit_frame
[250797.931671] ixgbe: ixgbe_xmit_frame_ring
[250797.931671] ixgbe: ixgbe_xmit_frame_ring
[250797.931674] ixgbe: ixgbe_maybe_stop_tx
[250797.931674] ixgbe: ixgbe_maybe_stop_tx
[250797.931677] ixgbe: ixgbe_tso
[250797.931677] ixgbe: ixgbe_tso
[250797.931679] ixgbe: ixgbe_tx_csum
[250797.931680] ixgbe: ixgbe_tx_csum
[250797.931681] ixgbe: ixgbe_atr
[250797.931682] ixgbe: ixgbe_atr
[250797.931684] ixgbe: ixgbe_tx_cmd_type
[250797.931685] ixgbe: ixgbe_tx_cmd_type
[250797.931687] ixgbe: ixgbe_tx_map
[250797.931687] ixgbe: ixgbe_tx_map
[250797.931689] ixgbe: ixgbe_tx_olinfo_status
[250797.931689] ixgbe: ixgbe_tx_olinfo_status
[250797.931692] ixgbe: ixgbe_maybe_stop_tx
[250797.931693] ixgbe: ixgbe_maybe_stop_tx
[250797.931702] ixgbe: ixgbe_msix_clean_rings
[250797.931703] ixgbe: ixgbe_msix_clean_rings
[250797.931717] ixgbe: ixgbe_poll v_idx=7 budget=64
[250797.931724] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250797.931723] ixgbe: ixgbe_poll v_idx=0 budget=64
[250797.931728] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250797.931816] ixgbe: ixgbe_msix_clean_rings
[250797.931820] ixgbe: ixgbe_poll v_idx=0 budget=64
[250797.931822] ixgbe: ixgbe_get_rx_buffer
[250797.931823] ixgbe: ixgbe_run_xdp
[250797.931824] ixgbe: ixgbe_build_skb
[250797.931826] ixgbe: ixgbe_put_rx_buffer
[250797.931827] ixgbe: ixgbe_can_reuse_rx_page
[250797.931828] ixgbe: ixgbe_reuse_rx_page
[250797.931829] ixgbe: ixgbe_is_non_eop
[250797.931830] ixgbe: ixgbe_cleanup_headers
[250797.931830] ixgbe: ixgbe_process_skb_fields
[250797.931831] ixgbe: ixgbe_update_rsc_stats
[250797.931832] ixgbe: ixgbe_rx_hash
[250797.931833] ixgbe: ixgbe_rx_checksum
[250797.931834] ixgbe: ixgbe_rx_skb
[250797.931844] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250798.891665] ixgbe: ixgbe_service_timer
[250798.891678] ixgbe: ixgbe_service_event_schedule
[250798.891701] ixgbe: ixgbe_service_task
[250798.891702] ixgbe: ixgbe_check_fw_error
[250798.891704] ixgbe: ixgbe_reset_subtask
[250798.891706] ixgbe: ixgbe_phy_interrupt_subtask
[250798.891707] ixgbe: ixgbe_sfp_detection_subtask
[250798.891708] ixgbe: ixgbe_sfp_link_config_subtask
[250798.891709] ixgbe: ixgbe_check_overtemp_subtask
[250798.891710] ixgbe: ixgbe_watchdog_subtask
[250798.891711] ixgbe: ixgbe_watchdog_update_link
[250798.891712] ixgbe: ixgbe_watchdog_link_is_up
[250798.891713] ixgbe: ixgbe_check_for_bad_vf
[250798.891714] ixgbe: ixgbe_spoof_check
[250798.891715] ixgbe: ixgbe_update_stats
[250798.891775] ixgbe: ixgbe_update_xoff_received
[250798.891777] ixgbe: ixgbe_update_xoff_rx_lfc
[250798.891800] ixgbe: ixgbe_watchdog_flush_tx
[250798.891801] ixgbe: ixgbe_fdir_reinit_subtask
[250798.891802] ixgbe: ixgbe_check_hang_subtask
[250798.891804] ixgbe: ixgbe_irq_rearm_queues
[250798.891805] ixgbe: ixgbe_service_event_complete
[250798.891813] ixgbe: ixgbe_msix_clean_rings
[250798.891814] ixgbe: ixgbe_msix_clean_rings
[250798.891814] ixgbe: ixgbe_msix_clean_rings
[250798.891815] ixgbe: ixgbe_msix_clean_rings
[250798.891821] ixgbe: ixgbe_poll v_idx=9 budget=64
[250798.891822] ixgbe: ixgbe_poll v_idx=5 budget=64
[250798.891823] ixgbe: ixgbe_poll v_idx=1 budget=64
[250798.891823] ixgbe: ixgbe_poll v_idx=11 budget=64
[250798.891826] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250798.891828] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250798.891831] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250798.891831] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250798.891841] ixgbe: ixgbe_msix_clean_rings
[250798.891842] ixgbe: ixgbe_msix_clean_rings
[250798.891843] ixgbe: ixgbe_msix_clean_rings
[250798.891844] ixgbe: ixgbe_msix_clean_rings
[250798.891843] ixgbe: ixgbe_msix_clean_rings
[250798.891844] ixgbe: ixgbe_msix_clean_rings
[250798.891845] ixgbe: ixgbe_msix_clean_rings
[250798.891842] ixgbe: ixgbe_msix_clean_rings
[250798.891844] ixgbe: ixgbe_msix_clean_rings
[250798.891846] ixgbe: ixgbe_msix_clean_rings
[250798.891848] ixgbe: ixgbe_msix_clean_rings
[250798.891853] ixgbe: ixgbe_poll v_idx=0 budget=64
[250798.891847] ixgbe: ixgbe_msix_clean_rings
[250798.891848] ixgbe: ixgbe_msix_clean_rings
[250798.891847] ixgbe: ixgbe_msix_clean_rings
[250798.891858] ixgbe: ixgbe_poll v_idx=4 budget=64
[250798.891846] ixgbe: ixgbe_msix_clean_rings
[250798.891849] ixgbe: ixgbe_msix_clean_rings
[250798.891866] ixgbe: ixgbe_poll v_idx=3 budget=64
[250798.891865] ixgbe: ixgbe_poll v_idx=10 budget=64
[250798.891871] ixgbe: ixgbe_poll v_idx=2 budget=64
[250798.891873] ixgbe: ixgbe_poll v_idx=15 budget=64
[250798.891866] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250798.891875] ixgbe: ixgbe_poll v_idx=7 budget=64
[250798.891877] ixgbe: ixgbe_poll v_idx=14 budget=64
[250798.891882] ixgbe: ixgbe_poll v_idx=12 budget=64
[250798.891887] ixgbe: ixgbe_poll v_idx=6 budget=64
[250798.891892] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250798.891892] ixgbe: ixgbe_poll v_idx=8 budget=64
[250798.891895] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250798.891900] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250798.891900] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250798.891908] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250798.891914] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250798.891914] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250798.891918] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250798.891919] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250798.891906] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250798.891933] ixgbe: ixgbe_poll v_idx=16 budget=64
[250798.891935] ixgbe: ixgbe_poll v_idx=18 budget=64
[250798.891930] ixgbe: ixgbe_poll v_idx=19 budget=64
[250798.891939] ixgbe: ixgbe_poll v_idx=17 budget=64
[250798.891949] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250798.891949] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250798.891950] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250798.891952] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues
[250798.891954] ixgbe: ixgbe_poll v_idx=13 budget=64
[250798.891960] ixgbe:  ixgbe_poll -> ixgbe_irq_enable_queues


```