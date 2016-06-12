#!/bin/sh


## run the secure bridge
#ssh -D 9040 xxx.xxx.xxx.xxx #-g ## global

## run the double hop bridge
ssh -L 9041:localhost:9040 10.0.xxx.xxx ssh -D 9040 xxx.xxx.xxx.xxx

## run the anonym bridge!
#sudo nano /etc/tsocks
#sudo nano /etc/tor/torrc
tsocks tor

## run the http bridge
# sudo nano /etc/polipo/config
polipo


## run my tools
#pidgin
#skype
#tsocks xchat
tsocks steam

