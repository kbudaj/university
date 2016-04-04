#!/bin/bash

interval=3

if [ "$1" ]
then
  url=$1
else
  echo "Podaj adres strony"
  echo "./program [url] [minuty]"
  echo "Drugi atrybut jest dodatkowy, ustawia co ile nalezy"
  echo "sprawdzic zmiany. Standardowo 10min"
  exit
fi

wget --output-document file_org.html $url 2> /dev/null

while [ True ]
do
  wget --output-document file1.html $url 2> /dev/null
  diff file_org.html file1.html
  mv file1.html file_org.html  
  sleep "$interval"
  #sleep "$interval"m
done
