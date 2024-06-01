import sys
from code_gen import CodeGen

# TODO: Improve program internal documentation
def print_help():
    print('Bunch of help text!')
    sys.exit(1)


if __name__ == "__main__":

    if len(sys.argv) < 3:
        print("Usage: python cscaffolder.py gen <data-struct> <type>")
        sys.exit(1)

    call = sys.argv[1]
    arg1 = sys.argv[2]
    arg2 = sys.argv[3]

    match call:
        case '-h':
            print_help()
        case '--help':
            print_help()
        case 'gen':
            gen = CodeGen(arg1, arg2)
            (impl, header) = gen.generate_code()
            gen.save_file(impl, header)
        case _:
            print("Usage: python cscaffolder.py <data-struct> <type>")
