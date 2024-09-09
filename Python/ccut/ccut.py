#!/usr/bin/python3
import sys
import os


delimeter = '\t'
field_number = None
file_path = None


for arg in sys.argv[1:]:
    if arg.startswith('-f'):
        try:
            field_number = int(arg[2:])
            if field_number < 1:
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
if field_number is None:
    print("Error: Missing -f option")
    sys.exit(1)

if file_path is None or not os.path.isfile(file_path):
    print(f"Error: Cannot open file '{file_path}'")
    sys.exit(1)

with open(file_path, 'r') as file:
    data = file.readlines()

    for line in data:
        split_line = line.split(delimeter)
        if len(split_line) < field_number:
            print("Error: Field number out of range")
        else:
            print(split_line[field_number -1])