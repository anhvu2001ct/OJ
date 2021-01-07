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

def get_files(path):
    files = [f for f in os.listdir(path) if os.path.isfile(path+f)]
    files.sort()
    return files

def pack_codeforces(path, files):
    def get_contest(name):
        for i in range(len(name)):
            if name[i].isalpha():
                return name[:i]

    folder_not_create = set()
    contests = defaultdict(list)
    for f in files:
        contest = get_contest(f)
        contests[contest].append(f)
        if not os.path.exists(path+contest): folder_not_create.add(contest)
    
    print("-> {} file(s) need to be packed".format(len(files)))
    print("-> {} folder(s) will be created".format(len(folder_not_create)))

    for folder in folder_not_create:
        os.makedirs(path+folder)

    for contest, files in contests.items():
        names = tuple((f.split('.')[0][len(contest):] for f in files))
        print("----> Packing {}{}... ".format(contest, names), end="")
        for f in files:
            move(path+f, path+contest+'/'+f)
        print("Done.")

def pack_atcoder(path, files):
    def get_contest(name):
        type = name[:3].upper()
        for i in range(3, len(name)):
            if name[i].isalpha():
                return type, name[len(type):i]

    folder_not_create = set()
    contests = defaultdict(lambda: defaultdict(list))
    for f in files:
        contest_type, contest_id = get_contest(f)
        contests[contest_type][contest_id].append(f)
        path2 = f"{path}{contest_type}/{contest_id}"
        if not os.path.exists(path2): folder_not_create.add(path2)
    
    print("-> {} file(s) need to be packed".format(len(files)))
    print("-> {} folder(s) will be created".format(len(folder_not_create)))

    for folder in folder_not_create:
        os.makedirs(folder)

    for contest_type, list_contest in contests.items():
        print(f"---> Packing contest_type = {contest_type}")
        for contest_id, files in list_contest.items():
            path2 = f"{path}{contest_type}/{contest_id}/"
            contest = contest_type + contest_id
            names = tuple((f.split('.')[0][len(contest):] for f in files))
            print("----> Packing {}{}... ".format(contest, names), end="")
            for f in files:
                move(path+f, path2+f)
            print("Done.")

if __name__ == "__main__":
    args = sys.argv[1:]
    path = get_path(config["default"] if len(args) == 0 else args[0]).lower()
    files = get_files(path)
    prefixes = defaultdict(list)
    
    if path == "codeforces/":
        pack_codeforces(path, files)
    elif path == "atcoder/":
        pack_atcoder(path, files)

