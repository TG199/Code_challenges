#!/usr/bin/python3
import sys

if len(sys.argv[1]) != 3:
    print(f'cut: invalid field value `{sys.argv[2]}`\n'
          'Try "cut --help" for more information')

else:
    second_arg_list = list(sys.argv[1])
    arg_number = int(second_arg_list[-1])

    with open(sys.argv[2], 'r') as file:
        data = file.readlines()

        for line in data:
            split_line = line.split('\t')
            field = split_line[arg_number - 1]
            if arg_number - 1 < 0:
                print(f'cut: invalid field value `{sys.argv[2]}`\n'
                'Try "cut --help" for more information')
            else:
                print(field)