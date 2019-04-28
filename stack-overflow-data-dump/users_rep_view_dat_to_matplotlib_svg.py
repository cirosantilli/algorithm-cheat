#!/usr/bin/env python3

'''
Produce one huge 2.2G SVG with clickable points. Chromium 73 can't
handle it though, it just becomes too slow. Generation takes 30 mins
as well, which is not cool.

Bibliography:

- https://stackoverflow.com/questions/12387585/python-matplotlib-svg-and-hyperlinks-in-text-labels
- https://stackoverflow.com/questions/15417586/python-matlplotlib-add-hyperlink-to-text
'''

import sys

import numpy as np
import matplotlib.pyplot as plt

dat_path = sys.argv[1]

reputations = []
profile_view_counts = []
urls = []
with open(dat_path, 'r', encoding='utf-8') as f:
    next(f)
    for line in f:
        line = line[:-1]
        id, reputation, profile_view_count, name = line.split(' ')
        reputations.append(int(reputation))
        profile_view_counts.append(int(profile_view_count))
        urls.append('https://stackoverflow.com/users/' + id)
__import__('ipdb').set_trace(context=31)
f = plt.figure()
s = plt.scatter(reputations, profile_view_counts)
s.set_urls(urls)
f.canvas.print_figure('users_rep_view_dat_matplotlib.svg')
