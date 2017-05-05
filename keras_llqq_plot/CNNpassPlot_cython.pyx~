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

def CNNplot():
    
    prePath = "/Users/masahiroyamatani/icepp/physics/diBoson/output/"
    prefilename_mc = "output_inclusive_spin2/submitDir_sp2_mc/data-minitree/"
    prefilename_signal = "output_inclusive_spin2/submitDir_sp2_signal/data-minitree/"
    prefilename_data = "output_inclusive_spin2/submitDir_sp2_data/data-minitree/"
    
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

    # MC (filename, ttree name, category)
    mc_list = np.array([
        ["ZeeB_v221", "Z_Nominal", "Z+jets"],
        ["ZeeC_v221", "Z_Nominal", "Z+jets"],
        ["ZeeL_v221", "Z_Nominal", "Z+jets"],
        ["ZeeHPT_v221", "Z_Nominal", "Z+jets"],
        ["ZmumuB_v221", "Z_Nominal", "Z+jets"],
        ["ZmumuC_v221", "Z_Nominal", "Z+jets"],
        ["ZmumuL_v221", "Z_Nominal", "Z+jets"],
        ["ZmumuHPT_v221", "Z_Nominal", "Z+jets"],
        ["ZtautauB_v221", "Z_Nominal", "Z+jets"],
        ["ZtautauC_v221", "Z_Nominal", "Z+jets"],
        ["ZtautauL_v221", "Z_Nominal", "Z+jets"],
        ["ZtautauHPT_v221", "Z_Nominal", "Z+jets"],
        ["ttbar", "ttbar_Nominal", "topQuarks"],
        ["singletop_Wt", "stopWt_Nominal", "topQuarks"],
        ["singletop_s", "stops_Nominal", "topQuarks"],
        ["singletop_t", "stopt_Nominal", "topQuarks"],
        ["ZZ_improved", "ZZ_Nominal", "SMdiboson"],
        ["WW_improved", "WW_Nominal", "SMdiboson"],
        ["WZ_improved", "WZ_Nominal", "SMdiboson"]
        ])
        
    # Data
    data_list = np.array([        
        ["data15", "data_Nominal", "data"],
        ["data16", "data_Nominal", "data"]
        ])
    
    # Signal
    signal_list = np.array([        
        ["RS_G_ZZ", "GZZllqqc10m2400_Nominal", "signal"],
        ["RS_G_ZZ", "GZZllqqc10m1400_Nominal", "signal"]
        ])
    
    # CNN Model loading
    model = model_from_json(open('model1_architecture.json').read())
    model.load_weights('model1_weights.h5')

    model.summary()

    # signal
    for i in range(signal_list[:,0].size):
        
        filePath = prePath + prefilename_signal + signal_list[i][0] + ".root"
        print filePath
        f = TFile(filePath, 'read')
        tr = f.Get(signal_list[i][1])
        for entry in tr:
            dat = np.array([])
            dat = np.append(dat, entry.Mlljj)
            dat = np.append(dat, entry.ptjj)
            dat = np.append(dat, entry.Mjj)
            dat = np.append(dat, np.sqrt(entry.ptll*entry.ptll+entry.ptjj*entry.ptjj)/entry.Mlljj)
            dat = np.append(dat, entry.ptll)
            dat = np.append(dat, entry.Mll)
            dat = np.append(dat, entry.MllJ)
            dat = np.append(dat, entry.ptJ)
            dat = np.append(dat, entry.MJ)
            dat = np.append(dat, np.sqrt(entry.ptll*entry.ptll+entry.ptJ*entry.ptJ)/entry.MllJ)
            dat = np.append(dat, entry.E_l1)
            dat = np.append(dat, entry.E_l2)
            dat = np.append(dat, entry.pt_l1)
            dat = np.append(dat, entry.pt_l2)
            dat = np.append(dat, entry.mjjvbftag)
            dat = np.append(dat, entry.deltaetajjvbftag)
            dat = np.append(dat, entry.eta_l1)
            dat = np.append(dat, entry.eta_l2)
            dat = np.append(dat, entry.phi_l1)
            dat = np.append(dat, entry.phi_l2)
            X = np.array([])
            for s in range(len(dat)):
                for t in range(s+1, len(dat)):
                    X = np.append(X, dat[s]*dat[t])
                for t in range(s+1, len(dat)):
                    X = np.append(X, dat[s]/(dat[t]+1.))
                for t in range(s+1, len(dat)):
                    X = np.append(X, dat[s]+dat[t])
                for t in range(s+1, len(dat)):
                    X = np.append(X, dat[s]-dat[t])
            X[np.isnan(X)] = 0
            X[np.isinf(X)] = 0
            X = X.reshape((1,len(X)))
            print("1------------------------")
            print(X[0][:10])
            X = scaler.transform(X) 
            print(X[0][:10])
            X = X.reshape(1,1,20,38)
            pre = model.predict(X)
            print(pre)
            if entry.MllJ > 0 and np.argmax(pre) == 0:
            #if entry.MllJ > 0 and pre[0][0] > 0.5:
                h_signal.Fill(entry.MllJ, entry.weight)

    # mc
    for i in range(mc_list[:,0].size):
        filePath = prePath + prefilename_mc + mc_list[i][0] + ".root"
        print filePath
        f = TFile(filePath, 'read')
        tr = f.Get(mc_list[i][1])
        for entry in tr:
            dat = np.array([])
            dat = np.append(dat, entry.Mlljj)
            dat = np.append(dat, entry.ptjj)
            dat = np.append(dat, entry.Mjj)
            dat = np.append(dat, np.sqrt(entry.ptll*entry.ptll+entry.ptjj*entry.ptjj)/entry.Mlljj)
            dat = np.append(dat, entry.ptll)
            dat = np.append(dat, entry.Mll)
            dat = np.append(dat, entry.MllJ)
            dat = np.append(dat, entry.ptJ)
            dat = np.append(dat, entry.MJ)
            dat = np.append(dat, np.sqrt(entry.ptll*entry.ptll+entry.ptJ*entry.ptJ)/entry.MllJ)
            dat = np.append(dat, entry.E_l1)
            dat = np.append(dat, entry.E_l2)
            dat = np.append(dat, entry.pt_l1)
            dat = np.append(dat, entry.pt_l2)
            dat = np.append(dat, entry.mjjvbftag)
            dat = np.append(dat, entry.deltaetajjvbftag)
            dat = np.append(dat, entry.eta_l1)
            dat = np.append(dat, entry.eta_l2)
            dat = np.append(dat, entry.phi_l1)
            dat = np.append(dat, entry.phi_l2)
            X = np.array([])
            for s in range(len(dat)):
                for t in range(s+1, len(dat)):
                    X = np.append(X, dat[s]*dat[t])
                for t in range(s+1, len(dat)):
                    X = np.append(X, dat[s]/(dat[t]+1.))
                for t in range(s+1, len(dat)):
                    X = np.append(X, dat[s]+dat[t])
                for t in range(s+1, len(dat)):
                    X = np.append(X, dat[s]-dat[t])
            X[np.isnan(X)] = 0
            X[np.isinf(X)] = 0
            X = X.reshape((1,len(X)))
            X = scaler.transform(X) 
            X = X.reshape(1,1,20,38)
            pre = model.predict(X)
            if entry.MllJ > 0 and np.argmax(pre) == 0:
            #if entry.MllJ > 0 and pre[0][0] > 0.5:
                h_mc.Fill(entry.MllJ, entry.weight)
    

    # data
    for i in range(data_list[:,0].size):
        filePath = prePath + prefilename_data + data_list[i][0] + ".root"
        print filePath
        f = TFile(filePath, 'read')
        tr = f.Get(data_list[i][1])
        #data_Nominal;1
        for entry in tr:
            dat = np.array([])
            dat = np.append(dat, entry.Mlljj)
            dat = np.append(dat, entry.ptjj)
            dat = np.append(dat, entry.Mjj)
            dat = np.append(dat, np.sqrt(entry.ptll*entry.ptll+entry.ptjj*entry.ptjj)/entry.Mlljj)
            dat = np.append(dat, entry.ptll)
            dat = np.append(dat, entry.Mll)
            dat = np.append(dat, entry.MllJ)
            dat = np.append(dat, entry.ptJ)
            dat = np.append(dat, entry.MJ)
            dat = np.append(dat, np.sqrt(entry.ptll*entry.ptll+entry.ptJ*entry.ptJ)/entry.MllJ)
            dat = np.append(dat, entry.E_l1)
            dat = np.append(dat, entry.E_l2)
            dat = np.append(dat, entry.pt_l1)
            dat = np.append(dat, entry.pt_l2)
            dat = np.append(dat, entry.mjjvbftag)
            dat = np.append(dat, entry.deltaetajjvbftag)
            dat = np.append(dat, entry.eta_l1)
            dat = np.append(dat, entry.eta_l2)
            dat = np.append(dat, entry.phi_l1)
            dat = np.append(dat, entry.phi_l2)
            X = np.array([])
            for s in range(len(dat)):
                for t in range(s+1, len(dat)):
                    X = np.append(X, dat[s]*dat[t])
                for t in range(s+1, len(dat)):
                    X = np.append(X, dat[s]/(dat[t]+1.))
                for t in range(s+1, len(dat)):
                    X = np.append(X, dat[s]+dat[t])
                for t in range(s+1, len(dat)):
                    X = np.append(X, dat[s]-dat[t])
            X[np.isnan(X)] = 0
            X[np.isinf(X)] = 0
            X = X.reshape((1,len(X)))
            X = scaler.transform(X) 
            X = X.reshape(1,1,20,38)
            pre = model.predict(X)
            if entry.MllJ > 0 and np.argmax(pre) == 0:
            #if entry.MllJ > 0 and pre[0][0] > 0.5:
                h_data.Fill(entry.MllJ)

    h_mc.Rebin(2)
    h_data.Rebin(2)
    h_signal.Rebin(2)
    
    h_mc.Draw()
    h_data.Draw("same")
    h_data.SetLineColor(2)
    h_signal.Draw("same")
    h_signal.SetLineColor(4)
