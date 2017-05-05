import sys, os
import numpy as np

from ROOT import TH1D, gROOT, std
from ROOT import TFile, TTree

from keras.models import model_from_json
from sklearn import preprocessing
    
h_mc = TH1D('mc','mc',100, 0, 3000)
h_signal = TH1D('sig','sig',100, 0, 3000)
h_data = TH1D('data','data',100, 0, 3000)

input_dim = 760


mc_list = np.array(["bkg-aa","bkg-ab","bkg-ac","bkg-ad","bkg-ae","bkg-af","bkg-ag",
    "bkg-ah","bkg-ai","bkg-aj","bkg-ak","bkg-al","bkg-am","bkg-an","bkg-ao","bkg-ap","bkg-aq",
    "bkg-ar","bkg-as","bkg-at","bkg-au","bkg-av","bkg-aw","bkg-ax","bkg-ay","bkg-az","bkg-ba",
    "bkg-bb","bkg-bc","bkg-bd","bkg-be","bkg-bf","bkg-bg","bkg-bh","bkg-bi","bkg-bj","bkg-bk",
    "bkg-bl","bkg-bm","bkg-bn","bkg-bo"])

data_list = np.array(["data-aa","data-ab","data-ac"])

signal_list = np.array(["RSG0700.txt"])


def CNNplot():
    
    prePath = "/Users/masahiroyamatani/icepp/practice/practice_Python/kerasTest/llqqTest/sampkeTXTmake/sample/"
    
    ## For taking scale parametor
    # Load Pima indians datase
    print("Loading signal data ...")
    dataset = np.loadtxt("../signal.txt", delimiter=',')
    print("Loading bkg data ...")
    datasetB = np.loadtxt("../bkg.txt", delimiter=',')
    np.random.shuffle(dataset)
    np.random.shuffle(datasetB)
    
    # Data size
    N = 10000
    # Signal and Bkg stack
    print("Stacking Signal and Bkg sample ...")
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

    # CNN Model loading
    model = model_from_json(open('model1_architecture.json').read())
    model.load_weights('model1_weights.h5')

    signal_count = 0.0
    bkg_count = 0.0

    # mc
    for i in range(mc_list.size):
        filePath = prePath + mc_list[i]
        print filePath
        dataset = np.loadtxt(filePath, delimiter=',')
        N = len(dataset)
        X = dataset[:, 0:input_dim]
        Y = dataset[:, input_dim:]
        X[np.isnan(X)] = 0
        X[np.isinf(X)] = 0
        sX= scaler.transform(X)
        pX = sX.reshape(N, 1, 20, 38)
        pre = model.predict(pX)
        for j in range(len(pre)):    
            #if np.argmax(pre) == 0:
            if pre[j][0] > 0.3:
                # Mlljj (39+58)/2
                # MllJ (45-64)/2
                mass = (X[j][39] + X[j][58])/2. 
                h_mc.Fill(mass, Y[j][0])
                bkg_count += 1.0
    # data
    for i in range(data_list.size):
        filePath = prePath + data_list[i]
        print filePath
        dataset = np.loadtxt(filePath, delimiter=',')
        N = len(dataset)
        X = dataset[:, 0:input_dim]
        Y = dataset[:, input_dim:]
        X[np.isnan(X)] = 0
        X[np.isinf(X)] = 0
        sX= scaler.transform(X)
        pX = sX.reshape(N, 1, 20, 38)
        pre = model.predict(pX)
        for j in range(len(pre)):    
            #if np.argmax(pre) == 0:
            if pre[j][0] > 0.3:
                # Mlljj (39+58)/2
                # MllJ (45-64)/2
                mass = (X[j][39] + X[j][58])/2. 
                h_data.Fill(mass, Y[j][0])
    
    # signal
    for i in range(signal_list.size):
        filePath = prePath + signal_list[i]
        print filePath
        dataset = np.loadtxt(filePath, delimiter=',')
        N = len(dataset)
        X = dataset[:, 0:input_dim]
        Y = dataset[:, input_dim:]
        X[np.isnan(X)] = 0
        X[np.isinf(X)] = 0
        sX= scaler.transform(X)
        pX = sX.reshape(N, 1, 20, 38)
        pre = model.predict(pX)
        for j in range(len(pre)):    
            #if np.argmax(pre) == 0:
            if pre[j][0] > 0.3:
                # Mlljj (39+58)/2
                # MllJ (45-64)/2
                mass = (X[j][39] + X[j][58])/2. 
                h_signal.Fill(mass, Y[j][0])
                signal_count += 1.0

    h_mc.Rebin(2)
    h_data.Rebin(2)
    h_signal.Rebin(2)
    
    h_mc.Draw('e0')
    h_data.Draw("same")
    h_data.SetLineColor(2)
    h_signal.Draw("same")
    h_signal.SetLineColor(4)

    print signal_count, bkg_count
