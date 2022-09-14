#!/bin/bash
echo "Enter user name"
read USER_NAME
who | grep $USER_NAME
