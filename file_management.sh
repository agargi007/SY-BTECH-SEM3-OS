#!/bin/bash
mkdir -p mydir/mysubdir
echo "Hello World" | cat > mydir/file.txt
cp mydir/file.txt mydir/copy.txt
mv mydir/copy.txt mydir/renamed_file.txt
chmod 744 mydir/renamed_file.txt
ls -l mydir/
