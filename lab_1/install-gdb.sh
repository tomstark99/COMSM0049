#!/install-gdb.sh 
# a script for manually installing GDB on vagrant boxes where
#     $ sudo apt install gdb
# does not work
cd /tmp
if [ -z $(ls gdb-7.11.tar.gz) ]
then
    wget "http://ftp.gnu.org/gnu/gdb/gdb-7.11.tar.gz"
fi
if [ -z $(ls gdb-7.11) ]
then
    tar -xvzf gdb-7.11.tar.gz
fi
cd gdb-7.11
if [ -z $(which gcc) ]
then
    echo installing gcc...
    sudo apt install gcc-7-multilib
else
    echo gcc installed...
fi
./configure
if [ -z $(which make) ]
then
    echo installing make...
    sudo apt install make
else
    echo make installed...
fi
make || date && echo GDB could not be installed
sudo cp /tmp/gdb-7.11/gdb/gdb /usr/bin/
echo DONE... GDB installed
