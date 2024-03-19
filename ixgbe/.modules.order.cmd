cmd_drivers/net/ethernet/intel/ixgbe/modules.order := {   echo drivers/net/ethernet/intel/ixgbe/ixgbe.ko; :; } | awk '!x[$$0]++' - > drivers/net/ethernet/intel/ixgbe/modules.order
