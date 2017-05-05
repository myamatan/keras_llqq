import os
import numpy as np

from sklearn import preprocessing
from sklearn.model_selection import train_test_split
from matplotlib import pyplot

import matplotlib.pyplot as plt
from PIL import Image
import matplotlib.mlab as mlab

from keras.models import model_from_json

seed = 7
np.random.seed(seed)

input_dim = 684

if __name__ == "__main__":

	# Pima indians datasetをロード
	#dataset = np.loadtxt(os.path.join("data", "pima-indians-diabetes.data"), delimiter=',')
	dataset = np.loadtxt("signal.txt", delimiter=',')
	datasetB = np.loadtxt("bkg.txt", delimiter=',')
	np.random.shuffle(dataset)
	np.random.shuffle(datasetB)

	# Data size
	N = 10000#550000

	# Signal and Bkg stack
	dataset = dataset[:N]
	datasetB = datasetB[:N]
	dataset = np.vstack((dataset,datasetB))
	np.random.shuffle(dataset)

	# データとラベルを取得
	X = dataset[:, 0:input_dim]
	Y = dataset[:, input_dim]
	# 正規化
	X = preprocessing.scale(X)

	X_train, X_test, Y_train, Y_test = train_test_split(X, Y, train_size=0.8)

	X_test = X_test.reshape(2*N*0.2,36,19)

	while True:
		print("Enter Image No")
		x = int(input())
		if x == -1:
			break
		plt.imshow(X_test[x],interpolation = 'none')
		print(Y_test[x])
		plt.show()
