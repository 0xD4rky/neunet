import torch
import torch.nn as nn
import torch.nn.functional as F
import torch.optim as optim
import torchvision
from torchvision.transforms import transforms
from torch.utils.data import Dataset,DataLoader
from torchvision.models import vgg19, VGG19_Weights


import numpy as np
import os 
import matplotlib.pyplot as plt
from PIL import Image
import copy


img_size = 512 if torch.cuda.is_available() else 128

loader = transforms.Compose([
    transforms.Resize(imsize),
    transforms.ToTensor()
])
