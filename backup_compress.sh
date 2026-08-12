#!/bin/bash
mkdir -p backup
cp *.txt backup/
tar -czvf backup.tar.gz backup/
