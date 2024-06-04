# Copyright 2024 Hendrick Dias <hendrickdias66@gmail.com>

# Permission is hereby granted, free of charge, to any person obtaining
# a copy of this software and associated documentation files (the
# "Software"), to deal in the Software without restriction, including
# without limitation the rights to use, copy, modify, merge, publish,
# distribute, sublicense, and/or sell copies of the Software, and to
# permit persons to whom the Software is furnished to do so, subject to
# the following conditions:

# The above copyright notice and this permission notice shall be
# included in all copies or substantial portions of the Software.

# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
# NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
# LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
# OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
# WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

import sys
from singletons import HELP
from code_gen import CodeGen


# TODO: Improve program internal documentation
# TODO: Implement `All` function
# TODO: Implement LinkedList

def print_help():
    print(HELP)
    sys.exit(1)

def print_usage():
    print("Usage: python cscaffolder.py gen <data-struct> <type>")
    sys.exit(1)


if __name__ == "__main__":

    if len(sys.argv) < 2:
        print_usage()

    call = sys.argv[1]

    match call:
        case '-h':
            print_help()
        case '--help':
            print_help()
        case 'gen':
            if len(sys.argv) < 4:
                print_usage()
            arg1 = sys.argv[2]
            arg2 = sys.argv[3]
            gen = CodeGen(arg1, arg2)
            (impl, header) = gen.generate_code()
            gen.save_file(impl, header)
        case _:
            print("Usage: python cscaffolder.py gen <data-struct> <type>")
            sys.exit(1)
