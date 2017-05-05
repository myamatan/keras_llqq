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


def build_multilayer_perceptron():
    model = Sequential()
    
    model.add(Dense(input_dim*5, input_dim=input_dim, init='uniform'))
    model.add(Activation('relu'))
    model.add(Dropout(0.2))
    model.add(Dense(input_dim*5/2))
    model.add(Activation('relu'))
    model.add(Dropout(0.2))
    model.add(Dense(1))
    model.add(Activation('sigmoid'))
    
    return model

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
    X[np.isnan(X)] = 0.
    X[np.isinf(X)] = 0.
    scaler = preprocessing.StandardScaler().fit(X)
    X = scaler.transform(X)
    #X = preprocessing.scale(X)
    
    X_train, X_test, Y_train, Y_test = train_test_split(X, Y, train_size=0.8)
    
    # Construct Neuralnet work
    if (argc != 2):
        print('Usage: # python %s filename' % argvs[1])
        quit()      
    if argvs[1] == "first":
        #model = build_multilayer_perceptron()
        model = build_CNN()
    elif argvs[1] == "later":
        model = model_from_json(open('model1_architecture.json').read())
        model.load_weights('model1_weights.h5')
        
    # For CNN reshape
    X_train = X_train.reshape(4*N*0.8,1,20,38)
    X_test = X_test.reshape(4*N*0.2,1,20,38)
    
    # Model summary
    model.summary()
    
    # Model compile
    model.compile(loss='binary_crossentropy', optimizer='adam', metrics=["accuracy"])
    #sgd = SGD(lr='0.01', momentum=0.9, nesterov=True)
    #model.compile(optimizer=sgd, loss="binary_crossentropy")
    
    # Early-stopping
    early_stopping = EarlyStopping(patience=0, verbose=1)
    
    # Learning models
    hist = model.fit(X_train, Y_train,
            nb_epoch=5,
            batch_size=10,
            validation_data=(X_test, Y_test) )
            #callbacks=[early_stopping])
            
    # Evaluating models
    scores = model.evaluate(X_test, Y_test, show_accuracy=True, verbose=0)
    
    # Output
    print("Test score:", scores[0])
    print("Test accuracy:", scores[1])
    json_string = model.to_json()
    open('model1_architecture_c.json', 'w').write(json_string)
    model.save_weights('model1_weights_c.h5')

"""
    pyplot.plot(hist.history['loss'], linewidth=3, label='train')
    pyplot.plot(hist.history['val_loss'], linewidth=3, label='valid')
    pyplot.grid()
    pyplot.legend()
    pyplot.xlabel('epoch')
    pyplot.ylabel('loss')
    pyplot.ylim(1e-2, 1e+0)
    pyplot.yscale('log')
    pyplot.show()
"""
