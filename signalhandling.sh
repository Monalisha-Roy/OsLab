#!bin/bash

echo Program for performing KILL operation
ps
echo enter the pid: 
read pid
kill -9 $pid
echo finished killing the process with pid: $pid
