#!/bin/bash
mount -t cifs -o credentials=/home/matt/.credentials,iocharset=utf8,file_mode=0777,dir_mode=0777,uid=1000,gid=1000 //192.168.0.42/terastore /mnt/terastore/
