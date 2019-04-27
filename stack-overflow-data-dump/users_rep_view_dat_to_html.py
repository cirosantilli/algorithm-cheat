#!/usr/bin/env python3

"""
Convert Users.xml to both:

- a simple space separated text file
- an HTML file with hyperlinks for interactive exploration

Can only contain fields which don't contain spaces, but this basically equals all the interesting fields.
"""

from signal import signal, SIGPIPE, SIG_DFL
import sys

dat_path = sys.argv[1]

signal(SIGPIPE, SIG_DFL)
sys.stdout.write('<!DOCTYPE html><html lang="en"><head><meta charset="utf-8"></head><body><table><th>Reputation</th><th>Views</th><th>Id</th><th>DisplayName</th>\n')
with open(dat_path, 'r', encoding='utf-8', newline='\n') as f:
    for line in f:
        reputation, views, id_name = line[:-1].split(' ')
        idx = id_name.find('_')
        id = id_name[:idx]
        name = id_name[idx + 1:]
        sys.stdout.write(
            '<tr>' +
            '<td>' + reputation + '</td>' +
            '<td>' + id + '</td>' +
            '<td><a href="https://stackoverflow.com/users/' + id + '">' + id + '</a></td>' +
            '<td><a href="https://stackoverflow.com/users/' + id + '">' + name + '</a></td>' +
            '</tr>\n'
        )
sys.stdout.write('</table></body></html>\n')
