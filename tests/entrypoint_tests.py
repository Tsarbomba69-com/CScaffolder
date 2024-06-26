import unittest
import subprocess


class MainTest(unittest.TestCase):
    def test_no_input_should_fail(self):
        res = subprocess.run(["python", "../cscaffolder.py"])
        self.assertEqual(res.returncode, 1)

    def test_no_gen_should_fail(self):
        res = subprocess.run(["python", "../cscaffolder.py", "int"])
        self.assertEqual(res.returncode, 1)

    def test_no_type_should_fail(self):
        res = subprocess.run(["python", "../cscaffolder.py", "gen"])
        self.assertEqual(res.returncode, 1)

    def test_should_succeed(self):
        res = subprocess.run(["python", "../cscaffolder.py", "gen", "type"])
        self.assertEqual(res.returncode, 1)

if __name__ == '__main__':
    unittest.main()
