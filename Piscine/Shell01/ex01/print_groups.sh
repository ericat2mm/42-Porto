#!/bin/bash
id -G -n $FT_USER |tr -d '\n' |tr ' ' ','
