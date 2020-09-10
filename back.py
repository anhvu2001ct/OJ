import os
import sys
import json
from shutil import copy

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

def get_src_name(name):
    contest = str(config["contest"])
    if contest == "-1": contest = ""
    contest += name
    return contest.upper()

if __name__ == "__main__":
    args = sys.argv[1:]
    if len(args) == 1: args.insert(0, str(config["default"]))
    if len(args) == 2: args.append("main")
    path = get_path(args[0])
    src = f"{path}{get_src_name(args[1])}.cpp"
    des = args[2] + ".cpp"
    print("{} -> {}".format(src, copy(src, des)))
    
    