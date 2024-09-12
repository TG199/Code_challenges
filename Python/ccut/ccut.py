#!/usr/bin/python3
import sys
import os
""" A simple Unix Cut tool """


delimeter = '\t'
field_numbers = None
file_path = None


for arg in sys.argv[1:]:
    if arg.startswith('-f'):
        try:
            if '"' in arg[2:]:
                field_numbers = arg[2:].strip('"')
            if ',' in arg[2:]:
                field_numbers = arg[2:].split(',')
            elif ' ' in arg[2:]:
                field_numbers = arg[2:].split(' ')
            else:
                field_numbers = [arg[2:]]
            field_numbers = [int(i) for i in field_numbers]
            if any(i < 1 for i in field_numbers):
                print("Error: Invalid field number")
                sys.exit(1)
        except ValueError:
            print("Error: Field number must be an integer")
            sys.exit(1)
    elif arg.startswith('-d'):
        if len(arg) > 2:
            delimeter = arg[2:]
        else:
            print("Error: Missing delimeter value after -d")
            sys.exit(1)
    else:
        file_path = arg

if file_path == '-' or file_path is None:
    with sys.stdin as file:
        data = file.readlines()

    for line in data:
        split_line = line.split(delimeter)
        if len(split_line) < max(field_numbers):
            print("Error: Field number out of range")
            continue
        
        selected_fields = [split_line[num - 1] for num in field_numbers]

        print(delimeter.join(selected_fields))

else:
    with open(file_path, 'r') as file:
        data = file.readlines()

        for line in data:
            split_line = line.split(delimeter)
            if len(split_line) < max(field_numbers):
                print("Error: Field number out of range")
                continue
        
            selected_fields = [split_line[num - 1] for num in field_numbers]

            print(delimeter.join(selected_fields))
