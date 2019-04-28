#!/usr/bin/env python3

from signal import signal, SIGPIPE, SIG_DFL
import sys

dat_path = sys.argv[1]

signal(SIGPIPE, SIG_DFL)
sys.stdout.write('<!DOCTYPE html><html lang="en"><head><meta charset="utf-8"></head><body><table><th>Id</th><th>Reputation</th><th>Views</th><th>DisplayName</th>\n')
with open(dat_path, 'r', encoding='utf-8') as f:
    next(f)
    for line in f:
        id, reputation, views, name = line[:-1].split(' ')
        sys.stdout.write(
            '<tr>' +
            '<td><a href="https://stackoverflow.com/users/' + id + '">' + id + '</a></td>' +
            '<td>' + reputation + '</td>' +
            '<td>' + views + '</td>' +
            '<td><a href="https://stackoverflow.com/users/' + id + '">' + name + '</a></td>' +
            '</tr>\n'
        )
sys.stdout.write('</table></body></html>\n')
