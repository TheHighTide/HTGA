#!/bin/bash

echo Welcome to HTGA but on Linux!
echo Please press enter to continue...
read -n 1 -s
clear

while true; do
  echo What do you want to do?
  echo [1] display message
  echo [2] display calendar
  echo [3] quit
  read -p "Enter your choice: " choice
  case $choice in
    1)
      echo -------------------------
      echo "This is a really cool message that doesn't really serve a purpose at all!"
      ;;
    2)
      echo -------------------------
      ;;
    3)
      echo -------------------------
      echo You are about to exit this app! Are you sure you want this?
      echo [1] = Yes
      echo [2] = No
      read -p "Enter your choice: " choice
      case $choice in
        1)
          echo Exiting...
          exit
          ;;
        2)
          echo Returning to Menu!
          ;;
        *)
          echo Invalid Option!
          echo Exiting Application...
          exit
          ;;
        esac
      ;;
    *)
      echo Invalid Option!
      echo Please press enter to continue...
      read -n 1 -s
      ;;
  esac
  echo Please press enter to continue...
  read -n 1 -s
  clear
done
