#!/bin/sh
export sS_mode=1
export ss_server=1.1.1.1
export ss_port=8080
export ss_methor=rc4-mD5
export ss_timeout=600
export ss_password=asdEasd
export ss_socks5=1080
export ss_redirect_port=3333
export ss_httpport=8118

export chinadns_enable=1
export chinadns_updns=114.114.114.114
export chinadns_port=5656
export chinadns_iplist=/etc/chinadns_iplist.txt
export chinadns_chnroute=/etc/chinadns_chnroute.txt
export chinadns_timeout=3
export chinadns_both=1
export chinadns_mdns=0

export dns2socks_enable=1
export dns2socks_host=8.8.8.8:53
export dns2socks_lhost=127.0.0.1:5959

export dnscrypt_enable=1
export dnscrypt_lhost=127.0.0.1:5858
export dnscrypt_name=opendns
export dnscrypt_csv=/etc/dnscrypt-resolvers.csv
export dnscrypt_tcp=0

export dnsmasq_serverhost=127.0.0.1:1053
export dnsmasq_address=/ares.dl.playstation.net/60.210.22.216,/zeus.dl.playstation.net/60.210.22.216,/poseidon.dl.playstation.net/60.210.22.216,/gs2.ww.prod.dl.playstation.net/60.210.22.216

export policy_udp=0
export policy_webonly=1
export policy_lanip_ss=192.168.1.33,192.168.1.34
export policy_lanip_noss=192.168.1.133,192.168.1.134
export policy_ip_ss=18.1.1.1,19.1.1.1
export policy_ip_noss=20.1.1.1,20.1.1.2
export policy_host_ss=www.google.com,www.youtube.com
export policy_host_noss=
export policy_pal=/etc/pal-list.txt


