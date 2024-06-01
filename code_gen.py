import re
import os

TEMPLATE_PATH = './templates'
OUTPUT_PATH = './output'


class CodeGen:
    data_struct: str
    type: str

    def __init__(self, data_stuct: str, type: str):
        self.data_struct = self.sanitize(data_stuct, r'[^a-zA-Z0-9]')
        self.type = self.sanitize(type, r'[^a-zA-Z0-9]\*')

    def sanitize(self, text: str, pattern: str):
        text = re.sub(pattern, '', text)
        match = re.search(r'[a-zA-Z]', text)
        if match:
            start = match.start()
            return text[start:]
        else:
            return text

    def generate_code(self):
        _type = self.type.replace('*', '') + '_'
        with open(f"{TEMPLATE_PATH}/{self.data_struct}.c", "r") as impl_file:  # TODO: Error handling
            impl_buffer = impl_file.read()
            impl_buffer = re.sub('{type}_', _type, impl_buffer)
            impl_buffer = re.sub('{type}', self.type, impl_buffer)

        with open(f"{TEMPLATE_PATH}/{self.data_struct}.h", "r") as header_file:  # TODO: Error handling
            header_buffer = header_file.read()
            header_buffer = re.sub('{type}_', _type, header_buffer)
            header_buffer = re.sub('{type}', self.type, header_buffer)

        return (impl_buffer, header_buffer)

    def save_file(self, impl_buf: str, header_buf: str):
        if not os.path.exists(OUTPUT_PATH):
            os.makedirs(OUTPUT_PATH)
        _type = self.type.replace('*', '')
        with open(f"{OUTPUT_PATH}/{_type}_{self.data_struct}.c", "w") as impl_file:  # TODO: Error handling
            impl_file.write(impl_buf)
        with open(f"{OUTPUT_PATH}/{_type}_{self.data_struct}.h", "w") as header_file:  # TODO: Error handling
            header_file.write(header_buf)
