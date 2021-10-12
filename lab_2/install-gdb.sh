cd /tmp
wget "http://ftp.gnu.org/gnu/gdb/gdb-7.11.tar.gz"
tar -xvzf gdb-7.11.tar.gz
cd gdb-7.11
./configure
make
sudo cp /tmp/gdb-7.11/gdb/gdb /usr/bin/
