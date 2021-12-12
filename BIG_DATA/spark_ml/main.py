import pandas as pd
import numpy as np
import pyspark.sql
from pyspark.sql import SparkSession
from pyspark.ml.evaluation import RegressionEvaluator
from pyspark.ml.recommendation import ALS
from pyspark.sql.types import IntegerType
from pyspark.ml.feature import StringIndexer
from pyspark.ml import Pipeline
from pyspark.sql.functions import col,explode

#region COPY_USR_VALORACIONES_TO_GLOBAL
#with open("valoraciones_EP.csv","r") as file1, open("rating_complete.csv","a+") as file2:  
#    file2.write(file1.read())
#    print(file1,file2)
#endregion

#region init spark session with utf8
spark = SparkSession.builder.config("spark.driver.memory","20g").appName("Recomendador").getOrCreate()
#endregion

#region open csvs
animes_dataset = spark.read.option("header","true").option("encoding","utf-8").csv('anime.csv')
ratings_dataset = spark.read.option("header","true").option("encoding","utf-8").csv('rating_complete.csv')
#endregion

#region castear data a int para poder operar
casted_anime = animes_dataset.withColumn("ID",animes_dataset["ID"].cast(IntegerType()))

ratings_dataset = ratings_dataset.withColumn("user_id",ratings_dataset["user_id"].cast(IntegerType()))
ratings_dataset = ratings_dataset.withColumn("anime_id",ratings_dataset["anime_id"].cast(IntegerType()))
ratings_dataset = ratings_dataset.withColumn("rating",ratings_dataset["rating"].cast(IntegerType()))
#endregion

#region training ALS, ERROR
(training,recom) = ratings_dataset.randomSplit([0.8,0.2])
als = ALS(maxIter=5,regParam=0.09,rank=25,userCol="user_id",itemCol = "anime_id",ratingCol ="rating",coldStartStrategy="drop",nonnegative= True )
model = als.fit(training)
evaluator = RegressionEvaluator(metricName = "rmse",labelCol = "rating", predictionCol = "prediction")
predictions = model.transform(recom)
rmse = evaluator.evaluate(predictions)
print("RMSE="+str(rmse))
# predictions.show()
#endregion

#region model recomendations 
model_rec_usrs = model.recommendForAllUsers(20)

model_rec_usr = model_rec_usrs.withColumn("rec_exp",explode("recommendations")).select("user_id",col("rec_exp.anime_id"),col("rec_exp.rating"))
model_rec_usr = model_rec_usr.filter(col("user_id") == 666666)
#endregion

#region animes recom
animes = casted_anime.select(casted_anime["ID"], casted_anime["Name"],casted_anime["English name"], casted_anime["Type"])
model_rec_usr = model_rec_usr.join(animes,model_rec_usr.anime_id == animes.ID)
#endregion

#region movies recom
movies = model_rec_usr.filter((col("Type") == "Movie")& (col("rating") <= 10))
movies = movies.orderBy(col("rating").desc()).limit(5)
movies.show(5,truncate = False)
#endregion 

#region TV series recom
TVseries = model_rec_usr.filter((col("Type") == "TV") | (col("rating") <= 10)).orderBy(col("rating").desc()).limit(5)
TVseries = TVseries.orderBy(col("rating").desc()).limit(5)
TVseries.show(5,truncate = False)
#endregion 

#region TXT outputer

movies_out = movies.toPandas()
np.savetxt(r'movies_out.txt', movies_out.values, fmt = '%s')

TVseries_out = TVseries.toPandas()
np.savetxt(r'TVseries_out.txt',TVseries_out.values, fmt = '%s')

#endregion