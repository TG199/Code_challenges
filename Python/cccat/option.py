def cat_with_line(file):
    """Numbers the file"""
    line_num = 1    
    for line in file:
        print(f"{line_num:6d} {line}", end='')
        line_num += 1

def cat_with_line_b_option(file):
    """Numbers the file"""
    line_num = 1    
    for line in file:
        if line.isspace():
            print()
        else:
            print(f"{line_num:6d} {line}", end='')
            line_num += 1