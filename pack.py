import os
import sys
import json
from collections import defaultdict
from shutil import move

def get_config():
    with open("config.json") as f:
        config = json.load(f)
        config["alias"] = {str(als): judge for judge, li in config["alias"].items() for als in li}
    return config

config = get_config()

def get_path(folder):
    folder = str(folder)
    if folder in config["alias"]:
        folder = config["alias"][folder]
    path = f"{folder}/"
    if not os.path.exists(path):
        os.makedirs(path)
    return path

def get_prefix(name: str):
    for i in range(len(name)):
        if name[i].isalpha():
            return name[:i]

def get_files(path):
    files = [f for f in os.listdir(path) if os.path.isfile(path+f)]
    files.sort()
    return files

if __name__ == "__main__":
    args = sys.argv[1:]
    path = get_path(config["default"] if len(args) == 0 else args[0])
    files = get_files(path)
    prefixes = defaultdict(list)

    cnt = set()
    for f in files:
        prefix = get_prefix(f)
        prefixes[prefix].append(f)
        if not os.path.exists(path+prefix): cnt.add(prefix)
    print("-> {} file(s) need to be packed".format(len(files)))
    print("-> {} folder(s) will be created".format(len(cnt)))

    for prefix in cnt:
        os.makedirs(path+prefix)

    for prefix, files in prefixes.items():
        names = tuple((f.split('.')[0][len(prefix):] for f in files))
        print("---> Packing {}{}... ".format(prefix, names), end="")
        for f in files:
            move(path+f, path+prefix)
        print("Done.")
