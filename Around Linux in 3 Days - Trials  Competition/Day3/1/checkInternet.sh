#!/bin/bash
wget -q http://google.com
if [ $? -eq 0 ]; then
        echo "Net is Connected"
else
        echo "Net is Disconnected"
fi