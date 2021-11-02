import json
from engine import *
from path_config import *

path = ConfigPath().filename('config.json')

with open(path.get_path()) as config_file:
    data = json.load(config_file)
    Engine(data).draw()
