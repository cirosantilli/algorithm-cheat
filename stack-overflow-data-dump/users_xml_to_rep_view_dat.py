#!/usr/bin/env python3

'''
https://stats.stackexchange.com/questions/376361/how-to-find-the-sample-points-that-have-statistically-meaningful-large-ratios-be
'''

import sys
import xml.parsers.expat

xml_path = sys.argv[1]

def tag_open(tag, attrs):
    if tag == 'row':
        row = []
        row.append(attrs['Reputation'])
        row.append(attrs['Views'])
        row.append(attrs['Id'] + '_' + attrs['DisplayName'].replace(' ', '_').replace('\n', '_'))
        sys.stdout.write((' '.join(row) + '\n'))

print('Reputation Views Id_DisplayName')
parser = xml.parsers.expat.ParserCreate()
parser.StartElementHandler = tag_open
with open(xml_path, 'br') as f:
    parser.ParseFile(f)
