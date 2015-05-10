#!/bin/sh

. ./a.sh

IFS=',' read -ra LINE <<< "$dnsmasq_address"
for i in "${LINE[@]}"; do
    echo "address=$i"
done
