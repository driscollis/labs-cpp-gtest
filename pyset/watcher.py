import argparse
import os
import subprocess
import time

from watchdog.observers import Observer
from watchdog.events import FileSystemEventHandler

def get_args():
    parser = argparse.ArgumentParser(
        description="A File Watcher that executes the specified tests"
        )
    parser.add_argument('--tests', action="store", required=True,
                        help='The path to the test file to run')
    return parser.parse_args()

class FW(FileSystemEventHandler):
    def __init__(self, test_file_path):
        self.test_file_path = test_file_path

    def on_any_event(self, event):

        if os.path.exists(self.test_file_path):
            cmd = ['python', self.test_file_path]
            subprocess.call(cmd)
            print '-' * 70

if __name__ =='__main__':
    args = get_args()
    observer = Observer()
    path = args.tests
    fobj = FW(path)

    if os.path.exists(path) and os.path.isfile(path):
        observer.schedule(fobj, os.path.dirname(path), recursive=True)
        observer.start()
        try:
            while True:
                time.sleep(1)
        except KeyboardInterrupt:
            observer.stop()
        observer.join()