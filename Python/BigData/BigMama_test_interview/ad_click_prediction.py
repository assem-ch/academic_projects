# -*- coding: utf-8 -*-
"""
Created on Sat Jan 30 08:45:37 2016

@author: assem

"""
import datetime
#import numpy as np
import matplotlib.pyplot as plt
#from matplotlib import style
import pandas as pd
from patsy import dmatrix
from sklearn import linear_model

#learning_milestone = 100000


non_cat_features = [
            "timestamp",
            "verticals_0", "verticals_1", "verticals_2",
            "vertical_3",
            "cpc_price",
            "bidfloor",
            "bid_price",
            "won_price",
            "viewability"
            ]

cat_features = [
            #"format",
            "position",
            "support_type",
            "device_type",
            "device_geo_country",
            ##u'support_category_0', u'support_category_1', u'support_category_2', u'support_category_3',
]


# fixing data
# TODO


# normalization
#def Scale(df):
#    df =  (df - df.mean())/df.max()

def normalize(df):
    # get only hour from timestamp
    get_hour = lambda t: int(datetime.datetime.fromtimestamp(t).strftime('%H'))
    df["timestamp"]=df["timestamp"].apply(get_hour)
    # Feature scaling
    #for feature in non_cat_features:
    #    Scale(df[feature])


train = pd.read_csv("data/train.csv")
normalize(train)


# Analyze features
# train.groupby('clicked').mean()
# pd.crosstab(train["clicked"], train["format"], rownames=["clicked"])



#
features = "+".join(non_cat_features) +" + "+ " C("+ ") + C(".join(cat_features)+ ")"

X = dmatrix(features, train, return_type="dataframe") #train[features] #
y = train["clicked"]

#Plotting
#style.use("ggplot")
plt.scatter(y,X["cpc_price"])
plt.show()


clf = linear_model.SGDClassifier() ## for bigger data, fitting partially
#clf = linear_model.LogisticRegression()

clf.fit(X, y)

score = clf.score(X, y)

print "number of clicked = %d / %d" % (sum(y), len(y))
print  "score is", score
print  "score of predicting-always-0 is", (1 - y.mean())

#assert score > (1 - y.mean()), " Wait! Look again!!, your model is not doing well"

# TODO: Partial fit for milestones
# TODO: Use pickle to save the model

print "training done!"

test = pd.read_csv("data/test.csv")
normalize(test)

X_test = dmatrix(features, test, return_type="dataframe")
y_test = clf.predict(X_test)

print "number of predicted ones =", sum(y_test)
print "prediction done!"