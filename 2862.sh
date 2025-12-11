#! /usr/bin/env bash
sed '1d;s/.*404.*/Found/;t;s/.*/NotFound/'
