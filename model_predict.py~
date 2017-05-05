import os
import numpy as np
import sys

from keras.models import Sequential
from keras.layers import Dense, Dropout, Activation
from keras.optimizers import SGD, Adam
from keras.layers import Convolution2D, MaxPooling2D, Flatten
from keras.callbacks import EarlyStopping
from keras.utils import np_utils

from sklearn import preprocessing
from sklearn.model_selection import train_test_split
#from matplotlib import pyplot

#import matplotlib.pyplot as plt
from PIL import Image
#import matplotlib.mlab as mlab

from keras.models import model_from_json


#seed = 7
#np.random.seed(seed)

input_dim = 760

argvs = sys.argv 
argc = len(argvs)

def build_CNN():
    model = Sequential()
    
    model.add(Convolution2D(32, 3, 3, input_shape=(1,20,38)))
    model.add(Activation('relu'))
    model.add(Convolution2D(32, 3, 3))
    model.add(Activation('relu'))
    model.add(MaxPooling2D(pool_size=(2, 2)))
    model.add(Dropout(0.25))
    
    model.add(Convolution2D(64, 3, 3))
    model.add(Activation('relu'))
    model.add(Convolution2D(64, 3, 3))
    model.add(Activation('relu'))
    model.add(MaxPooling2D(pool_size=(2, 2)))
    model.add(Dropout(0.25))	
    
    model.add(Flatten())
    model.add(Dense(512))
    model.add(Activation('relu'))
    model.add(Dropout(0.25))
    
    model.add(Dense(4))
    #model.add(Activation('sigmoid'))
    model.add(Activation('softmax'))
    
    return model

if __name__ == "__main__":
    
    # Load Pima indians datase
    print("Loading signal data ...")
    dataset = np.loadtxt("signal.txt", delimiter=',')
    print("Loading bkg data ...")
    datasetB = np.loadtxt("bkg.txt", delimiter=',')
    np.random.shuffle(dataset)
    np.random.shuffle(datasetB)
    
    # Data size
    N = 10000
    # Signal and Bkg stack
    print("Stacking ...")
    dataset = dataset[:N]
    datasetB = datasetB[:3*N]
    dataset = np.vstack((dataset,datasetB))
    np.random.shuffle(dataset)

    # Get data and labels 
    print("Arranging data and label ...")
    X = dataset[:, 0:input_dim]
    Y = dataset[:, input_dim:]
    # normalization
    X[np.isnan(X)] = 0
    X[np.isinf(X)] = 0
    #X = preprocessing.scale(X)
    scaler = preprocessing.StandardScaler().fit(X)
    X = scaler.transform(X) 
    
    model = model_from_json(open('model1_architecture.json').read())
    model.load_weights('model1_weights.h5')

    model.summary()
        
    # For CNN reshape
    X = X.reshape(4*N,1,20,38)

    pre = model.predict(X[:20])#:8
    print(pre)
    print(Y[:20])
    
    # Model compile
    #model.compile(loss='binary_crossentropy', optimizer='adam', metrics=["accuracy"])
    #sgd = SGD(lr='0.01', momentum=0.9, nesterov=True)
    #model.compile(optimizer=sgd, loss="binary_crossentropy")
    
    # Evaluating models
    #scores = model.evaluate(X_test, Y_test, show_accuracy=True, verbose=0)
    
