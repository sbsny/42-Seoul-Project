#!/bin/bash

architecture=$(uname -a)
cpu_physical=$(grep "physical id" /proc/cpuinfo | sort -u | wc -l)
vcpu=$(grep -c "^processor" /proc/cpuinfo)
memory_usage=$(free -m | awk 'NR==2 {printf "%s/%sMB (%.2f%%)", $3, $2, $3 * 100 / $2}')
disk_usage=$(df -BG --total | awk '/total/ {printf "%s/%s (%s)", $3, $2, $5}')
cpu_load=$(top -bn1 | awk -F',' '/Cpu\(s\)|^%Cpu/ {gsub(/[^0-9.]/, "", $4); printf "%.1f%%", 100 - $4}')
last_boot=$(who -b | awk '{print $3, $4}')
lvm_use=$(lsblk | grep -q "lvm" && echo yes || echo no)

if command -v ss >/dev/null 2>&1; then
	tcp_connections=$(ss -tan state established 2>/dev/null | grep -c ESTAB)
else
	tcp_connections=$(netstat -tan 2>/dev/null | grep -c ESTABLISHED)
fi

user_log=$(who | wc -l)
ip_address=$(hostname -I 2>/dev/null | awk '{print $1}')
mac_address=$(ip link 2>/dev/null | awk '/link\/ether/ {print $2; exit}')

[ "$cpu_physical" -eq 0 ] && cpu_physical=1
[ -z "$ip_address" ] && ip_address="unavailable"
[ -z "$mac_address" ] && mac_address="unavailable"

if [ -f /var/log/sudo/sudo.log ]; then
	sudo_count=$(awk '/COMMAND/ {count++} END {print count + 0}' /var/log/sudo/sudo.log)
else
	sudo_count=0
fi

wall "#Architecture: $architecture
#CPU physical: $cpu_physical
#vCPU: $vcpu
#Memory Usage: $memory_usage
#Disk Usage: $disk_usage
#CPU load: $cpu_load
#Last boot: $last_boot
#LVM use: $lvm_use
#Connexions TCP: $tcp_connections ESTABLISHED
#User log: $user_log
#Network: IP $ip_address ($mac_address)
#Sudo: $sudo_count cmd"
