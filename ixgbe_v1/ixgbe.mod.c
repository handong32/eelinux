#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

MODULE_INFO(intree, "Y");

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x99c41e59, "module_layout" },
	{ 0xb9681621, "xdp_do_flush" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x60443957, "mdio45_probe" },
	{ 0xf3198317, "netdev_info" },
	{ 0xf9af596, "kmalloc_caches" },
	{ 0xeb233a45, "__kmalloc" },
	{ 0xe404f30c, "xsk_tx_release" },
	{ 0x174a1916, "ethtool_op_get_ts_info" },
	{ 0xc4f0da12, "ktime_get_with_offset" },
	{ 0xf9a482f9, "msleep" },
	{ 0x862258db, "timecounter_init" },
	{ 0x356560bc, "dcb_ieee_setapp" },
	{ 0x1ed8b599, "__x86_indirect_thunk_r8" },
	{ 0xe222a566, "skb_clone_tx_timestamp" },
	{ 0xb796b038, "pci_enable_sriov" },
	{ 0x619cb7dd, "simple_read_from_buffer" },
	{ 0x6ec20ae, "pci_write_config_word" },
	{ 0x1eb04ee1, "debugfs_create_dir" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0xa44b3fda, "param_ops_int" },
	{ 0x461dff08, "dcb_ieee_delapp" },
	{ 0x5d707a1b, "napi_disable" },
	{ 0x754d539c, "strlen" },
	{ 0x11724dcb, "pci_sriov_set_totalvfs" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x6b04e507, "napi_consume_skb" },
	{ 0xf000e26c, "__napi_schedule_irqoff" },
	{ 0x53e71ea1, "napi_schedule_prep" },
	{ 0x56809fce, "dma_set_mask" },
	{ 0xc5c2f59, "dev_uc_add" },
	{ 0x7257cf6b, "xdp_rxq_info_reg" },
	{ 0x1f79754f, "xp_free" },
	{ 0xd948bf5a, "pci_disable_device" },
	{ 0xc7a4fbed, "rtnl_lock" },
	{ 0xc1c8e33c, "pci_disable_msix" },
	{ 0x5450a500, "__mdiobus_register" },
	{ 0x6f8f674a, "bpf_dispatcher_xdp_func" },
	{ 0x4ea25709, "dql_reset" },
	{ 0x3acb5457, "netdev_set_num_tc" },
	{ 0x330fb81b, "netif_carrier_on" },
	{ 0xfa8396ff, "pci_disable_sriov" },
	{ 0x279c4700, "__hw_addr_sync_dev" },
	{ 0xdf566a59, "__x86_indirect_thunk_r9" },
	{ 0xda3db3bd, "netif_carrier_off" },
	{ 0x56470118, "__warn_printk" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0xb43f9365, "ktime_get" },
	{ 0xd9f4820c, "pci_dev_get" },
	{ 0xf088c8bf, "mdiobus_write" },
	{ 0xc29957c3, "__x86_indirect_thunk_rcx" },
	{ 0xdaceb7a6, "mdio_mii_ioctl" },
	{ 0x3eaf44f2, "xdp_rxq_info_unreg" },
	{ 0x7ff7b6d3, "xp_set_rxq_info" },
	{ 0xca59f5ad, "pcie_print_link_status" },
	{ 0xffd41ca, "driver_for_each_device" },
	{ 0x4f5101d6, "__dev_kfree_skb_any" },
	{ 0xeae3dfd6, "__const_udelay" },
	{ 0xdc8d3228, "__x86_indirect_alt_call_r9" },
	{ 0xc6f46339, "init_timer_key" },
	{ 0x2d5f69b3, "rcu_read_unlock_strict" },
	{ 0x999e8297, "vfree" },
	{ 0x4e850f7, "dma_free_attrs" },
	{ 0xae8d4d41, "netdev_reset_tc" },
	{ 0xbaf22757, "kvfree_call_rcu" },
	{ 0x9d2db284, "xsk_set_tx_need_wakeup" },
	{ 0xddd3b15e, "debugfs_create_file" },
	{ 0x4629334c, "__preempt_count" },
	{ 0x7a2af7b4, "cpu_number" },
	{ 0xa648e561, "__ubsan_handle_shift_out_of_bounds" },
	{ 0x8868d75f, "netdev_bind_sb_channel_queue" },
	{ 0x97651e6c, "vmemmap_base" },
	{ 0x922f45a6, "__bitmap_clear" },
	{ 0xb4f1f675, "ipv6_find_hdr" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xef756149, "mdiobus_unregister" },
	{ 0x739e22dd, "__page_frag_cache_drain" },
	{ 0x29c85bd2, "pv_ops" },
	{ 0x642b9331, "netdev_walk_all_upper_dev_rcu" },
	{ 0xd432385a, "dma_set_coherent_mask" },
	{ 0xfd0b060a, "netdev_unbind_sb_channel" },
	{ 0x15ba50a6, "jiffies" },
	{ 0xbe744112, "__dynamic_netdev_dbg" },
	{ 0x2e373757, "devm_mdiobus_alloc_size" },
	{ 0xfb384d37, "kasprintf" },
	{ 0xfe50fc3a, "xp_dma_unmap" },
	{ 0x323fafc6, "ptp_clock_unregister" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x67463775, "netdev_set_tc_queue" },
	{ 0x17de3d5, "nr_cpu_ids" },
	{ 0x882cd3fd, "pci_set_master" },
	{ 0xea365dfa, "dca3_get_tag" },
	{ 0xe265ec03, "__alloc_pages" },
	{ 0x4f63d0cc, "netif_schedule_queue" },
	{ 0x20fc068f, "ptp_clock_event" },
	{ 0x2688ec10, "bitmap_zalloc" },
	{ 0x97934ecf, "del_timer_sync" },
	{ 0x7e526bfa, "__x86_indirect_thunk_r10" },
	{ 0x26faca8d, "_dev_warn" },
	{ 0xfb578fc5, "memset" },
	{ 0x5338184f, "ethtool_sprintf" },
	{ 0x1f5a716f, "devm_hwmon_device_register_with_groups" },
	{ 0x5cc3e1ce, "dcb_getapp" },
	{ 0xb30dfd4e, "pci_enable_pcie_error_reporting" },
	{ 0x9a7765d0, "dma_sync_single_for_cpu" },
	{ 0xac34ecec, "dca_register_notify" },
	{ 0x1e1e140e, "ns_to_timespec64" },
	{ 0x576f3cf2, "netdev_set_sb_channel" },
	{ 0xab29af88, "netif_tx_wake_queue" },
	{ 0x4c198da9, "pci_restore_state" },
	{ 0x85f8ff34, "netif_tx_stop_all_queues" },
	{ 0x1a33ab9, "dca_unregister_notify" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x1f9fcf51, "dev_addr_del" },
	{ 0x84678725, "__SCK__tp_func_xdp_exception" },
	{ 0x6da2604d, "netif_set_xps_queue" },
	{ 0x6ad68f24, "eth_platform_get_mac_address" },
	{ 0xc5850110, "printk" },
	{ 0xaae6260f, "ethtool_op_get_link" },
	{ 0xbcab6ee6, "sscanf" },
	{ 0x3c3fce39, "__local_bh_enable_ip" },
	{ 0x449ad0a7, "memcmp" },
	{ 0x5a5a2271, "__cpu_online_mask" },
	{ 0xa50a3da7, "_find_next_bit" },
	{ 0x9ec6ca96, "ktime_get_real_ts64" },
	{ 0xde80cd09, "ioremap" },
	{ 0xa00aca2a, "dql_completed" },
	{ 0x4c9d28b0, "phys_base" },
	{ 0xcd279169, "nla_find" },
	{ 0xd61eeee, "__bitmap_subset" },
	{ 0x1ce47862, "xsk_get_pool_from_qid" },
	{ 0x3790b248, "free_netdev" },
	{ 0xe7b00dfb, "__x86_indirect_thunk_r13" },
	{ 0x5debe3fe, "mdiobus_read" },
	{ 0xc6c70552, "register_netdev" },
	{ 0x3c215a75, "xsk_uses_need_wakeup" },
	{ 0x6fc11aae, "xsk_clear_rx_need_wakeup" },
	{ 0x5a921311, "strncmp" },
	{ 0x73ac1bbb, "napi_enable" },
	{ 0x7d0d7325, "pcie_flr" },
	{ 0x8f72e7c1, "pci_read_config_word" },
	{ 0xf43b707d, "debugfs_remove" },
	{ 0xccd6fd88, "dma_alloc_attrs" },
	{ 0x520eb68f, "pci_get_domain_bus_and_slot" },
	{ 0x8c03d20c, "destroy_workqueue" },
	{ 0x6eb77fd2, "netif_set_real_num_rx_queues" },
	{ 0xc38c83b8, "mod_timer" },
	{ 0x18b7924d, "netif_set_real_num_tx_queues" },
	{ 0xc245fce7, "netif_napi_add" },
	{ 0xce8b1878, "__x86_indirect_thunk_r14" },
	{ 0x7dbd520b, "xsk_tx_peek_desc" },
	{ 0x3097f49, "dcb_ieee_getapp_mask" },
	{ 0x7548d46b, "xp_dma_sync_for_cpu_slow" },
	{ 0x9cca9dde, "ptp_clock_register" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x3c944da6, "xdp_return_frame" },
	{ 0xd2d75d30, "dca_add_requester" },
	{ 0x6091797f, "synchronize_rcu" },
	{ 0x1fc70e11, "simple_open" },
	{ 0xa111cee5, "softnet_data" },
	{ 0xe7c319fc, "_dev_err" },
	{ 0xa33038e2, "pci_enable_msi" },
	{ 0xf84bd6ee, "bpf_stats_enabled_key" },
	{ 0xc8a91f5b, "cpumask_local_spread" },
	{ 0xe523ad75, "synchronize_irq" },
	{ 0x6f9e763b, "timecounter_read" },
	{ 0xfe37f65b, "build_skb" },
	{ 0x800473f, "__cond_resched" },
	{ 0x6b7c9536, "flow_block_cb_setup_simple" },
	{ 0x6be71d9d, "device_wakeup_disable" },
	{ 0x7cd8d75e, "page_offset_base" },
	{ 0xa0124c25, "eth_get_headlen" },
	{ 0x364d747a, "xp_raw_get_dma" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x167c5967, "print_hex_dump" },
	{ 0x9a74f1a8, "pci_select_bars" },
	{ 0xbc3f2cb0, "timecounter_cyc2time" },
	{ 0xdf858a61, "netif_device_attach" },
	{ 0x1c221005, "napi_gro_receive" },
	{ 0xcdf72876, "__hw_addr_unsync_dev" },
	{ 0xa191c11f, "_dev_info" },
	{ 0x1d03ede8, "__x86_indirect_alt_call_r8" },
	{ 0xc09b81d1, "dev_addr_add" },
	{ 0x218bc6e2, "__free_pages" },
	{ 0xb601be4c, "__x86_indirect_thunk_rdx" },
	{ 0x618911fc, "numa_node" },
	{ 0xe2e80efa, "netif_device_detach" },
	{ 0x7efe7378, "__alloc_skb" },
	{ 0xa916b694, "strnlen" },
	{ 0xb6a3c4d3, "xsk_set_rx_need_wakeup" },
	{ 0x12a38747, "usleep_range" },
	{ 0xb5d51a64, "pci_enable_msix_range" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0xf57c5e9d, "skb_checksum_help" },
	{ 0xe3beea76, "kfree_skb" },
	{ 0xe6d2458e, "do_trace_netlink_extack" },
	{ 0x88edac31, "ndo_dflt_fdb_add" },
	{ 0x7694ca4, "napi_complete_done" },
	{ 0x66cd8ac0, "dma_map_page_attrs" },
	{ 0x2ea2c95c, "__x86_indirect_thunk_rax" },
	{ 0x5c8386cf, "pci_read_config_dword" },
	{ 0x6ee1fff2, "eth_type_trans" },
	{ 0x3a26ed11, "sched_clock" },
	{ 0x9d1da08d, "xdp_rxq_info_reg_mem_model" },
	{ 0x31876137, "dev_driver_string" },
	{ 0x99186ec8, "pskb_expand_head" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x49df716b, "netdev_err" },
	{ 0x910024be, "__x86_indirect_alt_call_rdx" },
	{ 0x467df16d, "netdev_rss_key_fill" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xf4fcf6e4, "pci_unregister_driver" },
	{ 0xef95a58c, "kmem_cache_alloc_trace" },
	{ 0xba8fbd64, "_raw_spin_lock" },
	{ 0xb19a5453, "__per_cpu_offset" },
	{ 0xca21ebd3, "bitmap_free" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xc0b19709, "__x86_indirect_alt_call_r13" },
	{ 0x69c3b110, "__netif_napi_del" },
	{ 0x3d0a6398, "xdp_rxq_info_unreg_mem_model" },
	{ 0x2b82becb, "pci_set_power_state" },
	{ 0x53da7fa2, "udp_tunnel_nic_ops" },
	{ 0x1ab7d9fa, "netdev_warn" },
	{ 0xbb4f4766, "simple_write_to_buffer" },
	{ 0x4a5c748, "eth_validate_addr" },
	{ 0xdd45607e, "pci_disable_pcie_error_reporting" },
	{ 0x27773882, "xdp_do_redirect" },
	{ 0x37a0cba, "kfree" },
	{ 0x69acdf38, "memcpy" },
	{ 0xc1db9159, "___pskb_trim" },
	{ 0xe5a3f6b4, "ptp_clock_index" },
	{ 0x428b4d36, "pci_disable_msi" },
	{ 0x53bc6327, "dev_trans_start" },
	{ 0x5953f108, "__x86_indirect_alt_call_r10" },
	{ 0x7b37d4a7, "_find_first_zero_bit" },
	{ 0x310a5bc9, "skb_add_rx_frag" },
	{ 0x1c087794, "pci_num_vf" },
	{ 0xedc03953, "iounmap" },
	{ 0x4961e024, "dma_sync_single_for_device" },
	{ 0xe98a828a, "__x86_indirect_alt_call_r14" },
	{ 0x5bd55f24, "__pci_register_driver" },
	{ 0x15af7f4, "system_state" },
	{ 0x53569707, "this_cpu_off" },
	{ 0xd33d4dd1, "dma_unmap_page_attrs" },
	{ 0x661c55bb, "pci_get_device" },
	{ 0x9a353ae, "__x86_indirect_alt_call_rax" },
	{ 0x63c4d61f, "__bitmap_weight" },
	{ 0xe9a06459, "xdp_convert_zc_to_xdp_frame" },
	{ 0xaa953934, "unregister_netdev" },
	{ 0xd16758c, "ndo_dflt_bridge_getlink" },
	{ 0x5c2bcd37, "bpf_warn_invalid_xdp_action" },
	{ 0x1ba59527, "__kmalloc_node" },
	{ 0xe8113eb6, "pci_dev_put" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x63602b9f, "pci_vfs_assigned" },
	{ 0x656e4a6e, "snprintf" },
	{ 0xe113bbbc, "csum_partial" },
	{ 0xbb7195a5, "xdp_warn" },
	{ 0xba488467, "consume_skb" },
	{ 0xcc93e399, "dca_remove_requester" },
	{ 0xafc46f80, "pci_enable_device_mem" },
	{ 0x1d47cf95, "__napi_alloc_skb" },
	{ 0xc60d0620, "__num_online_cpus" },
	{ 0xe5498c99, "skb_tstamp_tx" },
	{ 0xe598cd31, "__x86_indirect_alt_call_rcx" },
	{ 0x32fe1356, "skb_put" },
	{ 0x68a11fb9, "pci_wake_from_d3" },
	{ 0x672dfcd2, "devm_kmalloc" },
	{ 0xefacc7ed, "pci_release_selected_regions" },
	{ 0x5625e8e4, "pci_request_selected_regions" },
	{ 0x59c6aff4, "irq_set_affinity_hint" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x786f437c, "param_ops_uint" },
	{ 0xc7ed0bf2, "skb_copy_bits" },
	{ 0xa8b3defb, "xp_dma_map" },
	{ 0xdf9208c0, "alloc_workqueue" },
	{ 0xd7630d39, "bpf_prog_put" },
	{ 0x32bac188, "pci_find_ext_capability" },
	{ 0x23fd3028, "vmalloc_node" },
	{ 0x6e720ff2, "rtnl_unlock" },
	{ 0x9e7d6bd0, "__udelay" },
	{ 0x3343a8d6, "__skb_pad" },
	{ 0x8fa9d9e8, "__SCT__tp_func_xdp_exception" },
	{ 0xb772e004, "device_set_wakeup_enable" },
	{ 0xee9d95dd, "pcie_capability_read_word" },
	{ 0xe9fe8636, "dev_get_stats" },
	{ 0xe05cc145, "xp_alloc" },
	{ 0xc31db0ce, "is_vmalloc_addr" },
	{ 0xc1514a3b, "free_irq" },
	{ 0x45400a50, "xp_dma_sync_for_device_slow" },
	{ 0xef042b60, "pci_save_state" },
	{ 0xb0b54a94, "alloc_etherdev_mqs" },
	{ 0x7a06be92, "xsk_tx_completed" },
	{ 0x9f223fe4, "__tracepoint_xdp_exception" },
	{ 0x9c093053, "netdev_crit" },
};

MODULE_INFO(depends, "mdio,dca");

MODULE_ALIAS("pci:v00008086d000010B6sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000010C6sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000010C7sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000010C8sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000150Bsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000010DDsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000010ECsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000010F1sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000010E1sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000010F4sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000010DBsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001508sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000010F7sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000010FCsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001517sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000010FBsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001507sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001514sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000010F9sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000152Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001529sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000151Csv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000010F8sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001528sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000154Dsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000154Fsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001558sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001557sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d0000154Asv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001560sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d00001563sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000015D1sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000015AAsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000015B0sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000015ABsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000015ADsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000015ACsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000015AEsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000015C2sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000015C3sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000015C4sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000015C6sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000015C7sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000015C8sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000015CEsv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000015E4sv*sd*bc*sc*i*");
MODULE_ALIAS("pci:v00008086d000015E5sv*sd*bc*sc*i*");

MODULE_INFO(srcversion, "DD39B62F366221FD34E892E");
