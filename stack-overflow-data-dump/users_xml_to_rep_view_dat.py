#!/usr/bin/env python3

import sys
import xml.parsers.expat

xml_path = sys.argv[1]

def tag_open(tag, attrs):
    if tag == 'row':
        row = []
        row.append(attrs['Id'])
        row.append(attrs['Reputation'])
        row.append(attrs['Views'])
        clean_display_name = []
        bad_chars = {' ', '\n', '\r'}
        for c in attrs['DisplayName']:
            if c in bad_chars:
                clean_display_name.append('_')
            else:
                clean_display_name.append(c)
        clean_display_name = ''.join(clean_display_name)
        row.append(clean_display_name)
        sys.stdout.write((' '.join(row) + '\n'))

print('Id Reputation Views DisplayName')
parser = xml.parsers.expat.ParserCreate()
parser.StartElementHandler = tag_open
with open(xml_path, 'br') as f:
    parser.ParseFile(f)
