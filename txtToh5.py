
import pandas as pd
import numpy as np
import os
import sys
#import deepdish.io as io
input_csv = sys.argv[1]

path = input_csv 
data = pd.read_csv(path, header=None,nrows=1)

print("data: ",data.shape)

columns = data.columns.tolist()

cols_to_use = columns[:len(columns)-1]

data = pd.read_csv(path,header=None, usecols=cols_to_use)
print("data: ",data.shape)

data.to_hdf(path+'.h5', key='FatJetsPpxpypz', mode='w')






