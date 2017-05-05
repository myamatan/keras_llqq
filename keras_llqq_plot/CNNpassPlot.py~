import sys, os
import numpy as np

from ROOT import TH1D, gROOT, std
from ROOT import TFile, TTree

from keras.models import model_from_json

prePath = "/Users/masahiroyamatani/icepp/physics/diBoson/output/"
prefilename_mc = "output_inclusive_spin2/submitDir_sp2_mc/data-minitree/"
prefilename_data = "output_inclusive_spin2/submitDir_sp2_data/data-minitree/"

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
    ["ZZ_improved", "ZZ_imporved_Nominal", "SMdiboson"],
    ["WW_improved", "WW_imporved_Nominal", "SMdiboson"],
    ["WZ_improved", "WZ_imporved_Nominal", "SMdiboson"]
    ])

# Data
data_list = np.array([
    ["data15", "data_Nominal", "data"],
    ["data16", "data_Nominal", "data"]
    ])

h_mc = TH1D('mc','mc',100, 0, 3000)
h_data = TH1D('data','data',100, 0, 3000)

if __name__ == "__main__":

    # CNN Model loading
    model = model_from_json(open('model1_architecture.json').read())
    model.load_weights('model1_weights.h5')

    # mc
    for i in range(mc_list[:,0].size):
        filePath = prePath + prefilename_mc + mc_list[i][0] + ".root"
        print filePath
        f = TFile(filePath, 'read')
        tr = f.Get(mc_list[i][1])
        for entry in tr:
            h_mc.Fill(entry.Mlljj)
        
    # data
    for i in range(data_list[:,0].size):
        filePath = prePath + prefilename_data + data_list[i][0] + ".root"
        print filePath
        f = TFile(filePath, 'read')
        tr = f.Get(data_list[i][1])
        for entry in tr:
            h_data.Fill(entry.Mlljj)

    h_mc.Draw()
    h_data.Draw("same")
