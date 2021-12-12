import pandas as pd
import pyspark
import collections
import numpy as np
from pyspark import SparkConf,SparkContext
from pyspark.sql import SparkSession, column, dataframe
from pyspark.sql import functions as F
from pyspark.sql.types import  DateType, DoubleType,IntegerType,StringType 

def main():  
    #spark = SparkSession.builder.getOrCreate()
    #animes_dataset = spark.read.csv('anime.csv',sep = ',', header = True)
    #ratings_dataset = spark.read.csv('rating_complete.csv', sep = ',', header = True)
    #
    #animes_dataset.show(100, truncate = True)
    #print("a")



    conf = SparkConf().setMaster("local").setAppName("Recomendador")
    sc = SparkContext(conf = conf)
    lines = sc.textFile("rating_complete.csv")

    movies = lines.zipWithIndex().filter(lambda row, idx: idx > 0).map(lambda row,idx:row).map(lambda x: (int(x.split(',')[1]),1))
    moviesCount = movies.reduceByKey(lambda x,y : x + y)
    flipped = moviesCount.map(lambda xy: (xy[1],xy[0]))


    # ratings = lines.map(lambda x: x.split(",")[2])
    sortedmovies = flipped.sortByKey()
    # result = ratings.countByValue()
    result = sortedmovies.collect()

    sortedResults = collections.OrderedDict(sorted(result.items()))
    for key,value in sortedResults.items():
        print("%s %i" % (key,value))

main()