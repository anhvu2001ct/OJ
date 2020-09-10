import json
import argparse

def get_config():
    with open("config.json") as f:
        return json.load(f)

def out_config(config):
    with open("config.json", "w") as f:
        json.dump(config, f, indent=4)

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Configuration for config.json")
    parser.add_argument("-c", "--contest", help="Set the contest that append as prefix")
    parser.add_argument("-d", "--default", help="Set the default OJ folder for storing")

    args = parser.parse_args()
    config = get_config()
    if args.contest is not None:
        config["contest"] = args.contest
    if args.default is not None:
        config["default"] = args.default
    out_config(config)
    print("config.json: contest={}, default={}".format(config["contest"], config["default"]))
