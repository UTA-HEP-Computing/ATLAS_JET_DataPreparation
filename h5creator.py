
# coding: utf-8

# In[1]:

import pandas as pd
import numpy as np
import os
import deepdish.io as io


# In[2]:

#data_bkg = pd.read_csv('/home/debo/UTILITIES/ttbar_out.txt', header=None, skiprows=2,error_bad_lines=False)

data = pd.read_csv('/data/debo/jetAnomaly/AtlasData/dijets/mergedRoot/miniTrees/JZ5W.mini.SameLen.txt', header=None,)
#data_sig = pd.read_csv('/home/debo/UTILITIES/gluino_out.txt', header=None, skiprows=2)


# In[3]:

print("data: ",data.shape)


# In[14]:

#data


# In[4]:

dataVal = data.values
#data_sig = data_sig.values


# In[6]:

print("dataVal: ",dataVal.shape)
#print("data_sig: ",data_sig.shape)


# In[7]:

dataVal= dataVal[:,0:448]


# In[8]:

print("dataVal: ",dataVal.shape)


# In[9]:

JZ5W_clusters = {
        'FatJetsPpxpypz' : dataVal
    }


# In[10]:

SAMPLE_PATH = os.path.join('/data/debo/jetAnomaly/AtlasData/dijets/mergedRoot/miniTrees')


# In[11]:

io.save(os.path.join(SAMPLE_PATH, 'JZ5W_clusters'+'.h5'), JZ5W_clusters)


# In[ ]:
