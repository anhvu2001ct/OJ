import json
import argparse

def get_config():
    with open("config.json") as f:
        return json.load(f)

def out_config(config):
    with open("config.json", "w") as f:
        json.dump(config, f, indent=4)

def print_dict(d: dict, indent=4):
    if len(d) == 0:
        print("{}")
    else:
        print("{")
        prefix = ""
        for _ in range(indent): prefix += " "
        cnt, sz = 0, len(d)
        for k, v in d.items():
            cnt += 1
            print("{}'{}': {}{}".format(prefix, k, v, "," if cnt < sz else ""))
        print("}")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Configuration for config.json")
    parser.add_argument("-c", "--contest", help="Set the contest that append as prefix")
    parser.add_argument("-d", "--default", help="Set the default OJ folder for storing")
    parser.add_argument("-r", "--reset", help="Reset all configuration", action="store_true")
    parser.add_argument("-a", "--alias", help="Show all alias names", action="store_true")

    args = parser.parse_args()
    config = get_config()

    # For Easily reading
    print("")

    if args.alias:
        print_dict(config["alias"], 4)
    
    if args.reset:
        config["contest"] = -1
        config["default"] = 0
        print("Configuration reseted!")

    if args.contest is not None:
        config["contest"] = args.contest
    if args.default is not None:
        config["default"] = args.default
    out_config(config)
    print("config.json: contest={}, default={}".format(config["contest"], config["default"]))

    # For Easily reading
    print("")