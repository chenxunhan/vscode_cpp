cat /proc/sys/vm/swappiness
echo 100 > /proc/sys/vm/swappiness

free -m
dd if=/dev/zero of=/tmp/swap bs=1M count=64
mkswap /tmp/swap
free -m
swapon /tmp/swap
swapon -s
swapoff /tmp/swap
swapon -s