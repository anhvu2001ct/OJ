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

if __name__ == "__main__":
    args = sys.argv[1:]
    path = get_path(args[0])
    files = [f for f in os.listdir(path) if os.path.isfile(path+f)]
    prefixes = defaultdict(list)
    for f in files: prefixes[get_prefix(f)].append(f)
    print("{} file(s) need to be packed".format(len(files)))
    print("{} folder(s) will be created".format(len(prefixes)))

    for prefix, files in prefixes.items():
        print("Packing {} .. ".format(prefix), end="")
        if not os.path.exists(path+prefix):
            os.makedirs(path+prefix)
        for f in files:
            move(path+f, path+prefix)
        print("Done.")
