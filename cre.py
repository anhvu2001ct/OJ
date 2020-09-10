import os
import sys
import json
from shutil import copy2

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

def get_des_name(name):
    contest = str(config["contest"])
    if contest == "-1": contest = ""
    contest += name
    return contest.upper()

if __name__ == "__main__":
    args = sys.argv[1:]
    if len(args) == 1: args.insert(0, str(config["default"]))
    if len(args) == 2: args.append("main")
    path = get_path(args[0])
    src = args[2]
    extension = os.path.splitext(src)[-1]
    if extension == '': extension = ".cpp"
    src += extension
    des = f"{path}{get_des_name(args[1])}{extension}"
    print(copy2(src, des))
    copy2(f"template{extension}", src)
    
    