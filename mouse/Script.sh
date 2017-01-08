#!/bin/sh

#  Script.sh
#
#  Created by Ronnel Davis on 11/7/16.
#  Copyright © 2016 Ronnel Davis. All rights reserved.

echo "=============="
echo "Installing ADB"
echo "=============="

sudo add-apt-repository ppa:phablet-team/tools
sudo apt-get update
sudo apt-get install android-tools-adb

echo "=================="
echo "Installing headers"
echo "=================="

sudo apt-get install build-essential linus-headers-$(uname -r)

echo "============="
echo "Making module"
echo "============="

sudo rmmod vms1.ko
make
sudo insmod vms1.ko

echo "================"
echo "Compiling client"
echo "================"

gcc coord.c
adb logcat -s "OSP" | sudo ./a.out
