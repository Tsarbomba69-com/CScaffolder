import sys

if __name__ == "__main__":

    if len(sys.argv) < 3:
        print("Usage: python cscaffolder.py <data-struct> <type>")
        sys.exit(1)

    if sys.argv[1] == '-h' or sys.argv[1] == '--help':
        print('Bunch of help text!')


    data_struct = sys.argv[1]
    data_type = sys.argv[2]
    impl_buffer = ''
    header_buffer = ''
    with open(f"{data_struct}.c", "r") as impl_file: # TODO: Error handling
        impl_buffer = impl_file.read()

    with open(f"{data_struct}.h", "r") as header_file:
        header_buffer = open(f"{data_struct}.h", "r")
