import json
import sys

def get_config():
    with open("config.json") as f:
        return json.load(f)

def out_config(config):
    with open("config.json", "w") as f:
        json.dump(config, f, indent=4)

if __name__ == "__main__":
    config = get_config()
    config["contest"] = sys.argv[1]
    out_config(config)
