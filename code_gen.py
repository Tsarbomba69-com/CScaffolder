import re
import os

TEMPLATE_PATH = './templates'
OUTPUT_PATH = './output'


class CodeGen:
    _data_struct: str
    _type: str
    _type2: str

    def __init__(self, data_stuct: str, type: str, type2: str = ''):
        self._data_struct = self.sanitize(data_stuct, r'[^a-zA-Z0-9_]')
        self._type = self.sanitize(type, r'[^a-zA-Z0-9_]\*')
        self._type2 = self.sanitize(type2, r'[^a-zA-Z0-9_]\*')

    @staticmethod
    def sanitize(text: str, pattern: str):
        text = re.sub(pattern, '', text)
        match = re.search(r'[a-zA-Z_]', text)
        if match:
            start = match.start()
            return text[start:]
        else:
            return text

    def generate_code(self):
        _type = self._type.replace('*', '') + '_'
        type2 = self._type2.replace('*', '') + '_'
        with open(f"{TEMPLATE_PATH}/{self._data_struct}.c", "r") as impl_file:  # TODO: Error handling
            impl_buffer = impl_file.read()
            if self._data_struct == 'hashtable':
                impl_buffer = re.sub('{TValue}_', _type, impl_buffer)
                impl_buffer = re.sub('{TValue}', self._type, impl_buffer)
                impl_buffer = re.sub('{TKey}_', type2, impl_buffer)
                impl_buffer = re.sub('{TKey}', self._type2, impl_buffer)
            else:
                impl_buffer = re.sub('{type}_', _type, impl_buffer)
                impl_buffer = re.sub('{type}', self._type, impl_buffer)

        with open(f"{TEMPLATE_PATH}/{self._data_struct}.h", "r") as header_file:  # TODO: Error handling
            header_buffer = header_file.read()
            if self._data_struct == 'hashtable':
                header_buffer = re.sub('{TValue}_', _type, header_buffer)
                header_buffer = re.sub('{TValue}', self._type, header_buffer)
                header_buffer = re.sub('{TKey}_', type2, header_buffer)
                header_buffer = re.sub('{TKey}', self._type2, header_buffer)
            else:
                header_buffer = re.sub('{type}_', _type, header_buffer)
                header_buffer = re.sub('{type}', self._type, header_buffer)

        return impl_buffer, header_buffer

    def save_file(self, impl_buf: str, header_buf: str):
        if not os.path.exists(OUTPUT_PATH):
            os.makedirs(OUTPUT_PATH)
        _type = self._type.replace('*', '')
        with open(f"{OUTPUT_PATH}/{_type}_{self._data_struct}.c", "w") as impl_file:  # TODO: Error handling
            impl_file.write(impl_buf)
        with open(f"{OUTPUT_PATH}/{_type}_{self._data_struct}.h", "w") as header_file:  # TODO: Error handling
            header_file.write(header_buf)
